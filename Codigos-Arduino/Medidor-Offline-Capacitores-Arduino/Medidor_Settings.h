void setUpMedidorSettings()
{
    // Declaracion pines
    pinMode(TRIG, OUTPUT);
    pinMode(ECO, INPUT);
    // Inicialización de componentes y comunicación serial
    lcd.begin(16, 2); // Inicialización LCD
    // Modificar esta valor cuando se use la ESP32
    Serial.begin(9600);
}
