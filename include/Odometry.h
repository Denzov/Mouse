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

    Odometry(OdometryConnectionParams *ocp) : OdometryConnectionParams(*ocp){}
    void tick();
};

#endif // !_ODOMETRY_H_