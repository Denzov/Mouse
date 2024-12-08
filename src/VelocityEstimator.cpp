#include "VelocityEstimetor.h"

void VelocityEstimator::tick(float phi){
    w_raw = (phi - phi_old) / Ts_s;
    phi_old = phi;      

    
}

void VelocityEstimator::lowPassFilter(){

}