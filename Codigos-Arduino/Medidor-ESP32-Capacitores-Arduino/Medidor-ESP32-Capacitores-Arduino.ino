int TRIG = 36;      // trigger en pin 10
int ECO = 39;      // echo en pin 9

int DURACION;
int DISTANCIA;

void setup()
{
  pinMode(TRIG, OUTPUT);  // trigger como salida
  pinMode(ECO, INPUT);    // echo como entrada
  Serial.begin(115200);     // inicializacion de comunicacion serial a 115200 bps

}

void loop()
{
  
  digitalWrite(TRIG, HIGH);     // generacion del pulso a enviar
  delay(1);                     // al pin conectado al trigger
  digitalWrite(TRIG, LOW);      // del sensor
  
  DURACION = pulseIn(ECO, HIGH);  // con funcion pulseIn se espera un pulso
                                  // alto en Echo
  DISTANCIA = DURACION / 58.2;    // distancia medida en centimetros
  Serial.println(DISTANCIA);    // envio de valor de distancia por monitor serial
  
  delay(200);       // demora entre datos
  
}
