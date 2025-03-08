#ifndef _CONFIG_H_
#define _CONFIG_H_

#define Ts_us 50000
#define Ts_s (Ts_us / 1000000.0)

#define LEFT_CLK_A_PIN 2
#define LEFT_B_PIN 4
#define LEFT_ENC_DIR -1

#define RIGHT_CLK_A_PIN 3
#define RIGHT_B_PIN 5
#define RIGHT_ENC_DIR 1

#define WHEEL_RADIUS 0.016

#define ENC_PPR 48
#define GEAR_RATIO 30
#define TICK2RAD (2.0 * M_PI / (ENC_PPR * GEAR_RATIO))

#define LEFT_MOTOR_DIR 7
#define LEFT_MOTOR_PWM 9
#define LEFT_MOTOR_POLARITY 1

#define RIGHT_MOTOR_DIR 8
#define RIGHT_MOTOR_PWM 10
#define RIGHT_MOTOR_POLARITY 0

#define LPF_ALPHA 1.f
#define HALF 0.5f

#define ROBOT_WIDTH 0.07f

/*=====POWER BEGIN=====*/
#define V_BATT (5.0)
#define MAX_U V_BATT
#define NEG_MAX_U -V_BATT
/*=====POWER END=====*/

/*=====W MOTOT PIREG BEGIN=====*/
#define W_KP 0.15f
#define W_KI (W_KP / 0.21) 

// #define W_KP 0.696f
// #define W_KI 1.565f
/*=====W MOTOT PIREG=====*/

#endif // !_CONFIG_H_