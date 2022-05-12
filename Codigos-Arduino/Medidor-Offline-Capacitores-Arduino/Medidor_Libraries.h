//-------------------Librerías para los componentes
#include <LiquidCrystal.h> //Librería LCD

//-------------------Creación de objetos
//-------------RS,EN,D4,D5,D6,D7             //Referencia pines display
LiquidCrystal lcd(7, 6, 5, 4, 3, 2); // Objeto LCD

//-------------------Número de PIN para conexión
#define TRIG 9 // Trigger del sensor ultrasónico
#define ECO 8  // Eco del sensor ultrasónico
