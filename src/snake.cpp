#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define ANCHO_PANTALLA 128
#define ALTO_PANTALLA 64
#define DIRECCION_OLED 0x3C
#define LONGITUD_MAXIMA 50

const unsigned long eventInterval = 1000;
unsigned long previousTime = 0;


Adafruit_SSD1306 display(ANCHO_PANTALLA,ALTO_PANTALLA,&Wire,-1);

int direccion = 1;

const int botonArriba     = 2;
const int botonAbajo      = 19;
const int botonDerecha    = 4;
const int botonIzquierda  = 16;
const int botonSelect     = 5;


enum class states{
  INIT,
  START,
  GAME_OVER,
  AGAIN
};

states ACTUAL_STATE = states::INIT;

// int x = 0;   // posición X
// int y = 0;   // posición Y
int largo = 20;

int snake_x[LONGITUD_MAXIMA];
int snake_y[LONGITUD_MAXIMA];
// int is_alive = true;


int rans = 40;
int ran  = 30;
const int len_block = 4; //3
int comidaX = random(0, 32) * len_block; //42
int comidaY = random(0, 16) * len_block; //21


// void better_delay(){
//   unsigned long currentTime = millis();
//   if(currentTime - PreviousTime >= eventInterval){
//     PreviousTime = currentTime;
//   }
  
// }



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

    snake_x[0] = 8;//9
    snake_y[0] = 8;//9

    for (int i = 1; i < largo; i++) {
        snake_x[i] = snake_x[0] - i * len_block;
        snake_y[i] = snake_y[0];
    }

}

void game_letters(){
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println("Iniciado Juego Snake");
    delay(100);
    display.display();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(15, 20);
    display.println("Presiona Start!");
    display.display();

    if(digitalRead(botonSelect)==LOW){
      ACTUAL_STATE = states::START;
    }
}

void random_food() {
    comidaX = random(0, 32) * len_block; //42
    comidaY = random(0, 16) * len_block; //21

    display.display();
    // display.fillRect(comidaX, comidaY, 3, 3, SSD1306_WHITE);
}

void check_food() {
    display.fillRect(comidaX, comidaY, 3, 3, SSD1306_WHITE);
    if (snake_x[0] == comidaX && snake_y[0] == comidaY) {
        random_food();
        if(largo < LONGITUD_MAXIMA){
          largo = largo + 1;
        }
        else{
          display.clearDisplay();
          display.setTextSize(1);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(0, 0);
          display.println("Has Ganado!");
          // is_alive = false;
        }
        
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
    } else if (digitalRead(botonSelect) == LOW) {
        
    }
  }

void space_limits() {
  if (snake_x[0] >= ANCHO_PANTALLA) {
    snake_x[0] = 0;
  } 
  else if (snake_x[0] < 0) {
    snake_x[0] = ANCHO_PANTALLA - len_block;
  }

  if (snake_y[0] >= ALTO_PANTALLA) {
    snake_y[0] = 0;
  } 
  else if (snake_y[0] < 0) {
    snake_y[0] = ALTO_PANTALLA - len_block;
  }
}

void print_snake() {
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

// void beta(){
//   for (int i = 0; i < largo; i++) {
//   Serial.print("Segmento ");
//   Serial.print(i);
//   Serial.print(": X=");
//   Serial.print(snake_x[i]);
//   Serial.print(" Y=");
//   Serial.println(snake_y[i]);
// }
// Serial.println("----");
// }



void lose_conditions(){
  for(int i=1; i<largo; i++){
    if (snake_x[0] == snake_x[i] && snake_y[0] == snake_y[i]){
      
      ACTUAL_STATE = states::GAME_OVER;
      return;
    }
  }
}

void lose_display(){
      display.display();
      display.clearDisplay();
      display.setTextSize(2);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(4, 0);
      display.println("Game Over!");
      display.display();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(15, 20);
      display.println("Volver a jugar?");
 
}

void reset_game() {
  largo = 3;
  direccion = 1;

  snake_x[0] = 8;
  snake_y[0] = 8;

  for (int i = 1; i < largo; i++) {
    snake_x[i] = snake_x[0] - i * len_block;
    snake_y[i] = snake_y[0];
  }

  random_food();
  ACTUAL_STATE = states::START;
}


void loop() {
  if(ACTUAL_STATE == states::INIT){
    game_letters();
  }


  else if(ACTUAL_STATE == states::START){
      
      display.clearDisplay();
      buttons_read();
      
      body();
      direcciones();
      space_limits();
      lose_conditions();
      print_snake();
      check_food();
      display.display();
      delay(120);
  
  }
  else if(ACTUAL_STATE == states::GAME_OVER){
    
    lose_display();
      if (digitalRead(botonSelect) == LOW) {
      delay(200);
      reset_game();
      }
  }
}

