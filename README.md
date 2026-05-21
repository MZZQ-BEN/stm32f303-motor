STM32F303Motor

Quickstart (PlatformIO):
- In platformio.ini add:
  lib_deps = https://github.com/MZZQ-BEN/stm32f303-motor.git
  board = genericSTM32F303CCT6

Arduino IDE support (basic):
- This repo includes a minimal hardware package template under `hardware/STM32F303`:
  - Copy the `hardware/STM32F303` folder into your Arduino "hardware" directory (e.g., <Arduino sketchbook>/hardware/).
  - Restart Arduino IDE. The board "STM32F303CCT6 (Generic)" should appear under Boards.
  - IMPORTANT: The template is minimal. For full functionality, install the stm32duino core (https://github.com/stm32duino/Arduino_Core_STM32) and adapt the variant pins file in `hardware/STM32F303/variants/genericSTM32F303CCT6/pins_arduino.h` to match your board's pin mapping and boot/upload settings.

Notes:
- The library expects HAL initialization (CubeMX or manual) for TIM (PWM), ADC, and encoder TIM.
- For PlatformIO the PlatformIO ststm32 platform + appropriate board configuration is still recommended.

Co-authored-by: Copilot <223556219+Copilot@users.noreply.github.com>