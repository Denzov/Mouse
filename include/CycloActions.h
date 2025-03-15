#ifndef _CYCLO_ACTIONS_H
#define _CYCLO_ACTIONS_H

#include "Cyclogram.h"

#define CYCLOGRAM(name) void name(MotionStates* ms, Sensors* s)

CYCLOGRAM(STOP){
    ms->v_f0 = 0;
    ms->theta_i0 = 0;
    ms->is_completed = 1;
}

CYCLOGRAM(IDLE){
    ms->v_f0 = 0;
    ms->theta_i0 = 0;
    ms->is_completed = 1;
}

CYCLOGRAM(DELAY_1S){
    ms->v_f0 = 0;
    ms->theta_i0 = 0;
    
    if(s->time > 1000){
        ms->is_completed = 1;
    }
}

CYCLOGRAM(DELAY_5S){
    ms->v_f0 = 0;
    ms->theta_i0 = 0;
    
    if(s->time > 5000){
        ms->is_completed = 1;
    }
}

CYCLOGRAM(FWD){
    ms->v_f0 = FORWARD_SPEED;
    ms->theta_i0 = 0;

    if(s->time > 1000){
        ms->is_completed = 1;
    }
}

CYCLOGRAM(SS90SL){
    ms->v_f0 = (HALF * PI * CELL_SIZE);
    ms->theta_i0 = (PI * HALF); // pi/2 * 0.1

    if(s->time > 1000){
        ms->is_completed = 1;
    }
}

#endif // !_CYCLO_ACTIONS_H