#ifndef PANTALLALED_H
#define PANTALLALED_H
/*********************************************************************************************************************

                                  DEFINICIONES PARA EL CONTROL DEL PANEL LED

*********************************************************************************************************************/
#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include "Font_data.h"

#include "Pinout.h"

#include <Font_Data.h>

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_ZONES 2
#define ZONE_SIZE 10
#define MAX_DEVICES (MAX_ZONES * ZONE_SIZE)

#define ZONE_UPPER 0
#define ZONE_LOWER 1

#include <Preferences.h>
extern Preferences memoria;

#include <Servo.h>


class PanelLED
{
public:
    PanelLED() {}
    void Setup();
    void Run();
    void Inclinar();
    void IluminacionAutomatica();

    
    int GetBrillo(){return brillo;}
    int GetBrilloAuto(){return iluminacionAutomatica;}
    int GetGrados(){Serial.println("Grados :"+String(inclinacion));return inclinacion;}
    int GetIluminacionExterior(){return iluminacionExterior;}
    
    void SetGrados(int grados){inclinacion=grados;}
    void SetGradosAnterior(int grados){inclinacionAnterior=grados;}
    void SetBrillo(int value) { brillo=value; memoria.putInt("BrilloPanel",brillo);}
    void SetIluminacionAutomatica(bool value){iluminacionAutomatica=value; Serial.println("> iluminacionAutomatica: " + (String)iluminacionAutomatica);}

private:
    MD_Parola Panel = MD_Parola(HARDWARE_TYPE, LED_DATA_PIN, LED_CLK_PIN, LED_CS_PIN, MAX_DEVICES);

    //! Menus
public:
    int GetMenuActual() { return menuActual; };
    int GetTextoPredeterminado() { return textoPredeterminadoPanel; }
    int GetEfectoDinamicoPredeterminado() { return efectoDinamicoPredeterminadoPanel; }
    void SetMenuActual(int Menu)
    {
        menuActual = Menu;
        //Serial.println("MenuActual: " + (String)Menu);
    }
    void SetTextoPredeterminado(int Texto) { textoPredeterminadoPanel = Texto; }
    void SetEfectoDinamicoPredeterminado(int Efecto) { efectoDinamicoPredeterminadoPanel = Efecto; }

private:
    int menuActual = 100;
    int menuAnterior = 100;
    int textoPredeterminadoPanel = 0;
    int efectoDinamicoPredeterminadoPanel = 0;
    int efectoPersonalizado = 0;
    int efectoPersonalizadoSuperior = 0;
    int efectoPersonalizadoInferior = 0;
    int velocidadMSGPersonalizado = 100;
    int velocidadMSGPersonalizadoSuperior = 100;
    int velocidadMSGPersonalizadoInferior = 100;
    int inclinacion = 0;
    int inclinacionAnterior=0;
    unsigned long int tiempoInclinacionAnterior=0;
    bool valorInclinacionGuardado=true;
    int estadoMensaje = 0;
    int brillo;
    int brilloAnterior;
    int iluminacionExterior; //? Valor leido en la LDR.
    bool iluminacionAutomatica;

    Servo servo;

public:
    enum
    {
        AtencionAccidente = 0,
        PrecaucionViento,
        PrecaucionNiebla,
        PrecaucionLuvia,
        PrecaucionNieve,
        ReduzcaVelocidad,
        DesvioIzquierda,
        DesvioDerecha,
        CarrilIzquierdoCortado,
        CarrilDerechoCortado,
        CarrilCortado,
        AtencionPare,
        Sigame,
        Peligro,
        MantengaseEnSuCarril,
        ControlAlcohol,
        ConduzcaResponsoblemente,
        DespejeCalzada
    };

    enum
    {
        DesvioEfectosIzquierda = 0,
        DesvioEfectosDerecha,
        MedioAExtremos,
        ExtremosAMedio,
        ParpadeoMitad,
        ParpadeoAlterno,
        ParpadeoTotal,
        ParpadeosDosADos
    };

    enum
    {
        MenuMensajeTexto = 0,
        MenuEfectosDinamicos,
        MenuMensajePersonalizadoUnaFila,
        MenuMensajePersonalizadoDosFilas,
    };

    //! Mensajes personalizados
public:
    String GetTextoUnaFila() { return textoUnaFila; }
    String GetTextoFilaSuperior() { return textoFilaSuperior; }
    String GetTextoFilaInferior() { return textoFilaInferior; }

    void SetTextoUnaFila(char *Texto)
    {
        strncpy(textoUnaFila, Texto, sizeof(textoUnaFila) - 1);
        textoUnaFila[sizeof(textoUnaFila) - 1] = '\0'; // Asegúrate de terminar la cadena con un carácter nulo
    }
    void SetTextoFilaSuperior(char *Texto)
    {
        strncpy(textoFilaSuperior, Texto, sizeof(textoFilaSuperior) - 1);
        textoFilaSuperior[sizeof(textoFilaSuperior) - 1] = '\0'; // Asegúrate de terminar la cadena con un carácter nulo
    }
    void SetTextoFilaInferior(char *Texto)
    {
        strncpy(textoFilaInferior, Texto, sizeof(textoFilaInferior) - 1);
        textoFilaInferior[sizeof(textoFilaInferior) - 1] = '\0'; // Asegúrate de terminar la cadena con un carácter nulo
    }

    void SetEfectoPersonalizado(int Efecto)
    {
        efectoPersonalizado = Efecto;
        //Serial.println("Efecto: " + (String)efectoPersonalizado);
    }
    void SetEfectoPersonalizadoSuperior(int Efecto)
    {
        efectoPersonalizadoSuperior = Efecto;
        //Serial.println("Efecto: " + (String)efectoPersonalizadoSuperior);
    }
    void SetEfectoPersonalizadoInferior(int Efecto)
    {
        efectoPersonalizadoInferior = Efecto;
        //Serial.println("Efecto: " + (String)efectoPersonalizadoInferior);
    }
    textEffect_t GetEfecto(int numero);
    
    void SetVelocidadMSGPersonalizado(int Velocidad)
    {
        velocidadMSGPersonalizado = Velocidad;
        //Serial.println("Velocidad: " + (String)Velocidad);
    }
    void SetVelocidadMSGPersonalizadoSuperior(int Velocidad)
    {
        velocidadMSGPersonalizadoSuperior = Velocidad;
        //Serial.println("Velocidad Superior: " + (String)velocidadMSGPersonalizadoSuperior);
    }
    void SetVelocidadMSGPersonalizadoInferior(int Velocidad)
    {
        velocidadMSGPersonalizadoInferior = Velocidad;
        //Serial.println("Velocidad Inferior: " + (String)velocidadMSGPersonalizadoInferior);
    }

    int GetVelocidad(int velocidad);
    int GetPausa(int velocidad);

private:
#define tamanoMensaje 50
    char textoUnaFila[tamanoMensaje];
    char textoFilaSuperior[tamanoMensaje];
    char textoFilaInferior[tamanoMensaje];
};
#endif