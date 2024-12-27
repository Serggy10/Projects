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
    WebSocketsServer webSocketComedero = WebSocketsServer(1337);
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
    int dosisSinricPro = 0;
    bool darDosisSinricPro = false;
    bool comederoAtascado = false;

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

    void DosisSinricPro(int dosis);
    void setup();
    void loop();

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
    void Calibrar(int pesoConocido);
    void ComprobarHora();
    void DarDosis(int dosis);
    void Tarar();
    void CalculaPeso();
    void MandarPeso();
    void MoverMotor();
    void DosificarSinricPro();
};
