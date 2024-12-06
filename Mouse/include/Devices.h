#ifndef _DEVICES_H_
#define _DEVICES_H_

#include "Config.h"
#include "Encoder.h"
#include "Motor.h"

void left_ISR();
void right_ISR();

EncoderConnectionParams left_ecp = 
{
    .CLK_A_PIN = LEFT_CLK_A_PIN,
    .B_PIN = LEFT_B_PIN,
    .ENC_DIR = LEFT_ENC_DIR,
    .ISR_CALLBACK = left_ISR
};

EncoderConnectionParams right_ecp = 
{
    .CLK_A_PIN = RIGHT_CLK_A_PIN,
    .B_PIN = RIGHT_B_PIN,
    .ENC_DIR = RIGHT_ENC_DIR,
    .ISR_CALLBACK = right_ISR
};

MotorConnectionParams left_mcp = {
    .DIR = 10,
    .PWM = 12,
    .M_POLARITY = 0
};

MotorConnectionParams right_mcp = {
    .DIR = 11,
    .PWM = 13,
    .M_POLARITY = 0
};

Motor leftMotor(&left_mcp);
Motor rightMotor(&right_mcp);

Encoder leftEncoder(&left_ecp);
Encoder rightEncoder(&right_ecp);

void left_ISR()
{
    leftEncoder.isr_callback();
}

void right_ISR()
{
    rightEncoder.isr_callback();
}

#endif 
