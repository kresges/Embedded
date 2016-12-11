#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "uart.h"

#define CPU_PRESCALE(n) (CLKPR = 0x80,CLKPR = (n))
#define CPU_8Mhz        0x01
int main(void){
  CPU_PRESCALE(CPU_8Mhz);
  sei();

  DDRD |= 0xFF;
  DDRC |= 0xFF;
  PORTC |= 0xFF;

  uart_init();

  char msg[100] = "Teensy out";

  while(1){
    PORTD |= (1<<6);
    uart_puts(msg);
    _delay_ms(100);
    PORTD &= ~(1<<6);
    _delay_ms(100);
  }

}
