#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>  
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


#define ANCHO_PANTALLA 128
#define ALTO_PANTALLA 64

#define OLED_RESET -1 //No se pondra boton de reset a la pantalla, aunque es buena idea...
#define DIRECCION_PANTALLA 0x3C //Dirección de comunicacion: 0x3D para 128x64, 0x3C para 128x32

#define LOGOS_WIDTH 84
#define LODGOS_HEIGHT 52

extern Adafruit_SSD1306 display;

void InitDisplay();
void ClearDisplay();
void menuDisplay();



#endif
