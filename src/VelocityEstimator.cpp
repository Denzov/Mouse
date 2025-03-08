#include "VelocityEstimator.h"

void VelocityEstimator::init(){
    encoder->init();
}

void VelocityEstimator::tick(){
    encoder->tick();
    
    w = encoder->q_dphi / Ts_s;
}