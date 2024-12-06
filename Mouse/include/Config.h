#ifndef _CONFIG_H_
#define _CONFIG_H_

#define Ts_us 5000
#define Ts_s (Ts_us / 1000000.0)

#define LEFT_CLK_A_PIN 2
#define LEFT_B_PIN 4
#define LEFT_ENC_DIR -1


#define RIGHT_CLK_A_PIN 3
#define RIGHT_B_PIN 5
#define RIGHT_ENC_DIR -1

#define ENC_PPR 48
#define GEAR_RATIO 30
#define TICK2RAD (2.0 * M_PI / (ENC_PPR * GEAR_RATIO))

#define V_BATT (5.0)

#endif 