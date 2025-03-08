#include <Arduino.h>
#include "Config.h"
#include "Devices.h"

void setup()
{
  //////// INIT /////////
  mixer.init();
  mixer.calcMotorsAngVel(0, 0.05);

  Serial.begin(115200);
}

void loop(){
  static uint32_t timer = micros();
  while(micros() - timer < Ts_us)
    ;
  timer = micros();

  mixer.tick();

  Serial.print(left_w_PiReg.q_u);
  Serial.print(" ");
  Serial.println(right_w_PiReg.q_u);
}
