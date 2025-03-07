#include "PiReg.h"

// void PI_Reg::init(constexpr float KP){
//     Kp = KP;
//     Ki = KP / Ts_s;
// }

void PiReg::init(){
    return;
}

void PiReg::passSet(float& _set){
    set = _set;
}

void PiReg::passCur(float& _cur){
    cur = _cur;
}

void PiReg::tick(){
    err = set - cur;

    P = err*Kp;
    I = integrator * Ki;

    u = P + I;

    constrain_u = constrain(u, NEG_MAX_U, MAX_U);
    if(u == constrain_u){
        integrator = err * Ts_s;
    }
    else{
        u = constrain_u;
    }

}