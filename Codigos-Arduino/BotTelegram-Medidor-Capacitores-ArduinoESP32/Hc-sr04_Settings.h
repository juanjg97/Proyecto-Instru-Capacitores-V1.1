int TRIG = 36;
int ECO = 39;
int DURACION;

int DISTANCIA;  // cm

int ALTO = 80;  // cm
int LARGO = 10; // cm
int ANCHO = 10; // cm
float volumen_total = (ALTO) * (LARGO) * (ANCHO);

// Modificar datos
float Pi = 3.1415;
float radio = 7.5;
float altura = 20-12;
float volumen_total_c = (Pi) * (radio) * (radio) * (altura);

void setUpHcSettings()
{
  pinMode(TRIG, OUTPUT);
  pinMode(ECO, INPUT);
}
