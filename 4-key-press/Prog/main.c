#include <mega32.h>
#include <delay.h>

void main(void)
{
    DDRB.0=0;           // Set B.0 input
    DDRD.0=1;           // Set D.0 output
    
    while(1)            // Loop
    {
        if(PINB.0==1)   // Check B.0 status
        {
            PORTD.0=1;  // LED ON   
        }
        else            
        {
            PORTD.0=0;  // LED OFF
        } 
    }
    
}
