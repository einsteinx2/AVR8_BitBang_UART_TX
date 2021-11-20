/*  Software ("bit-bang") UART Transmitter (8 data bits, 1 stop bit, no parity)
    for Attiny24A/44A/84A using the internal 8MHz oscillator as clock source

    (c) 2018 Marcel Meyer-Garcia
    see LICENCE.txt
 */

 /* NOTE: since the internal 8MHz oscillator is not very accurate, the value for OCR0A can be tuned
    to achieve the desired baud rate (nominal value is 103)
 */

#include "teensy20.h"
#include "uart_serial.h"
#include <util/delay.h>

int main(void) {
   // Teensy defaults to 2MHz unless we specify the CPU_PRESCALE value
   CPU_PRESCALE(CPU_8MHz);

   UART_init();

   while(1) {
      UART_tx_str("Hello world!\n");
      _delay_ms(100);
   }

   return 0;
}
