#ifndef _PI_REGULATOR_H_
#define _PI_REGULATOR_H_

#include "Config.h"
#include "VelocityEstimator.h"
#include "Arduino.h"

class PI_regulator{
private:
    const float K = 3;
    const float Kp = K;
    const float Ki = K / Ts_s;
    float integrator = 0;
    float err = 0;
    float P = 0;
    float I = 0;

    float u = 0;
    float constrain_u = 0; 
public:
    float &q_u = u;

    void passErr(float& inputErr);
    void tick(); 
};

#endif // !_PI_REGULATOR_H_