STM32F303Motor

Quickstart:
- Add this library to PlatformIO's lib_deps using the repository URL:
  lib_deps = https://github.com/MZZQ-BEN/stm32f303-motor.git
- Ensure your project initializes TIM (PWM), ADC, and encoder TIM (CubeMX generated code recommended).
- Include "STM32F303Motor.h" and call begin().

This is a starter skeleton: expand driver support (DRV drivers), refine FOC, and add board variants.
