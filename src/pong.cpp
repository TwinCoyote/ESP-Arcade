#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define ANCHO_PANTALLA 128
#define ALTO_PANTALLA 64
#define DIRECCION_OLED 0x3C



Adafruit_SSD1306 display(ANCHO_PANTALLA,ALTO_PANTALLA,&Wire,-1);

int direccion = 1;

const int botonArriba     = 2;
const int botonAbajo      = 19;
const int botonDerecha    = 4;
const int botonIzquierda  = 16;
const int botonSelect     = 5;

const int len_block = 4;
const int width = 12;


int x = 4;
int y = 0;


enum class states{
  INIT,
  START,
  GAME_OVER,
  AGAIN
};

void direcciones(){
    if (direccion == 0) y -= len_block; 
    if (direccion == 1) y += len_block;
}

void buttons_read() {
    if (digitalRead(botonArriba) == LOW) {
        direccion = 0;
    } else if (digitalRead(botonAbajo) == LOW) {
        direccion = 1;
    } 
}

void screen_limits(){
  if(y<=0) y = 0;
  else if(y >ALTO_PANTALLA - width) y = 52;  
}


void setup() {
  Serial.begin(9600);
    if (!display.begin(SSD1306_SWITCHCAPVCC, DIRECCION_OLED)) {
        Serial.println(F("Error en la asignación de SSD1306"));
        for (;;);
    }

    display.clearDisplay();

    pinMode(botonArriba, INPUT_PULLUP);
    pinMode(botonAbajo, INPUT_PULLUP);
    pinMode(botonDerecha, INPUT_PULLUP);
    pinMode(botonIzquierda, INPUT_PULLUP);
    pinMode(botonSelect, INPUT_PULLUP);


}

void loop(){
  display.clearDisplay();

  buttons_read();
  direcciones();
  screen_limits();
  display.fillRect(x, y, len_block, width, SSD1306_WHITE);
  display.display();

  delay(120);
}

