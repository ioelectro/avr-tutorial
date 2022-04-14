#include <mega32.h>
#include <delay.h>

void main(void)
{
      DDRB.0=1;                 // Set pin 0 of port B az output

      while (1)                 // Loop
      {                                
            PORTB.0=!PINB.0;    // Toggle LED
            delay_ms(300);      // Delay
      }
}
