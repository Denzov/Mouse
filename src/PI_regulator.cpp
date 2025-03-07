#include "PI_regulator.h"

void PI_regulator::passErr(float &inputErr){
    err = inputErr;
}

void PI_regulator::tick(){
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