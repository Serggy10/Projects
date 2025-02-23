//<File !Start!>
// FILE: [GUI_V6_GSLC.h]
// Created by GUIslice Builder version: [0.17.b24]
//
// GUIslice Builder Generated GUI Framework File
//
// For the latest guides, updates and support view:
// https://github.com/ImpulseAdventure/GUIslice
//
//<File !End!>

#ifndef _GUISLICE_GEN_H
#define _GUISLICE_GEN_H

// ------------------------------------------------
// Headers to include
// ------------------------------------------------
#include "GUIslice.h"
#include "GUIslice_drv.h"
#include "PanelLED.h"
extern PanelLED PanelEmergencia;

// Include any extended elements
//<Includes !Start!>
// Include extended elements
#include "elem/XKeyPad_Alpha.h"
#include "elem/XListbox.h"
#include "elem/XRingGauge.h"
#include "elem/XSeekbar.h"
#include "elem/XSlider.h"
#include "elem/XTogglebtn.h"

// Ensure optional features are enabled in the configuration
//<Includes !End!>

// ------------------------------------------------
// Headers and Defines for fonts
// Note that font files are located within the Adafruit-GFX library folder:
// ------------------------------------------------
//<Fonts !Start!>
#if !defined(DRV_DISP_TFT_ESPI)
  #error E_PROJECT_OPTIONS tab->Graphics Library should be Adafruit_GFX
#endif
#include <TFT_eSPI.h>
#include "NotoSansBold8pt7b.h"
#include "dosis_bold8pt7b.h"
#include "dosis_book8pt7b.h"
//<Fonts !End!>

// ------------------------------------------------
// Defines for resources
// ------------------------------------------------
//<Resources !Start!>
//<Resources !End!>

// ------------------------------------------------
// Enumerations for pages, elements, fonts, images
// ------------------------------------------------
//<Enum !Start!>
enum {E_MenuBase,E_MenuPrincipal,MenuMensajesTexto,MenuEfectosDinamicos
      ,MenuInclinacionPanel,MenuAjustes,MenuMensajePersonalizado
      ,MenuIluminacionPanel,MenuMensajePersonalizadoDos
      ,E_POP_KEYPAD_ALPHA};
enum {Boton135,Boton45,Boton90,BotonHome,BotonMenuAjustes
      ,BotonMenuEfectosDinamicos,BotonMenuIluminacionPanel
      ,BotonMenuInclinacionPanel,BotonMenuMensajePersonalizado
      ,BotonMenuMensajesTexto,BotonVolver1,BotonVolver2,BotonVolver3
      ,BotonVolver4,BotonVolver5,BotonVolver6,E_ArcoInclinacion
      ,E_BarraIluminacionPantalla,E_BarraIluminacionPersonalizadaPanel
      ,E_BarraInclinacion,E_BarraListaEfectos
      ,E_BarraListaEfectosInferior,E_BarraListaEfectosSuperior
      ,E_BarraMensajesDinamicos,E_BarraMensajesTexto
      ,E_BarraVelocidadInferior,E_BarraVelocidadPersonalizada
      ,E_BarraVelocidadSuperior,E_BotonApagar
      ,E_BotonAutoIluminacionPanel,E_BotonCalibrado,E_BotonDosFilas
      ,E_BotonVolverUnaFila,E_CirculoLogo,E_ELEM_BOX1,E_ELEM_BOX2
      ,E_ELEM_BOX3,E_ELEM_BOX4,E_ELEM_BOX5,E_ELEM_BOX6,E_ELEM_BOX7
      ,E_ELEM_TEXT26,E_ELEM_TEXT30,E_ELEM_TEXT31,E_ELEM_TEXT34
      ,E_ELEM_TEXT35,E_ELEM_TEXT36,E_ELEM_TEXT37,E_ELEM_TEXT38
      ,E_ELEM_TEXT41,E_EntradaTextoInferior,E_EntradaTextoSuperior
      ,E_ListaEfectos,E_ListaEfectosInferior,E_ListaEfectosSuperior
      ,E_ListaMensajesDinamicos,E_ListaMensajesTexto
      ,E_TextoAutoIluminacionPanel,E_TextoEstadoInclinacion
      ,E_TextoIluminacionPantalla,E_TextoIluminacionPersonalizada
      ,E_TextoLuzAmbiente,E_TextoPersonalizado
      ,E_VariableTextoLuzAmbiente,EstadoActual,Nombre,TextoEstadoActual
      ,Titulo,TituloMenuAjustes,TituloMenuEfectos
      ,TituloMenuIluminacionPanel,TituloMenuInclinacionPanel
      ,TituloMenuTexto,E_ELEM_KEYPAD_ALPHA};
// Must use separate enum for fonts with MAX_FONT at end to use gslc_FontSet.
enum {E_BUILTIN5X8,E_DOSIS_BOLD8,E_DOSIS_BOOK8,E_FREESANS9
      ,E_FREESANSBOLD9,E_NOTOSANSBOLD8,MAX_FONT};
//<Enum !End!>

// ------------------------------------------------
// Instantiate the GUI
// ------------------------------------------------

// ------------------------------------------------
// Define the maximum number of elements and pages
// ------------------------------------------------
//<ElementDefines !Start!>
#define MAX_PAGE                10

#define MAX_ELEM_MenuBase 12 // # Elems total on page
#define MAX_ELEM_MenuBase_RAM MAX_ELEM_MenuBase // # Elems in RAM

#define MAX_ELEM_MenuPrincipal 10 // # Elems total on page
#define MAX_ELEM_MenuPrincipal_RAM MAX_ELEM_MenuPrincipal // # Elems in RAM

#define MAX_ELEM_MenuMensajesTexto 5 // # Elems total on page
#define MAX_ELEM_MenuMensajesTexto_RAM MAX_ELEM_MenuMensajesTexto // # Elems in RAM

#define MAX_ELEM_MenuEfectosDinamicos 5 // # Elems total on page
#define MAX_ELEM_MenuEfectosDinamicos_RAM MAX_ELEM_MenuEfectosDinamicos // # Elems in RAM

#define MAX_ELEM_MenuInclinacionPanel 9 // # Elems total on page
#define MAX_ELEM_MenuInclinacionPanel_RAM MAX_ELEM_MenuInclinacionPanel // # Elems in RAM

#define MAX_ELEM_MenuAjustes 5 // # Elems total on page
#define MAX_ELEM_MenuAjustes_RAM MAX_ELEM_MenuAjustes // # Elems in RAM

#define MAX_ELEM_MenuMensajePersonalizado 8 // # Elems total on page
#define MAX_ELEM_MenuMensajePersonalizado_RAM MAX_ELEM_MenuMensajePersonalizado // # Elems in RAM

#define MAX_ELEM_MenuIluminacionPanel 9 // # Elems total on page
#define MAX_ELEM_MenuIluminacionPanel_RAM MAX_ELEM_MenuIluminacionPanel // # Elems in RAM

#define MAX_ELEM_MenuMensajePersonalizadoDos 15 // # Elems total on page
#define MAX_ELEM_MenuMensajePersonalizadoDos_RAM MAX_ELEM_MenuMensajePersonalizadoDos // # Elems in RAM
//<ElementDefines !End!>

// ------------------------------------------------
// Create element storage
// ------------------------------------------------
gslc_tsGui                      m_gui;
gslc_tsDriver                   m_drv;
gslc_tsFont                     m_asFont[MAX_FONT];
gslc_tsPage                     m_asPage[MAX_PAGE];

//<GUI_Extra_Elements !Start!>
gslc_tsElem                     m_asBasePage1Elem[MAX_ELEM_MenuBase_RAM];
gslc_tsElemRef                  m_asBasePage1ElemRef[MAX_ELEM_MenuBase];
gslc_tsElem                     m_asPage1Elem[MAX_ELEM_MenuPrincipal_RAM];
gslc_tsElemRef                  m_asPage1ElemRef[MAX_ELEM_MenuPrincipal];
gslc_tsElem                     m_asPage2Elem[MAX_ELEM_MenuMensajesTexto_RAM];
gslc_tsElemRef                  m_asPage2ElemRef[MAX_ELEM_MenuMensajesTexto];
gslc_tsElem                     m_asPage3Elem[MAX_ELEM_MenuEfectosDinamicos_RAM];
gslc_tsElemRef                  m_asPage3ElemRef[MAX_ELEM_MenuEfectosDinamicos];
gslc_tsElem                     m_asPage4Elem[MAX_ELEM_MenuInclinacionPanel_RAM];
gslc_tsElemRef                  m_asPage4ElemRef[MAX_ELEM_MenuInclinacionPanel];
gslc_tsElem                     m_asPage5Elem[MAX_ELEM_MenuAjustes_RAM];
gslc_tsElemRef                  m_asPage5ElemRef[MAX_ELEM_MenuAjustes];
gslc_tsElem                     m_asPage6Elem[MAX_ELEM_MenuMensajePersonalizado_RAM];
gslc_tsElemRef                  m_asPage6ElemRef[MAX_ELEM_MenuMensajePersonalizado];
gslc_tsElem                     m_asPage7Elem[MAX_ELEM_MenuIluminacionPanel_RAM];
gslc_tsElemRef                  m_asPage7ElemRef[MAX_ELEM_MenuIluminacionPanel];
gslc_tsElem                     m_asPage8Elem[MAX_ELEM_MenuMensajePersonalizadoDos_RAM];
gslc_tsElemRef                  m_asPage8ElemRef[MAX_ELEM_MenuMensajePersonalizadoDos];
gslc_tsElem                     m_asKeypadAlphaElem[1];
gslc_tsElemRef                  m_asKeypadAlphaElemRef[1];
gslc_tsXKeyPad                  m_sKeyPadAlpha;
gslc_tsXRingGauge               m_sXRingGauge2;
gslc_tsXListbox                 m_sListbox8;
// - Note that XLISTBOX_BUF_OH_R is extra required per item
char                            m_acListboxBuf8[301 + XLISTBOX_BUF_OH_R];
gslc_tsXSlider                  m_sListScroll8;
gslc_tsXListbox                 m_sListbox9;
// - Note that XLISTBOX_BUF_OH_R is extra required per item
char                            m_acListboxBuf9[130 + XLISTBOX_BUF_OH_R];
gslc_tsXSlider                  m_sListScroll9;
gslc_tsXRingGauge               m_sXRingGauge1;
gslc_tsXSeekbar                 m_sXSeekbar1;
gslc_tsXSlider                  m_sXSlider1;
gslc_tsXListbox                 m_sListbox4;
// - Note that XLISTBOX_BUF_OH_R is extra required per item
char                            m_acListboxBuf4[300 + XLISTBOX_BUF_OH_R];
gslc_tsXSlider                  m_sListScroll4;
gslc_tsXSeekbar                 m_sXSeekbar5;
gslc_tsXSeekbar                 m_sXSeekbar3;
gslc_tsXTogglebtn               m_asXToggle2;
gslc_tsXListbox                 m_sListbox5;
// - Note that XLISTBOX_BUF_OH_R is extra required per item
char                            m_acListboxBuf5[299 + XLISTBOX_BUF_OH_R];
gslc_tsXSlider                  m_sListScroll5;
gslc_tsXListbox                 m_sListbox7;
// - Note that XLISTBOX_BUF_OH_R is extra required per item
char                            m_acListboxBuf7[299 + XLISTBOX_BUF_OH_R];
gslc_tsXSlider                  m_sListScroll7;
gslc_tsXSeekbar                 m_sXSeekbar7;
gslc_tsXSeekbar                 m_sXSeekbar8;

#define MAX_STR                 100

//<GUI_Extra_Elements !End!>

// ------------------------------------------------
// Program Globals
// ------------------------------------------------

// Element References for direct access
//<Extern_References !Start!>
extern gslc_tsElemRef* ArcoInclinacion;
extern gslc_tsElemRef* BarraIluminacionPantalla;
extern gslc_tsElemRef* BarraIluminacionPersonalizadaPanel;
extern gslc_tsElemRef* BarraInclinacion;
extern gslc_tsElemRef* BarraListaEfectos;
extern gslc_tsElemRef* BarraListaEfectosInferior;
extern gslc_tsElemRef* BarraListaEfectosSuperior;
extern gslc_tsElemRef* BarraMensajesDinamicos;
extern gslc_tsElemRef* BarraMensajesTexto;
extern gslc_tsElemRef* BarraVelocidadInferior;
extern gslc_tsElemRef* BarraVelocidadPersonalizada;
extern gslc_tsElemRef* BarraVelocidadSuperior;
extern gslc_tsElemRef* BotonAutoIluminacionPanel;
extern gslc_tsElemRef* CirculoLogo;
extern gslc_tsElemRef* EntradaTextoInferior;
extern gslc_tsElemRef* EntradaTextoSuperior;
extern gslc_tsElemRef* ListaEfectos;
extern gslc_tsElemRef* ListaEfectosInferior;
extern gslc_tsElemRef* ListaEfectosSuperior;
extern gslc_tsElemRef* ListaMensajesDinamico;
extern gslc_tsElemRef* ListaMensajesTexto;
extern gslc_tsElemRef* TextoPersonalizado;
extern gslc_tsElemRef* VariableEstadoActual;
extern gslc_tsElemRef* VariableTextoLuzAmbiente;
extern gslc_tsElemRef* m_pElemKeyPadAlpha;
extern gslc_tsElemRef* VariableEstadoInlcinacion;
//<Extern_References !End!>

// Define debug message function
static int16_t DebugOut(char ch);

// ------------------------------------------------
// Callback Methods
// ------------------------------------------------
bool CbBtnCommon(void* pvGui,void *pvElemRef,gslc_teTouch eTouch,int16_t nX,int16_t nY);
bool CbCheckbox(void* pvGui, void* pvElemRef, int16_t nSelId, bool bState);
bool CbDrawScanner(void* pvGui,void* pvElemRef,gslc_teRedrawType eRedraw);
bool CbKeypad(void* pvGui, void *pvElemRef, int16_t nState, void* pvData);
bool CbListbox(void* pvGui, void* pvElemRef, int16_t nSelId);
bool CbSlidePos(void* pvGui,void* pvElemRef,int16_t nPos);
bool CbSpinner(void* pvGui, void *pvElemRef, int16_t nState, void* pvData);
bool CbTickScanner(void* pvGui,void* pvScope);

// ------------------------------------------------
// Create page elements
// ------------------------------------------------
void InitGUIslice_gen()
{
  gslc_tsElemRef* pElemRef = NULL;

  if (!gslc_Init(&m_gui,&m_drv,m_asPage,MAX_PAGE,m_asFont,MAX_FONT)) { return; }

  // ------------------------------------------------
  // Load Fonts
  // ------------------------------------------------
//<Load_Fonts !Start!>
    if (!gslc_FontSet(&m_gui,E_BUILTIN5X8,GSLC_FONTREF_PTR,NULL,1)) { return; }
    if (!gslc_FontSet(&m_gui,E_DOSIS_BOLD8,GSLC_FONTREF_PTR,&dosis_bold8pt7b,1)) { return; }
    if (!gslc_FontSet(&m_gui,E_DOSIS_BOOK8,GSLC_FONTREF_PTR,&dosis_book8pt7b,1)) { return; }
    if (!gslc_FontSet(&m_gui,E_FREESANS9,GSLC_FONTREF_PTR,&FreeSans9pt7b,1)) { return; }
    if (!gslc_FontSet(&m_gui,E_FREESANSBOLD9,GSLC_FONTREF_PTR,&FreeSansBold9pt7b,1)) { return; }
    if (!gslc_FontSet(&m_gui,E_NOTOSANSBOLD8,GSLC_FONTREF_PTR,&NotoSansBold8pt7b,1)) { return; }
//<Load_Fonts !End!>

//<InitGUI !Start!>
  gslc_PageAdd(&m_gui,E_MenuBase,m_asBasePage1Elem,MAX_ELEM_MenuBase_RAM,m_asBasePage1ElemRef,MAX_ELEM_MenuBase);
  gslc_PageAdd(&m_gui,E_MenuPrincipal,m_asPage1Elem,MAX_ELEM_MenuPrincipal_RAM,m_asPage1ElemRef,MAX_ELEM_MenuPrincipal);
  gslc_PageAdd(&m_gui,MenuMensajesTexto,m_asPage2Elem,MAX_ELEM_MenuMensajesTexto_RAM,m_asPage2ElemRef,MAX_ELEM_MenuMensajesTexto);
  gslc_PageAdd(&m_gui,MenuEfectosDinamicos,m_asPage3Elem,MAX_ELEM_MenuEfectosDinamicos_RAM,m_asPage3ElemRef,MAX_ELEM_MenuEfectosDinamicos);
  gslc_PageAdd(&m_gui,MenuInclinacionPanel,m_asPage4Elem,MAX_ELEM_MenuInclinacionPanel_RAM,m_asPage4ElemRef,MAX_ELEM_MenuInclinacionPanel);
  gslc_PageAdd(&m_gui,MenuAjustes,m_asPage5Elem,MAX_ELEM_MenuAjustes_RAM,m_asPage5ElemRef,MAX_ELEM_MenuAjustes);
  gslc_PageAdd(&m_gui,MenuMensajePersonalizado,m_asPage6Elem,MAX_ELEM_MenuMensajePersonalizado_RAM,m_asPage6ElemRef,MAX_ELEM_MenuMensajePersonalizado);
  gslc_PageAdd(&m_gui,MenuIluminacionPanel,m_asPage7Elem,MAX_ELEM_MenuIluminacionPanel_RAM,m_asPage7ElemRef,MAX_ELEM_MenuIluminacionPanel);
  gslc_PageAdd(&m_gui,MenuMensajePersonalizadoDos,m_asPage8Elem,MAX_ELEM_MenuMensajePersonalizadoDos_RAM,m_asPage8ElemRef,MAX_ELEM_MenuMensajePersonalizadoDos);
  gslc_PageAdd(&m_gui,E_POP_KEYPAD_ALPHA,m_asKeypadAlphaElem,1,m_asKeypadAlphaElemRef,1);  // KeyPad

  // Now mark E_MenuBase as a "base" page which means that it's elements
  // are always visible. This is useful for common page elements.
  gslc_SetPageBase(&m_gui, E_MenuBase);


  // NOTE: The current page defaults to the first page added. Here we explicitly
  //       ensure that the main page is the correct page no matter the add order.
  gslc_SetPageCur(&m_gui,E_MenuPrincipal);
  
  // Set Background to a flat color
  gslc_SetBkgndColor(&m_gui,GSLC_COL_WHITE);

  // -----------------------------------
  // PAGE: E_MenuBase
  
  
  // Create Titulo text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,Titulo,E_MenuBase,(gslc_tsRect){60,55,370,13},
    (char*)"PANEL DE EMERGENCIA EN CARRETERA",0,E_FREESANSBOLD9);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){58,5,139}));
  
  // Create Nombre text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,Nombre,E_MenuBase,(gslc_tsRect){260,13,206,17},
    (char*)"IEIA Sergio Carrasco Hernandez ",0,E_DOSIS_BOLD8);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){58,5,139}));

  // Create ring gauge E_CirculoLogo 
  static char m_sRingText2[2] = "";
  pElemRef = gslc_ElemXRingGaugeCreate(&m_gui,E_CirculoLogo,E_MenuBase,&m_sXRingGauge2,
          (gslc_tsRect){5,1,54,54},
          (char*)m_sRingText2,2,E_BUILTIN5X8);
  gslc_ElemXRingGaugeSetValRange(&m_gui, pElemRef, 0, 1);
  gslc_ElemXRingGaugeSetVal(&m_gui, pElemRef, 0); // Set initial value
  gslc_ElemXRingGaugeSetThickness(&m_gui,pElemRef, 27);
  gslc_ElemXRingGaugeSetColorActiveFlat(&m_gui,pElemRef, ((gslc_tsColor){58,5,139}));
  gslc_ElemXRingGaugeSetColorInactive(&m_gui,pElemRef, ((gslc_tsColor){58,5,139}));
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){58,5,139}));
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_WHITE,((gslc_tsColor){58,5,139}),GSLC_COL_BLACK);
  CirculoLogo = pElemRef;
   
  // Create E_ELEM_BOX1 box
  pElemRef = gslc_ElemCreateBox(&m_gui,E_ELEM_BOX1,E_MenuBase,(gslc_tsRect){13,16,19,6});
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_WHITE,GSLC_COL_WHITE,GSLC_COL_WHITE);
   
  // Create E_ELEM_BOX2 box
  pElemRef = gslc_ElemCreateBox(&m_gui,E_ELEM_BOX2,E_MenuBase,(gslc_tsRect){13,25,19,6});
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_WHITE,GSLC_COL_WHITE,GSLC_COL_WHITE);
   
  // Create E_ELEM_BOX3 box
  pElemRef = gslc_ElemCreateBox(&m_gui,E_ELEM_BOX3,E_MenuBase,(gslc_tsRect){13,34,19,6});
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_WHITE,GSLC_COL_WHITE,GSLC_COL_WHITE);
   
  // Create E_ELEM_BOX4 box
  pElemRef = gslc_ElemCreateBox(&m_gui,E_ELEM_BOX4,E_MenuBase,(gslc_tsRect){35,16,6,6});
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_WHITE,GSLC_COL_WHITE,GSLC_COL_WHITE);
   
  // Create E_ELEM_BOX5 box
  pElemRef = gslc_ElemCreateBox(&m_gui,E_ELEM_BOX5,E_MenuBase,(gslc_tsRect){44,16,6,6});
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_WHITE,GSLC_COL_WHITE,GSLC_COL_WHITE);
   
  // Create E_ELEM_BOX6 box
  pElemRef = gslc_ElemCreateBox(&m_gui,E_ELEM_BOX6,E_MenuBase,(gslc_tsRect){35,25,6,15});
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_WHITE,GSLC_COL_WHITE,GSLC_COL_WHITE);
   
  // Create E_ELEM_BOX7 box
  pElemRef = gslc_ElemCreateBox(&m_gui,E_ELEM_BOX7,E_MenuBase,(gslc_tsRect){44,25,6,15});
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_WHITE,GSLC_COL_WHITE,GSLC_COL_WHITE);
  
  // Create E_ELEM_TEXT30 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT30,E_MenuBase,(gslc_tsRect){60,15,179,12},
    (char*)"ESCUELA DE INGENIERÍAS",0,E_NOTOSANSBOLD8);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){58,5,139}));
  
  // Create E_ELEM_TEXT31 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT31,E_MenuBase,(gslc_tsRect){60,30,107,12},
    (char*)"INDUSTRIALES",0,E_NOTOSANSBOLD8);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){58,5,139}));

  // -----------------------------------
  // PAGE: E_MenuPrincipal
  
  
  // create BotonMenuMensajesTexto button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,BotonMenuMensajesTexto,E_MenuPrincipal,
    (gslc_tsRect){20,150,210,40},(char*)"MENSAJES TEXTO",0,E_FREESANS9,&CbBtnCommon);
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){208,148,234}),((gslc_tsColor){58,5,139}),((gslc_tsColor){58,5,139}));
  gslc_ElemSetRoundEn(&m_gui, pElemRef, true);
  
  // create BotonMenuEfectosDinamicos button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,BotonMenuEfectosDinamicos,E_MenuPrincipal,
    (gslc_tsRect){250,150,210,40},(char*)"EFECTOS DINAMICOS",0,E_FREESANS9,&CbBtnCommon);
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){208,148,234}),((gslc_tsColor){58,5,139}),((gslc_tsColor){58,5,139}));
  gslc_ElemSetRoundEn(&m_gui, pElemRef, true);
  
  // create BotonMenuInclinacionPanel button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,BotonMenuInclinacionPanel,E_MenuPrincipal,
    (gslc_tsRect){20,200,210,40},(char*)"INCLINACION PANEL",0,E_FREESANS9,&CbBtnCommon);
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){208,148,234}),((gslc_tsColor){58,5,139}),((gslc_tsColor){58,5,139}));
  gslc_ElemSetRoundEn(&m_gui, pElemRef, true);
  
  // create BotonMenuIluminacionPanel button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,BotonMenuIluminacionPanel,E_MenuPrincipal,
    (gslc_tsRect){250,200,210,40},(char*)"ILUMINACION PANEL",0,E_FREESANS9,&CbBtnCommon);
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){208,148,234}),((gslc_tsColor){58,5,139}),((gslc_tsColor){58,5,139}));
  gslc_ElemSetRoundEn(&m_gui, pElemRef, true);
  
  // create BotonMenuAjustes button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,BotonMenuAjustes,E_MenuPrincipal,
    (gslc_tsRect){250,250,210,40},(char*)"AJUSTES",0,E_FREESANS9,&CbBtnCommon);
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){208,148,234}),((gslc_tsColor){58,5,139}),((gslc_tsColor){58,5,139}));
  gslc_ElemSetRoundEn(&m_gui, pElemRef, true);
  
  // create BotonMenuMensajePersonalizado button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,BotonMenuMensajePersonalizado,E_MenuPrincipal,
    (gslc_tsRect){20,250,210,40},(char*)"MSG PERSONALIZADO",0,E_FREESANS9,&CbBtnCommon);
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){208,148,234}),((gslc_tsColor){58,5,139}),((gslc_tsColor){58,5,139}));
  gslc_ElemSetRoundEn(&m_gui, pElemRef, true);
  
  // Create TextoEstadoActual text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,TextoEstadoActual,E_MenuPrincipal,(gslc_tsRect){75,80,169,13},
    (char*)"ESTADO  ACTUAL :",0,E_FREESANSBOLD9);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,(gslc_tsColor){58,5,139});
  
  // Create EstadoActual runtime modifiable text
  static char m_sDisplayText5[13] = "APAGADO";
  pElemRef = gslc_ElemCreateTxt(&m_gui,EstadoActual,E_MenuPrincipal,(gslc_tsRect){260,80,130,13},
    (char*)m_sDisplayText5,13,E_FREESANSBOLD9);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_RED);
  VariableEstadoActual = pElemRef;
  
  // Create E_TextoEstadoInclinacion text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_TextoEstadoInclinacion,E_MenuPrincipal,(gslc_tsRect){170,100,144,8},
    (char*)"EL PANEL ESTA DESPLEGADO",13,E_BUILTIN5X8);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_RED);
  VariableEstadoInlcinacion = pElemRef;
  
  // create E_BotonApagar button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_BotonApagar,E_MenuPrincipal,
    (gslc_tsRect){190,118,100,25},(char*)"APAGAR",0,E_FREESANS9,&CbBtnCommon);
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){208,148,234}),((gslc_tsColor){58,5,139}),((gslc_tsColor){58,5,139}));
  gslc_ElemSetRoundEn(&m_gui, pElemRef, true);

  // -----------------------------------
  // PAGE: MenuMensajesTexto
  
  
  // create BotonVolver1 button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,BotonVolver1,MenuMensajesTexto,
    (gslc_tsRect){140,270,210,40},(char*)"VOLVER",0,E_FREESANS9,&CbBtnCommon);
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){208,148,234}),((gslc_tsColor){58,5,139}),((gslc_tsColor){58,5,139}));
  gslc_ElemSetRoundEn(&m_gui, pElemRef, true);
  
  // Create TituloMenuTexto text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,TituloMenuTexto,MenuMensajesTexto,(gslc_tsRect){110,80,257,13},
    (char*)"MENU MENSAJES DE TEXTO",0,E_FREESANSBOLD9);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){235,148,207}));
   
  // Create wrapping box for listbox E_ListaMensajesTexto and scrollbar
  pElemRef = gslc_ElemCreateBox(&m_gui,GSLC_ID_AUTO,MenuMensajesTexto,(gslc_tsRect){15,100,450,160});
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){208,148,234}),((gslc_tsColor){58,5,139}),((gslc_tsColor){235,148,207}));
  
  // Create listbox
  pElemRef = gslc_ElemXListboxCreate(&m_gui,E_ListaMensajesTexto,MenuMensajesTexto,&m_sListbox8,
    (gslc_tsRect){15+2,100+4,450-4-30,160-7},E_DOSIS_BOOK8,
    (uint8_t*)&m_acListboxBuf8,sizeof(m_acListboxBuf8),0);
  gslc_ElemXListboxSetSize(&m_gui, pElemRef, 4, 1); // 4 rows, 1 columns
  gslc_ElemXListboxItemsSetSize(&m_gui, pElemRef, -1, 30);
  gslc_ElemSetTxtMarginXY(&m_gui, pElemRef, 5, 5);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){208,148,234}),((gslc_tsColor){58,5,139}),((gslc_tsColor){235,148,207}));
  gslc_ElemXListboxSetSelFunc(&m_gui, pElemRef, &CbListbox);
  gslc_ElemXListboxItemsSetGap(&m_gui, pElemRef, 5,GSLC_COL_WHITE);
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "ATENCION ACCIDENTE");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "PRECAUCION VIENTO");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "PRECAUCION NIEBLA");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "PRECAUCION LLUVIA");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "PRECAUCION NIEVE");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "REDUZCA VELOCIDAD");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "DESV. A LA IZQUIERDA");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "DESV. A LA DERECHA");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "CARRIL IZQ. CORTADO");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "CARRIL DER. CORTADO");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "CARRIL CORTADO");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "ATENCION PARE");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "SIGAME");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "PELIGRO");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "MANT. EN SU CARRIL");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "CONTROL ALCOHOL");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "CONDUZCA RESPONS.");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "DESPEJE CALZADA");
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_MID);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,true);
  ListaMensajesTexto = pElemRef;

  // Create vertical scrollbar for listbox
  pElemRef = gslc_ElemXSliderCreate(&m_gui,E_BarraMensajesTexto,MenuMensajesTexto,&m_sListScroll8,
          (gslc_tsRect){15+450-2-30,100+4,30,160-8},0,15,0,8,true);
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){208,148,234}),((gslc_tsColor){58,5,139}),((gslc_tsColor){208,148,234}));
  gslc_ElemXSliderSetPosFunc(&m_gui,pElemRef,&CbSlidePos);
  BarraMensajesTexto = pElemRef;

  // -----------------------------------
  // PAGE: MenuEfectosDinamicos
  
  
  // create BotonVolver2 button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,BotonVolver2,MenuEfectosDinamicos,
    (gslc_tsRect){140,270,210,40},(char*)"VOLVER",0,E_FREESANS9,&CbBtnCommon);
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){208,148,234}),((gslc_tsColor){58,5,139}),((gslc_tsColor){58,5,139}));
  gslc_ElemSetRoundEn(&m_gui, pElemRef, true);
  
  // Create TituloMenuEfectos text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,TituloMenuEfectos,MenuEfectosDinamicos,(gslc_tsRect){110,80,257,13},
    (char*)"MENU EFECTOS DINAMICOS",0,E_FREESANSBOLD9);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){235,148,207}));
   
  // Create wrapping box for listbox E_ListaMensajesDinamicos and scrollbar
  pElemRef = gslc_ElemCreateBox(&m_gui,GSLC_ID_AUTO,MenuEfectosDinamicos,(gslc_tsRect){15,100,450,160});
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){208,148,234}),((gslc_tsColor){58,5,139}),((gslc_tsColor){235,148,207}));
  
  // Create listbox
  pElemRef = gslc_ElemXListboxCreate(&m_gui,E_ListaMensajesDinamicos,MenuEfectosDinamicos,&m_sListbox9,
    (gslc_tsRect){15+2,100+4,450-4-30,160-7},E_DOSIS_BOOK8,
    (uint8_t*)&m_acListboxBuf9,sizeof(m_acListboxBuf9),0);
  gslc_ElemXListboxSetSize(&m_gui, pElemRef, 4, 1); // 4 rows, 1 columns
  gslc_ElemXListboxItemsSetSize(&m_gui, pElemRef, -1, 30);
  gslc_ElemSetTxtMarginXY(&m_gui, pElemRef, 5, 5);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){208,148,234}),((gslc_tsColor){58,5,139}),((gslc_tsColor){235,148,207}));
  gslc_ElemXListboxSetSelFunc(&m_gui, pElemRef, &CbListbox);
  gslc_ElemXListboxItemsSetGap(&m_gui, pElemRef, 5,GSLC_COL_WHITE);
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "DESV. IZQUIERDA");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "DESV. DERECHA");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "MEDIO A EXTREMOS");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "EXTREMOS A MEDIO");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "PARPADEO MITAD");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "PARPADEO ALTERNO");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "PARPADEO TOTAL");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "PARPADEO DOS A DOS");
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_MID);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,true);
  ListaMensajesDinamico = pElemRef;

  // Create vertical scrollbar for listbox
  pElemRef = gslc_ElemXSliderCreate(&m_gui,E_BarraMensajesDinamicos,MenuEfectosDinamicos,&m_sListScroll9,
          (gslc_tsRect){15+450-2-30,100+4,30,160-8},0,13,0,8,true);
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){208,148,234}),((gslc_tsColor){58,5,139}),((gslc_tsColor){208,148,234}));
  gslc_ElemXSliderSetPosFunc(&m_gui,pElemRef,&CbSlidePos);
  BarraMensajesDinamicos = pElemRef;

  // -----------------------------------
  // PAGE: MenuInclinacionPanel
  
  
  // create BotonVolver3 button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,BotonVolver3,MenuInclinacionPanel,
    (gslc_tsRect){135,270,210,40},(char*)"VOLVER",0,E_FREESANS9,&CbBtnCommon);
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){208,148,234}),((gslc_tsColor){58,5,139}),((gslc_tsColor){58,5,139}));
  gslc_ElemSetRoundEn(&m_gui, pElemRef, true);
  
  // Create TituloMenuInclinacionPanel text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,TituloMenuInclinacionPanel,MenuInclinacionPanel,(gslc_tsRect){110,80,248,13},
    (char*)"MENU INCLINACION PANEL",0,E_FREESANSBOLD9);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){235,148,207}));
  
  // create BotonHome button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,BotonHome,MenuInclinacionPanel,
    (gslc_tsRect){20,105,100,40},(char*)"0 Grados",0,E_FREESANS9,&CbBtnCommon);
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){208,148,234}),((gslc_tsColor){58,5,139}),((gslc_tsColor){58,5,139}));
  gslc_ElemSetRoundEn(&m_gui, pElemRef, true);

  // Create ring gauge E_ArcoInclinacion 
  static char m_sRingText1[11] = "";
  pElemRef = gslc_ElemXRingGaugeCreate(&m_gui,E_ArcoInclinacion,MenuInclinacionPanel,&m_sXRingGauge1,
          (gslc_tsRect){190,125,100,100},
          (char*)m_sRingText1,11,E_FREESANSBOLD9);
  gslc_ElemXRingGaugeSetValRange(&m_gui, pElemRef, 0, 180);
  gslc_ElemXRingGaugeSetVal(&m_gui, pElemRef, PanelEmergencia.GetGrados()); // Set initial value
  gslc_ElemXRingGaugeSetThickness(&m_gui,pElemRef, 15);
  gslc_ElemXRingGaugeSetAngleRange(&m_gui,pElemRef, -90, 180, true);
  gslc_ElemXRingGaugeSetColorActiveGradient(&m_gui, pElemRef, ((gslc_tsColor){58,5,139}), ((gslc_tsColor){208,148,234}));
  gslc_ElemXRingGaugeSetColorInactive(&m_gui,pElemRef, ((gslc_tsColor){220,220,220}));
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){58,5,139}));
  ArcoInclinacion = pElemRef;

  // Create seekbar E_BarraInclinacion 
  pElemRef = gslc_ElemXSeekbarCreate(&m_gui,E_BarraInclinacion,MenuInclinacionPanel,&m_sXSeekbar1,
    (gslc_tsRect){105,224,270,30},0,180,PanelEmergencia.GetGrados(),
    4,2,8,((gslc_tsColor){208,148,234}),GSLC_COL_WHITE,GSLC_COL_WHITE,false);
  gslc_ElemXSeekbarSetPosFunc(&m_gui,pElemRef,&CbSlidePos);
  gslc_ElemXSeekbarSetStyle(&m_gui,pElemRef,true,((gslc_tsColor){208,148,234}),false,((gslc_tsColor){58,5,139}),
    18,3,GSLC_COL_CYAN);
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){58,5,139}),((gslc_tsColor){58,5,139}),((gslc_tsColor){58,5,139}));
  BarraInclinacion = pElemRef;
  
  // create Boton90 button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,Boton90,MenuInclinacionPanel,
    (gslc_tsRect){360,105,100,40},(char*)"90 Grados",0,E_FREESANS9,&CbBtnCommon);
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){208,148,234}),((gslc_tsColor){58,5,139}),((gslc_tsColor){58,5,139}));
  gslc_ElemSetRoundEn(&m_gui, pElemRef, true);
  
  // create Boton45 button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,Boton45,MenuInclinacionPanel,
    (gslc_tsRect){20,155,100,40},(char*)"45 Grados",0,E_FREESANS9,&CbBtnCommon);
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){208,148,234}),((gslc_tsColor){58,5,139}),((gslc_tsColor){58,5,139}));
  gslc_ElemSetRoundEn(&m_gui, pElemRef, true);
  
  // create Boton135 button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,Boton135,MenuInclinacionPanel,
    (gslc_tsRect){360,155,100,40},(char*)"135 Grados",0,E_FREESANS9,&CbBtnCommon);
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){208,148,234}),((gslc_tsColor){58,5,139}),((gslc_tsColor){58,5,139}));
  gslc_ElemSetRoundEn(&m_gui, pElemRef, true);
  
  // Create E_ELEM_TEXT41 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT41,MenuInclinacionPanel,(gslc_tsRect){100,209,293,13},
    (char*)"0              INCLINACION            180 ",0,E_FREESANSBOLD9);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){58,5,139}));

  // -----------------------------------
  // PAGE: MenuAjustes
  
  
  // create BotonVolver4 button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,BotonVolver4,MenuAjustes,
    (gslc_tsRect){140,270,210,40},(char*)"VOLVER",0,E_FREESANS9,&CbBtnCommon);
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){208,148,234}),((gslc_tsColor){58,5,139}),((gslc_tsColor){58,5,139}));
  gslc_ElemSetRoundEn(&m_gui, pElemRef, true);
  
  // Create TituloMenuAjustes text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,TituloMenuAjustes,MenuAjustes,(gslc_tsRect){168,80,143,13},
    (char*)"MENU AJUSTES",0,E_FREESANSBOLD9);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){235,148,207}));
  
  // create E_BotonCalibrado button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_BotonCalibrado,MenuAjustes,
    (gslc_tsRect){140,131,200,40},(char*)"CALIBRAR PANTALLA",0,E_FREESANS9,&CbBtnCommon);
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){208,148,234}),((gslc_tsColor){58,5,139}),((gslc_tsColor){58,5,139}));
  gslc_ElemSetRoundEn(&m_gui, pElemRef, true);
  
  // Create E_TextoIluminacionPantalla text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_TextoIluminacionPantalla,MenuAjustes,(gslc_tsRect){126,194,228,13},
    (char*)"ILUMINACION PANTALLA",0,E_FREESANSBOLD9);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){58,5,139}));

  // Create slider E_BarraIluminacionPantalla 
  pElemRef = gslc_ElemXSliderCreate(&m_gui,E_BarraIluminacionPantalla,MenuAjustes,&m_sXSlider1,
          (gslc_tsRect){165,214,150,20},1,10,map(memoria.getInt("BrilloPantalla",255),10,255,1,10),5,false);
  gslc_ElemXSliderSetStyle(&m_gui,pElemRef,false,((gslc_tsColor){58,5,139}),9,5,((gslc_tsColor){58,5,139}));
  gslc_ElemXSliderSetPosFunc(&m_gui,pElemRef,&CbSlidePos);
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){58,5,139}),GSLC_COL_WHITE,GSLC_COL_GRAY_LT3);
  BarraIluminacionPantalla = pElemRef;

  // -----------------------------------
  // PAGE: MenuMensajePersonalizado
  
  
  // create BotonVolver5 button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,BotonVolver5,MenuMensajePersonalizado,
    (gslc_tsRect){140,270,210,40},(char*)"VOLVER",0,E_FREESANS9,&CbBtnCommon);
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){208,148,234}),((gslc_tsColor){58,5,139}),((gslc_tsColor){58,5,139}));
  gslc_ElemSetRoundEn(&m_gui, pElemRef, true);
  
  // Create E_TextoPersonalizado text input field
  static char m_sInputText1[31] = "";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_TextoPersonalizado,MenuMensajePersonalizado,(gslc_tsRect){90,85,300,30},
    (char*)m_sInputText1,31,E_FREESANSBOLD9);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_MID);
  gslc_ElemSetTxtMargin(&m_gui,pElemRef,5);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){58,5,139}));
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){208,148,234}),GSLC_COL_WHITE,((gslc_tsColor){208,148,234}));
  gslc_ElemSetFrameEn(&m_gui,pElemRef,true);
  gslc_ElemSetClickEn(&m_gui, pElemRef, true);
  gslc_ElemSetTouchFunc(&m_gui, pElemRef, &CbBtnCommon);
  TextoPersonalizado = pElemRef;
   
  // Create wrapping box for listbox E_ListaEfectos and scrollbar
  pElemRef = gslc_ElemCreateBox(&m_gui,GSLC_ID_AUTO,MenuMensajePersonalizado,(gslc_tsRect){10,125,260,135});
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){208,148,234}),((gslc_tsColor){58,5,139}),((gslc_tsColor){235,148,207}));
  
  // Create listbox
  pElemRef = gslc_ElemXListboxCreate(&m_gui,E_ListaEfectos,MenuMensajePersonalizado,&m_sListbox4,
    (gslc_tsRect){10+2,125+4,260-4-25,135-7},E_FREESANS9,
    (uint8_t*)&m_acListboxBuf4,sizeof(m_acListboxBuf4),0);
  gslc_ElemXListboxSetSize(&m_gui, pElemRef, 4, 1); // 4 rows, 1 columns
  gslc_ElemXListboxItemsSetSize(&m_gui, pElemRef, -1, 25);
  gslc_ElemSetTxtMarginXY(&m_gui, pElemRef, 5, 5);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){208,148,234}),((gslc_tsColor){58,5,139}),((gslc_tsColor){235,148,207}));
  gslc_ElemXListboxSetSelFunc(&m_gui, pElemRef, &CbListbox);
  gslc_ElemXListboxItemsSetGap(&m_gui, pElemRef, 5,GSLC_COL_WHITE);
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "NO EFFECT");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "PRINT");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "SCROLL UP");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "SCROLL DOWN");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "SCROLL LEFT");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "SCROLL RIGHT");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "SPRITE");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "SLICE");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "MESH");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "FADE");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "DISSOLVE");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "BLINDS");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "RANDOM");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "WIPE");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "WIPE CURSOR");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "SCAN HORIZ");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "SCAN HORIZX");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "SCAN VERT");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "SCAN VERTX");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "OPENING");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "OPENING CURSOR");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "CLOSING");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "CLOSING CURSOR");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "SCROLL UP LEFT");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "SCROLL UP RIGHT");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "SCROLL DOWN LEFT");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "SCROLL DOWN RIGHT");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "GROW UP");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "GROW DOWN");
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_MID);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,true);
  ListaEfectos = pElemRef;

  // Create vertical scrollbar for listbox
  pElemRef = gslc_ElemXSliderCreate(&m_gui,E_BarraListaEfectos,MenuMensajePersonalizado,&m_sListScroll4,
          (gslc_tsRect){10+260-2-25,125+4,25,135-8},0,26,0,5,true);
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){208,148,234}),((gslc_tsColor){58,5,139}),((gslc_tsColor){208,148,234}));
  gslc_ElemXSliderSetPosFunc(&m_gui,pElemRef,&CbSlidePos);
  BarraListaEfectos = pElemRef;

  // Create seekbar E_BarraVelocidadPersonalizada 
  pElemRef = gslc_ElemXSeekbarCreate(&m_gui,E_BarraVelocidadPersonalizada,MenuMensajePersonalizado,&m_sXSeekbar5,
    (gslc_tsRect){300,232,150,30},100,500,100,
    4,2,8,((gslc_tsColor){208,148,234}),GSLC_COL_WHITE,GSLC_COL_WHITE,false);
  gslc_ElemXSeekbarSetPosFunc(&m_gui,pElemRef,&CbSlidePos);
  gslc_ElemXSeekbarSetStyle(&m_gui,pElemRef,true,((gslc_tsColor){208,148,234}),true,((gslc_tsColor){58,5,139}),
    9,5,GSLC_COL_CYAN);
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){58,5,139}),((gslc_tsColor){58,5,139}),((gslc_tsColor){58,5,139}));
  BarraVelocidadPersonalizada = pElemRef;
  
  // Create E_ELEM_TEXT34 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT34,MenuMensajePersonalizado,(gslc_tsRect){290,215,175,13},
    (char*)"100        VEL        500",0,E_FREESANSBOLD9);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){58,5,139}));
  
  // create E_BotonDosFilas button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_BotonDosFilas,MenuMensajePersonalizado,
    (gslc_tsRect){300,140,150,40},(char*)"DOS FILAS",0,E_FREESANS9,&CbBtnCommon);
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){58,5,139}),((gslc_tsColor){58,5,139}),((gslc_tsColor){208,148,234}));
  gslc_ElemSetRoundEn(&m_gui, pElemRef, true);

  // -----------------------------------
  // PAGE: MenuIluminacionPanel
  
  
  // create BotonVolver6 button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,BotonVolver6,MenuIluminacionPanel,
    (gslc_tsRect){140,270,210,40},(char*)"VOLVER",0,E_FREESANS9,&CbBtnCommon);
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){208,148,234}),((gslc_tsColor){58,5,139}),((gslc_tsColor){58,5,139}));
  gslc_ElemSetRoundEn(&m_gui, pElemRef, true);
  
  // Create TituloMenuIluminacionPanel text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,TituloMenuIluminacionPanel,MenuIluminacionPanel,(gslc_tsRect){115,80,250,13},
    (char*)"MENU ILUMINACION PANEL",0,E_FREESANSBOLD9);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){235,148,207}));

  // Create seekbar E_BarraIluminacionPersonalizadaPanel 
  pElemRef = gslc_ElemXSeekbarCreate(&m_gui,E_BarraIluminacionPersonalizadaPanel,MenuIluminacionPanel,&m_sXSeekbar3,
    (gslc_tsRect){345,193,100,30},1,10,PanelEmergencia.GetBrillo(),
    4,2,8,((gslc_tsColor){208,148,234}),GSLC_COL_WHITE,GSLC_COL_WHITE,false);
  gslc_ElemXSeekbarSetPosFunc(&m_gui,pElemRef,&CbSlidePos);
  gslc_ElemXSeekbarSetStyle(&m_gui,pElemRef,true,((gslc_tsColor){208,148,234}),false,((gslc_tsColor){58,5,139}),
    9,3,GSLC_COL_CYAN);
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){58,5,139}),((gslc_tsColor){58,5,139}),GSLC_COL_BLACK);
  BarraIluminacionPersonalizadaPanel = pElemRef;
  
  // Create E_TextoIluminacionPersonalizada text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_TextoIluminacionPersonalizada,MenuIluminacionPanel,(gslc_tsRect){15,203,291,13},
    (char*)"ILUMINACION PERSONALIZADA:",0,E_FREESANSBOLD9);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){58,5,139}));
  
  // Create E_TextoLuzAmbiente text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_TextoLuzAmbiente,MenuIluminacionPanel,(gslc_tsRect){15,128,231,15},
    (char*)"NIVEL DE LUZ AMBIENTE:",0,E_FREESANSBOLD9);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){58,5,139}));
  
  // Create E_VariableTextoLuzAmbiente runtime modifiable text
  static char m_sDisplayText23[7] = "0";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_VariableTextoLuzAmbiente,MenuIluminacionPanel,(gslc_tsRect){260,128,64,15},
    (char*)m_sDisplayText23,7,E_FREESANSBOLD9);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_MID);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,true);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){208,148,234}));
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){58,5,139}),GSLC_COL_BLACK,GSLC_COL_BLACK);
  VariableTextoLuzAmbiente = pElemRef;
  
  // Create E_TextoAutoIluminacionPanel text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_TextoAutoIluminacionPanel,MenuIluminacionPanel,(gslc_tsRect){340,128,52,13},
    (char*)"AUTO",0,E_FREESANSBOLD9);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){58,5,139}));
  
  // Create toggle button E_BotonAutoIluminacionPanel
  pElemRef = gslc_ElemXTogglebtnCreate(&m_gui,E_BotonAutoIluminacionPanel,MenuIluminacionPanel,&m_asXToggle2,
    (gslc_tsRect){400,123,50,20},((gslc_tsColor){58,5,139}),((gslc_tsColor){208,148,234}),((gslc_tsColor){200,200,200}),
    true,false,&CbBtnCommon);
  BotonAutoIluminacionPanel = pElemRef;
  
  // Create E_ELEM_TEXT26 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT26,MenuIluminacionPanel,(gslc_tsRect){340,178,113,13},
    (char*)"1                 10",0,E_FREESANSBOLD9);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){58,5,139}));

  // -----------------------------------
  // PAGE: MenuMensajePersonalizadoDos
  
  
  // Create E_EntradaTextoSuperior text input field
  static char m_sInputText2[16] = "";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_EntradaTextoSuperior,MenuMensajePersonalizadoDos,(gslc_tsRect){20,100,190,25},
    (char*)m_sInputText2,16,E_FREESANSBOLD9);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_MID);
  gslc_ElemSetTxtMargin(&m_gui,pElemRef,5);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){58,5,139}));
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){208,148,234}),GSLC_COL_WHITE,((gslc_tsColor){208,148,234}));
  gslc_ElemSetFrameEn(&m_gui,pElemRef,true);
  gslc_ElemSetClickEn(&m_gui, pElemRef, true);
  gslc_ElemSetTouchFunc(&m_gui, pElemRef, &CbBtnCommon);
  EntradaTextoSuperior = pElemRef;
  
  // Create E_EntradaTextoInferior text input field
  static char m_sInputText3[16] = "";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_EntradaTextoInferior,MenuMensajePersonalizadoDos,(gslc_tsRect){260,100,190,25},
    (char*)m_sInputText3,16,E_FREESANSBOLD9);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_MID);
  gslc_ElemSetTxtMargin(&m_gui,pElemRef,5);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){58,5,139}));
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){208,148,234}),GSLC_COL_WHITE,((gslc_tsColor){208,148,234}));
  gslc_ElemSetFrameEn(&m_gui,pElemRef,true);
  gslc_ElemSetClickEn(&m_gui, pElemRef, true);
  gslc_ElemSetTouchFunc(&m_gui, pElemRef, &CbBtnCommon);
  EntradaTextoInferior = pElemRef;
   
  // Create wrapping box for listbox E_ListaEfectosSuperior and scrollbar
  pElemRef = gslc_ElemCreateBox(&m_gui,GSLC_ID_AUTO,MenuMensajePersonalizadoDos,(gslc_tsRect){20,130,190,80});
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){208,148,234}),((gslc_tsColor){58,5,139}),((gslc_tsColor){235,148,207}));
  
  // Create listbox
  pElemRef = gslc_ElemXListboxCreate(&m_gui,E_ListaEfectosSuperior,MenuMensajePersonalizadoDos,&m_sListbox5,
    (gslc_tsRect){20+2,130+4,190-4-25,80-7},E_BUILTIN5X8,
    (uint8_t*)&m_acListboxBuf5,sizeof(m_acListboxBuf5),0);
  gslc_ElemXListboxSetSize(&m_gui, pElemRef, 3, 1); // 3 rows, 1 columns
  gslc_ElemXListboxItemsSetSize(&m_gui, pElemRef, -1, 18);
  gslc_ElemSetTxtMarginXY(&m_gui, pElemRef, 5, 5);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){208,148,234}),((gslc_tsColor){58,5,139}),((gslc_tsColor){235,148,207}));
  gslc_ElemXListboxSetSelFunc(&m_gui, pElemRef, &CbListbox);
  gslc_ElemXListboxItemsSetGap(&m_gui, pElemRef, 5,GSLC_COL_WHITE);
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "NO EFFECT");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "PRINT");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "SCROLL UP");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "SCROLL DOWN");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "SCROLL LEFT");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "SCROLL RIGHT");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "SPRITE");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "SLICE");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "MESH");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "FADE");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "DISSOLVE");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "BLINDS");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "RANDOM");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "WIPE");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "WIPE CURSOR");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "SCAN HORIZ");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "SCAN HORIZX");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "SCAN VERT");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "SCAN VERTX");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "OPENING");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "OPENING CURSOR");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "CLOSING");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "CLOSING CURSOR");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "SCROLL UP LEFT");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "SCROLL UP RIGT");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "SCROLL DOWN LEFT");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "SCROLL DOWN RIGHT");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "GROW UP");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "GROW DOWN");
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_MID);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,true);
  ListaEfectosSuperior = pElemRef;

  // Create vertical scrollbar for listbox
  pElemRef = gslc_ElemXSliderCreate(&m_gui,E_BarraListaEfectosSuperior,MenuMensajePersonalizadoDos,&m_sListScroll5,
          (gslc_tsRect){20+190-2-25,130+4,25,80-8},0,25,0,5,true);
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){208,148,234}),((gslc_tsColor){58,5,139}),((gslc_tsColor){208,148,234}));
  gslc_ElemXSliderSetPosFunc(&m_gui,pElemRef,&CbSlidePos);
  BarraListaEfectosSuperior = pElemRef;
  
  // create E_BotonVolverUnaFila button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_BotonVolverUnaFila,MenuMensajePersonalizadoDos,
    (gslc_tsRect){140,270,210,40},(char*)"VOLVER",0,E_FREESANS9,&CbBtnCommon);
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){208,148,234}),((gslc_tsColor){58,5,139}),((gslc_tsColor){58,5,139}));
  gslc_ElemSetRoundEn(&m_gui, pElemRef, true);
  
  // Create E_ELEM_TEXT35 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT35,MenuMensajePersonalizadoDos,(gslc_tsRect){20,80,190,13},
    (char*)"LINEA SUPERIOR",0,E_FREESANS9);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_MID);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){235,148,207}));
  
  // Create E_ELEM_TEXT36 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT36,MenuMensajePersonalizadoDos,(gslc_tsRect){260,80,190,13},
    (char*)"LINEA INFERIOR",0,E_FREESANS9);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_MID);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){235,148,207}));
   
  // Create wrapping box for listbox E_ListaEfectosInferior and scrollbar
  pElemRef = gslc_ElemCreateBox(&m_gui,GSLC_ID_AUTO,MenuMensajePersonalizadoDos,(gslc_tsRect){260,130,190,80});
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){208,148,234}),((gslc_tsColor){58,5,139}),((gslc_tsColor){235,148,207}));
  
  // Create listbox
  pElemRef = gslc_ElemXListboxCreate(&m_gui,E_ListaEfectosInferior,MenuMensajePersonalizadoDos,&m_sListbox7,
    (gslc_tsRect){260+2,130+4,190-4-25,80-7},E_BUILTIN5X8,
    (uint8_t*)&m_acListboxBuf7,sizeof(m_acListboxBuf7),0);
  gslc_ElemXListboxSetSize(&m_gui, pElemRef, 3, 1); // 3 rows, 1 columns
  gslc_ElemXListboxItemsSetSize(&m_gui, pElemRef, -1, 18);
  gslc_ElemSetTxtMarginXY(&m_gui, pElemRef, 5, 5);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){208,148,234}),((gslc_tsColor){58,5,139}),((gslc_tsColor){235,148,207}));
  gslc_ElemXListboxSetSelFunc(&m_gui, pElemRef, &CbListbox);
  gslc_ElemXListboxItemsSetGap(&m_gui, pElemRef, 5,GSLC_COL_WHITE);
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "NO EFFECT");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "PRINT");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "SCROLL UP");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "SCROLL DOWN");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "SCROLL LEFT");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "SCROLL RIGHT");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "SPRITE");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "SLICE");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "MESH");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "FADE");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "DISSOLVE");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "BLINDS");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "RANDOM");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "WIPE");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "WIPE CURSOR");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "SCAN HORIZ");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "SCAN HORIZX");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "SCAN VERT");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "SCAN VERTX");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "OPENING");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "OPENING CURSOR");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "CLOSING");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "CLOSING CURSOR");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "SCROLL UP LEFT");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "SCROLL UP RIGT");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "SCROLL DOWN LEFT");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "SCROLL DOWN RIGHT");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "GROW UP");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "GROW DOWN");
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_MID);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,true);
  ListaEfectosInferior = pElemRef;

  // Create vertical scrollbar for listbox
  pElemRef = gslc_ElemXSliderCreate(&m_gui,E_BarraListaEfectosInferior,MenuMensajePersonalizadoDos,&m_sListScroll7,
          (gslc_tsRect){260+190-2-25,130+4,25,80-8},0,25,0,5,true);
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){208,148,234}),((gslc_tsColor){58,5,139}),((gslc_tsColor){208,148,234}));
  gslc_ElemXSliderSetPosFunc(&m_gui,pElemRef,&CbSlidePos);
  BarraListaEfectosInferior = pElemRef;

  // Create seekbar E_BarraVelocidadSuperior 
  pElemRef = gslc_ElemXSeekbarCreate(&m_gui,E_BarraVelocidadSuperior,MenuMensajePersonalizadoDos,&m_sXSeekbar7,
    (gslc_tsRect){30,230,200,20},100,500,100,
    4,2,8,((gslc_tsColor){208,148,234}),GSLC_COL_WHITE,GSLC_COL_WHITE,false);
  gslc_ElemXSeekbarSetPosFunc(&m_gui,pElemRef,&CbSlidePos);
  gslc_ElemXSeekbarSetStyle(&m_gui,pElemRef,true,((gslc_tsColor){208,148,234}),true,((gslc_tsColor){58,5,139}),
    9,5,GSLC_COL_CYAN);
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){58,5,139}),((gslc_tsColor){58,5,139}),((gslc_tsColor){58,5,139}));
  BarraVelocidadSuperior = pElemRef;
  
  // Create E_ELEM_TEXT37 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT37,MenuMensajePersonalizadoDos,(gslc_tsRect){20,215,218,13},
    (char*)"100             VEL            500 ",0,E_FREESANSBOLD9);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){58,5,139}));

  // Create seekbar E_BarraVelocidadInferior 
  pElemRef = gslc_ElemXSeekbarCreate(&m_gui,E_BarraVelocidadInferior,MenuMensajePersonalizadoDos,&m_sXSeekbar8,
    (gslc_tsRect){265,230,200,20},100,500,100,
    4,2,8,((gslc_tsColor){208,148,234}),GSLC_COL_WHITE,GSLC_COL_WHITE,false);
  gslc_ElemXSeekbarSetPosFunc(&m_gui,pElemRef,&CbSlidePos);
  gslc_ElemXSeekbarSetStyle(&m_gui,pElemRef,true,((gslc_tsColor){208,148,234}),true,((gslc_tsColor){58,5,139}),
    9,5,GSLC_COL_CYAN);
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){58,5,139}),((gslc_tsColor){58,5,139}),((gslc_tsColor){58,5,139}));
  BarraVelocidadInferior = pElemRef;
  
  // Create E_ELEM_TEXT38 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT38,MenuMensajePersonalizadoDos,(gslc_tsRect){255,215,218,13},
    (char*)"100             VEL            500 ",0,E_FREESANSBOLD9);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){58,5,139}));

  // -----------------------------------
  // PAGE: E_POP_KEYPAD_ALPHA
  
  static gslc_tsXKeyPadCfg_Alpha sCfgTx;
  sCfgTx = gslc_ElemXKeyPadCfgInit_Alpha();
  m_pElemKeyPadAlpha = gslc_ElemXKeyPadCreate_Alpha(&m_gui, E_ELEM_KEYPAD_ALPHA, E_POP_KEYPAD_ALPHA,
    &m_sKeyPadAlpha, 65, 80, E_BUILTIN5X8, &sCfgTx);
  gslc_ElemXKeyPadValSetCb(&m_gui, m_pElemKeyPadAlpha, &CbKeypad);
//<InitGUI !End!>

//<Startup !Start!>
//<Startup !End!>

}

#endif // end _GUISLICE_GEN_H
