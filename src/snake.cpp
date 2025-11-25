#include <cstdlib>
#include "display.h"

struct point{
    int x;
    int y;
};

point snakeLimit[64];
int snakeLength =3;
// Limites
const int ScreenWidth =127;
const int ScreenHeight =63;

enum Direction {UP, DOWN, LEFT, RIGHT};
Direction dir = RIGHT;

point food;

void RandomFood(){
    food.x = random() % ScreenWidth;
    food.y = random() % ScreenHeight;
}

void PrintFood(){
    display.drawPixel(food.x, food.y, 1);
}

void SnakeInit(){
dir = RIGHT; 
int StartX = 64;
int StartY = 32;

snakeLimit[0] = {StartX, StartY};
snakeLimit[1] = {StartX-1, StartY};
snakeLimit[2] = {StartX-2, StartY};

}


void MoveUpdate(){
    

    for (int i = snakeLength - 1; i > 0; i--){
        snakeLimit[i] = snakeLimit[i-1]; 
    // Movimiento del cuerops de la serpiente
    }

    switch(dir){//Movimiento de la cabeza
        case UP: snakeLimit[0].y--;
        break;
        case DOWN: snakeLimit[0].y++;
        break;
        case LEFT: snakeLimit[0].x--;
        break;
        case RIGHT: snakeLimit[0].x++;
        break;
    }
    display.display();
// En vez de borrar cada pixel, es ams eficiente limpiar
//toda la pantalla
}


void PrintSnake(){
    for(int i = 0; i < snakeLength; i++){
        display.drawPixel(snakeLimit[i].x, snakeLimit[i].y,1);
    }
}


//Aqui empieza el motot del juego.

void SnakeUpdate(){
    MoveUpdate();
}

void SnakeRender(){
    display.clearDisplay();
    PrintSnake();
    PrintFood();
    display.display();
}