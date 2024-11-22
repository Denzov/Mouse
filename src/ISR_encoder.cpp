#include "ISR_encoder.h"

void L_ENCODER_HANDLER()
{
    static uint8_t left_enc_old = 0;
    const uint8_t LEFT_B = digitalRead(LEFT_B_PIN);
    
    const uint8_t LEFT_CLK_A = digitalRead(LEFT_CLK_A_PIN);
    const uint8_t LEFT_A = LEFT_CLK_A ^ LEFT_B;

    const uint8_t left_enc = (LEFT_A << 1) | LEFT_B;

    l_encoder.SetCounter(l_encoder.GetCounter() + l_encoder.GetEtt(left_enc_old, left_enc));
    left_enc_old = left_enc;
}

void R_ENCODER_HANDLER()
{
    static uint8_t right_enc_old = 0;
    const uint8_t RIGHT_B = digitalRead(LEFT_B_PIN);
    
    const uint8_t RIGHT_CLK_A = digitalRead(LEFT_CLK_A_PIN);
    const uint8_t RIGHT_A = RIGHT_CLK_A ^ RIGHT_B;

    const uint8_t right_enc = (RIGHT_A << 1) | RIGHT_B;

    l_encoder.SetCounter(l_encoder.GetCounter() + l_encoder.GetEtt(right_enc_old, right_enc));
    right_enc_old = right_enc;
}