#include <Arduino.h>
#include "Config.h"
#include "Devices.h"

void setup()
{
  //////// INIT /////////
  leftServo.init();
  leftServo.SetW(6.28);

  Serial.begin(9600);
}

void loop(){
  ///////// TIMER /////////
  static uint32_t timer = micros();
  while(micros() - timer < Ts_us)
    ;
  timer = micros();
      
  ///////// SENSE /////////
  
  ///////// PLAN /////////

  Serial.println(w_pi);
  leftServo.tick();

  ///////// ACT /////////

}
