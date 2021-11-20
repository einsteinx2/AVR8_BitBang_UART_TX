// Bit banged UART serial based off of this example code: https://github.com/einsteinx2/AVR8_BitBang_UART_TX
// Original code MIT licensed by Marcel Meyer-Garcia at https://github.com/MarcelMG/AVR8_BitBang_UART_TX 

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