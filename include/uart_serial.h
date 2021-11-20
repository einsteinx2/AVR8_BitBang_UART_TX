// Bit banged UART serial modified by Ben Baron: https://github.com/einsteinx2/AVR8_BitBang_UART_TX
// Original code MIT licensed by Marcel Meyer-Garcia at https://github.com/MarcelMG/AVR8_BitBang_UART_TX 

/*  Software ("bit-bang") UART Transmitter (8 data bits, 1 stop bit, no parity)
    for Attiny24A/44A/84A using the internal 8MHz oscillator as clock source

    MIT License

    Copyright (c) 2018 Marcel Meyer-Garcia

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
 */

#ifndef __UART_SERIAL_H__
#define __UART_SERIAL_H__

// change these to use another pin
#define UART_TX_PORT PORTC
#define UART_TX_PIN  PC7
#define UART_TX_DDR  DDRC
#define UART_TX_DDR_PIN DDC7

void UART_tx(char character);
void UART_tx_str(char* string);
void UART_init();

#endif