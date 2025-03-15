#ifndef _CYCLOGRAM_H_
#define _CYCLOGRAM_H_

#include <Arduino.h>

#include "Mixer.h"
#include "Config.h"

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
    static constexpr uint8_t CYCLO_PROG_SIZE = 10;

    CycloAction cycloProg[CYCLO_PROG_SIZE];  

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