#ifndef _ODOMETRY_H_
#define _ODOMETRY_H_

#include "Encoder.h"

struct OdometryConnectionParams{
    Encoder* l_encoder;
    Encoder* r_encoder;
};

class Odometry : OdometryConnectionParams{
private:
    float f_dS, r_dS, l_dS;
    float dAngle;

    float x, y, angle;
public:
    Odometry(OdometryConnectionParams* ocp) : OdometryConnectionParams(* ocp){}
    void tick();
};

#endif // !_ODOMETRY_H_