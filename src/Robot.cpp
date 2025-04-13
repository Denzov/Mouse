#include "Robot.h"

void Robot::calcSubjCycloAction(uint8_t ind){
    if(ind == _Maze->GetPathSize() - 1){
        _buf_subj_cyclo_action = PrimitiveCycloAction_t::STOP;
        return;
    }
    _buf_subj_cyclo_action = static_cast<PrimitiveCycloAction_t>(   
        (static_cast<int8_t>(_Maze->GetPathDir(ind)) - static_cast<int8_t>(_Maze->GetPathDir(ind + 1)) + 4) % 4);
}

void Robot::convertPathToCyclogram(){
    _cycloWorker->addAction(SmartCycloAction_t::FWDH);
    for(uint8_t i = 0; i < _Maze->GetPathSize(); i++){
        calcSubjCycloAction(i);
        
        switch (_buf_subj_cyclo_action)
        {
        case PrimitiveCycloAction_t::FORWARD:
            _cycloWorker->addAction(SmartCycloAction_t::FWDF);
            break;

        case PrimitiveCycloAction_t::LEFT:
            _cycloWorker->addAction(SmartCycloAction_t::SS90SL);
            break;

        case PrimitiveCycloAction_t::RIGHT:
            _cycloWorker->addAction(SmartCycloAction_t::SS90SR);
            break;

        case PrimitiveCycloAction_t::STOP:
            _cycloWorker->addAction(SmartCycloAction_t::FWDH);
            _cycloWorker->addAction(SmartCycloAction_t::STOP);
            break;

        case PrimitiveCycloAction_t::BLANK:
            _cycloWorker->addAction(SmartCycloAction_t::IDLE);
            break;
        }
    }
}