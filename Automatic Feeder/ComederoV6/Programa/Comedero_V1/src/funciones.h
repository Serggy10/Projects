#include <WiFi.h>
#include <SPIFFS.h>
#include <ESPAsyncWebServer.h>
#include <WebSocketsServer.h>
#include <DNSServer.h>

const char *ssid = "ComederoAutomatico";
const char *password = "Comedero1234";
const char *ssidRouter = "DIGIFIBRA-ctUQ";
const char *passwordRouter = "3T67UeAPkNU7";

DNSServer dnsServer;
AsyncWebServer server(80);
WebSocketsServer webSocket = WebSocketsServer(1337);
char msg_buf[10];
bool conectadoWifi = false;

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

bool IniciaWifiStation(const char *ssid, const char *password);
void onWebSocketEvent(uint8_t client_num, WStype_t type, uint8_t *payload, size_t length);
String processor(const String &var);

void IniciaWiFi()
{
    // Iniciar el modo AP y STA
    WiFi.mode(WIFI_AP_STA);
    WiFi.softAP(ssid, password);
    dnsServer.start(53, "*", WiFi.softAPIP());

    conectadoWifi = IniciaWifiStation(ssidRouter, passwordRouter);
    IPAddress AP_IP = WiFi.softAPIP();
    Serial.print("AP IP address: ");
    Serial.println(AP_IP);

    // Iniciar SPIFFS
    if (!SPIFFS.begin(true))
    {
        Serial.println("An Error has occurred while mounting SPIFFS");
        return;
    }

    // Servir el archivo HTML principal
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
              {
        IPAddress remote_ip = request->client()->remoteIP();
        Serial.println("[" + remote_ip.toString() + "] HTTP GET request of " + request->url());
        //Si se accede desde AP
        if ((remote_ip.toString()).indexOf("192.168.4.") != -1 || WiFi.localIP().toString().equals(remote_ip.toString())) {
            request->send(SPIFFS, "/paginaWeb.html", "text/html");
        }
        // Si se accede desde WiFi 
        else if ((remote_ip.toString()).indexOf("192.168.1.") != -1 || WiFi.localIP().toString().equals(remote_ip.toString())) {
            request->send(SPIFFS, "/paginaWeb.html", "text/html");
        }
        // Si no error.
        else
        {
            request->send(404, "text/plain", "File Not Found");
        } });

    server.addHandler(new CaptiveRequestHandler()).setFilter(ON_AP_FILTER); // only when requested from AP

    // Iniciar el servidor web
    server.begin();
    Serial.println("HTTP server started");

    // Iniciar el servidor WebSocket y asignar el callback
    webSocket.begin();
    webSocket.onEvent(onWebSocketEvent);
}

bool IniciaWifiStation(const char *ssid, const char *password)
{
    Serial.printf("Intentando conectar a %s\n", ssid);

    WiFi.begin(ssid, password);
    long int tiempo = millis();
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
        if (millis() > tiempo + 10000)
        {
            Serial.println("\nTiempo de espera de conexion Wifi superado");
            return false;
        }
    }

    Serial.println("WiFi conectada.");
    Serial.print("STA dirección IP: ");
    Serial.println(WiFi.localIP());
    return true;
}

void onWebSocketEvent(uint8_t client_num, WStype_t type, uint8_t *payload, size_t length)
{
    // Manejo de eventos WebSocket
    String str((char *)payload);
    switch (type)
    {
    case WStype_DISCONNECTED:
        Serial.printf("[%u] Disconnected!\n", client_num);
        break;

    case WStype_CONNECTED:
    {
        IPAddress ip = webSocket.remoteIP(client_num);
        Serial.printf("[%u] Connection from ", client_num);
        Serial.println(ip.toString());
        break;
    }

    case WStype_TEXT:
        Serial.printf("[%u] Received text: %s\n", client_num, payload);
        break;

    default:
        break;
    }
}

void LoopWebServer()
{
    dnsServer.processNextRequest();
    webSocket.loop();
}

String processor(const String &var)
{
    Serial.println(var);
    if (var == "DIRIP")
    {
        String dirIp = WiFi.localIP().toString();
        Serial.println("Processor modo estacion");
        Serial.println(dirIp);
        return dirIp;
    }
    else
    {
        Serial.println("Dir ip no encontrada devuelvo 192.168.4.1");
        return "192.168.4.1";
    }
}
