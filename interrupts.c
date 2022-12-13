/************************************************************************
 interrupts.c: Inneh�ller avbrottsrutin f�r tryckknapp.               
************************************************************************/
#include "header.h"

/************************************************************************
* ISR: Avbrottsrutin vid uppsl�ppning av tryckknapp.
       
	    counter: R�knar antalet tryck p� knappen                         
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
