
void setUpBotSettings()
{
    Serial.begin(115200);
// get UTC time via NTP
#ifdef ESP8266
    configTime(0, 0, "pool.ntp.org");
    // Add root certificate for api.telegram.org
    client.setTrustAnchors(&cert);
#endif
    // Se define el número de pin como salida
    pinMode(ledPin, OUTPUT);
    // El led comienza apagado, ledState se declara como LOW
    digitalWrite(ledPin, ledState);
    // Connect to Wi-Fi
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
#ifdef ESP32
    // Add root certificate for api.telegram.org
    client.setCACert(TELEGRAM_CERTIFICATE_ROOT);
#endif
    // Se muestra en el monitor serial que se está conectando al wi-fi
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(1000);
        Serial.println("Conectando al WiFi ...");
    }
    // Una vez conectado a la red imprime el ESP32 Local IP Address
    Serial.print("Se ha establecido la conexión a la dirección IP: ");
    Serial.println(WiFi.localIP());
}
