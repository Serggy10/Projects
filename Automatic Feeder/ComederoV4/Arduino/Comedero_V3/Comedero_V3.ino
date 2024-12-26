#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int aceptar = 9; //Pin botón aceptar.

int cambiar_dosis = 10; //Pin botón cambiar la dosis que se desea programar.

int dosis = 1; //Se comienza por programar inicialmente la primera dosis.

int estado = 0; //Variable para saber en que estado se encuentra el arduino.
// 0: selección de la dosis a programar, del 1 al 4.
// 1: selección del tiempo en el que saltará la dosis programada.
// 2: actualizar Display para mostrar por pantalla el tiempo que falta para la siguiente dosis y accionar motor cuando el tiempo llegue a cero.

double tiempo_selec = 0; //Variable para almacenar el tiempo seleccionado mediante un potenciometro.

const double tiempo_entre_dosis = 18000000; //5 horas

int segundos = 0;

int minutos = 0; //Variable para mostrar los minutos en el LCD.

int horas = 0; //Variable para mostrar las horas en el LCD.

byte ordinal[8] = { //Crear caracter para motrar numeros ordinales.
  B11100,
  B00100,
  B11100,
  B10100,
  B11100,
  B00000,
  B00000,
  B00000,
};

unsigned long startmillis = 0;  //Variable para almacenar el tiempo que lleva el arduino encendido despues de ser programado y hacer temporizaciones posteriormente sin el comando delay().

unsigned long actualmillis = 0; //Variable para almacenar el tiempo que lleva encendido el arduino.

bool obtener_tiempo_inicio_contador = 1; //Variable para indicar cuando se debe obtener el tiempo del procesador para poder saber cuando realizar acciones sin emplear comando delay().
//1: medir, 0: no medir.

unsigned long tiempo_restante = 0;

bool mover_motor = 0; //Variable para indicar cuando se tiene que mover el motor.

void setup() {
  lcd.begin(16, 2);
  lcd.createChar(0, ordinal);
  pinMode(13, OUTPUT);
  pinMode(10, INPUT);
  pinMode(9, INPUT);
  lcd.clear();
  Serial.begin(9600);
}

void loop() {
  if (estado == 0) {
    seleccionar_dosis();
    if (digitalRead(aceptar) == 1) {
      Serial.println("Pulsado aceptar");
      delay(50);
      estado = 1;
      while (digitalRead(aceptar) == 1) {};
    }
  }
  else if (estado == 1) {
    seleccionar_hora();
    if (digitalRead(aceptar) == 1)
    {
      delay(50);
      estado = 2;
      while (digitalRead(aceptar) == 2) {};
    }
  }
  else if (estado == 2) {
    actualizar_hora();
    if(mover_motor==1){
      digitalWrite(13,HIGH);
      delay(1000);
      digitalWrite(13,LOW);
      delay(1000);
      ++dosis;
      if(dosis>4){dosis=1;}
      tiempo_selec=2;
      mover_motor=0;
      obtener_tiempo_inicio_contador=1;
    }
    if(digitalRead(aceptar)==1){digitalWrite(13,HIGH);}
    else{digitalWrite(13,LOW);}
  }
  else if (millis() > 300000 && estado != 2) {
    estado = 2;
    tiempo_selec = 0;
  }
  delay(100);
}

void seleccionar_dosis() {
  lcd.setCursor(0, 0);
  lcd.print("Seleccione dosis:");
  lcd.setCursor(0, 1);
  lcd.print(dosis);
  if (digitalRead(cambiar_dosis) == HIGH)
  {
    Serial.println("pulsado");
    delay(50);
    ++dosis;
    if (dosis > 4) {
      dosis = 1;
    }
    while (digitalRead(cambiar_dosis) == 1) {}
  }
}

void seleccionar_hora() {
  //  Serial.println("estado=1");
  lcd.setCursor(0, 0);
  lcd.print("Ajuste tiempo:  "); //Muestra en el display la palabra "Temperatura:".
  tiempo_selec = (analogRead(0) * 0.5273); //para 24h seria multiplicar por 1.0406. Para 9 horas sería multiplicar por 0.5273.
  Serial.println(tiempo_selec);
  tiempo_selec = round(tiempo_selec);
  Serial.println(tiempo_selec);
  horas = tiempo_selec / 60;
  minutos = tiempo_selec - 60 * horas;
  lcd.setCursor(0, 1);
  lcd.print(horas);
  lcd.print("h ");
  lcd.print(minutos);
  lcd.print("min      ");
  lcd.setCursor(0, 1);
  delay(100);
}

void actualizar_hora() {
  if (obtener_tiempo_inicio_contador == HIGH) {
    startmillis = millis();
    obtener_tiempo_inicio_contador = LOW;
    delay(50);
    //obtener_tiempo_inicio_contador se deberá poner a 1 cuando se active el motor para volver a realizar la temporización de los eventos.
  }
  actualmillis = millis();
  if (actualmillis - startmillis >= tiempo_selec*1000*60) { //tiempo restante sería inferior o igual que 0 y por tanto dariamos la orden de mover el motor.
    mover_motor = 1;
    //mover motor se podrá a 0 cuando se haya activado el motor para esperar a que pase el siguiente tiempo programado.
    tiempo_selec = 0;
    tiempo_restante = 0;
    
  }
  else {
    tiempo_restante = tiempo_selec*60 - (actualmillis - startmillis)/(1000); //tiempo restante en segundos
  }
  lcd.setCursor(0, 0);
  lcd.print(dosis);
  lcd.write(byte (0));
  lcd.print(" Dosis en:    ");
  horas = tiempo_restante / 3600;
  if (horas>0){
  minutos = round(tiempo_restante/60-horas*60);
  lcd.setCursor(0, 1);
  lcd.print(horas);
  lcd.print("h ");
  lcd.print(minutos);
  lcd.print("min      ");
  lcd.setCursor(0, 1);
  }
  else{
    minutos = tiempo_restante/60;
    segundos = tiempo_restante-minutos*60-horas*3600;
    lcd.setCursor(0, 1);
  lcd.print(minutos);
  lcd.print("min ");
  lcd.print(segundos);
  lcd.print("seg      ");
  lcd.setCursor(0, 1);
  }
}
