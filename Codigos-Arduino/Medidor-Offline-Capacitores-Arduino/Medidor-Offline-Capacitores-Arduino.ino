#include "Medidor_Libraries.h"
#include "Medidor_Settings.h"  
#include "Medidor_Functions.h"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
     
void setup() {
  setUpMedidorSettings();
}

void loop() {
  waterMeasurement();
}
