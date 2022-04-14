#include <mega32.h>
#include <delay.h>

void main(void)
{
      DDRA=0xff;                // Set all pin of port A as Output

      while (1)                 // Loop
      {
            if(PORTA==0x00)     // Chek the value of port
            {
                PORTA=0x80;     // Reset Value of port A (1000 0000)bin 
            } 
            delay_ms(500);      // Delay 0.5S    
            PORTA=PORTA >> 1;   // Shift port A 1time to right
      }
}
