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

//! PARAMETROS CONFIGURACIÓN
#define VEL_INTERMEDIA 150      // máx 255.
#define INTERVALO_TIEMPO 50     // Intervalo para calcular la velocidad por pulsos acumulados
#define DIFERENCIA_VEL 40       // Diferencia de velocidades máxima por si se detecta algún obstáculo.
#define PULSOS_SUBIDA 1000      // Pulsos totales de la altura de la puerta.
#define PULSOS_SUBIDA_LENTA 250 // Pulsos a los que al subir, la velocidad se reduce
#define PULSOS_BAJADA_LENTA 250 // Pulsos a los que al bajar la velocidad se reducec
#define TIEMPO_ENCENDIDO_LED 18 // Tiempo que permanece el LED encendido en segundos para iluminar el garaje.

bool autoON = false;
bool velMaxOn = false;
bool subiendo = false;
bool bajando = false;
double pulsos = 0;           // TODO Guardar y leer de memeoria en el setup
bool puertaArriba = false;   // TODO Guardar y leer de memeoria en el setup
bool anteriorArriba = false; // TODO Guardar y leer de memeoria en el setup
unsigned long int tiempoLED = 0, tiempoDetcAutoOn = 0;
bool enRampaCorriente = false;                // Indica si la rampa de corriente está activa
volatile unsigned long tiempoUltimoPulso = 0; // Tiempo del último pulso detectado
float velocidadPrevia = 0;                    // Velocidad anterior
float velocidadMedia = 0;                     // Velocidad media calculada

volatile unsigned long last_interrupt_time = 0; // Almacena el tiempo del último interrupt
const unsigned long debounce_delay = 50;        // Tiempo para ignorar rebotes (en ms)

//* FUNCIONES PARA INTERRUPCIONES
void IRAM_ATTR ContarPulsos()
{
  unsigned long tiempoActual = millis();
  if (subiendo)
    pulsos++;
  else if (bajando)
    pulsos--;
  tiempoUltimoPulso = tiempoActual; // Registrar tiempo del pulso
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
    if (millis() >= tiempoLED + 1000 * TIEMPO_ENCENDIDO_LED)
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
    Serial.println(">VelocidadPrevia: " + String(velocidadPrevia));
    Serial.println(">VelocidadMedia: " + String(velocidadMedia));
    vTaskDelay(10 / portTICK_PERIOD_MS);
  }
}
void MonitorVelocidad(void *pvParameters)
{
  static unsigned long ultimoTiempo = 0; // Último tiempo del cálculo basado en pulsos acumulados
  static double pulsosPrevios = 0;       // Pulsos acumulados en el último cálculo de velocidad
  float velocidadPendiente = 0;          // Velocidad calculada con la pendiente de los pulsos

  for (;;)
  {
    unsigned long tiempoActual = millis();

    // Calcular la velocidad cada INTERVALO_TIEMPO
    if (tiempoActual - ultimoTiempo >= INTERVALO_TIEMPO)
    {
      // Diferencia de pulsos y tiempo
      double deltaPulsos = pulsos - pulsosPrevios;
      unsigned long deltaTiempo = tiempoActual - ultimoTiempo;

      // Calcular la velocidad como pulsos por segundo
      velocidadMedia = (deltaPulsos / deltaTiempo) * 1000.0;

      // Actualizar valores previos
      pulsosPrevios = pulsos;
      ultimoTiempo = tiempoActual;
      Serial.println(">DiferenciaVelocidades: " + String(abs(velocidadMedia - velocidadPrevia)));
      if (abs(velocidadMedia - velocidadPrevia) > DIFERENCIA_VEL) // Ajustar umbral según necesidad
      {
        if (!enRampaCorriente) // Solo si no está en rampa
        {
          Serial.println("Cambio brusco de velocidad");
          // autoON = false; // Desactiva el modo automático
        }
        else
        {
          Serial.println("Cambio brusco detectado, pero ignorado por rampa.");
        }
      }
      velocidadPrevia = velocidadMedia;
    }
    vTaskDelay(10 / portTICK_PERIOD_MS); // Pausa de 10 ms
  }
}

//* FUNCIONES
void RampaCorriente(int inicioValorMOSFET, int finalValorMOSFET)
{
  enRampaCorriente = true;                                    // Activar bandera de rampa
  int paso = (inicioValorMOSFET < finalValorMOSFET) ? 1 : -1; // Determinar dirección
  for (int i = inicioValorMOSFET; i != finalValorMOSFET; i += paso)
  {
    tiempoLED = millis();
    ledcWrite(0, i);                     // Ajustar la corriente
    vTaskDelay(10 / portTICK_PERIOD_MS); // 10 ms de pausa
  }
  enRampaCorriente = false; // Desactivar bandera de rampa
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
    RampaCorriente(0, VEL_INTERMEDIA);                             // Rampa de subida de corriente para evitar CC.
    while (!digitalRead(botonAccion) && digitalRead(botonOpuesto)) // Mientras uno de los botones esté pulsado:
    {
      tiempoLED = millis(); // Actualizar tiempo LED y continuar con movimiento.
      delay(10);            // Delay para no saturar la memoria.
    }
    RampaCorriente(VEL_INTERMEDIA, 0); // Rampa de bajada de corriente para evitar CC.
    ledcWrite(0, 0);                   // Parar el motor.
    tiempoLED = millis();              // Actualizar tiempo para encendido LED.
    digitalWrite(releAccion, 1);       // Desactivar el relé.
    anteriorArriba = estadoAccion;     // Actualizar estado anterior (arriba o abajo).
    subiendo = bajando = false;
  }
}

void MovimientoAutomatico()
{
  if (autoON)
  {
    subiendo = !anteriorArriba;
    bajando = anteriorArriba;
    digitalWrite(RELE_BAJAR, (anteriorArriba) ? 0 : 1);
    digitalWrite(RELE_SUBIR, (!anteriorArriba) ? 0 : 1);
    RampaCorriente(0, 255); // Movimiento a velocidad máxima.
    while (autoON)
    {
      if (!anteriorArriba)
        if (pulsos > PULSOS_SUBIDA - PULSOS_SUBIDA_LENTA)
          break;
      if (anteriorArriba)
        if (pulsos < PULSOS_BAJADA_LENTA)
          break;
      vTaskDelay(10 / portTICK_PERIOD_MS);
    }
    RampaCorriente(255, VEL_INTERMEDIA); // Movimiento a velocidad intermedia.
    while (autoON)
    {
      if (!anteriorArriba)
        if (pulsos >= PULSOS_SUBIDA)
          break;
      if (anteriorArriba)
        if (pulsos <= 0)
          break;
      vTaskDelay(10 / portTICK_PERIOD_MS);
    }
    RampaCorriente(VEL_INTERMEDIA, 0); // Parar movimiento.
    digitalWrite(RELE_BAJAR, 1);
    digitalWrite(RELE_SUBIR, 1);
    vTaskDelay(10 / portTICK_PERIOD_MS);
    anteriorArriba = !anteriorArriba;
    autoON = false;
  }
}

void setup()
{
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(HAL_MOTOR), ContarPulsos, RISING);
  attachInterrupt(digitalPinToInterrupt(ENTRADAS_RF_MAN), DetectarAuto, FALLING);

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

  tiempoLED = -1000 * TIEMPO_ENCENDIDO_LED; // tiempo negativo para que no se encienda inicialmente el LED.
  xTaskCreate(EncenderLED, "EncenderLED", 10000, NULL, 1, NULL);
  xTaskCreate(MonitorSerie, "MonitorSerie", 10000, NULL, 1, NULL);
  xTaskCreate(MonitorVelocidad, "MonitorVelocidad", 10000, NULL, 1, NULL);
}

void loop()
{
  MovimientoManual(BOTON_SUBIR, BOTON_BAJAR, RELE_SUBIR, true);  //* SUBIR
  MovimientoManual(BOTON_BAJAR, BOTON_SUBIR, RELE_BAJAR, false); //* BAJAR
  MovimientoAutomatico();
  vTaskDelay(10 / portTICK_PERIOD_MS); // 10 ms de pausa para la tarea actual
}