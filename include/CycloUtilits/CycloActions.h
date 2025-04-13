#ifndef _CYCLO_ACTIONS_H
#define _CYCLO_ACTIONS_H

#include "Config.h"
#include "CycloStructs.h"

#define CYCLOGRAM(name) inline void name(MotionStates* ms, Sensors* s)

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

CYCLOGRAM(FWDF){
    ms->v_f0 = FORWARD_SPEED;
    ms->theta_i0 = 0;

    if(s->time > 1000){
        ms->is_completed = 1;
    }
}

CYCLOGRAM(FWDH){
    ms->v_f0 = FORWARD_SPEED;
    ms->theta_i0 = 0;

    if(s->time > 500){
        ms->is_completed = 1;
    }
}

CYCLOGRAM(SS90SL){
    ms->v_f0 = HALF(PI * CELL_SIZE);
    ms->theta_i0 = HALF(PI); 

    if(s->time > 1000){
        ms->is_completed = 1;
    }
}

CYCLOGRAM(SS90SR){
    ms->v_f0 = HALF(PI * CELL_SIZE);
    ms->theta_i0 = HALF(PI);

    if(s->time > 1000){
        ms->is_completed = 1;
    }
}

#endif // !_CYCLO_ACTIONS_H