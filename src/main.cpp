#include <Arduino.h>
#include <display.h>
#include <assets.h>
#include <inputs.h>
#include <menu.h>

unsigned long logoStartTime = 0;
bool logoDisplayed = false; 
bool menuDisplayed = false;

Estado estadoActual = MENU;

void setup() {
  Serial.begin(9600);

  if(!display.begin(SSD1306_SWITCHCAPVCC, DIRECCION_PANTALLA)) {
    Serial.println(F("Fallo en la asignacion de SSD1306"));
  }
  InitButtons();
  ClearDisplay();
  logoStartTime = millis();
  logoDisplayed = true;
}

void loop() {
  if (logoDisplayed && !menuDisplayed && (millis() - logoStartTime >= 2000)) {
    ClearDisplay();
    InitDisplay();
    display.display();
    menuDisplayed = true;
  }

  switch(estadoActual){
    case MENU:
      initMod();
      menuCarrusel();
      break;

    case Snake:
      // TODO: ingresar el juego Snake
      break;

    case Tetris:
      // TODO: ingresar el juego Tetris
      break;

    case Pong:
      // TODO: ingresar el juego Pong
      break;

    case Config:
      // TODO: ingresar configuración
      break;     
      
  }
}

