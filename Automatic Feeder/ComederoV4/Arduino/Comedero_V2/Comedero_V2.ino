#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
float tiempo;
int horas;
int minutos;
int dosis = 1;
int estado = 0;
//0: no se ha elegido dosis a programar.
//1: no se ha elegido el tiempo en el que salta la dosis elegida.
//2: todo programado y listo para inicial el ciclo diario del comedero.
int aceptar = 13; //Pin del boton para aceptar el tiempo.
int cambiar_dosis = 10; //Pin para programar la dosis elegida en el tiempo.

int inicializar(int &dosis, int &estado);
void ciclo(int dosis);
void setup() {
  lcd.begin(16, 2); //Definición de las dimensiones del display, 16 columnas, 2 filas.
  pinMode(aceptar, INPUT_PULLUP);
  pinMode(cambiar_dosis, INPUT_PULLUP);
  Serial.begin(9600);
}


void loop() {
  Serial.println(millis());
  if (millis() < 60000 && (estado == 0 || estado == 1)) {
    inicializar(dosis, estado);
    
  }
//  else {
//    if (estado = 2) {
//      ciclo(dosis);
//    }
//  }
  Serial.println(estado);
  delay(100);

}


int inicializar(int &dosis, int &estado)
{
  if (estado == 0) {
    Serial.println("estado=0");
    lcd.setCursor(0,0);
    lcd.print("Seleccione dosis");
    lcd.setCursor(0, 1);
    lcd.print(dosis);
    delay(100);
    Serial.println(estado);
    if (digitalRead(cambiar_dosis) == HIGH) {
      Serial.println("pulsado");
      delay(50);
      ++dosis;
      if (dosis > 4) {
        dosis = 1;
        Serial.println(dosis);
      }
      //while (digitalRead(cambiar_dosis)== HIGH) {Serial.println("bucle");};
    }
    if (digitalRead(aceptar)== HIGH) {
      delay(50);
      while (digitalRead(aceptar) == HIGH) {}
      estado = 1;
    }
    //Si se pulsa aceptar se selecciona la dosis que sale primero.
  }
  if (estado == 1) {
    lcd.print("Primera en:"); //Muestra en el display la palabra "Temperatura:".
    tiempo = (analogRead(0) * 1.406);
    horas = tiempo / 60;
    minutos = tiempo - 60 * horas;
    lcd.setCursor(0, 1);
    lcd.print(horas);
    lcd.print("h ");
    lcd.print(minutos);
    lcd.print("min");
    lcd.setCursor(0, 1);
    if (digitalRead(aceptar)==1) {
      estado = HIGH;
    }
    delay(100);
    lcd.print("               ");
  }
}

void ciclo(int dosis) {}
