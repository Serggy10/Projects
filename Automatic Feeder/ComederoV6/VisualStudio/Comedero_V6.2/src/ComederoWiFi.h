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

// TODO arreglar la calibración de la bascula, con el mismo valor de lectura (30940 en raw) al inicio muestra 0g pero tras reiniciar el esp32 muestra otros valores.

#define PIN_DT 2
#define PIN_SCK 5

class ComederoWiFi
{
public:
    const char *ssid = "ComederoAutomatico";
    const char *password = "Comedero1234";
    String ssidRouter = "DIGIFIBRA-ctUQ";
    String passwordRouter = "3T67UeAPkNU7";

    DNSServer dnsServer;
    AsyncWebServer server = AsyncWebServer(80);
    WebSocketsServer webSocket = WebSocketsServer(1337);
    Preferences datos;
    WiFiUDP ntpUDP;
    NTPClient timeClient = NTPClient(ntpUDP, "pool.ntp.org", 3600 * 2);
    HX711 bascula;

    bool conectadoWifi = false;
    bool clienteConectado = false;
    bool rotarHorario = false;
    bool rotarAntihorario = false;
    short int numDosis = 0;
    unsigned long tiempoActual = 0;
    unsigned long tiempoActualizarPeso = 0;
    float factorCalibracion = 0;

    struct Dosis
    {
        int hour;
        int minute;
        int quantity;
    };
    std::vector<Dosis> dosis;
    ComederoWiFi() {}

    void setup()
    {
        CargarParametros();
        IniciaWiFi();
        timeClient.begin();
        timeClient.update();
        Serial.println(timeClient.getFormattedTime());
        bascula.begin(PIN_DT, PIN_SCK);
        bascula.set_scale(factorCalibracion);
    }

    void loop()
    {
        dnsServer.processNextRequest();
        webSocket.loop();
        ComprobarHora();

        if (millis() > tiempoActualizarPeso + 1000)
        {
            tiempoActualizarPeso = millis();
            float peso = bascula.get_units(10);
            Serial.println(peso);
            Serial.println(bascula.read());
            StaticJsonDocument<200> jsonDoc;
            jsonDoc["weight"] = peso;
            String jsonString;
            serializeJson(jsonDoc, jsonString);
            webSocket.broadcastTXT(jsonString);
        }
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
};
