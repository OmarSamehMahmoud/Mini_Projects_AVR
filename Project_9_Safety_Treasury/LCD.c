#include "LCD.h"

extern void LCD_Init(void)
{
	_delay_ms(40);
	LCD_WriteCommand(0b00111000);//function set DL=1 for 8 bit connection,N=1 for 2 lines, F=1 for font size
    _delay_ms(3);
    LCD_WriteCommand(0b00001100);//Display control D display
    _delay_ms(3);
    LCD_WriteCommand(0b00000001);//Clear display

}

extern void LCD_WriteCommand(u8 command)
{
	CLRBIT(PORTC,5); // rs=0 rs->a0
	CLRBIT(PORTC ,6); // rw=0 rw->a1
	PORTA=command;
	SETBIT(PORTC,7);
	_delay_ms(2);
	CLRBIT(PORTC,7);


}

extern void LCD_WriteData(u8 data)
{
	SETBIT(PORTC,5); // rs=1 rs->a0
	CLRBIT(PORTC ,6); // rw=0 rw->a1
	PORTA=data;
	SETBIT(PORTC,7);
	_delay_ms(2);
	CLRBIT(PORTC,7);


}

