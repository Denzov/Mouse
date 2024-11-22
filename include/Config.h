#ifndef _CONFIG_H_

#include "Encoder.h"

#define _CONFIG_H_

#define Ts_us 5000 // Период квантования в [мкс]
#define Ts_s (Ts_us / 1000000.0) // Период квантования в [с]

#define LEFT_CLK_A_PIN 2
#define LEFT_B_PIN 4

#define RIGHT_CLK_A_PIN 3
#define RIGHT_B_PIN 5

#endif 