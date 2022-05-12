void measuringDistance()
{
  digitalWrite(TRIG, HIGH);      // generacion del pulso a enviar
  delay(1);                      // al pin conectado al trigger
  digitalWrite(TRIG, LOW);       // del sensor
  DURACION = pulseIn(ECO, HIGH); // con funcion pulseIn se espera un pulso
  DISTANCIA = DURACION / 58.2;   // distancia medida en centimetros
  delay(200);                    // demora entre datos
}
