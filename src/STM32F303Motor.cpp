#include "STM32F303Motor.h"
#include "stm32f3xx_hal.h"

// Note: This library expects the user project to provide and initialize
// TIM and ADC handles (e.g., htim1, hadc1). These are referenced as extern
// to keep the library generic across setups.

extern TIM_HandleTypeDef htim1;
extern ADC_HandleTypeDef hadc1;
extern TIM_HandleTypeDef htim3; // encoder/timer

STM32F303Motor::STM32F303Motor() {}

bool STM32F303Motor::begin() {
  initTimers();
  initADC();
  initEncoder();
  return true;
}

void STM32F303Motor::initTimers() {
  // Start PWM channels - user must configure timers in CubeMX
  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
}

void STM32F303Motor::initADC() {
  // ADC must be configured in user project
  HAL_ADC_Start(&hadc1);
}

void STM32F303Motor::initEncoder() {
  HAL_TIM_Encoder_Start(&htim3, TIM_CHANNEL_ALL);
}

void STM32F303Motor::setPWM(uint8_t channel, float duty) {
  if (duty < 0) duty = 0; if (duty > 1) duty = 1;
  uint32_t period = __HAL_TIM_GET_AUTORELOAD(&htim1);
  uint32_t ccr = (uint32_t)(duty * period);
  switch (channel) {
    case 1: __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, ccr); break;
    case 2: __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, ccr); break;
    default: break;
  }
}

uint32_t STM32F303Motor::readADC(uint8_t channel) {
  // Simple single conversion read; assumes channel configured in ADC sequence
  if (HAL_ADC_PollForConversion(&hadc1, 10) == HAL_OK) {
    return HAL_ADC_GetValue(&hadc1);
  }
  return 0;
}

int32_t STM32F303Motor::readEncoder() {
  return (int32_t)__HAL_TIM_GET_COUNTER(&htim3);
}

float STM32F303Motor::PID::update(float setpoint, float meas, float dt) {
  float err = setpoint - meas;
  integrator += err * dt;
  float derivative = (err - lastError) / (dt > 0 ? dt : 1e-6f);
  lastError = err;
  return kp * err + ki * integrator + kd * derivative;
}

void STM32F303Motor::controlPID(float setpoint, float meas, float dt) {
  float out = pid.update(setpoint, meas, dt);
  // Map output (-inf..inf) to 0..1 duty for demonstration
  float duty = (out + 1.0f) * 0.5f; // naive mapping; tune in real use
  setPWM(1, duty);
}
