#pragma once
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

extern Adafruit_SSD1306 display;

// Inicializa la pantalla OLED (llama a begin y limpia)
void InitDisplay();
// Limpia el buffer sin llamar display.display()
void ClearDisplay();
// Dibuja un bitmap completo del tamaño indicado y hace display()
void DrawBitmap(const unsigned char* bitmap, int w, int h);
// Conveniencia: dibuja el logo inicial
void DrawLogo();
// Conveniencia: dibuja gráfico de menú principal
void DrawMenu();
