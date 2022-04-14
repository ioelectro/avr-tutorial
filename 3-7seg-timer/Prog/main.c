#include <mega32.h>
#include <delay.h>

void main(void)
{
    int counter=0,dahgan,yekan,i;

    DDRC=0xff;                      // Set port C output
    DDRD=0xff;                      // Set port D output

    while(1)
    {
        dahgan=counter / 10;        // Get "dahgan" from counter
        yekan =counter % 10;        // Get "yekan" from counter
        
        
        for(i=0;i<20;i++)           // Use 2 digit 7seg by multiplexing
        {                           // Delay = 20*(5+5)=200ms

            PORTC=dahgan;           // Send "dahgan" to 7seg for display
            PORTD.0=1;              // Enable 7seg dig1
            delay_ms(5);            // Some small delay time for displaying
            PORTD.0=0;              // Disable 7seg dig1

            PORTC=yekan;            // Send "yekan" to 7seg for display
            PORTD.1=1;              // Enable 7seg dig2
            delay_ms(5);            // Some small delay time for displaying
            PORTD.1=0;              // Disable 7seg dig2
        }
        
        counter++;                  // counter = counter + 1
        if(counter>99)counter=0;    // Reset if counter > 99
    }
}
