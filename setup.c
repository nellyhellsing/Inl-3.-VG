/********************************************************************************
* setup.c: Innehåller initieringsrutiner.
********************************************************************************/
#include "header.h"

/* Statiska funktioner: */
static inline void init_ports(void);
static inline void init_interrupts(void);

/********************************************************************************
* setup: Initierar mikrodatorn vid start.
*********************************************************************************/
void setup(void)
{
	init_ports();
	init_interrupts();
	return;
}

/********************************************************************************
* init_ports: Sätter lysdiodernas pinnar till utportar och sätter tryckknappens
*             pin till aktiv inport.
*********************************************************************************/
static inline void init_ports(void)
{
	DDRB = (1 << LED1) | (1 << LED2) | (1 << LED3);
	PORTB = (1 << BUTTON1);
	return;
}

/********************************************************************************
* init_interrupts: Aktiverar PCI-avbrott på pin 13.
********************************************************************************/
static inline void init_interrupts(void)
{
	asm("SEI");
	PCICR = (1 << PCIE0);
	PCMSK0 = (1 << BUTTON1);
	
	return;
}
