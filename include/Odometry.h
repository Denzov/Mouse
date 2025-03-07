#ifndef _ODOMETRY_H_
#define _ODOMETRY_H_

#include "Encoder.h"

struct OdometryConnectionParams{
    Encoder* l_encoder;
    Encoder* r_encoder;
};

class Odometry : public OdometryConnectionParams{
private:
    float dS_r, dS_l, dS_f, dAngle;

    float x, y, angle;
public:
    float &q_x = x; 
    float &q_y = y;
    float &q_angle = angle;

    Odometry(OdometryConnectionParams *ocp) : OdometryConnectionParams(*ocp){}
    void tick();
};

#endif // !_ODOMETRY_H_