#include "ComederoWiFi.h"

/*
  V1: interfaz de la pagina WEB.
  V2: Creación de librería ComederoWiFi. Guardado de parametros en memoria SPIFFS.
*/

ComederoWiFi comedero;

void setup()
{
  Serial.begin(115200);
  comedero.setup();
}

void loop()
{
  comedero.loop();
}
