/*
 * motor.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: sameh
 */

#include "Door.h"

void Door_Open(void)
{
	set_bit(PORTD,5);
	clr_bit(PORTD,6);
	_delay_ms(1000); //open the door
	clr_bit(PORTD,5);
	clr_bit(PORTD,6);
}

void Door_Close(void)
{
	set_bit(PORTD,6);
	clr_bit(PORTD,5);
	_delay_ms(1000);//close the door
	clr_bit(PORTD,6);
	clr_bit(PORTD,5);
}

