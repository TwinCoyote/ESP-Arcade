#ifndef INPUTS_H
#define INPUTS_H

#define BTN_OK 35
#define BTN_BACK 34
#define BTN_UP 33
#define BTN_DOWN 32
#define BTN_LEFT 25
#define BTN_RIGHT 26

void InitButtons();
bool isPressed(int pin);

#endif
