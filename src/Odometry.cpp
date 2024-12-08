#include "Odometry.h"

void Odometry::tick(){
    f_dS = (l_encoder->q_dphi + r_encoder->q_dphi) * HALF;
    dAngle = (r_encoder->q_dphi - l_encoder->q_dphi) / ROBOT_WIDTH;

    x += f_dS*dAngle;
    y += f_dS*dAngle;
    angle += dAngle;
}