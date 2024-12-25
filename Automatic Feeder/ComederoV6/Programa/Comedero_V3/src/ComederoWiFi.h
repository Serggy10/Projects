#include <WiFi.h>
#include <SPIFFS.h>
#include <ESPAsyncWebServer.h>
#include <WebSocketsServer.h>
#include <DNSServer.h>
#include <Preferences.h>
#include <ArduinoJson.h>
#include <vector>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <HX711.h>
#include <s3servo.h>

#define PIN_DT 2
#define PIN_SCK 5

class ComederoWiFi
{
public:
    const char *ssid = "ComederoAutomatico";
    const char *password = "Comedero1234";
    String ssidRouter = "DIGIFIBRA-ctUQ";
    String passwordRouter = "3T67UeAPkNU7";
    unsigned int husoHorario = 0;

    DNSServer dnsServer;
    AsyncWebServer server = AsyncWebServer(80);
    WebSocketsServer webSocket = WebSocketsServer(1337);
    Preferences datos;
    WiFiUDP ntpUDP;
    NTPClient timeClient; // Declaración sin inicialización
    HX711 bascula;
    s3servo servo;

    bool conectadoWifi = false;
    bool clienteConectado = false;
    bool rotarHorario = false;
    bool rotarAntihorario = false;
    short int numDosis = 0;
    unsigned long tiempoActual = 0;
    unsigned long tiempoActualizarPeso = 0;

    float peso = 0;
    float valorMinBascula = 0;
    float valorCalibBascula = 1;
    int pesoReferencia = 0;
    int currentMinute = 0;
    int currentHour = 0;

    IPAddress IPSTA;

    struct Dosis
    {
        int hour;
        int minute;
        int quantity;
    };
    std::vector<Dosis> dosis;

    ComederoWiFi()
        : timeClient(ntpUDP, "pool.ntp.org", 0) // No inicializamos timeClient aquí
    {
    }

    void setup()
    {
        CargarParametros(); // Carga el huso horario

        // Inicializa timeClient con el huso horario cargado
        timeClient.setTimeOffset(husoHorario);

        IniciaWiFi();
        timeClient.begin();
        timeClient.update();
        Serial.println(timeClient.getFormattedTime());

        bascula.begin(PIN_DT, PIN_SCK);
        bascula.set_scale();
        pinMode(18, OUTPUT);
        servo.attach(18);
    }

    void loop()
    {
        dnsServer.processNextRequest();
        webSocket.loop();
        ComprobarHora();
        MandarPeso();
        MoverMotor();
    }

private:
    class CaptiveRequestHandler : public AsyncWebHandler
    {
    public:
        CaptiveRequestHandler() {}
        virtual ~CaptiveRequestHandler() {}

        bool canHandle(AsyncWebServerRequest *request)
        {
            return true;
        }

        void handleRequest(AsyncWebServerRequest *request)
        {
            request->send(SPIFFS, "/paginaWeb.html", "text/html");
        }
    };

    void IniciaWiFi();
    bool IniciaWifiStation(String ssid, String password);
    void onWebSocketEvent(uint8_t client_num, WStype_t type, uint8_t *payload, size_t length);
    String processor(const String &var);
    void GuardarParametros();
    void CargarParametros();
    void HandleTextMessage(uint8_t client_num, const String &message);
    void Calibrar(int pesoConocido); // TODO
    void ComprobarHora();
    void DarDosis(int dosis);
    void Tarar();
    void CalculaPeso() { peso = map(bascula.read_average(10), valorMinBascula, valorCalibBascula, 0, pesoReferencia); }
    void MandarPeso();
    void MoverMotor();
};
