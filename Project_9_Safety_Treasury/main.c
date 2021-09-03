
#include<avr/io.h>
#include<util/delay.h>
#include"Types.h"
#include"Bit_Math.h"
#include"TWI.h"
#include"LCD.h"
#include"EEPROM_Driver.h"
#include"keypad.h"
#include"password.h"
#include "GSM_Sender.h"
/*			NOTE : Password code saved in EEPROM via keybad and displayed on LCD		*/
int main (void)
{
	/*	PORTB for keypad	*/
	/*	PORTD PORTA for LCD	*/
	/*	PC0 PC1 for EEPROM	*/
	DDRD=0b11111110;
	DDRA=0xff;
	DDRC=0xff;
	u8 Password[4];
	u8 Password_saved[4];
	u8 count=0;
	LCD_Init();
	EEPROM_init();
	password_default ();
	USART_Init();
	while(1)
	{
		/*	Ask user to enter password	*/
		LCD_WriteCommand(0b00000001);
		LCD_WriteCommand(0b10000000);
		LCD_WriteData('P');
		LCD_WriteData('a');
		LCD_WriteData('s');
		LCD_WriteData('s');
		LCD_WriteData('w');
		LCD_WriteData('o');
		LCD_WriteData('r');
		LCD_WriteData('d');
		LCD_WriteData(':');
		_delay_ms(100);
		Password[0]=48+keybad();
		_delay_ms(100);
		LCD_WriteData(Password[0]);
		_delay_ms(100);
		Password[1]=48+keybad();
		_delay_ms(100);
		LCD_WriteData(Password[1]);
		_delay_ms(100);
		Password[2]=48+keybad();
		_delay_ms(100);
		LCD_WriteData(Password[2]);
		_delay_ms(100);
		Password[3]=48+keybad();
		_delay_ms(100);
		LCD_WriteData(Password[3]);
		_delay_ms(100);
		/*	Read the saved password from EEPROM	*/
		Password_saved[0]=EEPROM_Read_Data(0x0f);
		Password_saved[1]=EEPROM_Read_Data(0x1f);
		Password_saved[2]=EEPROM_Read_Data(0x2f);
		Password_saved[3]=EEPROM_Read_Data(0x3f);

		/*	Check if password is correct or not	*/
		if(Password[0]==Password_saved[0] && Password[1]==Password_saved[1] && Password[2]==Password_saved[2] && Password[3]==Password_saved[3])
		{
			count=0;
			SETBIT(PORTD,7);
			_delay_ms(500);
			CLRBIT(PORTD,7);
			welcome_change_password ();

		}
		else
		{
			count++;
			if(count<3)
			{
				wrong_tryagain();
			}
			else
			{
				not_allowed();

			}


		}


	}
	return 0;
}

