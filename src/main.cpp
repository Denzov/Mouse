#include <Arduino.h>
#include "Config.h"
#include "Devices.h"

#include "Maze.h"

void setup()
{
  DEVICES::INIT();

  // Serial.begin(115200);
}

float motor_time = 0;

void loop(){
  static uint32_t timer = micros();
  while(micros() - timer < Ts_us)
    ;
  timer = micros();

  DEVICES::TICK(); 
  
}
