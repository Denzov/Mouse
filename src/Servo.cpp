#include "Servo.h"

void Servo::SetW(float _w){
    w = _w;
    w_PiReg->passSet(_w);
}

void Servo::init(){
    w_PiReg->init();
    encoder->init();
    motor->init();
}

void Servo::act(){
    motor->drive(static_cast<float>(w_PiReg->q_u));

}

void Servo::tick(){
    encoder->tick();
    w_PiReg->tick();

    cur_w = encoder->q_phi;
    w_PiReg->passCur(cur_w);

    act();
}

