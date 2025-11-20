#include "menu.h"
#include "display.h"
#include "assets.h"
#include "inputs.h"

const char* options[]{
  "Snake",
  "Pong",
  "Tetris",
  "Configuraciones"
};

int totalOptions = sizeof(options) / sizeof(options[0]);
int indexMenu = 0;


//modulo para botones de inicio
void initMod() {
  if (isPressed(BTN_RIGHT)){
    indexMenu++;
    if (indexMenu >= totalOptions){
      indexMenu = 0;
    }
  }
  if(isPressed(BTN_LEFT)){
    indexMenu--;
    if(indexMenu<0){
      indexMenu = totalOptions -1;
    }
  }
}


// Carrusel con palabras (Provisional en lo que busco logos)
void menuCarrusel(){
  if (isPressed(BTN_OK)) {
    switch (indexMenu) {
      case 0:
        estadoActual = Snake;
        break;
      case 1:
        estadoActual = Pong;
        break;
      case 2:
        estadoActual = Tetris;
        break;
      case 3:
        estadoActual = Config;
        break;
    }
  }
  ClearDisplay();
  display.setCursor(25,15);
  display.setTextSize(1);
  display.print(options[indexMenu]);
  display.display();
}
