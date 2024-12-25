#include "ComederoWiFi.h"

/*
  V1: interfaz de la pagina WEB.
  V2: Creación de librería ComederoWiFi. Guardado de parametros en memoria SPIFFS.
  V4: Implementación de SinricPro
*/
// #define ENABLE_DEBUG

#ifdef ENABLE_DEBUG
#define DEBUG_ESP_PORT Serial
#define NODEBUG_WEBSOCKETS
#define NDEBUG
#endif

#ifdef ESP32
#include <WiFi.h>
#endif

#include <SinricPro.h>
#include "SinricProComedero.h"

#define APP_KEY "f5b6b057-f65b-4c34-b595-489667228191"
#define APP_SECRET "d9760d34-c170-4323-9a23-87303b92d7ba-b098499e-3931-4297-93c6-d295e4dc6d9d"
#define DEVICE_ID "66a41355888aa7f7a2503262"

ComederoWiFi comedero;
SinricProComedero &sinricProComedero = SinricPro[DEVICE_ID];
void TareaSinricPro(void *pvParameters);
void TareaComedero(void *pvParameters);

/*************
 * Variables *
 ***********************************************
 * Global variables to store the device states *
 ***********************************************/

// ModeController
std::map<String, String> globalModes;

/*************
 * Callbacks *
 *************/

// ModeController
bool onSetMode(const String &deviceId, const String &instance, String &mode)
{
  Serial.printf("[Device: %s]: Modesetting for \"%s\" set to mode %s\r\n", deviceId.c_str(), instance.c_str(), mode.c_str());
  globalModes[instance] = mode;
  comedero.DosisSinricPro(mode.toInt());
  return true;
}

/**********
 * Events *
 *************************************************
 * Examples how to update the server status when *
 * you physically interact with your device or a *
 * sensor reading changes.                       *
 *************************************************/

// PushNotificationController
void sendPushNotification(String notification)
{
  sinricProComedero.sendPushNotification(notification);
}

// ModeController
void updateMode(String instance, String mode)
{
  sinricProComedero.sendModeEvent(instance, mode, "PHYSICAL_INTERACTION");
}

/*********
 * Setup *
 *********/
void setupWiFi()
{
#if defined(ESP8266)
  WiFi.setSleepMode(WIFI_NONE_SLEEP);
  WiFi.setAutoReconnect(true);
#elif defined(ESP32)
  WiFi.setSleep(false);
  WiFi.setAutoReconnect(true);
#endif

  WiFi.begin(comedero.ssidRouter, comedero.passwordRouter);
  Serial.printf("[WiFi]: Connecting to %s", comedero.ssidRouter);
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.printf(".");
    delay(250);
    if (millis() > 10000)
    {
      Serial.println("No se ha podido conectar a la red WiFi.");
      return;
    }
  }
  Serial.printf("connected\r\n");
}

void setupSinricPro()
{
  // ModeController
  sinricProComedero.onSetMode("modeInstance1", onSetMode);

  SinricPro.onConnected([]
                        { Serial.printf("[SinricPro]: Connected\r\n"); });
  SinricPro.onDisconnected([]
                           { Serial.printf("[SinricPro]: Disconnected\r\n"); });
  SinricPro.begin(APP_KEY, APP_SECRET);
};

void setup()
{
  Serial.begin(115200);
  comedero.setup();
  setupWiFi();
  setupSinricPro();
  xTaskCreatePinnedToCore(
      TareaSinricPro, // Función de la tarea
      "Core0Task",    // Nombre de la tarea
      10000,          // Tamaño de la pila
      NULL,           // Parámetros de entrada
      1,              // Prioridad de la tarea
      NULL,           // Manejador de la tarea (puede ser NULL si no se necesita)
      0);             // Núcleo en el que se ejecutará la tarea (1 para el segundo núcleo)
  xTaskCreatePinnedToCore(
      TareaComedero, // Función de la tarea
      "Core1Task",   // Nombre de la tarea
      10000,         // Tamaño de la pila
      NULL,          // Parámetros de entrada
      1,             // Prioridad de la tarea
      NULL,          // Manejador de la tarea (puede ser NULL si no se necesita)
      1);            // Núcleo en el que se ejecutará la tarea (1 para el segundo núcleo)
}

void loop()
{
  comedero.loop();
  SinricPro.handle();
}
void TareaComedero(void *pvParametes)
{
  for (;;)
  {
    comedero.loop();
    delay(10);
  }
}

void TareaSinricPro(void *pvParametes)
{
  for (;;)
  {
    SinricPro.handle();
    if (comedero.comederoAtascado)
    {
      if (comedero.currentMinute >= 10)
        sendPushNotification("Comedero atascado a las " + String(comedero.currentHour) + ":" + String(comedero.currentMinute) + ". Dosis dada: " + String(comedero.peso));
      else
        sendPushNotification("Comedero atascado a las " + String(comedero.currentHour) + ":0" + String(comedero.currentMinute) + ". Dosis dada: " + String(comedero.peso));
      comedero.comederoAtascado = false;
    }
    delay(10);
  }
}
