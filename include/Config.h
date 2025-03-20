#ifndef _CONFIG_H_
#define _CONFIG_H_

/*===FREQUENCY DISCRETIZATION BEGIN===*/
#define Ts_us 50000
#define Ts_s (Ts_us / 1000000.0)
/*===FREQUENCY DISCRETIZATION END===*/

/*===ENCODER CONNECTION PINS BEGIN===*/
#define LEFT_CLK_A_PIN 2
#define LEFT_B_PIN 4
#define LEFT_ENC_DIR -1

#define RIGHT_CLK_A_PIN 3
#define RIGHT_B_PIN 5
#define RIGHT_ENC_DIR 1
/*===ENCODER CONNECTION PINS END===*/

/*===WHEELS PARAMS BEGIN===*/
#define ENC_PPR 48
#define GEAR_RATIO 30
#define TICK2RAD (2.f * M_PI / (ENC_PPR * GEAR_RATIO))

#define WHEEL_RADIUS 0.016f
/*===WHEELS PARAMS END===*/

/*===MOTOR PINS BEGIN===*/
#define LEFT_MOTOR_DIR 7
#define LEFT_MOTOR_PWM 9
#define LEFT_MOTOR_POLARITY 1

#define RIGHT_MOTOR_DIR 8
#define RIGHT_MOTOR_PWM 10
#define RIGHT_MOTOR_POLARITY 0
/*===MOTOR PINS END===*/

#define HALF 0.5f
#define ROBOT_WIDTH 0.0825f

/*===POWER BEGIN===*/
#define V_BATT 5.f
#define MAX_U V_BATT
#define NEG_MAX_U -V_BATT
/*===POWER END===*/

/*===W MOTOT PIREG BEGIN===*/
#define W_KP 0.12f
#define W_KI (W_KP / 0.21f) 
/*===W MOTOT PIREG END===*/

/*===CYCLOGRAM BEGIN===*/
#define FORWARD_SPEED 0.18
#define CELL_SIZE 0.18
/*===CYCLOGRAM END===*/

/*===MAZE BEGIN==*/
// MY MAZE STRUCT
// for exapmle, let's take maze 3x3:
//        X - a x i s 
//      Y      === === ===
//      |     | 0 | 1 | 2 |
//      a  === === === ===
//      x | 3 | 4 | 5 | 6 |
//      i  === === === ===
//      s | 7 | 8 | 9 | 10|
//         === === === ===
//        | 11| 12| 13| 14|
//         === === === ===
// here 0, 1, 2, 3, 7, 11 cells are utility. important for west and north fronts of maze
// total number of cells are 15, but informal numbers of cells are 9 (3x3)

#define MAZE_SIDE_LENGTH 10
#define MAZE_SIDE_LENGTH_ADD_ONE (MAZE_SIDE_LENGTH + 1)
#define MAZE_TOTAL_SIZE (MAZE_SIDE_LENGTH*2 + MAZE_SIDE_LENGTH*MAZE_SIDE_LENGTH)
#define MAZE_MEM_SIZE (((MAZE_SIDE_LENGTH + MAZE_SIDE_LENGTH) + MAZE_SIDE_LENGTH*MAZE_SIDE_LENGTH))

#define MAZE_PATH_SIZE ((MAZE_TOTAL_SIZE - (MAZE_TOTAL_SIZE % 2)) / 2)
/*===MAZE END===*/

#endif // !_CONFIG_H_