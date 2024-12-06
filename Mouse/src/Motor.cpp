#include "Motor.h"

void Motor::drive(float u){
    int pwm = constrain(255.0*u/V_BATT, -255, 255);

    if (pwm >= 0){
        digitalWrite(DIR, M_POLARITY);
        analogWrite(PWM, pwm);
    }
    else{
        digitalWrite(DIR, !M_POLARITY);
        analogWrite(PWM, -pwm);
    }
}