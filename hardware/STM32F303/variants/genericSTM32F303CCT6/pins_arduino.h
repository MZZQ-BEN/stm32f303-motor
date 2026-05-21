/*
  pins_arduino.h - Variant template for STM32F303CCT6
  This is a template. Replace with actual mappings from your board or the stm32duino core variant.
*/

#ifndef PINS_ARDUINO_H
#define PINS_ARDUINO_H

#define NUM_DIGITAL_PINS 38
#define NUM_ANALOG_INPUTS 8

// Define analog pins as placeholders; update to real pin numbers
#define A0 0
#define A1 1
#define A2 2
#define A3 3
#define A4 4
#define A5 5
#define A6 6
#define A7 7

// Minimal compatibility macros (may be overridden by core)
#define digitalPinToPinName(P) (P)
#define digitalPinToPort(P) (P)
#define digitalPinToBitMask(P) (1U<<((P)&31))

#endif // PINS_ARDUINO_H
