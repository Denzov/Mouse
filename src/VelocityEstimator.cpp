#include "VelocityEstimator.h"

void VelocityEstimator::tick(){
    encoder->tick();
    
    w = encoder->q_dphi / Ts_s;
}