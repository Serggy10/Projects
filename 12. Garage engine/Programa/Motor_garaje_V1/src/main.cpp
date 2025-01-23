#include <Arduino.h>
#include <FastLED.h>
#define RELE_BAJAR 5
#define RELE_SUBIR 4
#define MOSFET_LED 13
#define MOSFET_MOTOR 12
#define HAL_MOTOR 9
#define ENTRADAS_RF_MAN 10
#define BOTON_BAJAR 2
#define BOTON_SUBIR 1

#define PULSOS_SUBIDA 750
#define PULSOS_SUBIDA_LENTA 250
#define PULSOS_BAJADA_LENTA 250
#define TIEMPOENCENDIDO 18 // En segundos

#define ASCENDENTE true
#define DESCENDENTE false

bool autoON = false;
bool velMaxOn = false;
bool subiendo = false;
bool bajando = false;
double pulsos = 0;           // TODO Guardar y leer de memeoria en el setup
bool puertaArriba = false;   // TODO Guardar y leer de memeoria en el setup
bool anteriorArriba = false; // TODO Guardar y leer de memeoria en el setup
unsigned long int tiempoLED = 0, tiempoDetcAutoOn = 0;

volatile unsigned long last_interrupt_time = 0; // Almacena el tiempo del último interrupt
const unsigned long debounce_delay = 50;        // Tiempo para ignorar rebotes (en ms)

//* FUNCIONES PARA INTERRUPCIONES
void IRAM_ATTR ContarPulsos()
{
  if (subiendo)
    pulsos++;
  else if (bajando)
    pulsos--;
}

void IRAM_ATTR DetectarAuto() //? Para detectar por interrupción si se pulsa el interruptor o se activa con el mando a distancia. Variable de estado ON/OFF con cada pulsación.
{
  if (millis() > tiempoDetcAutoOn + 250)
  {
    autoON = !autoON;
    tiempoDetcAutoOn = millis();
  }
}

//* FUNCIONES EN OTROS NÚCLEOS
void EncenderLED(void *pvParameters)
{
  for (;;)
  {
    if (millis() >= tiempoLED + 1000 * TIEMPOENCENDIDO)
    {
      digitalWrite(MOSFET_LED, 0);
    }
    else
      digitalWrite(MOSFET_LED, 0); // TODO Cambiar a 1 para encenderlo.
    vTaskDelay(10 / portTICK_PERIOD_MS);
  }
}
void MonitorSerie(void *pvParameters)
{
  for (;;)
  {
    Serial.println(">Pulsos:" + String(pulsos));
    Serial.println(">AnteriorArriba: " + String(anteriorArriba));
    Serial.println(">AutoOn: " + String(autoON));
    vTaskDelay(100 / portTICK_PERIOD_MS);
  }
}

//* FUNCIONES
void RampaCorriente(bool subida)
{
  if (subida)
  {
    for (int i = 0; i < 255; i++)
    {
      tiempoLED = millis();
      ledcWrite(0, i);                     // Incrementar la corriente
      vTaskDelay(10 / portTICK_PERIOD_MS); // 10 ms de pausa para la tarea actual
    }
  }
  else
  {
    for (int i = 0; i < 255; i++)
    {
      tiempoLED = millis();
      ledcWrite(0, 255 - i);               // Decrementar la corriente
      vTaskDelay(10 / portTICK_PERIOD_MS); // 10 ms de pausa para la tarea actual
    }
  }
}

void MovimientoManual(int botonAccion, int botonOpuesto, int releAccion, bool estadoAccion)
{
  //* Si se pulsa el botón correspondiente, se realiza el movimiento manual con rampa de subida y bajada.
  if (!digitalRead(botonAccion) && digitalRead(botonOpuesto)) // Lógica negativa: solo uno de los dos botones está pulsado.
  {
    subiendo = estadoAccion;
    bajando = !estadoAccion;
    digitalWrite(releAccion, 0);                                   // Activar relé.
    tiempoLED = millis();                                          // Actualizar tiempo para encendido LED.
    RampaCorriente(ASCENDENTE);                                    // Rampa de subida de corriente para evitar CC.
    while (!digitalRead(botonAccion) && digitalRead(botonOpuesto)) // Mientras uno de los botones esté pulsado:
    {
      tiempoLED = millis(); // Actualizar tiempo LED y continuar con movimiento.
      delay(10);            // Delay para no saturar la memoria.
    }
    RampaCorriente(DESCENDENTE);   // Rampa de bajada de corriente para evitar CC.
    ledcWrite(0, 0);               // Parar el motor.
    tiempoLED = millis();          // Actualizar tiempo para encendido LED.
    digitalWrite(releAccion, 1);   // Desactivar el relé.
    anteriorArriba = estadoAccion; // Actualizar estado anterior (arriba o abajo).
    subiendo = bajando = false;
  }
}

void MovimientoAutomatico()
{
  if (autoON)
  {
    subiendo = anteriorArriba;
    bajando = !anteriorArriba;
    digitalWrite(RELE_BAJAR, (anteriorArriba) ? 0 : 1);
    digitalWrite(RELE_SUBIR, (!anteriorArriba) ? 0 : 1);
    RampaCorriente(ASCENDENTE);
    while (autoON &&
           ((anteriorArriba && pulsos < PULSOS_SUBIDA - PULSOS_SUBIDA_LENTA) ? 1 : 0 || (!anteriorArriba && pulsos > PULSOS_BAJADA_LENTA) ? 1
                                                                                                                                          : 0))
    {
    }
    RampaCorriente(DESCENDENTE);
    digitalWrite(RELE_BAJAR, 1);
    digitalWrite(RELE_SUBIR, 1);
    anteriorArriba = !anteriorArriba;
    autoON = false;
  }
}
void setup()
{
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(HAL_MOTOR), ContarPulsos, RISING);
  attachInterrupt(digitalPinToInterrupt(ENTRADAS_RF_MAN), DetectarAuto, FALLING);
  // attachInterrupt(digitalPinToInterrupt(BOTON_SUBIR), SetSubir, FALLING);
  // attachInterrupt(digitalPinToInterrupt(BOTON_BAJAR), SetBajar, FALLING);

  pinMode(BOTON_SUBIR, INPUT_PULLUP);
  pinMode(BOTON_BAJAR, INPUT_PULLUP);
  pinMode(ENTRADAS_RF_MAN, INPUT_PULLUP);
  pinMode(HAL_MOTOR, INPUT);

  pinMode(RELE_BAJAR, OUTPUT);
  pinMode(RELE_SUBIR, OUTPUT);
  pinMode(MOSFET_LED, OUTPUT);
  pinMode(MOSFET_MOTOR, OUTPUT);

  digitalWrite(RELE_BAJAR, 1);
  digitalWrite(RELE_SUBIR, 1);
  digitalWrite(MOSFET_MOTOR, 0);
  digitalWrite(MOSFET_LED, 0);
  analogWriteResolution(8);
  ledcSetup(0, 5000, 8);          // Canal 0, frecuencia 5 kHz, resolución de 8 bits
  ledcAttachPin(MOSFET_MOTOR, 0); // MOSFET_MOTOR al canal 0

  tiempoLED = -1000 * TIEMPOENCENDIDO; // tiempo negativo para que no se encienda inicialmente el LED.
  xTaskCreate(EncenderLED, "EncenderLED", 10000, NULL, 1, NULL);
  xTaskCreate(MonitorSerie, "MonitorSerie", 10000, NULL, 1, NULL);
}

void loop()
{
  MovimientoManual(BOTON_SUBIR, BOTON_BAJAR, RELE_SUBIR, true);  //* SUBIR
  MovimientoManual(BOTON_BAJAR, BOTON_SUBIR, RELE_BAJAR, false); //* BAJAR
  MovimientoAutomatico();
  vTaskDelay(10 / portTICK_PERIOD_MS); // 10 ms de pausa para la tarea actual
}