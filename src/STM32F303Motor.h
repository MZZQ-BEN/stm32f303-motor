#ifndef STM32F303MOTOR_H
#define STM32F303MOTOR_H

#include "stm32f3xx_hal.h"

class STM32F303Motor {
public:
  STM32F303Motor();
  bool begin();
  void setPWM(uint8_t channel, float duty); // duty: 0.0 - 1.0
  uint32_t readADC(uint8_t channel);
  int32_t readEncoder();

  struct PID {
    float kp, ki, kd;
    float integrator;
    float lastError;
    PID():kp(0),ki(0),kd(0),integrator(0),lastError(0){}
    float update(float setpoint, float meas, float dt);
  } pid;

  void controlPID(float setpoint, float meas, float dt);

private:
  void initTimers();
  void initADC();
  void initEncoder();
};

#endif // STM32F303MOTOR_H