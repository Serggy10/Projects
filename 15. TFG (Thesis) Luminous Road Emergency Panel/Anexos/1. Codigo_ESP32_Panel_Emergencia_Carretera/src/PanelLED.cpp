#include "PanelLED.h"

//! **********************************************************************************************************
//!                                       SETUP PANEL LED
//! **********************************************************************************************************
void PanelLED::Setup()
{
    pinMode(SERVO_PIN,OUTPUT);
    servo.attach(SERVO_PIN);
    Panel.begin(MAX_ZONES);
    Panel.setZone(ZONE_LOWER, 0, ZONE_SIZE - 1);
    Panel.setFont(ZONE_LOWER, BigFontLower);
    Panel.setZone(ZONE_UPPER, ZONE_SIZE, MAX_DEVICES - 1);
    Panel.setFont(ZONE_UPPER, BigFontUpper);
    Panel.setCharSpacing(Panel.getCharSpacing() * 2); // double height --> double spacing
    Panel.setIntensity(brillo);                            // TODO Leer ultimo valor guardado en la eeprom.

}

//! **********************************************************************************************************
//!                                       RUN PANEL LED
//! **********************************************************************************************************
void PanelLED::Run()
{
    Inclinar();
    IluminacionAutomatica();
    if (brillo!=brilloAnterior)
    {
        brilloAnterior=brillo;
        Panel.setIntensity(brillo);
    }
    if (menuActual != menuAnterior)
    {
        menuAnterior = menuActual;
        Panel.displayClear();
        Panel.displayZoneText(ZONE_UPPER, "", PA_CENTER, 100, 100, PA_NO_EFFECT, PA_NO_EFFECT);
        Panel.displayZoneText(ZONE_LOWER, "", PA_CENTER, 100, 100, PA_NO_EFFECT, PA_NO_EFFECT);
    }
    //Serial.println(">estadoMensaje:" + String(estadoMensaje));
    switch (menuActual)
    {
    case MenuMensajeTexto:
        switch (textoPredeterminadoPanel)
        {
        case AtencionAccidente:
            if (Panel.displayAnimate())
            {
                estadoMensaje++;
                //delay(50);
                if (estadoMensaje > 9)
                    estadoMensaje = 0;
            }
            if (Panel.getZoneStatus(ZONE_LOWER) && Panel.getZoneStatus(ZONE_UPPER))
                switch (estadoMensaje)
                {
                case 0:
                    Panel.setCharSpacing(2);
                    Panel.setFont(ZONE_LOWER, BigFontLower);
                    Panel.setFont(ZONE_UPPER, BigFontUpper);
                    Panel.displayZoneText(ZONE_UPPER, "ATENCION", PA_CENTER, 10, 10, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
                    Panel.displayZoneText(ZONE_LOWER, "ATENCION", PA_CENTER, 10, 10, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
                    break;
                case 5:
                    Panel.setCharSpacing(2);
                    Panel.setFont(ZONE_LOWER, BigFontLower);
                    Panel.setFont(ZONE_UPPER, BigFontUpper);
                    Panel.displayZoneText(ZONE_UPPER, "ACCIDENTE", PA_CENTER, 10, 10, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
                    Panel.displayZoneText(ZONE_LOWER, "ACCIDENTE", PA_CENTER, 10, 10, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
                    break;
                case 1:
                case 3:
                case 6:
                case 8:
                    Panel.setCharSpacing(0);
                    Panel.setFont(ZONE_LOWER, EfectosUpper);
                    Panel.setFont(ZONE_UPPER, EfectosUpper); // TODO Cambiar efectosLower
                    Panel.displayZoneText(ZONE_UPPER, "!        !        !        !        !        ", PA_CENTER, 200, 100, PA_PRINT, PA_PRINT);
                    Panel.displayZoneText(ZONE_LOWER, "        !        !        !        !        !", PA_CENTER, 200, 100, PA_PRINT, PA_PRINT);
                    break;
                case 2:
                case 4:
                case 7:
                case 9:
                    Panel.setCharSpacing(0);
                    Panel.setFont(ZONE_LOWER, EfectosUpper);
                    Panel.setFont(ZONE_UPPER, EfectosUpper);
                    Panel.displayZoneText(ZONE_UPPER, "        !        !        !        !        !", PA_CENTER, 200, 100, PA_PRINT, PA_PRINT);
                    Panel.displayZoneText(ZONE_LOWER, "!        !        !        !        !        ", PA_CENTER, 200, 100, PA_PRINT, PA_PRINT);
                    break;
                }
            break;
        case PrecaucionViento:
            if (Panel.displayAnimate())
            {
                estadoMensaje++;
                //delay(50);
                if (estadoMensaje > 4)
                    estadoMensaje = 0;
            }
            if (Panel.getZoneStatus(ZONE_LOWER) && Panel.getZoneStatus(ZONE_UPPER))
                switch (estadoMensaje)
                {
                case 0:
                    Panel.setCharSpacing(2);
                    Panel.setFont(ZONE_LOWER, BigFontLower);
                    Panel.setFont(ZONE_UPPER, BigFontUpper); // TODO Cambiar efectosLower
                    Panel.displayZoneText(ZONE_UPPER, "PRECAUCION VIENTO", PA_CENTER, 10, 10, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
                    Panel.displayZoneText(ZONE_LOWER, "PRECAUCION VIENTO", PA_CENTER, 10, 10, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
                    break;
                case 1:
                case 3:
                    Panel.setCharSpacing(0);
                    Panel.setFont(ZONE_LOWER, EfectosUpper);
                    Panel.setFont(ZONE_UPPER, EfectosUpper); // TODO Cambiar efectosLower
                    Panel.displayZoneText(ZONE_UPPER, "        !        !        !        !        !", PA_CENTER, 200, 100, PA_PRINT, PA_PRINT);
                    Panel.displayZoneText(ZONE_LOWER, "!        !        !        !        !        ", PA_CENTER, 200, 100, PA_PRINT, PA_PRINT);
                    break;
                case 2:
                case 4:
                    Panel.setCharSpacing(0);
                    Panel.setFont(ZONE_LOWER, EfectosUpper);
                    Panel.setFont(ZONE_UPPER, EfectosUpper);
                    Panel.displayZoneText(ZONE_UPPER, "!        !        !        !        !        ", PA_CENTER, 200, 100, PA_PRINT, PA_PRINT);
                    Panel.displayZoneText(ZONE_LOWER, "        !        !        !        !        !", PA_CENTER, 200, 100, PA_PRINT, PA_PRINT);
                    break;
                }
            break;
        case PrecaucionNiebla:
            if (Panel.displayAnimate())
            {
                estadoMensaje++;
                //delay(50);
                if (estadoMensaje > 1)
                    estadoMensaje = 0;
            }
            if (Panel.getZoneStatus(ZONE_LOWER) && Panel.getZoneStatus(ZONE_UPPER))
                switch (estadoMensaje)
                {
                case 0:
                    Panel.setCharSpacing(0);
                    Panel.setFont(ZONE_LOWER, EfectosUpper);
                    Panel.setFont(ZONE_UPPER, EfectosUpper); // TODO Cambiar efectosLower
                    Panel.displayZoneText(ZONE_UPPER, "$   P R E C A U C I O N    $", PA_CENTER, 200, 100, PA_PRINT, PA_NO_EFFECT);
                    Panel.displayZoneText(ZONE_LOWER, "$                N I E B L A               $", PA_CENTER, 200, 100, PA_PRINT, PA_NO_EFFECT);
                    break;
                case 1:
                    Panel.setCharSpacing(0);
                    Panel.setFont(ZONE_LOWER, EfectosUpper);
                    Panel.setFont(ZONE_UPPER, EfectosUpper); // TODO Cambiar efectosLower
                    Panel.displayZoneText(ZONE_UPPER, "#   P R E C A U C I O N    #", PA_CENTER, 200, 100, PA_PRINT, PA_NO_EFFECT);
                    Panel.displayZoneText(ZONE_LOWER, "#                N I E B L A               #", PA_CENTER, 200, 100, PA_PRINT, PA_NO_EFFECT);
                    break;
                    break;
                }
            break;
        case PrecaucionLuvia:
            if (Panel.displayAnimate())
            {
                estadoMensaje++;
                //delay(50);
                if (estadoMensaje > 7)
                    estadoMensaje = 0;
            }
            if (Panel.getZoneStatus(ZONE_LOWER) && Panel.getZoneStatus(ZONE_UPPER))
                switch (estadoMensaje)
                {
                case 0:
                    Panel.setCharSpacing(0);
                    Panel.setFont(ZONE_LOWER, EfectosUpper);
                    Panel.setFont(ZONE_UPPER, EfectosUpper); // TODO Cambiar efectosLower
                    Panel.displayZoneText(ZONE_UPPER, "a   P R E C A U C I O N    a", PA_CENTER, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    Panel.displayZoneText(ZONE_LOWER, "a                L L U V I A               a", PA_CENTER, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    break;
                case 1:
                    Panel.setCharSpacing(0);
                    Panel.setFont(ZONE_LOWER, EfectosUpper);
                    Panel.setFont(ZONE_UPPER, EfectosUpper); // TODO Cambiar efectosLower
                    Panel.displayZoneText(ZONE_UPPER, "b   P R E C A U C I O N    b", PA_CENTER, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    Panel.displayZoneText(ZONE_LOWER, "b                L L U V I A               b", PA_CENTER, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    break;
                case 2:
                    Panel.setCharSpacing(0);
                    Panel.setFont(ZONE_LOWER, EfectosUpper);
                    Panel.setFont(ZONE_UPPER, EfectosUpper); // TODO Cambiar efectosLower
                    Panel.displayZoneText(ZONE_UPPER, "c   P R E C A U C I O N    c", PA_CENTER, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    Panel.displayZoneText(ZONE_LOWER, "c                L L U V I A               c", PA_CENTER, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    break;
                case 3:
                    Panel.setCharSpacing(0);
                    Panel.setFont(ZONE_LOWER, EfectosUpper);
                    Panel.setFont(ZONE_UPPER, EfectosUpper); // TODO Cambiar efectosLower
                    Panel.displayZoneText(ZONE_UPPER, "d   P R E C A U C I O N    d", PA_CENTER, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    Panel.displayZoneText(ZONE_LOWER, "d                L L U V I A               d", PA_CENTER, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    break;
                case 4:
                    Panel.setCharSpacing(0);
                    Panel.setFont(ZONE_LOWER, EfectosUpper);
                    Panel.setFont(ZONE_UPPER, EfectosUpper); // TODO Cambiar efectosLower
                    Panel.displayZoneText(ZONE_UPPER, "e   P R E C A U C I O N    e", PA_CENTER, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    Panel.displayZoneText(ZONE_LOWER, "e                L L U V I A               e", PA_CENTER, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    break;
                case 5:
                    Panel.setCharSpacing(0);
                    Panel.setFont(ZONE_LOWER, EfectosUpper);
                    Panel.setFont(ZONE_UPPER, EfectosUpper); // TODO Cambiar efectosLower
                    Panel.displayZoneText(ZONE_UPPER, "f   P R E C A U C I O N    f", PA_CENTER, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    Panel.displayZoneText(ZONE_LOWER, "f                L L U V I A               f", PA_CENTER, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    break;
                case 6:
                    Panel.setCharSpacing(0);
                    Panel.setFont(ZONE_LOWER, EfectosUpper);
                    Panel.setFont(ZONE_UPPER, EfectosUpper); // TODO Cambiar efectosLower
                    Panel.displayZoneText(ZONE_UPPER, "g   P R E C A U C I O N    g", PA_CENTER, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    Panel.displayZoneText(ZONE_LOWER, "g                L L U V I A               g", PA_CENTER, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    break;
                case 7:
                    Panel.setCharSpacing(0);
                    Panel.setFont(ZONE_LOWER, EfectosUpper);
                    Panel.setFont(ZONE_UPPER, EfectosUpper); // TODO Cambiar efectosLower
                    Panel.displayZoneText(ZONE_UPPER, "h   P R E C A U C I O N    h", PA_CENTER, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    Panel.displayZoneText(ZONE_LOWER, "h                L L U V I A               h", PA_CENTER, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    break;
                }
            break;
        case PrecaucionNieve:
            if (Panel.displayAnimate())
            {
                estadoMensaje++;
                //delay(50);
                if (estadoMensaje > 7)
                    estadoMensaje = 0;
            }
            if (Panel.getZoneStatus(ZONE_LOWER) && Panel.getZoneStatus(ZONE_UPPER))
                switch (estadoMensaje)
                {
                case 0:
                    Panel.setCharSpacing(0);
                    Panel.setFont(ZONE_LOWER, EfectosUpper);
                    Panel.setFont(ZONE_UPPER, EfectosUpper); // TODO Cambiar efectosLower
                    Panel.displayZoneText(ZONE_UPPER, "i   P R E C A U C I O N    i", PA_CENTER, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    Panel.displayZoneText(ZONE_LOWER, "i                   N I E V E                  i", PA_CENTER, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    break;
                case 1:
                    Panel.setCharSpacing(0);
                    Panel.setFont(ZONE_LOWER, EfectosUpper);
                    Panel.setFont(ZONE_UPPER, EfectosUpper); // TODO Cambiar efectosLower
                    Panel.displayZoneText(ZONE_UPPER, "j   P R E C A U C I O N    j", PA_CENTER, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    Panel.displayZoneText(ZONE_LOWER, "j                   N I E V E                  j", PA_CENTER, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    break;
                case 2:
                    Panel.setCharSpacing(0);
                    Panel.setFont(ZONE_LOWER, EfectosUpper);
                    Panel.setFont(ZONE_UPPER, EfectosUpper); // TODO Cambiar efectosLower
                    Panel.displayZoneText(ZONE_UPPER, "k   P R E C A U C I O N    k", PA_CENTER, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    Panel.displayZoneText(ZONE_LOWER, "k                   N I E V E                  k", PA_CENTER, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    break;
                case 3:
                    Panel.setCharSpacing(0);
                    Panel.setFont(ZONE_LOWER, EfectosUpper);
                    Panel.setFont(ZONE_UPPER, EfectosUpper); // TODO Cambiar efectosLower
                    Panel.displayZoneText(ZONE_UPPER, "l   P R E C A U C I O N    l", PA_CENTER, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    Panel.displayZoneText(ZONE_LOWER, "l                   N I E V E                  l", PA_CENTER, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    break;
                case 4:
                    Panel.setCharSpacing(0);
                    Panel.setFont(ZONE_LOWER, EfectosUpper);
                    Panel.setFont(ZONE_UPPER, EfectosUpper); // TODO Cambiar efectosLower
                    Panel.displayZoneText(ZONE_UPPER, "m   P R E C A U C I O N    m", PA_CENTER, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    Panel.displayZoneText(ZONE_LOWER, "m                   N I E V E                  m", PA_CENTER, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    break;
                case 5:
                    Panel.setCharSpacing(0);
                    Panel.setFont(ZONE_LOWER, EfectosUpper);
                    Panel.setFont(ZONE_UPPER, EfectosUpper); // TODO Cambiar efectosLower
                    Panel.displayZoneText(ZONE_UPPER, "n   P R E C A U C I O N    n", PA_CENTER, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    Panel.displayZoneText(ZONE_LOWER, "n                   N I E V E                  n", PA_CENTER, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    break;
                case 6:
                    Panel.setCharSpacing(0);
                    Panel.setFont(ZONE_LOWER, EfectosUpper);
                    Panel.setFont(ZONE_UPPER, EfectosUpper); // TODO Cambiar efectosLower
                    Panel.displayZoneText(ZONE_UPPER, "o   P R E C A U C I O N    o", PA_CENTER, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    Panel.displayZoneText(ZONE_LOWER, "o                   N I E V E                  o", PA_CENTER, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    break;
                case 7:
                    Panel.setCharSpacing(0);
                    Panel.setFont(ZONE_LOWER, EfectosUpper);
                    Panel.setFont(ZONE_UPPER, EfectosUpper); // TODO Cambiar efectosLower
                    Panel.displayZoneText(ZONE_UPPER, "p   P R E C A U C I O N    p", PA_CENTER, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    Panel.displayZoneText(ZONE_LOWER, "p                   N I E V E                  p", PA_CENTER, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    break;
                }
            break;
        case ReduzcaVelocidad:
            if (Panel.displayAnimate())
            {
                estadoMensaje++;
                //delay(50);
                if (estadoMensaje > 9)
                    estadoMensaje = 0;
            }
            if (Panel.getZoneStatus(ZONE_LOWER) && Panel.getZoneStatus(ZONE_UPPER))
                switch (estadoMensaje)
                {
                case 0:
                case 5:
                    Panel.setCharSpacing(1);
                    Panel.setFont(ZONE_LOWER, NULL);
                    Panel.setFont(ZONE_UPPER, NULL); // TODO Cambiar efectosLower
                    Panel.displayZoneText(ZONE_UPPER, "REDUZCA", PA_CENTER, 100, 2000, PA_PRINT, PA_NO_EFFECT);
                    Panel.displayZoneText(ZONE_LOWER, "VELOCIDAD", PA_CENTER, 100, 2000, PA_PRINT, PA_NO_EFFECT);
                    break;
                case 1:
                case 2:
                case 3:
                    Panel.setCharSpacing(1);
                    Panel.setFont(ZONE_LOWER, NULL);
                    Panel.setFont(ZONE_UPPER, NULL); // TODO Cambiar efectosLower
                    Panel.displayZoneText(ZONE_UPPER, "REDUZCA", PA_CENTER, 100, 200, PA_NO_EFFECT, PA_NO_EFFECT);
                    Panel.displayZoneText(ZONE_LOWER, "VELOCIDAD", PA_CENTER, 100, 200, PA_PRINT, PA_PRINT);
                    break;
                case 6:
                case 7:
                case 8:
                    Panel.setCharSpacing(1);
                    Panel.setFont(ZONE_LOWER, NULL);
                    Panel.setFont(ZONE_UPPER, NULL); // TODO Cambiar efectosLower
                    Panel.displayZoneText(ZONE_UPPER, "REDUZCA", PA_CENTER, 100, 200, PA_PRINT, PA_PRINT);
                    Panel.displayZoneText(ZONE_LOWER, "VELOCIDAD", PA_CENTER, 100, 200, PA_NO_EFFECT, PA_NO_EFFECT);
                    break;
                }
            break;
        case DesvioIzquierda:
            if (Panel.displayAnimate())
            {
                estadoMensaje++;
                //delay(50);
                if (estadoMensaje > 12)
                    estadoMensaje = 0;
            }
            if (Panel.getZoneStatus(ZONE_LOWER) && Panel.getZoneStatus(ZONE_UPPER))
                switch (estadoMensaje)
                {
                case 0:
                    Panel.setCharSpacing(0);

                    Panel.setFont(ZONE_UPPER, EfectosUpper);
                    Panel.setFont(ZONE_LOWER, EfectosLower);
                    Panel.displayZoneText(ZONE_UPPER, "q q D E S V I O                ", PA_RIGHT, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    Panel.displayZoneText(ZONE_LOWER, "q q I Z Q U I E R D A", PA_RIGHT, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    break;
                case 1:
                    Panel.setCharSpacing(0);

                    Panel.setFont(ZONE_UPPER, EfectosUpper);
                    Panel.setFont(ZONE_LOWER, EfectosLower);
                    Panel.displayZoneText(ZONE_UPPER, "q q  D E S V I O                ", PA_RIGHT, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    Panel.displayZoneText(ZONE_LOWER, "q q  I Z Q U I E R D A", PA_RIGHT, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    break;
                case 2:
                    Panel.setCharSpacing(0);

                    Panel.setFont(ZONE_UPPER, EfectosUpper);
                    Panel.setFont(ZONE_LOWER, EfectosLower);
                    Panel.displayZoneText(ZONE_UPPER, "q q   D E S V I O                ", PA_RIGHT, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    Panel.displayZoneText(ZONE_LOWER, "q q   I Z Q U I E R D A", PA_RIGHT, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    break;
                case 3:
                    Panel.setCharSpacing(0);

                    Panel.setFont(ZONE_UPPER, EfectosUpper);
                    Panel.setFont(ZONE_LOWER, EfectosLower);
                    Panel.displayZoneText(ZONE_UPPER, "q q    D E S V I O                ", PA_RIGHT, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    Panel.displayZoneText(ZONE_LOWER, "q q    I Z Q U I E R D A", PA_RIGHT, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    break;
                case 4:
                    Panel.setCharSpacing(0);

                    Panel.setFont(ZONE_UPPER, EfectosUpper);
                    Panel.setFont(ZONE_LOWER, EfectosLower);
                    Panel.displayZoneText(ZONE_UPPER, "q q     D E S V I O                ", PA_RIGHT, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    Panel.displayZoneText(ZONE_LOWER, "q q     I Z Q U I E R D A", PA_RIGHT, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    break;
                case 5:
                    Panel.setCharSpacing(0);

                    Panel.setFont(ZONE_UPPER, EfectosUpper);
                    Panel.setFont(ZONE_LOWER, EfectosLower);
                    Panel.displayZoneText(ZONE_UPPER, "q q      D E S V I O                ", PA_RIGHT, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    Panel.displayZoneText(ZONE_LOWER, "q q      I Z Q U I E R D A", PA_RIGHT, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    break;
                case 6:
                    Panel.setCharSpacing(0);

                    Panel.setFont(ZONE_UPPER, EfectosUpper);
                    Panel.setFont(ZONE_LOWER, EfectosLower);
                    Panel.displayZoneText(ZONE_UPPER, "q q       D E S V I O                ", PA_RIGHT, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    Panel.displayZoneText(ZONE_LOWER, "q q       I Z Q U I E R D A", PA_RIGHT, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    break;
                case 7:
                    Panel.setCharSpacing(0);

                    Panel.setFont(ZONE_UPPER, EfectosUpper);
                    Panel.setFont(ZONE_LOWER, EfectosLower);
                    Panel.displayZoneText(ZONE_UPPER, "q q        D E S V I O                ", PA_RIGHT, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    Panel.displayZoneText(ZONE_LOWER, "q q        I Z Q U I E R D A", PA_RIGHT, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    break;
                case 8:
                    Panel.setCharSpacing(0);

                    Panel.setFont(ZONE_UPPER, EfectosUpper);
                    Panel.setFont(ZONE_LOWER, EfectosLower);
                    Panel.displayZoneText(ZONE_UPPER, "q q         D E S V I O                ", PA_RIGHT, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    Panel.displayZoneText(ZONE_LOWER, "q q         I Z Q U I E R D A", PA_RIGHT, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    break;
                case 9:
                    Panel.setCharSpacing(0);

                    Panel.setFont(ZONE_UPPER, EfectosUpper);
                    Panel.setFont(ZONE_LOWER, EfectosLower);
                    Panel.displayZoneText(ZONE_UPPER, "q q          D E S V I O                ", PA_RIGHT, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    Panel.displayZoneText(ZONE_LOWER, "q q          I Z Q U I E R D A", PA_RIGHT, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    break;
                case 10:
                    Panel.setCharSpacing(0);

                    Panel.setFont(ZONE_UPPER, EfectosUpper);
                    Panel.setFont(ZONE_LOWER, EfectosLower);
                    Panel.displayZoneText(ZONE_UPPER, "q q           D E S V I O                ", PA_RIGHT, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    Panel.displayZoneText(ZONE_LOWER, "q q           I Z Q U I E R D A", PA_RIGHT, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    break;
                case 11:
                    Panel.setCharSpacing(0);

                    Panel.setFont(ZONE_UPPER, EfectosUpper);
                    Panel.setFont(ZONE_LOWER, EfectosLower);
                    Panel.displayZoneText(ZONE_UPPER, "q q            D E S V I O                ", PA_RIGHT, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    Panel.displayZoneText(ZONE_LOWER, "q q            I Z Q U I E R D A", PA_RIGHT, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    break;
                case 12:
                    Panel.setCharSpacing(0);

                    Panel.setFont(ZONE_UPPER, EfectosUpper);
                    Panel.setFont(ZONE_LOWER, EfectosLower);
                    Panel.displayZoneText(ZONE_UPPER, "q q             D E S V I O                ", PA_RIGHT, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    Panel.displayZoneText(ZONE_LOWER, "q q             I Z Q U I E R D A", PA_RIGHT, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    break;
                }
            break;
        case DesvioDerecha:
            if (Panel.displayAnimate())
            {
                estadoMensaje++;
                //delay(50);
                if (estadoMensaje > 12)
                    estadoMensaje = 0;
            }
            if (Panel.getZoneStatus(ZONE_LOWER) && Panel.getZoneStatus(ZONE_UPPER))
                switch (estadoMensaje)
                {
                case 0:
                    Panel.setCharSpacing(0);

                    Panel.setFont(ZONE_UPPER, EfectosUpper);
                    Panel.setFont(ZONE_LOWER, EfectosLower);
                    Panel.displayZoneText(ZONE_UPPER, "D E S V I O         r r r ", PA_LEFT, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    Panel.displayZoneText(ZONE_LOWER, "D E R E C H A r r r ", PA_LEFT, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    break;
                case 1:
                    Panel.setCharSpacing(0);

                    Panel.setFont(ZONE_UPPER, EfectosUpper);
                    Panel.setFont(ZONE_LOWER, EfectosLower);
                    Panel.displayZoneText(ZONE_UPPER, "D E S V I O          r r r ", PA_LEFT, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    Panel.displayZoneText(ZONE_LOWER, "D E R E C H A  r r r ", PA_LEFT, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    break;
                case 2:
                    Panel.setCharSpacing(0);

                    Panel.setFont(ZONE_UPPER, EfectosUpper);
                    Panel.setFont(ZONE_LOWER, EfectosLower);
                    Panel.displayZoneText(ZONE_UPPER, "D E S V I O           r r r ", PA_LEFT, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    Panel.displayZoneText(ZONE_LOWER, "D E R E C H A   r r r ", PA_LEFT, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    break;
                case 3:
                    Panel.setCharSpacing(0);

                    Panel.setFont(ZONE_UPPER, EfectosUpper);
                    Panel.setFont(ZONE_LOWER, EfectosLower);
                    Panel.displayZoneText(ZONE_UPPER, "D E S V I O            r r r ", PA_LEFT, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    Panel.displayZoneText(ZONE_LOWER, "D E R E C H A    r r r ", PA_LEFT, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    break;
                case 4:
                    Panel.setCharSpacing(0);

                    Panel.setFont(ZONE_UPPER, EfectosUpper);
                    Panel.setFont(ZONE_LOWER, EfectosLower);
                    Panel.displayZoneText(ZONE_UPPER, "D E S V I O             r r r ", PA_LEFT, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    Panel.displayZoneText(ZONE_LOWER, "D E R E C H A     r r r ", PA_LEFT, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    break;
                case 5:
                    Panel.setCharSpacing(0);

                    Panel.setFont(ZONE_UPPER, EfectosUpper);
                    Panel.setFont(ZONE_LOWER, EfectosLower);
                    Panel.displayZoneText(ZONE_UPPER, "D E S V I O              r r r ", PA_LEFT, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    Panel.displayZoneText(ZONE_LOWER, "D E R E C H A      r r r ", PA_LEFT, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    break;
                case 6:
                    Panel.setCharSpacing(0);

                    Panel.setFont(ZONE_UPPER, EfectosUpper);
                    Panel.setFont(ZONE_LOWER, EfectosLower);
                    Panel.displayZoneText(ZONE_UPPER, "D E S V I O               r r r ", PA_LEFT, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    Panel.displayZoneText(ZONE_LOWER, "D E R E C H A       r r r ", PA_LEFT, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    break;
                case 7:
                    Panel.setCharSpacing(0);

                    Panel.setFont(ZONE_UPPER, EfectosUpper);
                    Panel.setFont(ZONE_LOWER, EfectosLower);
                    Panel.displayZoneText(ZONE_UPPER, "D E S V I O                r r r ", PA_LEFT, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    Panel.displayZoneText(ZONE_LOWER, "D E R E C H A        r r r ", PA_LEFT, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    break;
                case 8:
                    Panel.setCharSpacing(0);

                    Panel.setFont(ZONE_UPPER, EfectosUpper);
                    Panel.setFont(ZONE_LOWER, EfectosLower);
                    Panel.displayZoneText(ZONE_UPPER, "D E S V I O                 r r r ", PA_LEFT, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    Panel.displayZoneText(ZONE_LOWER, "D E R E C H A         r r r ", PA_LEFT, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    break;
                case 9:
                    Panel.setCharSpacing(0);

                    Panel.setFont(ZONE_UPPER, EfectosUpper);
                    Panel.setFont(ZONE_LOWER, EfectosLower);
                    Panel.displayZoneText(ZONE_UPPER, "D E S V I O                  r r r ", PA_LEFT, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    Panel.displayZoneText(ZONE_LOWER, "D E R E C H A          r r r ", PA_LEFT, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    break;
                case 10:
                    Panel.setCharSpacing(0);

                    Panel.setFont(ZONE_UPPER, EfectosUpper);
                    Panel.setFont(ZONE_LOWER, EfectosLower);
                    Panel.displayZoneText(ZONE_UPPER, "D E S V I O                   r r r ", PA_LEFT, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    Panel.displayZoneText(ZONE_LOWER, "D E R E C H A           r r r ", PA_LEFT, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    break;
                case 11:
                    Panel.setCharSpacing(0);

                    Panel.setFont(ZONE_UPPER, EfectosUpper);
                    Panel.setFont(ZONE_LOWER, EfectosLower);
                    Panel.displayZoneText(ZONE_UPPER, "D E S V I O                    r r r ", PA_LEFT, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    Panel.displayZoneText(ZONE_LOWER, "D E R E C H A            r r r ", PA_LEFT, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    break;
                case 12:
                    Panel.setCharSpacing(0);

                    Panel.setFont(ZONE_UPPER, EfectosUpper);
                    Panel.setFont(ZONE_LOWER, EfectosLower);
                    Panel.displayZoneText(ZONE_UPPER, "D E S V I O                     r r r ", PA_LEFT, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    Panel.displayZoneText(ZONE_LOWER, "D E R E C H A             r r r ", PA_LEFT, 100, 100, PA_PRINT, PA_NO_EFFECT);
                    break;
                }
            break;
        case CarrilIzquierdoCortado:
            if (Panel.displayAnimate())
            {
                estadoMensaje++;
                //delay(50);
                if (estadoMensaje > 1)
                    estadoMensaje = 0;
            }
            if (Panel.getZoneStatus(ZONE_LOWER) && Panel.getZoneStatus(ZONE_UPPER))
                switch (estadoMensaje)
                {
                case 0:
                    Panel.setCharSpacing(0);
                    Panel.setFont(ZONE_UPPER, EfectosUpper);
                    Panel.setFont(ZONE_LOWER, EfectosLower);
                    Panel.displayZoneText(ZONE_UPPER, "s         C A R R I L   I Z Q", PA_RIGHT, 300, 300, PA_NO_EFFECT, PA_NO_EFFECT);
                    Panel.displayZoneText(ZONE_LOWER, "s         C O R T A D O          ", PA_RIGHT, 300, 300, PA_NO_EFFECT, PA_NO_EFFECT);
                    break;
                case 1:
                    Panel.setCharSpacing(0);
                    Panel.setFont(ZONE_UPPER, EfectosUpper);
                    Panel.setFont(ZONE_LOWER, EfectosLower);
                    Panel.displayZoneText(ZONE_UPPER, "         C A R R I L   I Z Q", PA_RIGHT, 300, 300, PA_NO_EFFECT, PA_NO_EFFECT);
                    Panel.displayZoneText(ZONE_LOWER, "         C O R T A D O          ", PA_RIGHT, 300, 300, PA_NO_EFFECT, PA_NO_EFFECT);
                    break;
                }
            break;
        case CarrilDerechoCortado:
            if (Panel.displayAnimate())
            {
                estadoMensaje++;
                //delay(50);
                if (estadoMensaje > 1)
                    estadoMensaje = 0;
            }
            if (Panel.getZoneStatus(ZONE_LOWER) && Panel.getZoneStatus(ZONE_UPPER))
                switch (estadoMensaje)
                {
                case 0:
                    Panel.setCharSpacing(0);
                    Panel.setFont(ZONE_UPPER, EfectosUpper);
                    Panel.setFont(ZONE_LOWER, EfectosLower);
                    Panel.displayZoneText(ZONE_UPPER, "C A R R I L   D E R       s", PA_LEFT, 300, 300, PA_NO_EFFECT, PA_NO_EFFECT);
                    Panel.displayZoneText(ZONE_LOWER, "C O R T A D O                   s", PA_LEFT, 300, 300, PA_NO_EFFECT, PA_NO_EFFECT);
                    break;
                case 1:
                    Panel.setCharSpacing(0);
                    Panel.setFont(ZONE_UPPER, EfectosUpper);
                    Panel.setFont(ZONE_LOWER, EfectosLower);
                    Panel.displayZoneText(ZONE_UPPER, "C A R R I L   D E R", PA_LEFT, 300, 300, PA_NO_EFFECT, PA_NO_EFFECT);
                    Panel.displayZoneText(ZONE_LOWER, "C O R T A D O          ", PA_LEFT, 300, 300, PA_NO_EFFECT, PA_NO_EFFECT);
                    break;
                }
            break;
        case CarrilCortado:
            if (Panel.displayAnimate())
            {
                estadoMensaje++;
                //delay(50);
                Serial.println(">CarrilCortado:" + (String)estadoMensaje);
                if (estadoMensaje > 1)
                    estadoMensaje = 0;
            }
            if (Panel.getZoneStatus(ZONE_LOWER) && Panel.getZoneStatus(ZONE_UPPER))
                switch (estadoMensaje)
                {
                case 0:
                    Panel.setCharSpacing(0);
                    Panel.setFont(ZONE_UPPER, EfectosUpper);
                    Panel.setFont(ZONE_LOWER, EfectosLower);
                    Panel.displayZoneText(ZONE_UPPER, "s      C A R R I L      s", PA_CENTER, 300, 300, PA_NO_EFFECT, PA_NO_EFFECT);
                    Panel.displayZoneText(ZONE_LOWER, "s  C O R T A D O  s", PA_CENTER, 300, 300, PA_NO_EFFECT, PA_NO_EFFECT);
                    break;
                case 1:
                    Panel.setCharSpacing(0);
                    Panel.setFont(ZONE_UPPER, EfectosUpper);
                    Panel.setFont(ZONE_LOWER, EfectosLower);
                    Panel.displayZoneText(ZONE_UPPER, "C A R R I L", PA_CENTER, 300, 300, PA_NO_EFFECT, PA_NO_EFFECT);
                    Panel.displayZoneText(ZONE_LOWER, "C O R T A D O", PA_CENTER, 300, 300, PA_NO_EFFECT, PA_NO_EFFECT);
                    break;
                }
            break;
        case AtencionPare:
            if (Panel.displayAnimate())
            {
                estadoMensaje++;
                //delay(50);
                if (estadoMensaje > 1)
                    estadoMensaje = 0;
            }
            if (Panel.getZoneStatus(ZONE_LOWER) && Panel.getZoneStatus(ZONE_UPPER))
                switch (estadoMensaje)
                {
                case 0:
                    Panel.setCharSpacing(0);
                    Panel.setFont(ZONE_UPPER, BigEfectUpper);
                    Panel.setFont(ZONE_LOWER, BigEfectLower);
                    Panel.displayZoneText(ZONE_UPPER, "! P  A  R  E !", PA_CENTER, 300, 300, PA_NO_EFFECT, PA_NO_EFFECT);
                    Panel.displayZoneText(ZONE_LOWER, "! P  A  R  E !", PA_CENTER, 300, 300, PA_NO_EFFECT, PA_NO_EFFECT);
                    break;
                case 1:
                    Panel.setCharSpacing(0);
                    Panel.setFont(ZONE_UPPER, BigEfectUpper);
                    Panel.setFont(ZONE_LOWER, BigEfectLower);
                    Panel.displayZoneText(ZONE_UPPER, "P  A  R  E", PA_CENTER, 300, 300, PA_NO_EFFECT, PA_NO_EFFECT);
                    Panel.displayZoneText(ZONE_LOWER, "P  A  R  E", PA_CENTER, 300, 300, PA_NO_EFFECT, PA_NO_EFFECT);
                    break;
                }
            break;
        case Sigame:
            if (Panel.displayAnimate())
            {
                estadoMensaje++;
                //delay(50);
                if (estadoMensaje > 1)
                    estadoMensaje = 0;
            }
            if (Panel.getZoneStatus(ZONE_LOWER) && Panel.getZoneStatus(ZONE_UPPER))
                switch (estadoMensaje)
                {
                case 0:
                    Panel.setCharSpacing(0);
                    Panel.setFont(ZONE_UPPER, BigEfectUpper);
                    Panel.setFont(ZONE_LOWER, BigEfectLower);
                    Panel.displayZoneText(ZONE_UPPER, "# S  I  G  A  M  E #", PA_CENTER, 300, 300, PA_NO_EFFECT, PA_NO_EFFECT);
                    Panel.displayZoneText(ZONE_LOWER, "# S  I  G  A  M  E #", PA_CENTER, 300, 300, PA_NO_EFFECT, PA_NO_EFFECT);
                    break;
                case 1:
                    Panel.setCharSpacing(0);
                    Panel.setFont(ZONE_UPPER, BigEfectUpper);
                    Panel.setFont(ZONE_LOWER, BigEfectLower);
                    Panel.displayZoneText(ZONE_UPPER, "S  I  G  A  M  E", PA_CENTER, 300, 300, PA_NO_EFFECT, PA_NO_EFFECT);
                    Panel.displayZoneText(ZONE_LOWER, "S  I  G  A  M  E", PA_CENTER, 300, 300, PA_NO_EFFECT, PA_NO_EFFECT);
                    break;
                }
            break;
        case Peligro:
            if (Panel.displayAnimate())
            {
                estadoMensaje++;
                //delay(50);
                if (estadoMensaje > 1)
                    estadoMensaje = 0;
            }
            if (Panel.getZoneStatus(ZONE_LOWER) && Panel.getZoneStatus(ZONE_UPPER))
                switch (estadoMensaje)
                {
                case 0:
                    Panel.setCharSpacing(0);
                    Panel.setFont(ZONE_UPPER, BigEfectUpper);
                    Panel.setFont(ZONE_LOWER, BigEfectLower);
                    Panel.displayZoneText(ZONE_UPPER, "$   $   $   $", PA_CENTER, 300, 300, PA_NO_EFFECT, PA_NO_EFFECT);
                    Panel.displayZoneText(ZONE_LOWER, "$   $   $   $", PA_CENTER, 300, 300, PA_NO_EFFECT, PA_NO_EFFECT);
                    break;
                case 1:
                    Panel.setCharSpacing(0);
                    Panel.setFont(ZONE_UPPER, BigEfectUpper);
                    Panel.setFont(ZONE_LOWER, BigEfectLower);
                    Panel.displayZoneText(ZONE_UPPER, "P E L I G R O", PA_CENTER, 300, 300, PA_NO_EFFECT, PA_NO_EFFECT);
                    Panel.displayZoneText(ZONE_LOWER, "P E L I G R O", PA_CENTER, 300, 300, PA_NO_EFFECT, PA_NO_EFFECT);
                    break;
                }
            break;
        case MantengaseEnSuCarril:
            if (Panel.displayAnimate())
            {
                // estadoMensaje++;
                // if (estadoMensaje > 0)
                estadoMensaje = 0;
            }
            if (Panel.getZoneStatus(ZONE_LOWER) && Panel.getZoneStatus(ZONE_UPPER))
            {
                Panel.setCharSpacing(1);
                Panel.setFont(ZONE_UPPER, NULL);
                Panel.setFont(ZONE_LOWER, NULL);
                Panel.displayZoneText(ZONE_UPPER, "MANTENGASE EN", PA_CENTER, 300, 300, PA_NO_EFFECT, PA_NO_EFFECT);
                Panel.displayZoneText(ZONE_LOWER, "SU CARRIL", PA_CENTER, 300, 300, PA_NO_EFFECT, PA_NO_EFFECT);
            }
            break;
        case ControlAlcohol:
            if (Panel.displayAnimate())
            {
                // estadoMensaje++;
                // if (estadoMensaje > 0)
                estadoMensaje = 0;
            }
            if (Panel.getZoneStatus(ZONE_LOWER) && Panel.getZoneStatus(ZONE_UPPER))
            {
                Panel.setCharSpacing(1);
                Panel.setFont(ZONE_UPPER, NULL);
                Panel.setFont(ZONE_LOWER, NULL);
                Panel.displayZoneText(ZONE_UPPER, "CONTROL DE", PA_CENTER, 300, 300, PA_NO_EFFECT, PA_NO_EFFECT);
                Panel.displayZoneText(ZONE_LOWER, "ALCOHOLEMIA", PA_CENTER, 300, 300, PA_NO_EFFECT, PA_NO_EFFECT);
            }
            break;
        case ConduzcaResponsoblemente:
            if (Panel.displayAnimate())
            {
                // estadoMensaje++;
                // if (estadoMensaje > 0)
                estadoMensaje = 0;
            }
            if (Panel.getZoneStatus(ZONE_LOWER) && Panel.getZoneStatus(ZONE_UPPER))
            {
                Panel.setCharSpacing(1);
                Panel.setFont(ZONE_UPPER, NULL);
                Panel.setFont(ZONE_LOWER, NULL);
                Panel.displayZoneText(ZONE_UPPER, "CONDUZCA CON", PA_CENTER, 300, 300, PA_NO_EFFECT, PA_NO_EFFECT);
                Panel.displayZoneText(ZONE_LOWER, "PRECAUCION", PA_CENTER, 300, 300, PA_NO_EFFECT, PA_NO_EFFECT);
            }
            break;
        case DespejeCalzada:
            if (Panel.displayAnimate())
            {
                // estadoMensaje++;
                // if (estadoMensaje > 0)
                estadoMensaje = 0;
            }
            if (Panel.getZoneStatus(ZONE_LOWER) && Panel.getZoneStatus(ZONE_UPPER))
            {
                Panel.setCharSpacing(1);
                Panel.setFont(ZONE_UPPER, NULL);
                Panel.setFont(ZONE_LOWER, NULL);
                Panel.displayZoneText(ZONE_UPPER, "DESPEJE LA", PA_CENTER, 300, 300, PA_NO_EFFECT, PA_NO_EFFECT);
                Panel.displayZoneText(ZONE_LOWER, "CALZADA", PA_CENTER, 300, 300, PA_NO_EFFECT, PA_NO_EFFECT);
            }
            break;
        default:
            Panel.displayClear();
            break;
        }
        break;
    case MenuEfectosDinamicos:
        switch (efectoDinamicoPredeterminadoPanel)
        {
        case DesvioEfectosIzquierda:
            Panel.displayAnimate();
            if (Panel.getZoneStatus(ZONE_LOWER) && Panel.getZoneStatus(ZONE_UPPER))
            {
                Panel.setCharSpacing(0);
                Panel.setFont(ZONE_LOWER, EfectosLower);
                Panel.setFont(ZONE_UPPER, EfectosUpper);
                Panel.displayZoneText(ZONE_UPPER, "q  q  q  q  q  q  q  q  q", PA_CENTER, 10, 10, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
                Panel.displayZoneText(ZONE_LOWER, "q  q  q  q  q  q  q  q  q", PA_CENTER, 10, 10, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
                // Serial.println("Frlag2");
            }
            break;
        case DesvioEfectosDerecha:
            Panel.displayAnimate();
            if (Panel.getZoneStatus(ZONE_LOWER) && Panel.getZoneStatus(ZONE_UPPER))
            {
                Panel.setCharSpacing(0);
                Panel.setFont(ZONE_LOWER, EfectosLower);
                Panel.setFont(ZONE_UPPER, EfectosUpper);
                Panel.displayZoneText(ZONE_UPPER, "r  r  r  r  r  r  r  r  r", PA_CENTER, 10, 10, PA_SCROLL_RIGHT, PA_SCROLL_RIGHT);
                Panel.displayZoneText(ZONE_LOWER, "r  r  r  r  r  r  r  r  r", PA_CENTER, 10, 10, PA_SCROLL_RIGHT, PA_SCROLL_RIGHT);
            }
            break;
        case MedioAExtremos:
            Panel.displayAnimate();
            if (Panel.getZoneStatus(ZONE_LOWER) && Panel.getZoneStatus(ZONE_UPPER))
            {
                Panel.setCharSpacing(0);
                Panel.setFont(ZONE_LOWER, EfectosLower);
                Panel.setFont(ZONE_UPPER, EfectosUpper);
                Panel.displayZoneText(ZONE_UPPER, "!!!!!!!!!!", PA_CENTER, 30, 10, PA_OPENING, PA_CLOSING);
                Panel.displayZoneText(ZONE_LOWER, "!!!!!!!!!!", PA_CENTER, 30, 10, PA_OPENING, PA_CLOSING);
            }
            break;
        case ExtremosAMedio:
            Panel.displayAnimate();
            if (Panel.getZoneStatus(ZONE_LOWER) && Panel.getZoneStatus(ZONE_UPPER))
            {
                Panel.setCharSpacing(0);
                Panel.setFont(ZONE_LOWER, EfectosLower);
                Panel.setFont(ZONE_UPPER, EfectosUpper);
                Panel.displayZoneText(ZONE_UPPER, "!!!!!!!!!!", PA_CENTER, 30, 10, PA_CLOSING, PA_OPENING);
                Panel.displayZoneText(ZONE_LOWER, "!!!!!!!!!!", PA_CENTER, 30, 10, PA_CLOSING, PA_OPENING);
            }
            break;
        case ParpadeoMitad:
            if (Panel.displayAnimate())
            {
                estadoMensaje++;
                //delay(50);
                if (estadoMensaje > 1)
                    estadoMensaje = 0;
            }
            if (Panel.getZoneStatus(ZONE_LOWER) && Panel.getZoneStatus(ZONE_UPPER))
            {
                switch (estadoMensaje)
                {
                case 0:
                    Panel.setCharSpacing(0);
                    Panel.setFont(ZONE_LOWER, EfectosLower);
                    Panel.setFont(ZONE_UPPER, EfectosUpper);
                    Panel.displayZoneText(ZONE_UPPER, "!!!!!", PA_RIGHT, 250, 250, PA_PRINT, PA_NO_EFFECT);
                    Panel.displayZoneText(ZONE_LOWER, "!!!!!", PA_RIGHT, 250, 250, PA_PRINT, PA_NO_EFFECT);
                    break;
                case 1:
                    Panel.setCharSpacing(0);
                    Panel.setFont(ZONE_LOWER, EfectosLower);
                    Panel.setFont(ZONE_UPPER, EfectosUpper);
                    Panel.displayZoneText(ZONE_UPPER, "!!!!!", PA_LEFT, 250, 250, PA_PRINT, PA_NO_EFFECT);
                    Panel.displayZoneText(ZONE_LOWER, "!!!!!", PA_LEFT, 250, 250, PA_PRINT, PA_NO_EFFECT);
                    break;
                }
            }
            break;
        case ParpadeoAlterno:
            if (Panel.displayAnimate())
            {
                estadoMensaje++;
                //delay(50);
                if (estadoMensaje > 1)
                    estadoMensaje = 0;
            }
            if (Panel.getZoneStatus(ZONE_LOWER) && Panel.getZoneStatus(ZONE_UPPER))
            {
                switch (estadoMensaje)
                {
                case 0:
                    Panel.setCharSpacing(0);
                    Panel.setFont(ZONE_LOWER, EfectosLower);
                    Panel.setFont(ZONE_UPPER, EfectosUpper);
                    Panel.displayZoneText(ZONE_UPPER, "!        !        !        !        !        ", PA_RIGHT, 250, 250, PA_PRINT, PA_NO_EFFECT);
                    Panel.displayZoneText(ZONE_LOWER, "!        !        !        !        !        ", PA_RIGHT, 250, 250, PA_PRINT, PA_NO_EFFECT);
                    break;
                case 1:
                    Panel.setCharSpacing(0);
                    Panel.setFont(ZONE_LOWER, EfectosLower);
                    Panel.setFont(ZONE_UPPER, EfectosUpper);
                    Panel.displayZoneText(ZONE_UPPER, "        !        !        !        !        !", PA_RIGHT, 250, 250, PA_PRINT, PA_NO_EFFECT);
                    Panel.displayZoneText(ZONE_LOWER, "        !        !        !        !        !", PA_RIGHT, 250, 250, PA_PRINT, PA_NO_EFFECT);
                    break;
                }
            }
            break;
        case ParpadeoTotal:
            Panel.displayAnimate();
            if (Panel.getZoneStatus(ZONE_LOWER) && Panel.getZoneStatus(ZONE_UPPER))
            {
                Panel.setCharSpacing(0);
                Panel.setFont(ZONE_LOWER, EfectosLower);
                Panel.setFont(ZONE_UPPER, EfectosUpper);
                Panel.displayZoneText(ZONE_UPPER, "!!!!!!!!!!", PA_CENTER, 250, 250, PA_PRINT, PA_PRINT);
                Panel.displayZoneText(ZONE_LOWER, "!!!!!!!!!!", PA_CENTER, 250, 250, PA_PRINT, PA_PRINT);
            }
            break;
        case ParpadeosDosADos:
            if (Panel.displayAnimate())
            {
                estadoMensaje++;
                //delay(50);
                if (estadoMensaje > 1)
                    estadoMensaje = 0;
            }
            if (Panel.getZoneStatus(ZONE_LOWER) && Panel.getZoneStatus(ZONE_UPPER))
            {
                switch (estadoMensaje)
                {
                case 0:
                    Panel.setCharSpacing(0);
                    Panel.setFont(ZONE_LOWER, EfectosLower);
                    Panel.setFont(ZONE_UPPER, EfectosUpper);
                    Panel.displayZoneText(ZONE_UPPER, "!!                !!                !!                !!", PA_RIGHT, 250, 250, PA_PRINT, PA_NO_EFFECT);
                    Panel.displayZoneText(ZONE_LOWER, "!!                !!                !!                !!", PA_RIGHT, 250, 250, PA_PRINT, PA_NO_EFFECT);
                    break;
                case 1:
                    Panel.setCharSpacing(0);
                    Panel.setFont(ZONE_LOWER, EfectosLower);
                    Panel.setFont(ZONE_UPPER, EfectosUpper);
                    Panel.displayZoneText(ZONE_UPPER, "                !!                !!                !!                ", PA_RIGHT, 250, 250, PA_PRINT, PA_NO_EFFECT);
                    Panel.displayZoneText(ZONE_LOWER, "                !!                !!                !!                ", PA_RIGHT, 250, 250, PA_PRINT, PA_NO_EFFECT);
                    break;
                }
            }
            break;
        }
        break;
    case MenuMensajePersonalizadoDosFilas:
        Panel.displayAnimate();
        if (Panel.getZoneStatus(ZONE_LOWER) && Panel.getZoneStatus(ZONE_UPPER))
        {
            Panel.setCharSpacing(2);
            Panel.setFont(ZONE_LOWER, NULL);
            Panel.setFont(ZONE_UPPER, NULL);
            Panel.displayZoneText(ZONE_UPPER, textoFilaSuperior, PA_CENTER, GetVelocidad(velocidadMSGPersonalizadoSuperior), GetPausa(velocidadMSGPersonalizadoSuperior), GetEfecto(efectoPersonalizadoSuperior), GetEfecto(efectoPersonalizadoSuperior));
            Panel.displayZoneText(ZONE_LOWER, textoFilaInferior, PA_CENTER, GetVelocidad(velocidadMSGPersonalizadoInferior), GetPausa(velocidadMSGPersonalizadoInferior), GetEfecto(efectoPersonalizadoInferior), GetEfecto(efectoPersonalizadoInferior));
        }
        break;
        break;
    case MenuMensajePersonalizadoUnaFila:
        Panel.displayAnimate();
        if (Panel.getZoneStatus(ZONE_LOWER) && Panel.getZoneStatus(ZONE_UPPER))
        {
            Panel.setCharSpacing(2);
            Panel.setFont(ZONE_LOWER, BigFontLower);
            Panel.setFont(ZONE_UPPER, BigFontUpper);
            Panel.displayZoneText(ZONE_UPPER, textoUnaFila, PA_CENTER, GetVelocidad(velocidadMSGPersonalizado), GetPausa(velocidadMSGPersonalizado), GetEfecto(efectoPersonalizado), GetEfecto(efectoPersonalizado));
            Panel.displayZoneText(ZONE_LOWER, textoUnaFila, PA_CENTER, GetVelocidad(velocidadMSGPersonalizado), GetPausa(velocidadMSGPersonalizado), GetEfecto(efectoPersonalizado), GetEfecto(efectoPersonalizado));
        }
        break;
    default:
        Panel.displayClear();
        Panel.displayZoneText(ZONE_UPPER, "", PA_CENTER, 100, 100, PA_NO_EFFECT, PA_NO_EFFECT);
        Panel.displayZoneText(ZONE_LOWER, "", PA_CENTER, 100, 100, PA_NO_EFFECT, PA_NO_EFFECT);
        break;
    }
}

//! **********************************************************************************************************
//!                                       GETTERS
//! **********************************************************************************************************
textEffect_t PanelLED::GetEfecto(int numero)
{
    const textEffect_t efectos[] = {
        PA_NO_EFFECT,    ///< Used as a place filler, executes no operation
        PA_PRINT,        ///< Text just appears (printed)
        PA_SCROLL_UP,    ///< Text scrolls up through the display
        PA_SCROLL_DOWN,  ///< Text scrolls down through the display
        PA_SCROLL_LEFT,  ///< Text scrolls right to left on the display
        PA_SCROLL_RIGHT, ///< Text scrolls left to right on the display
#if ENA_SPRITE
        PA_SPRITE, ///< Text enters and exits using user defined sprite
#endif
#if ENA_MISC
        PA_SLICE,    ///< Text enters and exits a slice (column) at a time from the right
        PA_MESH,     ///< Text enters and exits in columns moving in alternate direction (U/D)
        PA_FADE,     ///< Text enters and exits by fading from/to 0 and intensity setting
        PA_DISSOLVE, ///< Text dissolves from one display to another
        PA_BLINDS,   ///< Text is replaced behind vertical blinds
        PA_RANDOM,   ///< Text enters and exits as random dots
#endif               // ENA_MISC
#if ENA_WIPE
        PA_WIPE,        ///< Text appears/disappears one column at a time, looks like it is wiped on and off
        PA_WIPE_CURSOR, ///< WIPE with a light bar ahead of the change
#endif                  // ENA_WIPES
#if ENA_SCAN
        PA_SCAN_HORIZ,  ///< Scan the LED column one at a time then appears/disappear at end
        PA_SCAN_HORIZX, ///< Scan a blank column through the text one column at a time then appears/disappear at end
        PA_SCAN_VERT,   ///< Scan the LED row one at a time then appears/disappear at end
        PA_SCAN_VERTX,  ///< Scan a blank row through the text one row at a time then appears/disappear at end
#endif                  // ENA_SCAN
#if ENA_OPNCLS
        PA_OPENING,        ///< Appear and disappear from the center of the display, towards the ends
        PA_OPENING_CURSOR, ///< OPENING with light bars ahead of the change
        PA_CLOSING,        ///< Appear and disappear from the ends of the display, towards the middle
        PA_CLOSING_CURSOR, ///< CLOSING with light bars ahead of the change
#endif                     // ENA_OPNCLS
#if ENA_SCR_DIA
        PA_SCROLL_UP_LEFT,    ///< Text moves in/out in a diagonal path up and left (North East)
        PA_SCROLL_UP_RIGHT,   ///< Text moves in/out in a diagonal path up and right (North West)
        PA_SCROLL_DOWN_LEFT,  ///< Text moves in/out in a diagonal path down and left (South East)
        PA_SCROLL_DOWN_RIGHT, ///< Text moves in/out in a diagonal path down and right (North West)
#endif                        // ENA_SCR_DIA
#if ENA_GROW
        PA_GROW_UP,   ///< Text grows from the bottom up and shrinks from the top down
        PA_GROW_DOWN, ///< Text grows from the top down and and shrinks from the bottom up
#endif                // ENA_GROW
    };

    // Asegurarse de que el número esté dentro del rango de efectos disponibles
    if (numero >= 0 && numero < sizeof(efectos) / sizeof(efectos[0]))
    {
        // Serial.println(String(efectos[numero]));
        return efectos[numero];
    }
    else
    {
        return PA_NO_EFFECT; // Efecto predeterminado si el número está fuera de rango
    }
}

int PanelLED::GetVelocidad(int vel)
{
    switch (GetEfecto(efectoPersonalizado))
    {
    //! MUY LENTOS
    case PA_DISSOLVE:
        return 40000 / vel;

    //! LENTOS
    case PA_MESH:
    case PA_FADE:
    case PA_BLINDS:
    case PA_SCAN_VERT:
    case PA_SCAN_VERTX:
        return 20000 / vel;

    //! RAPIDOS
    case PA_PRINT:
    case PA_RANDOM:
    case PA_WIPE:
    case PA_WIPE_CURSOR:
    case PA_SCAN_HORIZ:
    case PA_SCAN_HORIZX:
    case PA_SCROLL_UP_LEFT:
    case PA_SCROLL_UP_RIGHT:
    case PA_SCROLL_DOWN_LEFT:
    case PA_SCROLL_DOWN_RIGHT:
    case PA_GROW_DOWN:
    case PA_GROW_UP:
        return 10000 / vel;

    //! MUY RAPIDOS
    case PA_SCROLL_LEFT:
    case PA_SCROLL_RIGHT:
    case PA_SLICE:
    case PA_OPENING:
    case PA_OPENING_CURSOR:
    case PA_CLOSING:
    case PA_CLOSING_CURSOR:
        return 10000 / (2 * vel);
    default:
        return 10000 / vel;
    }
}

int PanelLED::GetPausa(int vel)
{
    switch (GetEfecto(efectoPersonalizado))
    {
    //! MUY LENTOS
    case PA_SLICE:
    case PA_SCAN_VERT:
    case PA_SCAN_VERTX:
    case PA_PRINT:
    case PA_MESH:
    case PA_FADE:
    case PA_DISSOLVE:
    case PA_BLINDS:
    case PA_SCAN_HORIZ:
    case PA_SCAN_HORIZX:
    case PA_SCROLL_DOWN_RIGHT:
    case PA_SCROLL_DOWN_LEFT:
    case PA_SCROLL_UP_RIGHT:
    case PA_SCROLL_UP_LEFT:
        return 200000 / vel;

        //! LENTOS
    case PA_SCROLL_UP:
    case PA_SCROLL_DOWN:
    case PA_RANDOM:
    case PA_WIPE:
    case PA_WIPE_CURSOR:
    case PA_OPENING:
    case PA_OPENING_CURSOR:
    case PA_CLOSING:
    case PA_CLOSING_CURSOR:
    case PA_GROW_DOWN:
    case PA_GROW_UP:
        return 100000 / vel;
    //! NULO
    case PA_SCROLL_LEFT:
    case PA_SCROLL_RIGHT:
        return 1;
    default:
        return 100;
    }
}


//! **********************************************************************************************************
//!                                       OTRAS FUNCIONES
//! **********************************************************************************************************
void PanelLED::Inclinar()
{
    if (inclinacion!=inclinacionAnterior){
        if (millis()>tiempoInclinacionAnterior+20){
            if (inclinacionAnterior>inclinacion)servo.write(inclinacionAnterior-=1);
            else servo.write(inclinacionAnterior+=1);
            tiempoInclinacionAnterior=millis();
            valorInclinacionGuardado=false;
        }
    }
    else if(valorInclinacionGuardado==false){
        memoria.putInt("Inclinacion",inclinacion);
        Serial.println("valor guardado en eeprom");
        valorInclinacionGuardado=true;
    }
}


void PanelLED::IluminacionAutomatica(){
    iluminacionExterior = analogRead(LDR_PIN);
    //Serial.println(">Iluminacion Automatica: " + String(iluminacionExterior));
    //Serial.println(">Iluminacion mapeada: " + String(map(iluminacionExterior,0,4000,1,10)));
    if (iluminacionAutomatica)
    {
        SetBrillo(map(iluminacionExterior,0,4000,1,10));
    }

}