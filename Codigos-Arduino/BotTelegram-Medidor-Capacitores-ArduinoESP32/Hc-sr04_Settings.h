int TRIG = 36;
int ECO = 39;
int DURACION;

int DISTANCIA;  // cm
int ALTO = 80;  // cm
int LARGO = 10; // cm
int ANCHO = 10; // cm
int volumen_total = (ALTO) * (LARGO) * (ANCHO);

void setUpHcSettings()
{
  pinMode(TRIG, OUTPUT);
  pinMode(ECO, INPUT);
}
