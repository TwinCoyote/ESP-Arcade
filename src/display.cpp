#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "display.h"
#include "assets.h"

Adafruit_SSD1306 display(128, 64, &Wire, -1);

void InitDisplay(){
    // Inicializar pantalla (dirección I2C típica 0x3C)
    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)){
        // En producción podrías agregar algún manejo de error
        return;
    }
    display.clearDisplay();
    display.display();
}

void ClearDisplay() {
    display.clearDisplay();
}

void DrawBitmap(const unsigned char* bitmap, int w, int h){
    display.clearDisplay();
    display.drawBitmap(0, 0, bitmap, w, h, 1);
    display.display();
}

void DrawLogo() {
    DrawBitmap(Logo_R, logoWidth, logoHeight);
}

void DrawMenu() {
    DrawBitmap(menu_principal, logoWidth, logoHeight);
}

