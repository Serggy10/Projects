#include <ListLib.h>
#include <Time.h>
#include <TimeLib.h>



extern bool Alarma, AlarmaHora;
extern int ContadorEncoder, ContadorAlarma;
extern int ValorActualEncoder, ValorAnteriorEncoder, OffsetHora, OffsetMinuto, HorasRestantes, MinutosRestantes;
extern byte NumDosis,  PorcentajeDosis;
extern unsigned long int InicioAlarma, TiempoAlarma;
extern List<byte> VectorHorasProgramadas, VectorMinutosProgramados;


short int PinLED1 = 10;
short int PinLED2 = 11;
#define BotonIzquierdo 12
#define BotonDerecho 13


void PonerEnHora() {
  bool Salir = false;
  long int TiempoEspera = millis() + 300000;
  while (!digitalRead(BotonIzquierdo) && Salir == false) {
    lcd.setCursor(0, 0);
    lcd.print("Seleccione hora:  ");
    OffsetHora = map(analogRead(0), 0, 1023, 23, -1);
    OffsetHora = constrain(OffsetHora, 0, 23);
    lcd.setCursor(0, 1);
    lcd.print(String(OffsetHora) + ":" + String(OffsetMinuto) + "   ");
    delay(100);
    if (millis() >= TiempoEspera) {
      Salir = true;
      AlarmaHora = true;
      OffsetHora = 0;
      OffsetMinuto = 0;
    }
  }
  delay(50);
  while (digitalRead(BotonIzquierdo)) {}
  delay(50);
  while (!digitalRead(BotonIzquierdo) && Salir == false) {
    lcd.setCursor(0, 0);
    lcd.print("Seleccione hora:  ");
    OffsetMinuto = map(analogRead(0), 0, 1023, 59, -1);
    OffsetMinuto = constrain(OffsetMinuto, 0, 59);
    lcd.setCursor(0, 1);
    lcd.print(String(OffsetHora) + ":" + String(OffsetMinuto) + "    ");
    delay(100);
    if (millis() >= TiempoEspera) {
      Salir = true;
      AlarmaHora = true;
      OffsetHora = 0;
      OffsetMinuto = 0;
    }
  }
  delay(50);
  while (digitalRead(BotonIzquierdo)) {}
  delay(50);
  setTime(OffsetHora, OffsetMinuto, 0, 0, 0, 0);
}

void ObtenerTiempoRestante() {
  for (int i = 0; i < VectorHorasProgramadas.Count(); ++i) {
    if (hour() * 60 + minute() < VectorHorasProgramadas[i] * 60 + VectorMinutosProgramados[i]) {
      HorasRestantes = (VectorHorasProgramadas[i] * 60 + VectorMinutosProgramados[i] - hour() * 60 - minute()) / 60;
      MinutosRestantes = VectorHorasProgramadas[i] * 60 + VectorMinutosProgramados[i] - hour() * 60 - minute() - HorasRestantes * 60 - 1;
      if (MinutosRestantes < 0) {
        MinutosRestantes = 0;
        HorasRestantes = HorasRestantes - 1;
      }
      i = 20;                                               //Salir del bucle directamente
    }
    else {
      HorasRestantes = ((24 - hour() + VectorHorasProgramadas[0]) * 60 - VectorMinutosProgramados[0] - minute()) / 60;
      MinutosRestantes = HorasRestantes * 60 + VectorMinutosProgramados[0] - minute() - 1;
    }
  }
}


void CompruebaValorEncoder() {
  ValorActualEncoder = map(analogRead(1), 0, 1023, 0, 2);
  if (ValorActualEncoder != ValorAnteriorEncoder) {
    ContadorEncoder++;
    Serial.println(String("Contador:: ") + ContadorEncoder++);
    ValorAnteriorEncoder = ValorActualEncoder;
  }
}

void Desatascar() {
  analogWrite(9, 0);
  analogWrite(8, 0);
  delay(100);
  ContadorEncoder = 0;
  unsigned long int Tiempo=millis()+1500;
  while (ContadorEncoder < 10 && millis()<Tiempo) {
    analogWrite(9, 0);
    analogWrite(8, 255);
    CompruebaValorEncoder();
  }
  TiempoAlarma = millis() + 5000.0 * PorcentajeDosis / 80.0;
  ContadorEncoder = 0;
  analogWrite(9, 0);
  analogWrite(8, 0);
  delay(5);
}

void DarDosis() {
  TiempoAlarma = millis() + 5000.0 * PorcentajeDosis / 80.0;
  Serial.println(millis());
  Serial.println(TiempoAlarma);
  double PulsosVuelta = 48 * PorcentajeDosis / 100; ///Una vuelta son 48 pulsos.
  while (ContadorEncoder < PulsosVuelta) {
    analogWrite(9, 255);
    analogWrite(8, 0);
    CompruebaValorEncoder();
    if (millis() > TiempoAlarma) {
      Serial.println("Alarma");
      Desatascar();
      ++ContadorAlarma;
      if (ContadorAlarma >= 3) {
        ContadorEncoder = 999;
        Alarma = true;
      }
    }
  }
  ContadorEncoder = 0;
  ContadorAlarma = 0;
  analogWrite(9, 0);
  analogWrite(8, 0);
}



void CompruebaAlarma() {
  if (AlarmaHora ) {
    if (millis() - InicioAlarma > 100)  analogWrite(PinLED2, 20);
    if (millis() - InicioAlarma > 200) {
      digitalWrite(PinLED2, LOW);
      InicioAlarma = millis();
    }
  }
  else if (Alarma) {
    if (millis() - InicioAlarma > 500)  analogWrite(PinLED2, 20);
    if (millis() - InicioAlarma > 1000) {
      digitalWrite(PinLED2, LOW);
      InicioAlarma = millis();
    }
  }
  else digitalWrite(PinLED2, LOW);
}

void SeleccionarCantidadDosis() {
  lcd.setCursor(0, 0);
  lcd.print("Cantidad Dosis: ");
  NumDosis = map(analogRead(0), 0, 1023, 8, 1);
  lcd.setCursor(0, 1);
  lcd.print(NumDosis);
  delay(100);
}

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

void ProgramarHora() {
  int Hora = 0, Minuto = 0, HoraAnterior = 0, MinutoAnterior = 0;
  VectorHorasProgramadas.Clear();
  VectorMinutosProgramados.Clear();
  for (int i = 1; i <= NumDosis; ++i) {
    while (!digitalRead(BotonIzquierdo)) {
      lcd.setCursor(0, 0);
      lcd.print("Hora " + String(i));
      lcd.write((byte)0);
      lcd.print("dosis  ");
      Hora = map(analogRead(0), 0, 1023, 23, -1 + HoraAnterior);
      Hora = constrain(Hora, HoraAnterior, 23);
      lcd.setCursor(0, 1);
      lcd.print(String(Hora) + ":00   ");
      delay(100);
    }
    
    if (Hora != HoraAnterior) MinutoAnterior = 0;
    VectorHorasProgramadas.Add(Hora);
    EEPROM.write(i,Hora);
    delay(50);
    while (digitalRead(BotonIzquierdo)) {}
    delay(50);
    while (!digitalRead(BotonIzquierdo)) {
      lcd.setCursor(0, 0);
      lcd.print("Minuto " + String(i));
      lcd.write((byte)0);
      lcd.print("dosis  ");
      Minuto = map(analogRead(0), 0, 1023, 59, -1 + MinutoAnterior);
      Minuto = constrain(Minuto, MinutoAnterior, 59);
      lcd.setCursor(0, 1);
      lcd.print(String(Hora) + ":" + String(Minuto) + "    ");
      delay(100);
    }
    VectorMinutosProgramados.Add(Minuto);
    EEPROM.write(10+i,Minuto);
    MinutoAnterior = Minuto;
    HoraAnterior = Hora;
    while (digitalRead(BotonIzquierdo)) {}
    delay(50);
  }
}

void PesoPorDosis() {
  while (!digitalRead(BotonIzquierdo)) {
    lcd.setCursor(0, 0);
    PorcentajeDosis = (map(analogRead(0), 0, 1023, 200, 10) / 10) * 10;
    lcd.print("Dosis al " + String(PorcentajeDosis) + "%     ");
    delay(100);
  }
  delay(50);
  while (digitalRead(BotonIzquierdo)) {}
  EEPROM.write(10,PorcentajeDosis);
  delay(50);
}


void CompruebaHoras() {
  for (int i = 0; i <= VectorHorasProgramadas.Count(); ++i) {
    if (hour() == VectorHorasProgramadas[i]) {
      if (minute() == VectorMinutosProgramados[i]) {
        if (second() == 0) DarDosis();
      }
    }
  }
}
