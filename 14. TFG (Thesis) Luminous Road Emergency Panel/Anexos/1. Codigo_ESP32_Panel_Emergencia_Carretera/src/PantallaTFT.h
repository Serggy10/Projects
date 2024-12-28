#ifndef PANTALLATFT_H
#define PANTALLATFT_h
//! ***********************************************************************************************************
//!
//!                                   DEFINICIONES DE LA PANTALLA TFT
//!
//! ***********************************************************************************************************
#include "FS.h"
#include <TFT_eSPI.h>
#include "Pinout.h"
#include "PantallaTFT/PantallaTFT_configs.h"
// #include "PantallaTFT/XRingGauge.h"
TFT_eSPI tft = TFT_eSPI();
extern PanelLED PanelEmergencia;

#define CALIBRATION_FILE "/TouchCalData1" // Fichero donde se guardan los archivos de calibración.

bool REPEAT_CAL = false; // Si se desea repetir la calibración se debe cambiar a true.
//! **********************************************************************************************************
//!
//!                                   FUNCIONES DE LA PANTALLA TFT
//!
//! **********************************************************************************************************

void CalibrarPantalla()
{
  uint16_t calData[5];
  uint8_t calDataOK = 0;

  if (!SPIFFS.begin()) // Comprobación de la existencia del sistema de ficheros. Si no existe se formatea la memoria SPIFFS.
  {
    Serial.println("Formatting file system");
    SPIFFS.format();
    SPIFFS.begin();
  }

  if (SPIFFS.exists(CALIBRATION_FILE)) // Comprobación de la existencia del fichero de calibración. Si existe se puede sobreescribir si se desea.
  {
    if (REPEAT_CAL)
    {
      // Delete if we want to re-calibrate
      SPIFFS.remove(CALIBRATION_FILE);
    }
    else
    {
      fs::File f = SPIFFS.open(CALIBRATION_FILE, "r");
      if (f)
      {
        if (f.readBytes((char *)calData, 14) == 14)
          calDataOK = 1;
        f.close();
      }
    }
  }

  if (calDataOK && !REPEAT_CAL) // Si los datos son correctos y no se desea repetir la calibración se cargan los datos en la patalla TFT.
  {
    tft.setTouch(calData);
  }
  else // Si no se empieza de nuevo la calibración.
  {
    tft.fillScreen(TFT_BLACK);
    tft.setCursor(20, 0);
    tft.setTextFont(2);
    tft.setTextSize(1);
    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.println("Toque las esquinas indicadas");
    tft.setTextFont(1);
    tft.println();

    if (REPEAT_CAL)
    {
      tft.setTextColor(TFT_RED, TFT_BLACK);
    }
    //
    tft.calibrateTouch(calData, TFT_MAGENTA, TFT_BLACK, 15); // Función para calibrar la pantalla.
    gslc_SetTouchRemapCal(&m_gui, calData[0], calData[1], calData[2], calData[3]);

    Serial.println(calData[0]);
    Serial.println(calData[1]);
    Serial.println(calData[2]);
    Serial.println(calData[3]);
    Serial.println(calData[4]);

    tft.setTextColor(TFT_GREEN, TFT_BLACK);
    tft.println("Calibración completada!");

    fs::File f = SPIFFS.open(CALIBRATION_FILE, "w"); // Se guardan los datos en la memoria SPIFFS.
    if (f)
    {
      f.write((const unsigned char *)calData, 14);
      f.close();
    }
  }
}

//! *************************
//!  Globales del programa:
//! *************************
// * Referencias para acceso directo:
gslc_tsElemRef *ArcoInclinacion = NULL;
gslc_tsElemRef *BarraIluminacionPantalla = NULL;
gslc_tsElemRef *BarraIluminacionPersonalizadaPanel = NULL;
gslc_tsElemRef *BarraInclinacion = NULL;
gslc_tsElemRef *BarraListaEfectos = NULL;
gslc_tsElemRef *BarraListaEfectosInferior = NULL;
gslc_tsElemRef *BarraListaEfectosSuperior = NULL;
gslc_tsElemRef *BarraMensajesDinamicos = NULL;
gslc_tsElemRef *BarraMensajesTexto = NULL;
gslc_tsElemRef *BarraVelocidadInferior = NULL;
gslc_tsElemRef *BarraVelocidadPersonalizada = NULL;
gslc_tsElemRef *BarraVelocidadSuperior = NULL;
gslc_tsElemRef *BotonAutoIluminacionPanel = NULL;
gslc_tsElemRef *CirculoLogo = NULL;
gslc_tsElemRef *EntradaTextoInferior = NULL;
gslc_tsElemRef *EntradaTextoSuperior = NULL;
gslc_tsElemRef *ListaEfectos = NULL;
gslc_tsElemRef *ListaEfectosInferior = NULL;
gslc_tsElemRef *ListaEfectosSuperior = NULL;
gslc_tsElemRef *ListaMensajesDinamico = NULL;
gslc_tsElemRef *ListaMensajesTexto = NULL;
gslc_tsElemRef *TextoPersonalizado = NULL;
gslc_tsElemRef *VariableEstadoActual = NULL;
gslc_tsElemRef *VariableTextoLuzAmbiente = NULL;
gslc_tsElemRef *m_pElemKeyPadAlpha = NULL;
gslc_tsElemRef *VariableEstadoInlcinacion = NULL;
//<Save_References !End!>

// Define debug message function
static int16_t DebugOut(char ch)
{
  if (ch == (char)'\n')
    Serial.println("");
  else
    Serial.write(ch);
  return 0;
}

// ------------------------------------------------
// Callback Methods
// ------------------------------------------------
// Common Button callback

bool tocado = 0, pantallaEncendida = 1;
unsigned long int TiempoApagarPantalla = 0;
int iluminacionPantalla;
//*Apagará la pantalla automaticamente tras el tiempo establecido si no se ha tocado la pantalla en ese intervalo. Activará la pantalla si se toca de nuevo
void ApagarPantalla(int16_t nX, int16_t nY, uint16_t nPress, gslc_teInputRawEvent eInputEvent, int16_t nInputVal, uint16_t tiempo)
{
  tocado = gslc_GetTouch(&m_gui, &nX, &nY, &nPress, &eInputEvent, &nInputVal);
  if (tocado)
  {
    TiempoApagarPantalla = millis();
    if (!pantallaEncendida)
    {
      analogWrite(BACKLIGHT_TFT, iluminacionPantalla);
      pantallaEncendida = true;
    }
  }
  else if (millis() > TiempoApagarPantalla + tiempo && pantallaEncendida)
  {
    analogWrite(BACKLIGHT_TFT, 0);
    pantallaEncendida = false;
  }
}

//! *******************************************************************************************************************************************************************
//!                                                                         BOTONES
//! *******************************************************************************************************************************************************************
bool CbBtnCommon(void *pvGui, void *pvElemRef, gslc_teTouch eTouch, int16_t nX, int16_t nY)
{
  gslc_tsGui *pGui = (gslc_tsGui *)(pvGui);
  gslc_tsElemRef *pElemRef = (gslc_tsElemRef *)(pvElemRef);
  gslc_tsElem *pElem = gslc_GetElemFromRef(pGui, pElemRef);
  char textoApagado[MAX_STR] = "APAGADO";
  char luzLeida[MAX_STR];

  if (eTouch == GSLC_TOUCH_UP_IN)
  {
    // From the element's ID we can determine which button was pressed.
    switch (pElem->nId)
    {
      //<Button Enums !Start!>
    case BotonMenuMensajesTexto:
      gslc_SetPageCur(&m_gui, MenuMensajesTexto);
      break;
    case BotonMenuEfectosDinamicos:
      gslc_SetPageCur(&m_gui, MenuEfectosDinamicos);
      break;
    case BotonMenuInclinacionPanel:
      gslc_SetPageCur(&m_gui, MenuInclinacionPanel);
      break;
    case BotonMenuIluminacionPanel:
      pElemRef = gslc_PageFindElemById(pGui, MenuIluminacionPanel, E_VariableTextoLuzAmbiente);
      sprintf(luzLeida, "%d", map(PanelEmergencia.GetIluminacionExterior(), 0, 4095, 1, 10));
      gslc_ElemSetTxtStr(&m_gui, VariableTextoLuzAmbiente, luzLeida);
      gslc_SetPageCur(&m_gui, MenuIluminacionPanel);
      break;
    case BotonMenuAjustes:
      gslc_SetPageCur(&m_gui, MenuAjustes);
      break;
    case BotonMenuMensajePersonalizado:
      gslc_SetPageCur(&m_gui, MenuMensajePersonalizado);
      break;
    case E_BotonApagar:
      // TODO AÑADIR APAGAR PANEL LED
      PanelEmergencia.SetMenuActual(100);
      gslc_ElemSetTxtStr(&m_gui, VariableEstadoActual, textoApagado);
      gslc_ElemSetTxtCol(&m_gui, VariableEstadoActual, GSLC_COL_RED);
      break;
    case BotonVolver1:
      gslc_SetPageCur(&m_gui, E_MenuPrincipal);
      break;
    case BotonVolver2:
      gslc_SetPageCur(&m_gui, E_MenuPrincipal);
      break;
    case BotonVolver3:
      gslc_SetPageCur(&m_gui, E_MenuPrincipal);
      break;
    case BotonHome:
      // TODO AÑADIR HACER HOME
      pElemRef = gslc_PageFindElemById(pGui, MenuInclinacionPanel, E_ArcoInclinacion);
      gslc_ElemXRingGaugeSetVal(pGui, pElemRef, 0);
      pElemRef = gslc_PageFindElemById(pGui, MenuInclinacionPanel, E_BarraInclinacion);
      gslc_ElemXSeekbarSetPos(pGui, pElemRef, 0);
      PanelEmergencia.SetGrados(0);
      gslc_ElemSetTxtCol(&m_gui, VariableEstadoInlcinacion, GSLC_COL_WHITE);
      break;
    case Boton90:
      // TODO AÑADIR MOVER 90º
      pElemRef = gslc_PageFindElemById(pGui, MenuInclinacionPanel, E_ArcoInclinacion);
      gslc_ElemXRingGaugeSetVal(pGui, pElemRef, 90);
      pElemRef = gslc_PageFindElemById(pGui, MenuInclinacionPanel, E_BarraInclinacion);
      gslc_ElemXSeekbarSetPos(pGui, pElemRef, 90);
      PanelEmergencia.SetGrados(90);
      gslc_ElemSetTxtCol(&m_gui, VariableEstadoInlcinacion, GSLC_COL_RED);
      break;
    case Boton45:
      // TODO AÑADIR MOVER 45º
      pElemRef = gslc_PageFindElemById(pGui, MenuInclinacionPanel, E_ArcoInclinacion);
      gslc_ElemXRingGaugeSetVal(pGui, pElemRef, 45);
      pElemRef = gslc_PageFindElemById(pGui, MenuInclinacionPanel, E_BarraInclinacion);
      gslc_ElemXSeekbarSetPos(pGui, pElemRef, 45);
      PanelEmergencia.SetGrados(45);
      gslc_ElemSetTxtCol(&m_gui, VariableEstadoInlcinacion, GSLC_COL_RED);
      break;
    case Boton135:
      // TODO AÑADIR MOVER 135º
      pElemRef = gslc_PageFindElemById(pGui, MenuInclinacionPanel, E_ArcoInclinacion);
      gslc_ElemXRingGaugeSetVal(pGui, pElemRef, 135);
      pElemRef = gslc_PageFindElemById(pGui, MenuInclinacionPanel, E_BarraInclinacion);
      gslc_ElemXSeekbarSetPos(pGui, pElemRef, 135);
      PanelEmergencia.SetGrados(135);
      gslc_ElemSetTxtCol(&m_gui, VariableEstadoInlcinacion, GSLC_COL_RED);
      break;
    case BotonVolver4:
      gslc_SetPageCur(&m_gui, E_MenuPrincipal);
      break;
    case E_BotonCalibrado:
      REPEAT_CAL = true;
      CalibrarPantalla(); // Comprobación de si la pantalla necesita una calibración o no.
      InitGUIslice_gen();
      break;
    case BotonVolver5:
      gslc_SetPageCur(&m_gui, E_MenuPrincipal);
      break;
    case E_TextoPersonalizado:
      // Clicked on edit field, so show popup box and associate with this text field
      gslc_ElemXKeyPadInputAsk(&m_gui, m_pElemKeyPadAlpha, E_POP_KEYPAD_ALPHA, TextoPersonalizado);
      // TODO PROBAR SI SE PUEDE MODIFICAR EL TECLADO
      break;
    case E_BotonDosFilas:
      gslc_SetPageCur(&m_gui, MenuMensajePersonalizadoDos);
      break;
    case BotonVolver6:
      gslc_SetPageCur(&m_gui, E_MenuPrincipal);
      break;
    case E_BotonAutoIluminacionPanel:
      pElemRef = gslc_PageFindElemById(pGui, MenuIluminacionPanel, E_VariableTextoLuzAmbiente);
      sprintf(luzLeida, "%d", map(PanelEmergencia.GetIluminacionExterior(), 0, 4095, 1, 10));
      gslc_ElemSetTxtStr(&m_gui, VariableTextoLuzAmbiente, luzLeida);
      if (gslc_ElemXTogglebtnGetState(&m_gui, BotonAutoIluminacionPanel))
        PanelEmergencia.SetIluminacionAutomatica(true);
      else
      {
        PanelEmergencia.SetIluminacionAutomatica(false);
        pElemRef = gslc_PageFindElemById(pGui, MenuIluminacionPanel, E_BarraIluminacionPersonalizadaPanel);
        PanelEmergencia.SetBrillo(gslc_ElemXSeekbarGetPos(pGui, BarraIluminacionPersonalizadaPanel));
      }
      break;
    case E_EntradaTextoSuperior:
      // Clicked on edit field, so show popup box and associate with this text field
      gslc_ElemXKeyPadInputAsk(&m_gui, m_pElemKeyPadAlpha, E_POP_KEYPAD_ALPHA, EntradaTextoSuperior);
      // TODO PROBAR SI SE PUEDE MODIFICAR EL TECLADO
      break;
    case E_EntradaTextoInferior:
      // Clicked on edit field, so show popup box and associate with this text field
      gslc_ElemXKeyPadInputAsk(&m_gui, m_pElemKeyPadAlpha, E_POP_KEYPAD_ALPHA, EntradaTextoInferior);
      // TODO PROBAR SI SE PUEDE MODIFICAR EL TECLADO
      break;
    case E_BotonVolverUnaFila:
      gslc_SetPageCur(&m_gui, MenuMensajePersonalizado);
      break;
      //<Button Enums !End!>
    default:
      break;
    }
  }
  return true;
}

//! *******************************************************************************************************************************************************************
//!                                                                         TECLADO
//! *******************************************************************************************************************************************************************
bool CbKeypad(void *pvGui, void *pvElemRef, int16_t nState, void *pvData)
{
  gslc_tsGui *pGui = (gslc_tsGui *)pvGui;
  gslc_tsElemRef *pElemRef = (gslc_tsElemRef *)(pvElemRef);
  gslc_tsElem *pElem = gslc_GetElemFromRef(pGui, pElemRef);
  char textoEncendido[MAX_STR] = "ENCENDIDO";
  // From the pvData we can get the ID element that is ready.
  int16_t nTargetElemId = gslc_ElemXKeyPadDataTargetIdGet(pGui, pvData);
  if (nState == XKEYPAD_CB_STATE_DONE)
  {
    // User clicked on Enter to leave popup
    // - If we have a popup active, pass the return value directly to
    //   the corresponding value field
    switch (nTargetElemId)
    {
    case E_EntradaTextoInferior:
      PanelEmergencia.SetTextoFilaInferior(gslc_ElemXKeyPadInputGet(pGui, EntradaTextoInferior, pvData));
      PanelEmergencia.SetMenuActual(PanelEmergencia.MenuMensajePersonalizadoDosFilas);
      // Serial.println(PanelEmergencia.GetTextoFilaInferior());
      gslc_ElemSetTxtStr(&m_gui, VariableEstadoActual, textoEncendido);
      gslc_ElemSetTxtCol(&m_gui, VariableEstadoActual, (gslc_tsColor){63, 255, 51});
      gslc_PopupHide(&m_gui);
      break;
    case E_EntradaTextoSuperior:
      PanelEmergencia.SetTextoFilaSuperior(gslc_ElemXKeyPadInputGet(pGui, EntradaTextoSuperior, pvData));
      PanelEmergencia.SetMenuActual(PanelEmergencia.MenuMensajePersonalizadoDosFilas);
      // Serial.println(PanelEmergencia.GetTextoFilaSuperior());
      gslc_ElemSetTxtStr(&m_gui, VariableEstadoActual, textoEncendido);
      gslc_ElemSetTxtCol(&m_gui, VariableEstadoActual, (gslc_tsColor){63, 255, 51});
      gslc_PopupHide(&m_gui);
      break;
    case E_TextoPersonalizado:
      PanelEmergencia.SetTextoUnaFila(gslc_ElemXKeyPadInputGet(pGui, TextoPersonalizado, pvData));
      PanelEmergencia.SetMenuActual(PanelEmergencia.MenuMensajePersonalizadoUnaFila);
      gslc_ElemSetTxtStr(&m_gui, VariableEstadoActual, textoEncendido);
      gslc_ElemSetTxtCol(&m_gui, VariableEstadoActual, (gslc_tsColor){63, 255, 51});
      gslc_PopupHide(&m_gui);
      break;
    }
  }
  else if (nState == XKEYPAD_CB_STATE_CANCEL)
  {
    // User escaped from popup, so don't update values
    gslc_PopupHide(&m_gui);
  }
  return true;
}

//! *******************************************************************************************************************************************************************
//!                                                                    LISTAS DE OPCIONES
//! *******************************************************************************************************************************************************************
bool CbListbox(void *pvGui, void *pvElemRef, int16_t nSelId)
{
  gslc_tsGui *pGui = (gslc_tsGui *)(pvGui);
  gslc_tsElemRef *pElemRef = (gslc_tsElemRef *)(pvElemRef);
  gslc_tsElem *pElem = gslc_GetElemFromRef(pGui, pElemRef);
  char acTxt[MAX_STR + 1];
  char textoEncendido[MAX_STR] = "ENCENDIDO";
  if (pElemRef == NULL)
  {
    return false;
  }

  // From the element's ID we can determine which listbox was active.
  switch (pElem->nId)
  {
  case E_ListaEfectos:
    if (nSelId != XLISTBOX_SEL_NONE)
    {
      gslc_ElemXListboxGetItem(&m_gui, pElemRef, nSelId, acTxt, MAX_STR);
      PanelEmergencia.SetEfectoPersonalizado(gslc_ElemXListboxGetSel(&m_gui, pElemRef));
      PanelEmergencia.SetMenuActual(PanelEmergencia.MenuMensajePersonalizadoUnaFila);
      gslc_ElemSetTxtStr(&m_gui, VariableEstadoActual, textoEncendido);
      gslc_ElemSetTxtCol(&m_gui, VariableEstadoActual, (gslc_tsColor){63, 255, 51});
    }
    break;
  case E_ListaEfectosSuperior:
    if (nSelId != XLISTBOX_SEL_NONE)
    {
      gslc_ElemXListboxGetItem(&m_gui, pElemRef, nSelId, acTxt, MAX_STR);
      PanelEmergencia.SetEfectoPersonalizadoSuperior(gslc_ElemXListboxGetSel(&m_gui, pElemRef));
      PanelEmergencia.SetMenuActual(PanelEmergencia.MenuMensajePersonalizadoDosFilas);
      gslc_ElemSetTxtStr(&m_gui, VariableEstadoActual, textoEncendido);
      gslc_ElemSetTxtCol(&m_gui, VariableEstadoActual, (gslc_tsColor){63, 255, 51});
    }
    break;
  case E_ListaEfectosInferior:
    if (nSelId != XLISTBOX_SEL_NONE)
    {
      gslc_ElemXListboxGetItem(&m_gui, pElemRef, nSelId, acTxt, MAX_STR);
      PanelEmergencia.SetEfectoPersonalizadoInferior(gslc_ElemXListboxGetSel(&m_gui, pElemRef));
      PanelEmergencia.SetMenuActual(PanelEmergencia.MenuMensajePersonalizadoDosFilas);
      gslc_ElemSetTxtStr(&m_gui, VariableEstadoActual, textoEncendido);
      gslc_ElemSetTxtCol(&m_gui, VariableEstadoActual, (gslc_tsColor){63, 255, 51});
    }
    break;
  case E_ListaMensajesTexto:
    if (nSelId != XLISTBOX_SEL_NONE)
    {
      gslc_ElemXListboxGetItem(&m_gui, pElemRef, nSelId, acTxt, MAX_STR);
      PanelEmergencia.SetTextoPredeterminado(gslc_ElemXListboxGetSel(&m_gui, pElemRef));
      PanelEmergencia.SetMenuActual(PanelEmergencia.MenuMensajeTexto);
      gslc_ElemSetTxtStr(&m_gui, VariableEstadoActual, textoEncendido);
      gslc_ElemSetTxtCol(&m_gui, VariableEstadoActual, (gslc_tsColor){63, 255, 51});
    }
    break;
  case E_ListaMensajesDinamicos:
    if (nSelId != XLISTBOX_SEL_NONE)
    {
      gslc_ElemXListboxGetItem(&m_gui, pElemRef, nSelId, acTxt, MAX_STR);
      PanelEmergencia.SetEfectoDinamicoPredeterminado(gslc_ElemXListboxGetSel(&m_gui, pElemRef));
      PanelEmergencia.SetMenuActual(PanelEmergencia.MenuEfectosDinamicos);
      gslc_ElemSetTxtStr(&m_gui, VariableEstadoActual, textoEncendido);
      gslc_ElemSetTxtCol(&m_gui, VariableEstadoActual, (gslc_tsColor){63, 255, 51});
    }
    break;
  default:
    break;
  }
  return true;
}

//! *******************************************************************************************************************************************************************
//!                                                                    BARRAS DESLIZANTES
//! *******************************************************************************************************************************************************************
// Callback function for when a slider's position has been updated
bool CbSlidePos(void *pvGui, void *pvElemRef, int16_t nPos)
{
  gslc_tsGui *pGui = (gslc_tsGui *)(pvGui);
  gslc_tsElemRef *pElemRef = (gslc_tsElemRef *)(pvElemRef);
  gslc_tsElem *pElem = gslc_GetElemFromRef(pGui, pElemRef);
  int16_t nVal;
  char luzLeida[MAX_STR];
  // From the element's ID we can determine which slider was updated.
  switch (pElem->nId)
  {
  case E_BarraIluminacionPantalla:
    nVal = gslc_ElemXSliderGetPos(pGui, pElemRef);
    iluminacionPantalla = map(nVal, 1, 10, 10, 255);
    analogWrite(BACKLIGHT_TFT, iluminacionPantalla);
    memoria.putInt("BrilloPantalla", iluminacionPantalla);
    // TODO GUARDAR VALOR EN EEPROM
    break;
  case E_BarraIluminacionPersonalizadaPanel:
    nVal = gslc_ElemXSeekbarGetPos(pGui, BarraIluminacionPersonalizadaPanel);
    pElemRef = gslc_PageFindElemById(pGui, MenuIluminacionPanel, E_BotonAutoIluminacionPanel);
    gslc_ElemXTogglebtnSetState(pGui, pElemRef, false); //?Pone a falso el boton de automatico.
    PanelEmergencia.SetIluminacionAutomatica(false);
    PanelEmergencia.SetBrillo(nVal);
    pElemRef = gslc_PageFindElemById(pGui, MenuIluminacionPanel, E_VariableTextoLuzAmbiente);
    sprintf(luzLeida, "%d", map(PanelEmergencia.GetIluminacionExterior(), 0, 4095, 1, 10));
    gslc_ElemSetTxtStr(&m_gui, VariableTextoLuzAmbiente, luzLeida);
    break;
  case E_BarraInclinacion:
    nVal = gslc_ElemXSeekbarGetPos(pGui, BarraInclinacion);
    pElemRef = gslc_PageFindElemById(pGui, MenuInclinacionPanel, E_ArcoInclinacion);
    gslc_ElemXRingGaugeSetVal(pGui, pElemRef, nVal);
    PanelEmergencia.SetGrados(nVal);
    if (nVal > 5)
      gslc_ElemSetTxtCol(&m_gui, VariableEstadoInlcinacion, GSLC_COL_RED);
    else
      gslc_ElemSetTxtCol(&m_gui, VariableEstadoInlcinacion, GSLC_COL_WHITE);
    break;
  case E_BarraListaEfectos:
    nVal = gslc_ElemXSliderGetPos(pGui, BarraListaEfectos);
    pElemRef = gslc_PageFindElemById(pGui, MenuMensajePersonalizado, E_ListaEfectos);
    gslc_ElemXListboxSetScrollPos(pGui, pElemRef, nVal);
    break;
  case E_BarraListaEfectosInferior:
    nVal = gslc_ElemXSliderGetPos(pGui, BarraListaEfectosInferior);
    pElemRef = gslc_PageFindElemById(pGui, MenuMensajePersonalizadoDos, E_ListaEfectosInferior);
    gslc_ElemXListboxSetScrollPos(pGui, pElemRef, nVal);
    break;
  case E_BarraListaEfectosSuperior:
    nVal = gslc_ElemXSliderGetPos(pGui, BarraListaEfectosSuperior);
    pElemRef = gslc_PageFindElemById(pGui, MenuMensajePersonalizadoDos, E_ListaEfectosSuperior);
    gslc_ElemXListboxSetScrollPos(pGui, pElemRef, nVal);
    break;
  case E_BarraMensajesDinamicos:
    nVal = gslc_ElemXSliderGetPos(pGui, BarraMensajesDinamicos);
    pElemRef = gslc_PageFindElemById(pGui, MenuEfectosDinamicos, E_ListaMensajesDinamicos);
    gslc_ElemXListboxSetScrollPos(pGui, pElemRef, nVal);
    break;
  case E_BarraMensajesTexto:
    nVal = gslc_ElemXSliderGetPos(pGui, BarraMensajesTexto);
    pElemRef = gslc_PageFindElemById(pGui, MenuMensajesTexto, E_ListaMensajesTexto);
    gslc_ElemXListboxSetScrollPos(pGui, pElemRef, nVal);
    break;
  case E_BarraVelocidadInferior:
    nVal = gslc_ElemXSeekbarGetPos(pGui, BarraVelocidadInferior);
    PanelEmergencia.SetVelocidadMSGPersonalizadoInferior(nVal);
    break;
  case E_BarraVelocidadPersonalizada:
    nVal = gslc_ElemXSeekbarGetPos(pGui, BarraVelocidadPersonalizada);
    PanelEmergencia.SetVelocidadMSGPersonalizado(nVal);
    break;
  case E_BarraVelocidadSuperior:
    nVal = gslc_ElemXSeekbarGetPos(pGui, BarraVelocidadSuperior);
    PanelEmergencia.SetVelocidadMSGPersonalizadoSuperior(nVal);
    break;
  default:
    break;
  }

  return true;
}

//! *******************************************************************************************************************************************************************
//!                                                             IMPRIMIR IMAGENES DESDE SPIFFS
//! *******************************************************************************************************************************************************************
uint16_t read16(fs::File &f)
{
  uint16_t result;
  ((uint8_t *)&result)[0] = f.read(); // LSB
  ((uint8_t *)&result)[1] = f.read(); // MSB
  return result;
}

uint32_t read32(fs::File &f)
{
  uint32_t result;
  ((uint8_t *)&result)[0] = f.read(); // LSB
  ((uint8_t *)&result)[1] = f.read();
  ((uint8_t *)&result)[2] = f.read();
  ((uint8_t *)&result)[3] = f.read(); // MSB
  return result;
}

void drawBmp(const char *filename, int16_t x, int16_t y)
{

  if ((x >= tft.width()) || (y >= tft.height()))
    return;

  fs::File bmpFS;

  // Open requested file on SD card
  bmpFS = SPIFFS.open(filename, "r");

  if (!bmpFS)
  {
    Serial.print("File not found");
    return;
  }

  uint32_t seekOffset;
  uint16_t w, h, row, col;
  uint8_t r, g, b;

  uint32_t startTime = millis();

  if (read16(bmpFS) == 0x4D42)
  {
    read32(bmpFS);
    read32(bmpFS);
    seekOffset = read32(bmpFS);
    read32(bmpFS);
    w = read32(bmpFS);
    h = read32(bmpFS);

    if ((read16(bmpFS) == 1) && (read16(bmpFS) == 24) && (read32(bmpFS) == 0))
    {
      y += h - 1;

      bool oldSwapBytes = tft.getSwapBytes();
      tft.setSwapBytes(true);
      bmpFS.seek(seekOffset);

      uint16_t padding = (4 - ((w * 3) & 3)) & 3;
      uint8_t lineBuffer[w * 3 + padding];

      for (row = 0; row < h; row++)
      {

        bmpFS.read(lineBuffer, sizeof(lineBuffer));
        uint8_t *bptr = lineBuffer;
        uint16_t *tptr = (uint16_t *)lineBuffer;
        // Convert 24 to 16 bit colours
        for (uint16_t col = 0; col < w; col++)
        {
          b = *bptr++;
          g = *bptr++;
          r = *bptr++;
          *tptr++ = ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3);
        }

        // Push the pixel row to screen, pushImage will crop the line if needed
        // y is decremented as the BMP image is drawn bottom up
        tft.pushImage(x, y--, w, 1, (uint16_t *)lineBuffer);
      }
      tft.setSwapBytes(oldSwapBytes);
      Serial.print("Loaded in ");
      Serial.print(millis() - startTime);
      Serial.println(" ms");
    }
    else
      Serial.println("BMP format not recognized.");
  }
  bmpFS.close();
}

// These read 16- and 32-bit types from the SD card file.
// BMP data is stored little-endian, Arduino is little-endian too.
// May need to reverse subscript order if porting elsewhere.

//! *******************************************************************************************************************************************************************
//!                                                                     SETUP PANTALLA
//! *******************************************************************************************************************************************************************
void SetupPantallaTFT()
{
  gslc_InitDebug(&DebugOut);
  tft.init();                // Inicializa la pantalla TFT.
  tft.setRotation(1);        // Se puede cambiar la rotación de la pantalla.
  tft.fillScreen(TFT_WHITE); // Se rellena la pantalla en color negro para eliminar imagenes anteriores.
  if (!SPIFFS.begin())
  {
    Serial.println("SPIFFS initialisation failed!");
  }
  drawBmp("/escudouva.bmp", 0, 10);
  delay(1000);
  InitGUIslice_gen();
  CalibrarPantalla();              // Comprobación de si la pantalla necesita una calibración o no.
  tft.fillScreen(TFT_BLACK);       // Se rellena la pantalla en color negro para eliminar imagenes anteriores.
  tft.setFreeFont(&FreeMono9pt7b); // Establece la fuente de la pantalla
}

#endif