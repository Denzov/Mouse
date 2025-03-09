#include "VelocityEstimator.h"

void VelocityEstimator::init(){
    return;
}

void VelocityEstimator::tick(){ 
    w = encoder->q_dphi / Ts_s;
}