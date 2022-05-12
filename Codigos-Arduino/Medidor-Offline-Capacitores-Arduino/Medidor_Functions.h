// Función para medir el volúmen de agua en un tinaco cúbico de 2x2x2
void waterMeasurement()
{
    // Variables para el sensor ultrasónico
    int duration;
    float distance;
    float water_height;
    // Variables para el volúmen del tinaco
    int side = 2;
    float volume;
    // Disparo de un pulso
    digitalWrite(TRIG, HIGH);
    delay(1);
    digitalWrite(TRIG, LOW);
    // Lectura de la duración del pulso HIGH
    duration = pulseIn(ECO, HIGH);
    // Cálculo de la distance
    distance = (duration / 58.2) / 100;
    water_height = side - distance;
    // Impresión de la distancia en el monitor serial
    Serial.print("Distancia entre en sensor y el agua: ");
    Serial.print(distance);
    Serial.println(" [m]");
    //-------------------------------------------------------
    Serial.print("Altura de la columna de agua: ");
    Serial.print(water_height);
    Serial.println(" [m]");
    //-------------------------------------------------------
    volume = side * side * (water_height);
    Serial.print("Volumen de agua actual: ");
    Serial.print(volume);
    Serial.println(" [m^3]");
    Serial.println("-------------------------------");
    Serial.println("");
    delay(1500);
}