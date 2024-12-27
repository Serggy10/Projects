#include <Arduino.h>

//* V1: Primera prueba con solo función de encendido completo.
//* V2: Optimización del consumo del WiFi. En modo apagado paso de consumo de 150mA a 90mA.
//*     Cambiado nombre a Lampara para que Alexa lo detecte mejor.

// Uncomment the following line to enable serial debug output
#define ENABLE_DEBUG

#ifdef ENABLE_DEBUG
#define DEBUG_ESP_PORT Serial
#define NODEBUG_WEBSOCKETS
#define NDEBUG
#endif

#include <Arduino.h>
#ifdef ESP8266
#include <ESP8266WiFi.h>
#endif
#ifdef ESP32
#include <WiFi.h>
#endif

#include <SinricPro.h>
#include <Adafruit_NeoPixel.h>
#include "Lampara.h"
#include <Colores.h>

#define APP_KEY "f5b6b057-f65b-4c34-b595-489667228191"
#define APP_SECRET "d9760d34-c170-4323-9a23-87303b92d7ba-b098499e-3931-4297-93c6-d295e4dc6d9d"
#define DEVICE_ID "668018626e1af359350aef60"

#define SSID "DIGIFIBRA-ctUQ"
#define PASS "3T67UeAPkNU7"

#define BAUD_RATE 9600

Lampara &lampara = SinricPro[DEVICE_ID];
void TareaSinricPro(void *pvParameters);
void TareaLEDs(void *pvParameters);
/*************
 * Variables *
 ***********************************************
 * Global variables to store the device states *
 ***********************************************/

// PowerStateController
bool globalPowerState;

// ModeController
std::map<String, String> globalModes;

// BrightnessController
int globalBrightness;

/*************
 * Callbacks *
 *************/

// ModeController
bool onSetMode(const String &deviceId, const String &instance, String &mode)
{
  Serial.printf("[Device: %s]: Modesetting for \"%s\" set to mode %s\r\n", deviceId.c_str(), instance.c_str(), mode.c_str());
  globalModes[instance] = mode;
  return true;
}

// BrightnessController
bool onBrightness(const String &deviceId, int &brightness)
{
  Serial.printf("[Device: %s]: Brightness set to %d\r\n", deviceId.c_str(), brightness);
  globalBrightness = brightness;
  return true; // request handled properly
}

bool onAdjustBrightness(const String &deviceId, int &brightnessDelta)
{
  globalBrightness += brightnessDelta; // calculate absolute brigthness
  Serial.printf("[Device: %s]: Brightness changed about %i to %d\r\n", deviceId.c_str(), brightnessDelta, globalBrightness);
  brightnessDelta = globalBrightness; // return absolute brightness
  return true;                        // request handled properly
}

/**********
 * Events *
 *************************************************
 * Examples how to update the server status when *
 * you physically interact with your device or a *
 * sensor reading changes.                       *
 *************************************************/

// ModeController
void updateMode(String instance, String mode)
{
  lampara.sendModeEvent(instance, mode, "PHYSICAL_INTERACTION");
}

// BrightnessController
void updateBrightness(int brightness)
{
  lampara.sendBrightnessEvent(brightness);
}

/*********
 * Setup *
 *********/

void setupSinricPro()
{

  // ModeController
  lampara.onSetMode("modeInstance1", onSetMode);
  lampara.onSetMode("modeInstance2", onSetMode);

  // BrightnessController
  lampara.onBrightness(onBrightness);
  lampara.onAdjustBrightness(onAdjustBrightness);

  SinricPro.onConnected([]
                        { Serial.printf("[SinricPro]: Connected\r\n"); });
  SinricPro.onDisconnected([]
                           { Serial.printf("[SinricPro]: Disconnected\r\n"); });
  SinricPro.begin(APP_KEY, APP_SECRET);
};

void setupWiFi()
{
  WiFi.setSleep(true); // Habilita el modo de bajo consumo para el WiFi

  WiFi.begin(SSID, PASS);
  Serial.printf("[WiFi]: Connecting to %s", SSID);
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.printf(".");
    delay(250);
  }
  Serial.printf("connected\r\n");
}

void setup()
{
  Serial.begin(BAUD_RATE);
  setupWiFi();
  setupSinricPro();
  lampara.SetupLEDs();

  xTaskCreatePinnedToCore(
      TareaSinricPro, // Función de la tarea
      "Core0Task",    // Nombre de la tarea
      10000,          // Tamaño de la pila
      NULL,           // Parámetros de entrada
      1,              // Prioridad de la tarea
      NULL,           // Manejador de la tarea (puede ser NULL si no se necesita)
      0);             // Núcleo en el que se ejecutará la tarea (1 para el segundo núcleo)
  xTaskCreatePinnedToCore(
      TareaLEDs,   // Función de la tarea
      "Core1Task", // Nombre de la tarea
      10000,       // Tamaño de la pila
      NULL,        // Parámetros de entrada
      1,           // Prioridad de la tarea
      NULL,        // Manejador de la tarea (puede ser NULL si no se necesita)
      1);          // Núcleo en el que se ejecutará la tarea (1 para el segundo núcleo)
}



void TareaSinricPro(void *pvParametes)
{
  for (;;)
  {
    SinricPro.handle();
    lampara.SetBrillo(globalBrightness);
    lampara.SetColor(globalModes["modeInstance1"]);
    lampara.SetModo(globalModes["modeInstance2"]);
    delay(10);
  }
}

void TareaLEDs(void *pvParameters)
{
  for (;;)
  {
    lampara.Run();
    delay(10);
  }
}

/********
 * Loop *
 ********/
void loop() {}