/************************************************************************
*Leds.c: Innehåller funktioner gällande blinkning av lysdioder.
************************************************************************/
#include "header.h"


volatile bool blink_direction = false;
static uint16_t speed_ms = 0;

/************************************************************************
* leds_switch_direction: Togglar lysdioderna.        
************************************************************************/
void leds_switch_direction(void)
{
	blink_direction = !blink_direction;
	speed_ms = 0;
	if(!blink_direction) LEDS_OFF;
	return;
}

/************************************************************************
* leds_blink: Anger vilket håll lysdioderna ska blinka åt.
              - blink_speed_ms: Blinkhastighet i millisekunder.
************************************************************************/
void leds_blink(uint16_t blink_speed_ms)
{
	speed_ms = blink_speed_ms;
	if (blink_direction)
	{
		leds_blink_forward(&speed_ms);
	}
	else if (!blink_direction)
	{
		leds_blink_reversed(&speed_ms);
	}
	return;
}

/********************************************************************************
*leds_blink_forward:  Genererar sekventiell blinkning av lysdioder, framåt. 
*
*                      - blink_speed_ms: Blinkhastighet i millisekunder.
********************************************************************************/
void leds_blink_forward(uint16_t* blink_speed_ms)
{
	
		LED1_ON;
		LED2_OFF;
		LED3_OFF;
		delay_ms(&speed_ms);

		LED1_OFF;
		LED2_ON;
		LED3_OFF;
		delay_ms(&speed_ms);

		LED1_OFF;
		LED2_OFF;
		LED3_ON;
		delay_ms(&speed_ms);
		LEDS_OFF;

	
	return;
}

/********************************************************************************
*leds_blink_forward:  Genererar sekventiell blinkning av lysdioder, bakåt.
*
*                      - blink_speed_ms: Blinkhastighet i millisekunder.
********************************************************************************/
void leds_blink_reversed(uint16_t* blink_speed_ms)
{
	
		LED1_OFF;
		LED2_OFF;
		LED3_ON;
		delay_ms(&speed_ms);
			
		LED1_OFF;
		LED2_ON;
		LED3_OFF;
		delay_ms(&speed_ms);
			
		LED1_ON;
		LED2_OFF;
		LED3_OFF;
		delay_ms(&speed_ms);
			
		LEDS_OFF;
	
	 
	 return;
}


/********************************************************************************
* delay_ms: Genererar angiven fördröjning mätt i millsekunder.

                   - blink_speed_ms: Blinkhastighet i millisekunder.
********************************************************************************/
void delay_ms(const volatile uint16_t* blink_speed_ms)
{
	for (uint16_t i = 0; i < *blink_speed_ms; ++i)
	{
		_delay_ms(1);
	}

	return;
}
