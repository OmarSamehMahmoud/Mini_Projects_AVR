/*
 * Led_Intensity.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: sameh
 */

#include "Led_Intensity.h"

void Toogle_Led(void)
{
	toggle_bit(PORTC,7);
}

void Led_25_Intensity(void)
{
	PORTB=0xff;
	TCCR0=0b01101001;
	TIMSK=0b00000010;
	OCR0=0;//duty cycle
}

void Led_50_Intensity(void)
{
	PORTB=0xff;
	TCCR0=0b01101001;
	TIMSK=0b00000010;
	OCR0=64;
}

void Led_100_Intensity(void)
{
	PORTB=0xff;
	TCCR0=0b01101001;
	TIMSK=0b00000010;
	OCR0=128;
}
