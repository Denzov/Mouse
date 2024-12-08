#ifndef _DEVICES_H_
#define _DEVICES_H_

#include "Config.h"
#include "Encoder.h"
#include "Motor.h"
#include "Odometry.h"


void left_encoder_ISR();
void right_encoder_ISR();

EncoderConnectionParams left_ecp {
    .CLK_A_PIN = LEFT_CLK_A_PIN,
    .B_PIN = LEFT_B_PIN,
    .ENC_DIR = LEFT_ENC_DIR,
    .ISR = left_encoder_ISR
};
Encoder leftEncoder(&left_ecp);

EncoderConnectionParams right_ecp {
    .CLK_A_PIN = RIGHT_CLK_A_PIN,
    .B_PIN = RIGHT_B_PIN,
    .ENC_DIR = RIGHT_ENC_DIR,
    .ISR = right_encoder_ISR
};
Encoder rightEncoder(&right_ecp);

OdometryConnectionParams ocp {
    .l_encoder = &leftEncoder,
    .r_encoder = &rightEncoder
};
Odometry odometry(&ocp);

MotorConnectionParams left_mcp {
    .DIR = LEFT_MOTOR_DIR,
    .PWM = LEFT_MOTOR_PWM,
    .M_POLARITY = LEFT_MOTOR_POLARITY
};
Motor leftMotor(&left_mcp);

MotorConnectionParams right_mcp {
    .DIR = RIGHT_MOTOR_DIR,
    .PWM = RIGHT_MOTOR_PWM,
    .M_POLARITY = RIGHT_MOTOR_POLARITY
};
Motor rightMotor(&right_mcp);

void left_encoder_ISR()
{
    leftEncoder.isr_callback();
}

void right_encoder_ISR()
{
    rightEncoder.isr_callback();
}

#endif 
