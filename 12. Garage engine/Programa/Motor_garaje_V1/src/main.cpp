#include <Arduino.h>
#include <FastLED.h>
#define RELE_BAJAR 5
#define RELE_SUBIR 4
#define MOSFET_LED 13
#define MOSFET_MOTOR 12
#define HAL_MOTOR 9
#define ENTRADAS_RF_MAN 8
#define GIRO_IZQ 2
#define GIRO_DER 1

double pulsos = 0;
bool subir = false;
bool bajar = false;

volatile unsigned long last_interrupt_time = 0; // Almacena el tiempo del último interrupt
const unsigned long debounce_delay = 50;        // Tiempo para ignorar rebotes (en ms)

// Función para manejar la interrupción
void IRAM_ATTR ContarPulsos()
{
  if (subir)
    pulsos++;
  else if (bajar)
    pulsos--;
}
void IRAM_ATTR SetSubir()
{
  subir = true;
  bajar = false;
}

void IRAM_ATTR SetBajar()
{
  bajar = true;
  subir = false;
}

void RampaSubidaCorriente()
{
  for (int i = 0; i < 255; i += 1)
  {
    analogWrite(MOSFET_MOTOR, i);
    analogWrite(MOSFET_LED, i);
    delay(10);
  }
}

void RampaBajadaCorriente()
{
  for (int i = 255; i > 0; i -= 1)
  {
    analogWrite(MOSFET_MOTOR, i);
    analogWrite(MOSFET_LED, i);
    delay(10);
  }
}

void setup()
{
  Serial.begin(115200);
  // Configura la interrupción para detectar flancos ascendentes
  attachInterrupt(digitalPinToInterrupt(HAL_MOTOR), ContarPulsos, RISING);
  attachInterrupt(digitalPinToInterrupt(GIRO_DER), SetSubir, FALLING);
  attachInterrupt(digitalPinToInterrupt(GIRO_IZQ), SetBajar, FALLING);

  pinMode(GIRO_DER, INPUT_PULLUP);
  pinMode(GIRO_IZQ, INPUT_PULLUP);
  pinMode(ENTRADAS_RF_MAN, INPUT_PULLUP);
  pinMode(HAL_MOTOR, INPUT);

  pinMode(RELE_BAJAR, OUTPUT);
  pinMode(RELE_SUBIR, OUTPUT);
  pinMode(MOSFET_LED, OUTPUT);
  pinMode(MOSFET_MOTOR, OUTPUT);

  digitalWrite(RELE_BAJAR, 1);
  digitalWrite(RELE_SUBIR, 1);
  digitalWrite(MOSFET_MOTOR, 0);
  analogWriteResolution(8);
}

void loop()
{
  if (subir)
  {
    digitalWrite(RELE_SUBIR, 0);
    RampaSubidaCorriente();
    while (pulsos < 250)
    {
      Serial.print(">Pulsos: ");
      Serial.println(pulsos);
      delay(100);
    }
    RampaBajadaCorriente();
    digitalWrite(RELE_SUBIR, 1);
    subir = 0;
    delay(1000);
    bajar = 1;
    digitalWrite(RELE_BAJAR, 0);
    RampaSubidaCorriente();
    while (pulsos > 10)
    {
      Serial.print(">Pulsos: ");
      Serial.println(pulsos);
      delay(100);
    }
    RampaBajadaCorriente();
    digitalWrite(RELE_BAJAR, 1);
    bajar = 0;
  }
  else if (!subir && !bajar)
  {
    digitalWrite(RELE_SUBIR, 1); //* Mantener el relé siempre desactivado.
    digitalWrite(RELE_BAJAR, 1); //* Mantener el relé siempre desactivado.
  }

  Serial.print(">Pulsos: ");
  Serial.println(pulsos);
  delay(10);
}
