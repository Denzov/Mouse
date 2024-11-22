#ifndef _MOTOR_H_
#define _MOTOR_H_

#include <Arduino.h>

class Encoder{
private:
    static int8_t ett[4][4];
    
    volatile int counter;
    
    float phi = 0;

    static uint8_t CLC_A_PIN;
    static uint8_t B_PIN;     

    const static uint8_t ENC_PPR = 12;
    const static uint8_t GEAR_RATIO = 30;
    const static int8_t ENC_DIR = 1;

    void (*ISR)();
    
    const float TICK2RAD = 2.0 * M_PI / (ENC_PPR * GEAR_RATIO);    
    
public:
    void init(const uint8_t& CLC_A_PIN, const uint8_t& B_PIN, void (*_ISR)());
    void tick();
    
    volatile int GetCounter();
    void SetCounter(const int);

    int8_t GetEtt(const uint8_t, const uint8_t);
};

#endif // !_MOTOR_H_