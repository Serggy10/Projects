/**
 * ! Importante
 * TODO: Cosas por hacer
 * ? Ideas para futuras implementaciones
 * 
*/


//TODO CAmbiar inclinacion del panel.
//TODO Funcionalidad iluminacion panelLED de forma automatica y manual.
//TODO Constructor para la libreria PanelLED donde se pasen los pines y parametros de MDParola.



/**
 *
 * V1: Introducción del programa de ejemplo Parola_Double_Heigth_Clock en el main para comprobar su funcionamiento.
 * V2: Introducción del programa de ejemplo TFT_Button_Label_Datanum el main para comprobar su funcionamiento.
 * V3: Introducción de acciones de control sobre el panel LED usando la pantalla TFT. Sin funcionar de forma correcta.
 * V4: Introducción de fuentes de doble altura e implementación de acciones de control usando la pantalla TFT. Limpieza de código.
 * V5: Cambio de pines panel LED para mejorar prestaciones.
 * V6: Implementación de multitareas empleando el segundo núcleo. Se separa el control de la pantalla TFT para que se ejecute en el segundo núcleo.
 * V7: Añadidas funciones para dibujar imagenes de la SD en la pantalla TFT.
 * V8: Implementación del menú en el panel TFT.
 * V9: Cambio del programa de la pantalla TFT usando ahora GUIslice.
 * V10: Saca por pantalla el efecto y menu seleccionados.
 * V11: 
 * V12: Se ha introducido la funcionalidad de introducir un mensaje personalizado por pantalla.
 * V13: Guardar algunos valores en la memoria flash del esp32. Añadida funcionalidad de inclinación del panel. Añadida funcionalidad de iluminacion automática.
 */
#define NumeroVersion 13
/*
  Descripción:
  Se creará un menú sin acciones de control que permitirá navegar entre las distintas pantallas.
  Permite mostrar algunos mensajes y efectos predeterminados, modificar la iluminacion de la pantalla y
  escribir mensajes personalizados tanto en una linea como en dos.
*/
#include <Arduino.h>
#include <SPI.h>
#include "Pinout.h"
#include "PanelLED.h"
#include "PantallaTFT.h"
#include "Memoria.h"
#include "BluetoothManager.h"


//Librerías para la implementación de lenguaje concurrente
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#define DEBUG

TaskHandle_t TareaTFT, TareaPanelLED;
void TareaRunTFT(void *pvParameters);
void TareaRunPanel(void *pvParameters);


//! *********************************************************************************************************************
//!
//!                                                      SETUP
//!
//! *********************************************************************************************************************

PanelLED PanelEmergencia;

void setup()
{
#ifdef DEBUG
  Serial.begin(115200);
  Serial.println("Modo depuracion activado");
  Serial.println("Panel_Emergencia_Carretera_V"+String(NumeroVersion));
  Serial.println("Sergio Carrasco Hernández. Curso 2023-2024");
#endif
  SetupMemoria();
  SetupPantallaTFT();                                                       // Inicialización pantalla TFT
  PanelEmergencia.Setup();                                                  // Inicialización Panel LED
  SetupBluetooth();
  xTaskCreatePinnedToCore(TareaRunPanel,"TareaPanel",4096,NULL,2,NULL,0);
  xTaskCreatePinnedToCore(TareaRunTFT,"TareaTFT",4096,NULL,2,NULL,1); //Separar laa tarea de la pantalla TFT en el segundo núcleo.
}

//! *********************************************************************************************************************
//!
//!                                                      LOOP
//!
//! *********************************************************************************************************************

void loop()
{
}

void TareaRunPanel(void *pvParameters)
{
  (void) pvParameters;
  for (;;)
  {
    PanelEmergencia.Run();
    delay(1);//10
  }
}

void TareaRunTFT(void *pvParameters)
{
  int16_t nX, nY;
        uint16_t nPress;
        gslc_teInputRawEvent eInputEvent;
        int16_t nInputVal;
  (void) pvParameters;
  for (;;)
  {
    gslc_Update(&m_gui);
    ApagarPantalla(nX,nY,nPress,eInputEvent,nInputVal,60000);
    RunBluetooth();
  }
  
}
