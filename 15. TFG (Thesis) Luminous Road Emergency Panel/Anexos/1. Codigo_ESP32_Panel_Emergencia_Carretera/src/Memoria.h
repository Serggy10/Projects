#ifndef MEMORIA_H
#define MEMORIA_H

#include <Preferences.h>
#include "PanelLED.h"

Preferences memoria;
extern PanelLED PanelEmergencia;
extern int iluminacionPantalla;

void SetupMemoria(){
    memoria.begin("Preferencias",false);
    PanelEmergencia.SetBrillo(memoria.getInt("BrilloPanel",1));
    PanelEmergencia.SetGrados(memoria.getInt("Inclinacion",0));
    PanelEmergencia.SetGradosAnterior(memoria.getInt("Inclinacion",0));
    pinMode(BACKLIGHT_TFT, OUTPUT);  //* Iluminacion pantalla TFT.
    iluminacionPantalla = memoria.getInt("BrilloPantalla",255);
    analogWrite(BACKLIGHT_TFT,iluminacionPantalla);
}


#endif