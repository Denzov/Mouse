#include <Arduino.h>
#include "Config.h"
#include "Devices.h"

void setup()
{
  // DEVICES::INIT();
  Serial.begin(115200);

  maze.Init();
  
  solver.MazeTestConfig();
  
  maze.Init();
  
  maze.Print();

  solver.SolveBfsMaze(0, 0, 9, 9);
  maze.Print();
}

float motor_time = 0;

void loop(){
  // static uint32_t timer = micros();
  // while(micros() - timer < Ts_us)
  //   ;
  // timer = micros();
  // DEVICES::TICK(); 
}
