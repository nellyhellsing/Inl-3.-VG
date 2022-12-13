/********************************************************************************
* main.c: Tre lysdioder anslutna till pin 8 – 10 samt en tryckknapp ansluten till
*         pin 13. Lysdiodernas blinkriktning ändras efter var femte uppsläppning
*         av tryckknappen.
*		                     
          - Blinkar med blinkhastigheten 100ms.
********************************************************************************/
#include "header.h"

int main(void)
{
    setup();
    while (1) 
    {
		leds_blink(100);
    }
	return 0;
}

