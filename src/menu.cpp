#include "menu.h"
#include "display.h"
#include "inputs.h"
#include "assets.h"

const char* options[] = {
  "Snake",
  "Pong",
  "Tetris",
  "Config"
};

int totalOptions = sizeof(options) / sizeof(options[0]);
int indexMenu = 0;

void MenuInit() {
    indexMenu = 0;
}

void MenuUpdate() {
    if (isPressed(BTN_RIGHT)) {
        indexMenu++;
        if (indexMenu >= totalOptions) indexMenu = 0;
    }

    if (isPressed(BTN_LEFT)) {
        indexMenu--;
        if (indexMenu < 0) indexMenu = totalOptions - 1;
    }
}

void MenuRender() {
    ClearDisplay();
    display.setCursor(20, 25);
    display.setTextSize(1);
    display.print(options[indexMenu]);
    display.display();
}


