int TRIG = 36;
int ECO = 39;
int DURACION;

int DISTANCIA;  // cm
int ALTO = 80;  // cm
int LARGO = 10; // cm
int ANCHO = 10; // cm
float volumen_total = (ALTO) * (LARGO) * (ANCHO);

float Pi = 3.1415;
float radio = 15;
float altura = 50;
float volumen_total_c = (Pi) * (radio) * (radio) * (altura);

void setUpHcSettings()
{
  pinMode(TRIG, OUTPUT);
  pinMode(ECO, INPUT);
}
