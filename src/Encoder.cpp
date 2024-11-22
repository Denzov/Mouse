#include "Encoder.h"

void Encoder::init(const uint8_t& _CLC_A_PIN, const uint8_t& _B_PIN, void (*_ISR)())
{
    CLC_A_PIN = _CLC_A_PIN;
    B_PIN = _B_PIN;
    ISR = _ISR;

    pinMode(CLC_A_PIN, INPUT);
    pinMode(B_PIN, INPUT);

    noInterrupts();
    attachInterrupt(
        digitalPinToInterrupt(CLC_A_PIN),
        ISR,
        CHANGE
    );

    ett[0b00][0b01] = ENC_DIR;
    ett[0b01][0b11] = ENC_DIR;
    ett[0b11][0b10] = ENC_DIR;
    ett[0b10][0b00] = ENC_DIR;
    
    ett[0b00][0b10] = -ENC_DIR;
    ett[0b10][0b11] = -ENC_DIR;
    ett[0b11][0b01] = -ENC_DIR;
    ett[0b01][0b00] = -ENC_DIR;
    
    interrupts();
}


void Encoder::tick()
{
    noInterrupts();
    const int counter_inc = counter;
    counter = 0;
    interrupts();

    phi += counter_inc * TICK2RAD;
}

volatile int Encoder::GetCounter(){
    return counter;
}

void Encoder::SetCounter(const int _counter){
    counter = _counter;
}

int8_t Encoder::GetEtt(const uint8_t i, const uint8_t j){
    return ett[i][j];
}