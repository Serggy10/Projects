#include <EEPROM.h>

#include <Time.h>
#include <TimeLib.h>

#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

#include "Funciones.h"

#define BotonIzquierdo 12
#define BotonDerecho 13

/////////////////////////////////////////
///   Declaración de enteros para     ///
///   poder distinguir los menus      ///
/////////////////////////////////////////
int Menu = 0;
#define MenuPrincipal 0
#define MenuLista 1
#define MenuManual 2
#define MenuParametros 3
#define MenuAjustes 4


/////////////////////////////////////////
///   Declaración de tiempos          ///
/////////////////////////////////////////
int OffsetHora = 0, OffsetMinuto = 0, HorasRestantes, MinutosRestantes;


/////////////////////////////////////////
///   Declaración de DOSIS            ///
/////////////////////////////////////////
byte NumDosis,  PorcentajeDosis;
unsigned long int InicioAlarma, TiempoAlarma;
List<byte> VectorHorasProgramadas, VectorMinutosProgramados;



int LecturaPot;





bool Alarma = false, AlarmaHora=false;



int ContadorEncoder = 0, ContadorAlarma = 0;
int ValorAnteriorEncoder = 0, ValorActualEncoder = 0;





void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  lcd.createChar(0, ordinal);
  pinMode(PinLED1, OUTPUT);
  pinMode(PinLED2, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  digitalWrite(PinLED1, LOW);
  Serial.begin(9600);
  NumDosis=EEPROM.read(0);
  Serial.println("NumDosis: "+String(NumDosis));
  
  VectorHorasProgramadas.Clear();
  VectorMinutosProgramados.Clear();
  for (int i=1; i<=NumDosis;++i){
    VectorHorasProgramadas.Add(EEPROM.read(i));
    VectorMinutosProgramados.Add(EEPROM.read(10+i));
    Serial.print("Hora programada: "+String(VectorHorasProgramadas[i-1]));
    Serial.println(" Minuto programado: "+String(VectorMinutosProgramados[i-1]));
  }


//  int Horass[] = {1, 8, 13, 18};
//  int Minutoss[] = {0, 30, 0, 30};
//  VectorHorasProgramadas.AddRange(Horass, 4);
//  VectorMinutosProgramados.AddRange(Minutoss, 4);
  PorcentajeDosis=EEPROM.read(10);
  Serial.println("PorcentajeDosis: "+String(PorcentajeDosis));
  PonerEnHora();
}

void loop() {
  CompruebaAlarma();
  CompruebaHoras();
  ObtenerTiempoRestante();
  LecturaPot = analogRead(A0);
  double LecturaEncoder = analogRead(A1);

  switch (Menu)
  {
    ////////////////////////////////////////////////////////////////////////////////////
    ///                                Menú Principal                                ///
    ////////////////////////////////////////////////////////////////////////////////////
    case MenuPrincipal:
      {
        lcd.setCursor(0, 0);
        lcd.print("Reloj: ");
        lcd.print(hour() + String(":") + minute() + String(":") + second() + String("     "));
        lcd.setCursor(0, 1);
        lcd.print("Dosis: " + String(HorasRestantes) + ":" + String(MinutosRestantes) + ":" + String(60 - second()) + "   ");
        if (digitalRead(BotonIzquierdo))
        {
          Menu = MenuLista;
          lcd.clear();
          delay(50);
          while (digitalRead(BotonIzquierdo)) {}
          delay(50);
        }
        break;
      }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    ////////////////////////////////////////////////////////////////////////////////////
    ///                        Menú Mostrando Lista de opciones                      ///
    ////////////////////////////////////////////////////////////////////////////////////
    case MenuLista:
      {
        LecturaPot = map(LecturaPot, 0, 1023, 0, 3);
        //Serial.println(LecturaPot);
        switch (LecturaPot)
        {

          ////////////////////////
          //// OPCIÓN MANUAL  ////
          ////////////////////////
          case 0:
            {
              lcd.setCursor(0, 0);
              lcd.print(">Manual   ");
              lcd.setCursor(0, 1);
              lcd.print(" Ajustes  ");
              if (digitalRead(BotonIzquierdo))
              {
                Menu = MenuManual;
                lcd.clear();
                delay(50);
                while (digitalRead(BotonIzquierdo)) {}
                delay(50);
              }
              break;
            }

          ////////////////////////
          //// OPCIÓN AJUSTES ////
          ////////////////////////
          case 1:
            {
              lcd.setCursor(0, 0);
              lcd.print(" Manual   ");
              lcd.setCursor(0, 1);
              lcd.print(">Ajustes  ");
              if (digitalRead(BotonIzquierdo))
              {
                Menu = MenuAjustes;
                lcd.clear();
                delay(50);
                while (digitalRead(BotonIzquierdo)) {}
                delay(50);
              }
              break;
            }


          //////////////////////////
          //// OPCIÓN DE VOLVER ////
          //////////////////////////
          case 2:
          case 3:
            {
              lcd.setCursor(0, 0);
              lcd.print(" Ajustes  ");
              lcd.setCursor(0, 1);
              lcd.print(">Volver   ");
              if (digitalRead(BotonIzquierdo))
              {
                Menu = MenuPrincipal;
                lcd.clear();
                delay(50);
                while (digitalRead(BotonIzquierdo)) {}
                delay(50);
              }
              break;
            }
        }
        break;
      }





    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    ////////////////////////////////////////////////////////////////////////////////////
    ///                             MENÚ DEL MODO MANUAL                             ///
    ////////////////////////////////////////////////////////////////////////////////////
    case MenuManual:
      {
        LecturaPot = map(LecturaPot, 0, 1023, 0, 3);
        //Serial.println(LecturaPot);
        switch (LecturaPot)
        {

          ////////////////////////
          //// DAR UNA DOSIS  ////
          ////////////////////////
          case 0:
            {
              lcd.setCursor(0, 0);
              lcd.print(">Dar Dosis    ");
              lcd.setCursor(0, 1);
              lcd.print(" Apagar Alarma");
              if (digitalRead(BotonIzquierdo))
              {
                DarDosis();
                delay(50);
                while (digitalRead(BotonIzquierdo)) {}
                delay(50);
              }
              break;
            }

          ////////////////////////
          //// APAGAR ALARMA  ////
          ////////////////////////
          case 1:
            {
              lcd.setCursor(0, 0);
              lcd.print(" Dar Dosis    ");
              lcd.setCursor(0, 1);
              lcd.print(">Apagar Alarma");
              if (digitalRead(BotonIzquierdo))
              {
                Alarma = false;
                AlarmaHora=false;
                digitalWrite(PinLED2, 0);
                delay(50);
                while (digitalRead(BotonIzquierdo)) {}
                delay(50);
              }
              break;
            }


          //////////////////////////////////
          //// VOLVER LISTA DE OPCIONES ////
          //////////////////////////////////
          case 2:
          case 3:
            {
              lcd.setCursor(0, 0);
              lcd.print(" Apagar Alarma  ");
              lcd.setCursor(0, 1);
              lcd.print(">Volver         ");
              if (digitalRead(BotonIzquierdo))
              {
                Menu = MenuLista;
                lcd.clear();
                delay(50);
                while (digitalRead(BotonIzquierdo)) {}
                delay(50);
              }
              break;
            }
        }
        break;
      }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    ////////////////////////////////////////////////////////////////////////////////////
    ///                             Menú Ajustes                                     ///
    ////////////////////////////////////////////////////////////////////////////////////
    case MenuAjustes:
      {
        LecturaPot = map(LecturaPot, 0, 1023, 0, 5);
        //Serial.println(LecturaPot);
        switch (LecturaPot)
        {

          ////////////////////////////////////////////////////////////
          //// SELECCIONAR TIEMPO PARA QUE SALTE LA PRIMERA DOSIS ////
          ////////////////////////////////////////////////////////////
          case 0:
            {
              lcd.setCursor(0, 0);
              lcd.print(">Poner en Hora  ");
              lcd.setCursor(0, 1);
              lcd.print(" Cantidad Dosis ");
              if (digitalRead(BotonIzquierdo))
              {
                lcd.clear();
                delay(50);
                while (digitalRead(BotonIzquierdo)) {}
                delay(50);
                PonerEnHora();
              }
              break;
            }

          //////////////////////////////////////////////////////////
          //// SELECCIONAR LA CANTIDAD DE DOSIS DEL DISPOSITIVO ////
          //////////////////////////////////////////////////////////
          case 1:
            {
              lcd.setCursor(0, 0);
              lcd.print(" Poner en Hora  ");
              lcd.setCursor(0, 1);
              lcd.print(">Cantidad Dosis ");
              if (digitalRead(BotonIzquierdo))
              {
                lcd.clear();
                delay(50);
                while (digitalRead(BotonIzquierdo)) {}
                delay(50);
                while (!digitalRead(BotonIzquierdo)) {
                  SeleccionarCantidadDosis();
                }
                EEPROM.write(0,NumDosis);
                lcd.clear();
                delay(50);
                while (digitalRead(BotonIzquierdo)) {}
                delay(50);
              }
              break;
            }

          ///////////////////////////////////////////
          ////     PROGRAMAR HORAS DE DOSIS      ////
          ///////////////////////////////////////////
          case 2:
            {
              lcd.setCursor(0, 0);
              lcd.print(" Cantidad Dosis ");
              lcd.setCursor(0, 1);
              lcd.print(">Programar horas");
              if (digitalRead(BotonIzquierdo))
              {
                lcd.clear();
                delay(50);
                while (digitalRead(BotonIzquierdo)) {}
                delay(50);
                ProgramarHora();
                lcd.clear();
                delay(50);
                while (digitalRead(BotonIzquierdo)) {}
                delay(50);
              }
              break;
            }

          case 3:
            {
              lcd.setCursor(0, 0);
              lcd.print(" Programar horas");
              lcd.setCursor(0, 1);
              lcd.print(">Peso por dosis ");
              if (digitalRead(BotonIzquierdo)) {
                lcd.clear();
                delay(50);
                while (digitalRead(BotonIzquierdo)) {}
                delay(50);
                PesoPorDosis();
              }
              break;
            }


          //////////////////////////////////
          //// VOLVER LISTA DE OPCIONES ////
          //////////////////////////////////
          case 4:
          case 5:
            {
              lcd.setCursor(0, 0);
              lcd.print(" Peso por dosis ");
              lcd.setCursor(0, 1);
              lcd.print(">Volver         ");
              if (digitalRead(BotonIzquierdo))
              {
                Menu = MenuLista;
                lcd.clear();
                delay(50);
                while (digitalRead(BotonIzquierdo)) {}
                delay(50);
              }
              break;
            }
        }
        break;
      }
  }

  // put your main code here, to run repeatedly:

}
