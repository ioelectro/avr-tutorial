#include <mega32.h>
#include <delay.h>

char ConvertTo7Seg[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};   // 7Seg Data Array

void main(void)
{
    int counter=0,i;

    DDRD=0xff;                              // Set port D output
    PORTD=0x00;                             // Set value to port D
    
    DDRA.0=0;                               // Set A.0 as input
    PORTA.0=1;                              // Pin is input so write 1 mean the pullUp enabled
    
    PORTD=ConvertTo7Seg[counter];           // Display counter on 7seg

    while(1)                                // Loop
    {
        if(PINA.0==0)                       // Check button
        {
          if(counter<9)counter++;           // counter = counter  + 1
          PORTD=ConvertTo7Seg[counter];     // Display counter on 7seg   
          
          for(i=0;i<20&&PINA.0==0;i++)      // Var delay time (max = 50*20ms = 1S) if key pressed
          {                                 // 'i' is timing var and 'for' is loop 20 times if PINA.0==0
           delay_ms(50);                    // Delay 50ms                    
          }
          
          while(PINA.0==0)                  // Check key pressed or not,it's a loop,continu until key realise
          {
              counter++;                    // counter = counter  + 1
              if(counter>9)counter=0;       // Reset counter value
              PORTD=ConvertTo7Seg[counter]; // Display counter on 7seg   
              delay_ms(500);                // Delay 0.5S
          }
        } 
    }
}
