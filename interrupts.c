/************************************************************************
 interrupts.c: Innehåller avbrottsrutin för tryckknapp.               
************************************************************************/
#include "header.h"

/************************************************************************
* ISR: Avbrottsrutin vid uppsläppning av tryckknapp.
       
	    counter: Räknar antalet tryck på knappen                         
************************************************************************/
ISR (PCINT0_vect)
{
	static volatile uint8_t counter = 0;
	
	if (!BUTTON1_IS_PRESSED)
	{
		if (counter == 5)
		{
			leds_switch_direction();
	        counter = 0;
		}
		counter ++;
	}
}
