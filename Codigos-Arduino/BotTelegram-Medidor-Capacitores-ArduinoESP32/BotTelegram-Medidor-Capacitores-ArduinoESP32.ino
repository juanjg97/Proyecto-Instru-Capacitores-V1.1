//-----------------------------------Se incluyen las bibliotecas realizadas por el usuario
#include "Token_Users_Wifi.h"
#include "BotTelegram_Libraries.h"
#include "BotTelegram_Settings.h"
#include "Hc-sr04_Settings.h"
#include "Hc-sr04_Functions.h"
#include "BotTelegram_Functions.h"


/* ******************************** Configuración del SetUp ************************************** */
void setup() {
  setUpBotSettings();
  setUpHcSettings();

}
/* ******************************** Configuración del Loop ********************************************* */
void loop() {
  measuringDistance();
  usinghandleNewMessages();
}
