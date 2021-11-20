#include "uart_serial.h"
#include <avr/io.h>
#include <avr/interrupt.h>

volatile uint16_t UART_tx_shift_reg = 0;

void UART_tx(char character) {
   uint16_t local_tx_shift_reg = UART_tx_shift_reg;
   //if sending the previous character is not yet finished, return
   //transmission is finished when UART_tx_shift_reg == 0
   if(local_tx_shift_reg){return;}
   //fill the TX shift register witch the character to be sent and the start & stop bits (start bit (1<<0) is already 0)
   local_tx_shift_reg = (character<<1) | (1<<9); //stop bit (1<<9)
   UART_tx_shift_reg = local_tx_shift_reg;
   //start timer0 with a prescaler of 8
   TCCR0B = (1<<CS01);
}

void UART_tx_str(char* string) {
    while( *string ) {
        UART_tx( *string++ );
        //wait until transmission is finished
        while(UART_tx_shift_reg);
    }
}

void UART_init() {
   //set TX pin as output
   UART_TX_DDR |= (1<<UART_TX_DDR_PIN);
   UART_TX_PORT |= (1<<UART_TX_PIN);
   //set timer0 to CTC mode
   TCCR0A = (1<<WGM01);
   //enable output compare 0 A interrupt
#ifdef TIMSK0
   TIMSK0 |= (1<<OCIE0A);
#else
   TIMSK |= (1<<OCIE0A);
#endif
   //set compare value to 103 to achieve a 9600 baud rate (i.e. 104µs)
   //together with the 8MHz/8=1MHz timer0 clock
   /*NOTE: since the internal 8MHz oscillator is not very accurate, this value can be tuned
     to achieve the desired baud rate, so if it doesn't work with the nominal value (103), try
     increasing or decreasing the value by 1 or 2 */
   OCR0A = 103;
   //enable interrupts
   sei();
}

//timer0 compare A match interrupt
ISR(TIMER0_COMPA_vect) {
   uint16_t local_tx_shift_reg = UART_tx_shift_reg;
   //output LSB of the TX shift register at the TX pin
   if (
      
      local_tx_shift_reg & 0x01 ) {
      UART_TX_PORT |= (1<<UART_TX_PIN);
   } else {
      UART_TX_PORT &=~ (1<<UART_TX_PIN);
   }
   //shift the TX shift register one bit to the right
   local_tx_shift_reg >>= 1;
   UART_tx_shift_reg = local_tx_shift_reg;
   //if the stop bit has been sent, the shift register will be 0
   //and the transmission is completed, so we can stop & reset timer0
   if (!local_tx_shift_reg) {
      TCCR0B = 0;
      TCNT0 = 0;
   }
}
