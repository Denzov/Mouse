#include "Servo.h"

void Servo::SetW(float _w){
    w = _w;
    w_PiReg->passSet(_w);
}

void Servo::init(){
    w_PiReg->init();
    velocityEstimator->init();
    motor->init();
}

void Servo::act(){
    motor->drive(w_PiReg->q_u);
}

void Servo::tick(){
    velocityEstimator->tick();
    w_PiReg->tick();

    cur_w = velocityEstimator->q_w;
    w_PiReg->passCur(cur_w);

    act();
}