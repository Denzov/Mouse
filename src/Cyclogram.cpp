#include "Cyclogram.h"

void CycloWorker::addAction(CycloAction action){
    cycloProg[cyclo_end++] = action;
    if(cyclo_end > CYCLO_PROG_SIZE){
        cyclo_end = CYCLO_PROG_SIZE;
    }
}

void CycloWorker::calc_time(){
    cur_time = millis();
    sensors.time = cur_time - last_time;
}

void CycloWorker::doBegin(){
    calc_time();
    
    cycloProg[cyclo_counter](&motion_states, &sensors);
    mixer->setMouseVelocity(motion_states.theta_i0, motion_states.v_f0);
}

void CycloWorker::doCyclogram(){
    calc_time();

    cycloProg[cyclo_counter](&motion_states, &sensors);
    mixer->setMouseVelocity(motion_states.theta_i0, motion_states.v_f0);

    if(motion_states.is_completed){
        cyclo_counter = (cyclo_counter + 1) % cyclo_end;
        last_time = cur_time; 
        
        motion_states.is_completed = 0;
    }
}