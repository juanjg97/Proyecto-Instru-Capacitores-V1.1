//----------------------------------------Librerias para que la ESP32 se conecte a internet
#ifdef ESP32
  #include <WiFi.h>
#else
  #include <ESP8266WiFi.h>
#endif
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>   
#include <ArduinoJson.h>

//-------------------------Configuración del token del Bot en telegram y Id's de usuario-----------------
/*
// Your Bot Token (Get from Botfather)
#define BOTtoken "5361211948:AAG80HAokxf_zrrczkXBmz1kWOcpEpor0tM" 
// Id de los usuarios autorizados para usar el bot (generado por telegram)
#define CHAT_ID   "1289944523"
#define CHAT_ID_2 "1284494200"
*/
//-----------------------------------------------------------------------------------------------
#ifdef ESP8266
  X509List cert(TELEGRAM_CERTIFICATE_ROOT);
#endif

WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);

// Revisa nuevos mensajes cada 1 segundo.
int botRequestDelay = 500;
unsigned long lastTimeBotRan;

//Se declara el pin 2 del ESP32 para hacer pruebas con el led integrado
const int ledPin = 23;
bool ledState = LOW;
