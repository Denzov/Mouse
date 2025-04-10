#include "Odometry.h"

void Odometry::tick(){
    dS_l = l_encoder->GetDPhi() * WHEEL_RADIUS;
    dS_r = r_encoder->GetDPhi() * WHEEL_RADIUS;

    dS_f = HALF(dS_l + dS_r);
    dAngle = (dS_r - dS_l) / ROBOT_WIDTH;

    angle += dAngle;
    x += dS_f*cos(angle);
    y += dS_f*sin(angle);
}