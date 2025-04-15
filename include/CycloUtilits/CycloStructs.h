#ifndef _CYCLO_STRUCTS_H_
#define _CYCLO_STRUCTS_H_

#include "Arduino.h"

enum class SmartCycloAction_t : uint8_t{
    STOP = 0,
    IDLE,
    FWDF,
    FWDH,
    SS90SL,
    SS90SR,

    CYCLO_ACTION_SIZE
};

constexpr char* Str_SmartCyclogramAction[]{
    "STOP",
    "IDLE",
    "FWDF",
    "FWDH",
    "SS90SL",
    "SS90SR"
};

enum class PrimitiveCycloAction_t : uint8_t{
    FORWARD = 0,
    
    LEFT = 1,
    RIGHT = 3,
    
    STOP = 2,
    BLANK = 4
};

struct Sensors
{
    float time;
};

struct MotionStates
{
    float v_f0;
    float theta_i0;
    bool is_completed;
};

typedef void (*CycloAction)(MotionStates*, Sensors*);


#endif // !_CYCLO_STRUCTS_H_