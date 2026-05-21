STM32F303 Hardware Package (template)

This folder contains a minimal Arduino hardware package template for the STM32F303CCT6 board. It is a convenience wrapper that helps the Arduino IDE display a board entry and provides placeholders for upload recipes.

Installation (recommended):
1. Install stm32duino core (Arduino_Core_STM32) following its README: https://github.com/stm32duino/Arduino_Core_STM32
2. Copy this `hardware/STM32F303` folder into your Arduino sketchbook's `hardware` directory (e.g., C:\Users\<you>\Documents\Arduino\hardware\).
3. Restart Arduino IDE. Select "STM32F303CCT6 (Generic)" from Boards menu.
4. Edit `platform.txt` and set `recipe.upload.pattern` to the upload tool provided by your core (for example, the stlink or openocd binary). If you want to use ST-Link, ensure the ST-Link upload tool is installed and available.

Notes:
- This package does not replace the official core. The stm32duino core is required for compilation and correct upload recipes.
- If you want a complete Boards Manager package (installable via URL), create a package_index.json and host binaries; for local use copying into hardware/ is sufficient.
