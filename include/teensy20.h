#ifndef __TEENSY20_H__
#define __TEENSY20_H__

#include <avr/io.h>

// Teensy++ 2.0 CPU Prescaling Macros
// More info: https://www.pjrc.com/teensy/prescaler.html

#define CPU_PRESCALE(n) (CLKPR = 0x80, CLKPR = (n))
#define CPU_16MHz       0x00
#define CPU_8MHz        0x01
#define CPU_4MHz        0x02
#define CPU_2MHz        0x03
#define CPU_1MHz        0x04
#define CPU_500kHz      0x05
#define CPU_250kHz      0x06
#define CPU_125kHz      0x07
#define CPU_62kHz       0x08

#endif