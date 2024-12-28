#ifndef BLUETOOTHMANAGER_h
#define BLUETOOTHMANAGER_h

#include "BluetoothSerial.h"
#include "PanelLED.h"
// #define USE_PIN
const char *pin = "1234";

String device_name = "Panel Emergencia";
extern PanelLED PanelEmergencia;
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Bluetooth not available or not enabled. It is only available for the ESP32 chip.
#endif

BluetoothSerial SerialBT;
String comandoRecivido = "";
short int indiceComando = 0;
String estadoBT = "", subEstadoBT = "";

void SetupBluetooth()
{
    SerialBT.begin(device_name); // Bluetooth device name
    Serial.printf("El dispositivo \"%s\" Ha iniciado. Se puede iniciar la comunicación Bluetooth!\n", device_name.c_str());
#ifdef USE_PIN
    SerialBT.setPin(pin);
    Serial.println("Using PIN");
#endif
}

void ProcesarComandoBT(String comandoRecivido)
{
    // Aquí procesas el comando según tus necesidades
    Serial.print("Comando recibido: ");
    Serial.println(comandoRecivido);
    if (indiceComando == 0)
    {
        estadoBT = comandoRecivido;
        indiceComando = 1;
    }
    else
    {
        subEstadoBT = comandoRecivido;
        indiceComando = 0;
        Serial.println("El primer comando es: " + estadoBT + " y el segundo: " + subEstadoBT);
        Serial.println(subEstadoBT.toInt());
        if (estadoBT == "TEXTO PREDETERMINADO")
        {
            PanelEmergencia.SetMenuActual(PanelEmergencia.MenuMensajeTexto);
            PanelEmergencia.SetTextoPredeterminado(subEstadoBT.toInt());
        }
        else if (estadoBT == "EFECTO PREDETERMINADO")
        {
            PanelEmergencia.SetMenuActual(PanelEmergencia.MenuEfectosDinamicos);
            PanelEmergencia.SetEfectoDinamicoPredeterminado(subEstadoBT.toInt());
        }
        else if (estadoBT == "TEXTO UNA FILA")
        {
            PanelEmergencia.SetMenuActual(PanelEmergencia.MenuMensajePersonalizadoUnaFila);
            PanelEmergencia.SetTextoUnaFila(const_cast<char *>(subEstadoBT.c_str()));
        }
        else if (estadoBT == "VELOCIDAD UNA FILA")
        {
            PanelEmergencia.SetMenuActual(PanelEmergencia.MenuMensajePersonalizadoUnaFila);
            PanelEmergencia.SetVelocidadMSGPersonalizado(subEstadoBT.toInt());
        }
        else if (estadoBT == "EFECTO UNA FILA")
        {
            PanelEmergencia.SetMenuActual(PanelEmergencia.MenuMensajePersonalizadoUnaFila);
            PanelEmergencia.SetEfectoPersonalizado(subEstadoBT.toInt());
        }
        else if (estadoBT == "TEXTO FILA SUPERIOR")
        {
            PanelEmergencia.SetMenuActual(PanelEmergencia.MenuMensajePersonalizadoDosFilas);
            PanelEmergencia.SetTextoFilaSuperior(const_cast<char *>(subEstadoBT.c_str()));
        }
        else if (estadoBT == "VELOCIDAD FILA SUPERIOR")
        {
            PanelEmergencia.SetMenuActual(PanelEmergencia.MenuMensajePersonalizadoDosFilas);
            PanelEmergencia.SetVelocidadMSGPersonalizadoSuperior(subEstadoBT.toInt());
        }
        else if (estadoBT == "EFECTO FILA SUPERIOR")
        {
            PanelEmergencia.SetMenuActual(PanelEmergencia.MenuMensajePersonalizadoDosFilas);
            PanelEmergencia.SetEfectoPersonalizadoSuperior(subEstadoBT.toInt());
        }
        else if (estadoBT == "TEXTO FILA INFERIOR")
        {
            PanelEmergencia.SetMenuActual(PanelEmergencia.MenuMensajePersonalizadoDosFilas);
            PanelEmergencia.SetTextoFilaInferior(const_cast<char *>(subEstadoBT.c_str()));
        }
        else if (estadoBT == "VELOCIDAD FILA INFERIOR")
        {
            PanelEmergencia.SetMenuActual(PanelEmergencia.MenuMensajePersonalizadoDosFilas);
            PanelEmergencia.SetVelocidadMSGPersonalizadoInferior(subEstadoBT.toInt());
        }
        else if (estadoBT == "EFECTO FILA INFERIOR")
        {
            PanelEmergencia.SetMenuActual(PanelEmergencia.MenuMensajePersonalizadoDosFilas);
            PanelEmergencia.SetEfectoPersonalizadoInferior(subEstadoBT.toInt());
        }
        else if (estadoBT == "INCLINACION")
        {
            PanelEmergencia.SetGrados(subEstadoBT.toInt());
        }
        else if (estadoBT == "BRILLO AUTO")
        {
            if (subEstadoBT == "FALSO")
                PanelEmergencia.SetIluminacionAutomatica(0);
            else if (subEstadoBT == "VERDADERO")
                PanelEmergencia.SetIluminacionAutomatica(1);
        }
        else if (estadoBT == "BRILLO")
        {
            PanelEmergencia.SetBrillo(subEstadoBT.toInt());
        }
        else if (estadoBT == "APAGAR")
        {
            PanelEmergencia.SetMenuActual(100);
        }
        else if (estadoBT == "SOLICITA DATOS INCLINACION")
            SerialBT.println("INCLINACION:" + String((PanelEmergencia.GetGrados()) / 360.0));
        else if (estadoBT == "SOLICITA DATOS BRILLO")
        {
            String mensaje = "DATOS BRILLO:" + String(PanelEmergencia.GetBrillo()) +
                             "|ILUM_EXTERIOR:" + String(map(PanelEmergencia.GetIluminacionExterior(),0,4095,1,10)) +
                             "|BRILLO_AUTO:" + String(PanelEmergencia.GetBrilloAuto());
            SerialBT.println(mensaje);
        }
        else if (estadoBT == "MENSAJE UNA FILA") SerialBT.println("TEXTO UNA FILA:" + PanelEmergencia.GetTextoUnaFila());
        else if (estadoBT == "MENSAJE DOS FILAS") SerialBT.println("TEXTO SUPERIOR:" + PanelEmergencia.GetTextoFilaSuperior() + "," + PanelEmergencia.GetTextoFilaInferior());
        else
        {
            Serial.println("MENSAJE NO COINCIDE CON EL PROTOCOLO");
            indiceComando = 0;
            comandoRecivido = "";
        }
    }
}

void RunBluetooth()
{
    if (Serial.available())
    {
        SerialBT.write(Serial.read());
    }
    if (SerialBT.available())
    {
        char charRecivido = SerialBT.read();
        if (charRecivido == '#')
        {
            // Fin del mensaje, procesar el comando recibido
            ProcesarComandoBT(comandoRecivido);
            comandoRecivido = ""; // Reiniciar el buffer para el próximo mensaje
        }
        else
        {
            comandoRecivido += charRecivido;
        }
    }
    delay(20);
}

#endif