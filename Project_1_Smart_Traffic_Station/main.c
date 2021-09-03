/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: sameh
 */
#include <avr/io.h>//include Library of avr input and output from our system
#include <util/delay.h>//include Library of avr delay from our system
#include "types.h"//include definition of data types By user
#include "utilss.h"//include definition of set 1 and clr 0
#include "Traffic.h"//include header file which defined Prototypes of our functions
int main(void)//the entry of our program
{
	/* defined variables and defined ports act as output */

	u8 segarr[6]={0b00000010,0b10011110,0b00100100,0b00001100,0b10011000,0b01001000};
	u8 seg[10]={0b00000010,0b10011110,0b00100100,0b00001100,0b10011000,0b01001000,0b01000000,0b00011110,0b00000000,0b00001000};
	u8 y;
	u8 i;
	DDRA=0b11111111;
	DDRB=0b11111111;
	DDRC=0b11111111;
	DDRD=0b11111111;
	/* calling functions of Liquid crystal display and 7 segements and while loop to execute the functions along the program*/
	while(1)
	{
	seven(segarr,i,seg,y);
	}
	while(1)
	{

	}

}

