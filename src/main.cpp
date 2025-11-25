#include <Arduino.h>
#include "display.h"
#include "assets.h"
#include "inputs.h"
#include "menu.h"
#include <iostream>

unsigned long logoTimer = 0;
bool showingLogo = true;
unsigned long previusTime = 0;

const char* options[] = {
  "Snake",
  "Pong",
  "Tetris",
  "Config"
};


void setup() {
    Serial.begin(9600);
    InitDisplay();
    InitButtons();
    MenuInit();

    // mostrar logo
    DrawBitmap(Logo_R, logoWidth, logoHeight);
    }

void loop() {
    unsigned long currentTime = millis();
    if (showingLogo) {
        if (currentTime - previusTime>= 2000) {
            showingLogo = false;
            ClearDisplay();
            previusTime = currentTime; 
        }
        return;
    }



    // 2. actualización del menú
    MenuUpdate();

    // 3. dibujar el menú
    MenuRender();
}
