#ifndef _ENCODER_H_
#define _ENCODER_H_

#include <Arduino.h>
#include "Config.h"

struct EncoderConnectionParams
{
    uint8_t CLK_A_PIN;
    uint8_t B_PIN;
    int8_t ENC_DIR;
    void (*ISR)();
};

class Encoder : public EncoderConnectionParams{
private:
    int8_t ett[4][4];
    
    volatile int counter;
    volatile int enc_old = 0;
    
    float phi = 0;
    float dphi = 0;

public:
    const float& q_phi = phi;
    const float& q_dphi = dphi;
    Encoder(EncoderConnectionParams* ecp) : EncoderConnectionParams(* ecp){}

    void init();
    void tick();
    
    void isr_callback();
};

#endif // !_ENCODER_H_