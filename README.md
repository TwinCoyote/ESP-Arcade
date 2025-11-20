# 🎮 Mini Consola Retro ESP32

**Autor:** [Tu nombre aquí]  
**Versión:** 0.1  
**Plataforma:** ESP32 (DOIT ESP32 DEVKIT V1)  
**Framework:** Arduino (PlatformIO)

---

## 🧠 Descripción general

Proyecto personal de una **mini consola retro** basada en un **ESP32**, diseñada para correr juegos sencillos (como _Snake_, _Pong_ o _Tetris_) en una **pantalla OLED**.  
El objetivo es aprender sobre **sistemas embebidos**, **hardware modular** y **arquitectura de software para juegos en microcontroladores**.

La idea final es integrar todos los componentes en una PCB personalizada con **componentes SMD** y una **carcasa impresa en 3D**.

---

## 🧩 Características principales

- Pantalla OLED 128x64 (I²C)
- Botones físicos de control (4 direccionales + 1 acción)
- Menú principal para seleccionar juegos
- 3 juegos clásicos integrados
- Sonido básico (buzzer o DAC del ESP32)
- Diseño modular (cada juego en su propio archivo)

---

## 🧰 Hardware y materiales

| Componente            | Descripción                | Cantidad | Notas                                      |
| --------------------- | -------------------------- | -------- | ------------------------------------------ |
| ESP32 DevKit V1       | Microcontrolador principal | 1        | 4 MB Flash, WiFi, BLE                      |
| OLED 0.96" (SSD1306)  | Pantalla gráfica I²C       | 1        | 128x64 píxeles                             |
| Pulsadores táctiles   | Botones de control         | 5        | Arriba, Abajo, Izquierda, Derecha, Aceptar |
| Buzzer piezoeléctrico | Generar sonido             | 1        | Opcional                                   |
| Resistencias 10kΩ     | Pull-up para botones       | 5        | Opcional si no son internas                |
| Protoboard y cables   | Montaje temporal           | 1 set    | —                                          |
| Fuente de 5V (USB)    | Alimentación               | 1        | —                                          |

> ![Foto del prototipo](./docs/images/prototipo.jpg)

---

## ⚙️ Conexiones de pines (Pantalla)

| Componente | Pin ESP32 | Descripción     |
| ---------- | --------- | --------------- |
| OLED SDA   | Pin 21    | Datos I²C       |
| OLED SCL   | Pin 22    | Reloj I²C       |
| 3.3V       | Vcc       | Entrada digital |
| GND        | GND       | Entrada digital |

> ![Foto del Esquema de la Pantalla](./docs/images/prototipo.jpg)

---

## ⚙️ Conexiones de pines (Botones)

| Componente | Pin ESP32 | Descripción     |
| ---------- | --------- | --------------- |
| UP         | Pin 33    | Entrada digital |
| Down       | Pin 32    | Entrada digital |
| Left       | Pin 25    | Entrada digital |
| Right      | Pin 26    | Entrada digital |

![Foto del Esquema de los Botones](./docs/images/prototipo.jpg)

---

## ⚙️ Conexiones de pines (DAC Module)

| Componente | Pin ESP32 | Descripción     |
| ---------- | --------- | --------------- |
| Pin 3      | Pin 9     | Entrada digital |
| Pin 2      | Pin 10    | Entrada digital |

![Foto del Esquema del DAC](./docs/images/prototipo.jpg)

---

## 💾 Librerías utilizadas

Estas se agregan automáticamente en `platformio.ini`:

```ini
lib_deps =
  adafruit/Adafruit GFX Library
  adafruit/Adafruit SSD1306
```

## Video y documentacion de los que me he basado

> [Video de pantalla] https://www.youtube.com/watch?v=_KD7skmusTQ
