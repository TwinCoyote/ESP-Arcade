#include "display.h"  // Incluye su propio header
#include "assets.h"
Adafruit_SSD1306 display(ANCHO_PANTALLA, ALTO_PANTALLA, &Wire, OLED_RESET);

void InitDisplay() {
  display.clearDisplay();
   //Se presenta logo principal
  display.drawBitmap(0, 0, Logo_R, 128, 64, 1);
  display.display();
}



void ClearDisplay(){
  display.clearDisplay();
  display.display();
}

void menuDisplay() {
  display.clearDisplay();
  display.display();
  display.drawBitmap(0,0, menu_principal, 128, 64, 1);
}