#include "Encoder.h"

void Encoder::init()
{
    pinMode(CLK_A_PIN, INPUT);
    pinMode(B_PIN, INPUT);

    noInterrupts();
    attachInterrupt(
        digitalPinToInterrupt(CLK_A_PIN),
        ISR_CALLBACK,
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

void Encoder::isr_callback()
    {
        const uint8_t B = digitalRead(B_PIN);
        // 0000000B
        
        const uint8_t CLK_A = digitalRead(CLK_A_PIN);
        const uint8_t A = CLK_A ^ B;
        // 0000000A

        const uint8_t enc = (A << 1) | B;
        /*
        000000AB = (0000000A << 1) | 0000000B;
        */

        counter += ett[enc_old][enc];
        enc_old = enc;
    }