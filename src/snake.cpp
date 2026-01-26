#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define ANCHO_PANTALLA 128
#define ALTO_PANTALLA 64
#define DIRECCION_OLED 0x3C
#define LONGITUD_MAXIMA 50



Adafruit_SSD1306 display(ANCHO_PANTALLA,ALTO_PANTALLA,&Wire,-1);

int direccion = 5;

const int botonArriba     = 2;
const int botonAbajo      = 19;
const int botonDerecha    = 4;
const int botonIzquierda  = 16;

int x = 0;   // posición X
int y = 0;   // posición Y
int largo = 3;

int snake_x[LONGITUD_MAXIMA];
int snake_y[LONGITUD_MAXIMA];


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
    display.println("Iniciado Juego Snake");
    delay(100);
    display.print("3");
    delay(50);
    display.print("2");
    delay(50);
    display.print("1");
    display.display();

    pinMode(botonArriba, INPUT_PULLUP);
    pinMode(botonAbajo, INPUT_PULLUP);
    pinMode(botonDerecha, INPUT_PULLUP);
    pinMode(botonIzquierda, INPUT_PULLUP);

    snake_x[0] = 10;
    snake_y[0] = 10;

    for (int i = 1; i < largo; i++) {
        snake_x[i] = snake_x[0] - i * len_block;
        snake_y[i] = snake_y[0];
    }

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

void direcciones(){
    if (direccion == 0) snake_y[0] -= len_block;
    if (direccion == 1) snake_y[0] += len_block;
    if (direccion == 2) snake_x[0] += len_block;
    if (direccion == 3) snake_x[0] -= len_block;
}

// void buttons_read() {
//     if (digitalRead(botonArriba) == LOW) {
//         direccion = 2;
//     }
//     if (digitalRead(botonAbajo) == LOW) {
//         direccion = 19;
//     }
//     if (digitalRead(botonDerecha) == LOW) {
//         direccion = 4;
//     }
//     if (digitalRead(botonIzquierda) == LOW) {
//         direccion = 16;
//     }

// }

void buttons_read() {
    if (digitalRead(botonArriba) == LOW) {
        direccion = 0;
    } else if (digitalRead(botonAbajo) == LOW) {
        direccion = 1;
    } else if (digitalRead(botonDerecha) == LOW) {
        direccion = 2;
    } else if (digitalRead(botonIzquierda) == LOW) {
        direccion = 3;
    }
}


void print_head() {
    for (int i =0; i < largo; i++){
      display.fillRect(snake_x[i], snake_y[i], len_block, len_block, SSD1306_WHITE);
    }
    
}

// Funcion Beta para el recorrimiento de las cordenadas; la intencion es que se pueda usar tanto con
//  las cordenadas en x como en las de y

void body(){
  for(int i= largo-1;i > 0; i--){
    snake_x[i] = snake_x[i-1];
    snake_y[i] = snake_y[i-1];
  }
}

void beta(){
  for (int i = 0; i < largo; i++) {
  Serial.print("Segmento ");
  Serial.print(i);
  Serial.print(": X=");
  Serial.print(snake_x[i]);
  Serial.print(" Y=");
  Serial.println(snake_y[i]);
}
Serial.println("----");

}

void loop() {
    display.clearDisplay();
    body();
    // Serial.println(snake_x);
    // beta();
    buttons_read();
    direcciones();
    print_head();

    display.display();
    delay(120);
}

