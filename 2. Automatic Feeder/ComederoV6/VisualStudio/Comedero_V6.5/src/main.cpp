#include "ComederoWiFi.h"
#include <WiFi.h>
#include <SinricPro.h>
#include "SinricProComedero.h"

#define APP_KEY "a366f4dd-579f-4c40-a0e0-bc57d98ca37a"
#define APP_SECRET "8b2d3640-04f8-4e32-b766-d30c7ddd990f-b845be20-f0fc-4193-89f5-17b2247f5aa7"
#define DEVICE_ID "66ad18096e1af3593521ea5f"

// #define APP_KEY "f5b6b057-f65b-4c34-b595-489667228191"
// #define APP_SECRET "d9760d34-c170-4323-9a23-87303b92d7ba-b098499e-3931-4297-93c6-d295e4dc6d9d"
// #define DEVICE_ID "66a41355888aa7f7a2503262"

void TareaComedero(void *pvParameters);
void TareaSinricPro(void *pvParameters);
ComederoWiFi comedero;
SinricProComedero &sinricProComedero = SinricPro[DEVICE_ID];

std::map<String, String> globalModes;

bool onSetMode(const String &deviceId, const String &instance, String &mode)
{
  Serial.printf("[Device: %s]: Modesetting for \"%s\" set to mode %s\r\n", deviceId.c_str(), instance.c_str(), mode.c_str());
  globalModes[instance] = mode;
  comedero.DosisSinricPro(mode.toInt());
  return true;
}

void sendPushNotification(String notification)
{
  sinricProComedero.sendPushNotification(notification);
}

void updateMode(String instance, String mode)
{
  sinricProComedero.sendModeEvent(instance, mode, "PHYSICAL_INTERACTION");
}

void setupWiFi()
{
  WiFi.setSleep(false);
  WiFi.setAutoReconnect(true);

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
  sinricProComedero.onSetMode("modeInstance1", onSetMode);
  SinricPro.onConnected([]
                        { Serial.printf("[SinricPro]: Connected\r\n"); });
  SinricPro.onDisconnected([]
                           { Serial.printf("[SinricPro]: Disconnected\r\n"); });
  SinricPro.begin(APP_KEY, APP_SECRET);
}

void setup()
{
  Serial.begin(115200);
  comedero.setup();
  setupWiFi();
  setupSinricPro();

  xTaskCreatePinnedToCore(TareaSinricPro, "Core0Task", 15000, NULL, 1, NULL, 0);
  xTaskCreatePinnedToCore(TareaComedero, "Core1Task", 15000, NULL, 1, NULL, 1);
}

void loop()
{
  delay(10);
}

void TareaComedero(void *pvParametes)
{
  for (;;)
  {
    comedero.loop();
    vTaskDelay(pdMS_TO_TICKS(10));
  }
}

void TareaSinricPro(void *pvParametes)
{
  for (;;)
  {
    SinricPro.handle();
    if (comedero.comederoAtascado)
    {
      String message = "Comedero atascado a las " + String(comedero.currentHour) + ":" + (comedero.currentMinute < 10 ? "0" : "") + String(comedero.currentMinute) + ". Dosis dada: " + String(comedero.peso);
      sendPushNotification(message);
      comedero.comederoAtascado = false;
    }
    vTaskDelay(pdMS_TO_TICKS(10));
  }
}
