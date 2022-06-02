//----------------------------------------Librerias para que la ESP32 se conecte a internet
#ifdef ESP32
#include <WiFi.h>
#else
#include <ESP8266WiFi.h>
#endif
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>

#ifdef ESP8266
X509List cert(TELEGRAM_CERTIFICATE_ROOT);
#endif

WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);

// Revisa nuevos mensajes cada 1 segundo.
int botRequestDelay = 500;
unsigned long lastTimeBotRan;

// Se declara el pin 2 del ESP32 para hacer pruebas con el led integrado
const int ledPin = 14;
bool ledState = LOW;
