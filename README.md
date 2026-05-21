STM32F303Motor

This repo now includes a complete Arduino hardware package template under `hardware/STM32F303` to enable single-folder installation into the Arduino IDE. It still expects the stm32duino core for compilation and upload tools.

How to install for Arduino IDE (local):
1. Install stm32duino core: https://github.com/stm32duino/Arduino_Core_STM32
2. Copy `hardware/STM32F303` into your Arduino sketchbook `hardware` folder.
3. Restart Arduino IDE and choose the board.
4. Edit `hardware/STM32F303/platform.txt` to point `recipe.upload.pattern` to the correct upload tool (stlink/openocd/dfu-util) available on your system.

PlatformIO: Prefer using lib_deps or a custom board JSON. See examples/ for PlatformIO usage.

Co-authored-by: Copilot <223556219+Copilot@users.noreply.github.com>