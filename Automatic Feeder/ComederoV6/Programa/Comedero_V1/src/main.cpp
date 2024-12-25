#include <WiFi.h>
#include <SPIFFS.h>
#include <ESPAsyncWebServer.h>
#include <WebSocketsServer.h>
#include <DNSServer.h>
#include "funciones.h"

/*
  V1: interfaz de la pagina WEB.
*/

void setup()
{
  Serial.begin(115200);
  IniciaWiFi();
}

void loop()
{
  LoopWebServer();
}
