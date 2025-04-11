#ifndef _CYCLOGRAM_H_
#define _CYCLOGRAM_H_

#include <Arduino.h>

#include "Mixer.h"
#include "Config.h"

enum class CycloAction_t : uint8_t{
    STOP,
    IDLE,
    DELAY_1S,
    DELAY_5S,
    FWD,
    SS90SL,
    SS90SR,

    CYCLO_ACTION_SIZE
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

struct CycloWorkerConnectionParams{
    Mixer* mixer;   
};

class CycloWorker : public CycloWorkerConnectionParams{
private:
    static constexpr uint8_t CYCLO_PROG_SIZE = 25;
    //CycloAction Actions[CycloAction_t::CYCLO_ACTION_SIZE];

    CycloAction_t cycloProg[CYCLO_PROG_SIZE];  

    uint8_t cyclo_counter = 0;
    uint8_t cyclo_end = 0;

    uint32_t cur_time = 0;
    uint32_t last_time = 0;

    Sensors sensors;
    MotionStates motion_states;

    void calc_time();
    
public:
    CycloWorker(CycloWorkerConnectionParams* cwcp) : CycloWorkerConnectionParams(*cwcp), 
                    sensors({       .time = 0}),
                    motion_states({ .v_f0 = 0,
                                    .theta_i0 = 0,
                                    .is_completed = 0}){}

    void addAction(CycloAction action);

    void doCyclogram();
};

#endif // !_CYCLOGRAM_H_