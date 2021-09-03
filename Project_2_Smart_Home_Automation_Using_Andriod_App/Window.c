/*

 * servo.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Omar
 */

#include "Window.h"

char res; //Received Data
char o,m,f;

ISR(TIMER0_OVF_vect)
{static int counter=0;
TCNT0=156;
counter++;
switch (res)
{
case 'o':
	if(counter==20)
	{
		clr_bit(PORTD,7);
	}
	else if(counter==200)
	{
		set_bit(PORTD,7);
		counter=0;
	}
	break;
case 'f':
	if(counter==10)
	{
		clr_bit(PORTD,7);
	}
	else if(counter==100)
	{
		set_bit(PORTD,7);
		counter=0;
	}
	break;
case 'm':
	res=Bluetooth_rx_data(); //resived command
	if(counter==res)
	{
		clr_bit(PORTD,7);
	}
	else if(counter==200)
	{
		set_bit(PORTD,7);
		counter=0;
	}
	break;
}}

void Window_Init(void)
{
TCCR0=0b00000010;
PORTD=0b10000000;
TIMSK=0b00000001;
sei();
}
