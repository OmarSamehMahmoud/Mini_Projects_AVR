/*
 * 7segement.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: sameh
 */
#include <avr/io.h>
#define F_CPU 16000000
#include "avr/delay.h"
#include "types.h"
#include "utilss.h"
#include "Traffic.h"
/* function to execute traffic lights with seven segement and colors led the first for loop
 * to counting the decimal values of segement portb and second for loop to counting the values
 * of other segement and delays order to wait the counting for seconds ,then portb will enable
 * the buzzer to give the beep and the gate is closing and while counting segement to next
 * for loop counting red and next become yellow and the buzzer is giving a beep and the gate
 * is open */
extern void seven(u8 segarr[],u8 i,u8 seg[],u8 y)
{
	for(i=5;i>=0;i--)
	{
		set_bit(PORTC,3);//set led green
		PORTB=segarr[i];
		if((i%2)==1)
		{
		lcd_init();
		lcd_writecommand(0b10000000);
							lcd_writedata('I');
							lcd_writedata('M');
							lcd_writedata('T');
							lcd_writedata(' ');
							lcd_writedata('S');
							lcd_writedata('c');
							lcd_writedata('h');
							lcd_writedata('o');
							lcd_writedata('o');
							lcd_writedata('l');
							lcd_writecommand(0xc0);//move cursor to second row
							lcd_writedata('B');
							lcd_writedata('e');
							lcd_writedata('s');
							lcd_writedata('t');
							lcd_writedata(' ');
							lcd_writedata('E');
							lcd_writedata('s');
							lcd_writedata(' ');
							lcd_writedata('C');
							lcd_writedata('e');
							lcd_writedata('n');
							lcd_writedata('t');
							lcd_writedata('e');
							lcd_writedata('r');
							lcd_writecommand(0x0c);//display on,cursor off
			}else
			{
						lcd_writecommand(0x01);//make clear lcd
							lcd_writedata('M');
							lcd_writedata('o');
							lcd_writedata('d');
							lcd_writedata('e');
							lcd_writedata('r');
							lcd_writedata('n');
							lcd_writedata(' ');
							lcd_writedata('A');
							lcd_writedata('c');
							lcd_writedata('a');
							lcd_writedata('d');
							lcd_writedata('e');
							lcd_writedata('m');
							lcd_writedata('y');
							lcd_writecommand(0xc0);//move cursor to second row
							lcd_writedata('F');
							lcd_writedata('o');
							lcd_writedata('r');
							lcd_writedata(' ');
							lcd_writedata('E');
							lcd_writedata('n');
							lcd_writedata('g');
							lcd_writedata('i');
							lcd_writedata('n');
							lcd_writedata('e');
							lcd_writedata('e');
							lcd_writedata('r');
							lcd_writedata('i');
							lcd_writedata('n');
							lcd_writedata('g');
							lcd_writecommand(0x0c);//display on,cursor off
					}
		for(y=9;y>0;y--)
		{
			PORTA=seg[y];
			_delay_ms(1000);

		}
		PORTA=0b00000010;

				_delay_ms(1000);
				if(i==0)
				{
					if(PORTA==0b00000010)
					break;
				}

	}
	clr_bit(PORTC,3);//clear led green
	set_bit(PORTC,5);//set led green
	PORTB=0b10011110;
	PORTA=0b00000010;
	_delay_ms(1000);
	PORTB=0b00000010;

		set_bit(PORTC,6);//set motor
		_delay_ms(300);
		clr_bit(PORTC,6);
		set_bit(PORTB,0);
		for(y=9;y>0;y--)
		{
			PORTA=seg[y];

			_delay_ms(1000);
		}
		PORTA=0b00000010;
		_delay_ms(1000);
	clr_bit(PORTB,0);
	for(i=5;i>=0;i--)
		{
		clr_bit(PORTC,5);
		clr_bit(PORTC,6);
		set_bit(PORTC,4);
		PORTB=segarr[i];
		if((i%2)==1)
				{
				lcd_init();
				lcd_writecommand(0b10000000);
									lcd_writedata('I');
									lcd_writedata('M');
									lcd_writedata('T');
									lcd_writedata(' ');
									lcd_writedata('S');
									lcd_writedata('c');
									lcd_writedata('h');
									lcd_writedata('o');
									lcd_writedata('o');
									lcd_writedata('l');
									lcd_writecommand(0xc0);//move cursor to second row
									lcd_writedata('B');
									lcd_writedata('e');
									lcd_writedata('s');
									lcd_writedata('t');
									lcd_writedata(' ');
									lcd_writedata('E');
									lcd_writedata('s');
									lcd_writedata(' ');
									lcd_writedata('C');
									lcd_writedata('e');
									lcd_writedata('n');
									lcd_writedata('t');
									lcd_writedata('e');
									lcd_writedata('r');
									lcd_writecommand(0x0c);//display on,cursor off
					}else
					{
								lcd_writecommand(0x01);//make clear lcd
									lcd_writedata('M');
									lcd_writedata('o');
									lcd_writedata('d');
									lcd_writedata('e');
									lcd_writedata('r');
									lcd_writedata('n');
									lcd_writedata(' ');
									lcd_writedata('A');
									lcd_writedata('c');
									lcd_writedata('a');
									lcd_writedata('d');
									lcd_writedata('e');
									lcd_writedata('m');
									lcd_writedata('y');
									lcd_writecommand(0xc0);//move cursor to second row
									lcd_writedata('F');
									lcd_writedata('o');
									lcd_writedata('r');
									lcd_writedata(' ');
									lcd_writedata('E');
									lcd_writedata('n');
									lcd_writedata('g');
									lcd_writedata('i');
									lcd_writedata('n');
									lcd_writedata('e');
									lcd_writedata('e');
									lcd_writedata('r');
									lcd_writedata('i');
									lcd_writedata('n');
									lcd_writedata('g');
									lcd_writecommand(0x0c);//display on,cursor off
							}
				for(y=9;y>0;y--)
				{
					PORTA=seg[y];
					_delay_ms(1000);

				}

				PORTA=0b00000010;
				_delay_ms(1000);
				if(i==0)
				{
					if(PORTA==0b00000010)
					break;
				}
	}
	clr_bit(PORTC,4);//clear led yellow
		set_bit(PORTC,5);//set led red
		PORTB=0b10011110;
			PORTA=0b00000010;
			_delay_ms(1000);
			PORTB=0b00000010;
		set_bit(PORTC,7);//motor anti clockwise
		set_bit(PORTB,0);//set buzzer
		_delay_ms(300);
		clr_bit(PORTC,7);//clear bit motor

		for(y=9;y>0;y--)
		{
			PORTA=seg[y];
			_delay_ms(1000);
		}
		PORTA=0b00000010;
		_delay_ms(1000);
		clr_bit(PORTC,5);//clear led red
		clr_bit(PORTB,0);


}

