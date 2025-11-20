#ifndef MENU_H
#define MENU_H

#include <Arduino.h>

enum Estado {
  MENU,
  Snake,
  Tetris,
  Pong,
  Config
};

extern Estado estadoActual;
extern int indexMenu;

void initMod();
void menuCarrusel();

#endif
