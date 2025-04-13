#include "CycloWorker.h"

void CycloWorker::addAction(SmartCycloAction_t action){
    if(_CYCLO_END + 1 < CYCLO_PROG_SIZE){
        _cyclo_program[_CYCLO_END++] = action;
    }
}

void CycloWorker::doCyclogram(){
    _cur_time = millis();
    _sensors.time = _cur_time - _last_time;

    _Actions_funcs[
        static_cast<uint8_t>(_cyclo_program[_CYCLO_COUNTER])](&_motion_states, &_sensors);

    mixer->setMouseVelocity(_motion_states.theta_i0, _motion_states.v_f0);

    if(_motion_states.is_completed){
        _CYCLO_COUNTER = (_CYCLO_COUNTER + 1) % _CYCLO_END;
        _last_time = _cur_time; 
        
        _motion_states.is_completed = 0;
    }
}

void CycloWorker::load_Actions_funcs(){
    _Actions_funcs[static_cast<uint8_t>(SmartCycloAction_t::STOP    )]  = STOP   ;
    _Actions_funcs[static_cast<uint8_t>(SmartCycloAction_t::IDLE    )]  = IDLE   ;
    _Actions_funcs[static_cast<uint8_t>(SmartCycloAction_t::FWDF    )]  = FWDF   ;
    _Actions_funcs[static_cast<uint8_t>(SmartCycloAction_t::FWDH    )]  = FWDH   ;
    _Actions_funcs[static_cast<uint8_t>(SmartCycloAction_t::SS90SL  )]  = SS90SL ;
    _Actions_funcs[static_cast<uint8_t>(SmartCycloAction_t::SS90SR  )]  = SS90SR ;
}

void CycloWorker::printCycloProgram(){
    Serial.print("cyclo program: ");
    for(uint8_t i = 0; i < _CYCLO_END; i++){
        // Serial.print(Str_SmartCyclogramAction[static_cast<uint8_t>(_cyclo_program[i])]);
        Serial.print(static_cast<uint8_t>(_cyclo_program[i]));
        Serial.print(' ');
    }
    Serial.println();
}