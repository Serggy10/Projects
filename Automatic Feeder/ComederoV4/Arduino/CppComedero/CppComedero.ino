#include <EEPROM.h>


int aceptar = 9; //Pin botón aceptar.

int cambiar_dosis = 10; //Pin botón cambiar la dosis que se desea programar.

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

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void MenuPrincipal()
{
  lcd.clear();
}


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
  // put your main code here, to run repeatedly:

}
