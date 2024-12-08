#ifndef _VELOCITY_ESTIMATOR_H_
#define _VELOCITY_ESTIMATOR_H_

#include "Config.h"

class VelocityEstimator {
private:
    float w = 0;
    float w_raw = 0;

    float phi_old = 0;
public:
    void tick(float phi);
    void lowPassFilter();

};

// float left_vel_estimsotor(float phi){
//     static float phi_old = 0;

//     float w_raw = (phi - phi_old) / Ts_s;
//     phi_old = phi;

//     return w_raw;
// }

// float left_low_pass_filter(float w_raw){
//     static float w = 0;

//     float LPF_ALPHA = 2.4;
//     w += (w_raw - w) * LPF_ALPHA; 

//     return w;
// }


// void velest_tick(){
//     // выше объявлена глоб left phi
//     const float left_phi = g_left_phi;

//     const float left_w_raw = left_vel_estimsotor(left_phi)

//     g_left_w = left_low_pass_filter(left_w_raw)
// }

#endif // !_VELOCITY_ESTIMATOR_H_