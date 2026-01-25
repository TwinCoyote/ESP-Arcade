#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define ANCHO_PANTALLA 128
#define ALTO_PANTALLA 64
#define DIRECCION_OLED 0x3C

Adafruit_SSD1306 display(ANCHO_PANTALLA,ALTO_PANTALLA,&Wire,-1);

int direccion = 0;

const int botonArriba     = 2;
const int botonAbajo      = 19;
const int botonDerecha    = 4;
const int botonIzquierda  = 16;

int x = 0;   // posición X
int y = 0;   // posición Y
int largo = 3;

int rans = 40;
int ran  = 30;

int comidaX = 0;
int comidaY = 0;

const int len_block = 3;

void setup() {
    if (!display.begin(SSD1306_SWITCHCAPVCC, DIRECCION_OLED)) {
        Serial.println(F("Error en la asignación de SSD1306"));
        for (;;);
    }

    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println("Iniciado");
    display.display();

    pinMode(botonArriba, INPUT_PULLUP);
    pinMode(botonAbajo, INPUT_PULLUP);
    pinMode(botonDerecha, INPUT_PULLUP);
    pinMode(botonIzquierda, INPUT_PULLUP);
}

void snake_move(int move_x, int move_y) {
  if (digitalRead(botonDerecha) == LOW){
    for(int i; i<largo; i++){
      display.fillRect(move_x-i, move_y, 3, 3, SSD1306_WHITE);
    }
  }

  if(digitalRead(botonIzquierda) == LOW){
    for(int i; i<largo; i++){
      display.fillRect(move_x+i,move_y,3, 3, SSD1306_WHITE);
    }
  }

  if(digitalRead(botonArriba) == LOW){
    for(int i; i<largo; i++){
      display.fillRect(move_x,move_y+i,3, 3, SSD1306_WHITE);
    }
  }

  if(digitalRead(botonAbajo) == LOW){
    for(int i; i<largo; i++){
      display.fillRect(move_x,move_y-i,3, 3, SSD1306_WHITE);
    }
  }
  // display.fillRect(move_x-2, move_y, 3, 3, SSD1306_WHITE);
  // display.fillRect(move_x-1, move_y, 3, 3, SSD1306_WHITE);
  // display.fillRect(move_x, move_y, 3, 3, SSD1306_WHITE);
}

void random_food() {
    comidaX = random(0, 42) * len_block;
    comidaY = random(0, 21) * len_block;

    display.display();
    display.fillRect(comidaX, comidaY, 3, 3, SSD1306_WHITE);
}

void check_food() {
    if (x == comidaX && y == comidaY) {
        random_food();
        largo++;
    }
}

void move() {
    if (digitalRead(botonArriba) == LOW) {
        direccion = 2;
    }
    if (digitalRead(botonAbajo) == LOW) {
        direccion = 19;
    }
    if (digitalRead(botonDerecha) == LOW) {
        direccion = 4;
    }
    if (digitalRead(botonIzquierda) == LOW) {
        direccion = 16;
    }

    display.display();

    if (direccion == 2) {
        y = y - 1;          // Arriba
    } else if (direccion == 19) {
        y = y + 1;          // Abajo
    } else if (direccion == 4) {
        x = x + 1;          // Derecha
    } else if (direccion == 16) {
        x = x - 1;          // Izquierda
    }

    display.fillRect(x, y, largo, 3, SSD1306_WHITE);
    display.display();
}

void loop() {
    display.clearDisplay();

    check_food();
    display.fillRect(comidaX, comidaY, 3, 3, SSD1306_WHITE);

    move();
    snake_move(x, y);

    display.display();
    delay(100);
}
