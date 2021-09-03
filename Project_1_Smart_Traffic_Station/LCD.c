/*

 * lcdfunction.c
 *
 *  Created on: Aug 11, 2017
 *      Author: OMAR
 */
#include <stdio.h>
#include "avr/io.h"
#define F_cpu 16000000
#include "avr/delay.h"
#include "types.h"
#include "utilss.h"
extern void lcd_init(void)
{
	_delay_ms(50);
	lcd_writecommand(0b00111000);
	_delay_ms(1);
	lcd_writecommand(0b00001111);
	_delay_ms(1);
	lcd_writecommand(0b00000001);
	_delay_ms(2);

}
extern void lcd_writecommand(u8 command)
{
	clr_bit(PORTC,0); // rs=0 rs->a0
	clr_bit(PORTC ,1); // rw=0 rw->a1
	PORTD=command;
	set_bit(PORTC,2);
	_delay_ms(2);
	clr_bit(PORTC,2);


}

extern void lcd_writedata(u8 data)
{
	set_bit(PORTC,0); // rs=1 rs->a0
	clr_bit(PORTC ,1); // rw=0 rw->a1
	PORTD=data;
	set_bit(PORTC,2);
	_delay_ms(2);
	clr_bit(PORTC,2);


}

