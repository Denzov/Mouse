#include <Arduino.h>

#include "ISR_encoder.h"

int main()
{
  //////// INIT /////////
  Serial.begin(9600);
  while (true)
  {
    ///////// TIMER /////////
    // Задание постоянной частоты главного цикла прогааммы
    static uint32_t timer = micros();
    while(micros() - timer < Ts_us);
    timer = micros();
    
    ///////// SENSE /////////
    // Считывание датчиков

    ///////// PLAN /////////
    // Расчет управляющих воздействий

    ///////// ACT /////////

  }
}
