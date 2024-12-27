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
  if (bajar)
    pulsos--;
}
void IRAM_ATTR SetSubir()
{
  unsigned long current_time = millis(); // Obtiene el tiempo actual en milisegundos

  // Verifica si el tiempo transcurrido desde la última interrupción es mayor que el tiempo de rebote
  if (current_time - last_interrupt_time > debounce_delay)
  {
    if (!subir)
    {
      subir = 1;
      bajar = 0;
    }
    else
    {
      bajar = 0;
      subir = 0;
    }
    last_interrupt_time = current_time; // Actualiza el tiempo de la última interrupción
  }
}

void IRAM_ATTR SetBajar()
{
  unsigned long current_time = millis(); // Obtiene el tiempo actual en milisegundos

  // Verifica si el tiempo transcurrido desde la última interrupción es mayor que el tiempo de rebote
  if (current_time - last_interrupt_time > debounce_delay)
  {
    if (!subir)
    {
      subir = 0;
      bajar = 1;
    }
    else
    {
      bajar = 0;
      subir = 0;
    }
    last_interrupt_time = current_time; // Actualiza el tiempo de la última interrupción
  }
}

void RampaSubidaCorriente()
{
  for (int i = 0; i < 255; i += 1)
  {
    analogWrite(MOSFET_MOTOR, i);
    delay(10);
  }
}

void RampaBajadaCorriente()
{
  for (int i = 255; i > 100; i -= 1)
  {
    analogWrite(MOSFET_MOTOR, i);
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
  if (bajar)
  {
    digitalWrite(RELE_BAJAR, 0);   //* Seleccionar relé para dar sentido a la corriente
    RampaSubidaCorriente();        //* Dar una rampa de corriente para que la fuente no se cortocircuite.
    while (bajar && pulsos > 1000) //* Mientras los pulsos sean mayores a un valor y se quiera seguir bajando se bajará a toda velocidad.
    {
      Serial.print(">Pulsos: ");
      Serial.println(pulsos);
    }
    RampaBajadaCorriente();     //* Se hace una rampa de bajada para evitar picos de corriente y bajar también despacio.
    while (bajar && pulsos > 0) //* Mientras los pulsos sean mayores que cero se bajará a velocidad moderada.
    {
      Serial.print(">Pulsos: ");
      Serial.println(pulsos);
    }
    analogWrite(MOSFET_MOTOR, 0); //* Apagar el MOSFET del motor.
    digitalWrite(RELE_BAJAR, 1);  //* Apagar el relé.
    bajar = false;                //* Liberar el estado de bajar.
  }
  else if (subir)
  {
    digitalWrite(RELE_SUBIR, 0);   //* Seleccionar el relé para subir.
    RampaSubidaCorriente();        //* Rampa de subida de la corriente.
    while (subir && pulsos < 2000) //* Mientras los pulsos sean pocos y se siga queriendo subir se subirá a toda velocidad.
    {
      Serial.print(">Pulsos: ");
      Serial.println(pulsos);
    }
    RampaBajadaCorriente();        //*Rampa de baja de corriente.
    while (subir && pulsos < 2500) //* Mientras los pulsos sean menores que el máximo de la puerta pero menores que antes y se siga queriendo subir se subirá despacio.
    {
      Serial.print(">Pulsos: ");
      Serial.println(pulsos);
    }
    analogWrite(MOSFET_MOTOR, 0); //* Apagar el MOSFET.
    digitalWrite(RELE_SUBIR, 1);  //* Apagar el Relé.
    subir = false;
  }
  else if (!subir && !bajar)
  {
    digitalWrite(RELE_SUBIR, 1); //* Mantener el relé siempre desactivado.
    digitalWrite(RELE_BAJAR, 1); //* Mantener el relé siempre desactivado.
  }
  Serial.print(">Pulsos: ");
  Serial.println(pulsos);
}
