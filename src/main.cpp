#include <Arduino.h>
#include "display.h"
#include "assets.h"
#include "inputs.h"
#include "menu.h"

unsigned long logoTimer = 0;
bool showingLogo = true;

void setup() {
    Serial.begin(9600);

    InitDisplay();
    InitButtons();
    MenuInit();

    // mostrar logo
    DrawBitmap(Logo_R, logoWidth, logoHeight);
    logoTimer = millis();
}

void loop() {

    // 1. mostrar logo por 2 segundos
    if (showingLogo) {
        if (millis() - logoTimer > 2000) {
            showingLogo = false;
            ClearDisplay();
        }
        return;
    }

    // 2. actualización del menú
    MenuUpdate();

    // 3. dibujar el menú
    MenuRender();
}
