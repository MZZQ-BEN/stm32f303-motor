#include "STM32F303Motor.h"

STM32F303Motor motor;

void setup() {
  Serial.begin(115200);
  motor.begin();
  motor.pid.kp = 1.0f; motor.pid.ki = 0.0f; motor.pid.kd = 0.0f;
}

void loop() {
  // Read pot on ADC channel 0 (user must route a pot to ADC channel in CubeMX)
  uint32_t pot = motor.readADC(0);
  float setpoint = pot / 4095.0f; // normalized

  // Read encoder (naive use)
  float meas = (motor.readEncoder() % 4096) / 4095.0f;

  motor.controlPID(setpoint, meas, 0.01f);
  delay(10);
}
