//-----------------------------------Se incluyen las bibliotecas realizadas por el usuario
#include "Token_Users_Wifi.h"      //Biblioteca con la configuración de redes wifi, token de los usuarios y del bot
#include "BotTelegram_Libraries.h" //Bibliotecas para que la ESP32 se conecte a internet
#include "BotTelegram_Settings.h"  //Biblioteca con la configuración para que la ESP32 se conecte a internet
#include "Hc-sr04_Settings.h"      //Biblioteca para la configuración para el echo, trigger y variables
#include "Hc-sr04_Functions.h"     //Biblioteca con función que modifica la variable distancia para dar su valor actual
#include "BotTelegram_Functions.h" //Biblioteca con las funciones para administrar los mensajes y las funciones de otras bibliotecas

/* ******************************** Configuración del SetUp ************************************** */
void setup()
{
  setUpBotSettings();
  setUpHcSettings();
  bot.sendMessage("1289944523", "\n*************Servicio activo*************\n", "");
}
/* ******************************** Configuración del Loop ********************************************* */
void loop()
{
  measuringDistance();
  usinghandleNewMessages();
  Serial.println("------------------");
  Serial.print("Distancia: ");
  Serial.println(DISTANCIA);
  Serial.print("Capacidad: ");
  Serial.println(capacidad);
  Serial.print("Volumen vacío: ");
  Serial.println(volumen_vacio_c);
  Serial.print("Volúmen agua: ");
  Serial.println(volumen_actual_c);
}
