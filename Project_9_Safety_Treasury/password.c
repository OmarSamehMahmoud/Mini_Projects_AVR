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

void password_default(void) {
	/*	Write default password in EEPROM 1234	*/
	EEPROM_Write_Data(0x0f, 49);
	_delay_ms(50);
	EEPROM_Write_Data(0x1f, 50);
	_delay_ms(50);
	EEPROM_Write_Data(0x2f, 51);
	_delay_ms(50);
	EEPROM_Write_Data(0x3f, 52);
	_delay_ms(50);

}
void password_change(void) { /*	To change the default password	*/
	u8 New_password[4];
	LCD_WriteCommand(0b00000001);
	LCD_WriteCommand(0b10000000);
	LCD_WriteData(' ');
	LCD_WriteData(' ');
	LCD_WriteData(' ');
	LCD_WriteData('E');
	LCD_WriteData('n');
	LCD_WriteData('t');
	LCD_WriteData('e');
	LCD_WriteData('r');
	LCD_WriteData(' ');
	LCD_WriteData('n');
	LCD_WriteData('e');
	LCD_WriteData('w');
	LCD_WriteData(' ');
	LCD_WriteCommand(0b11000000);
	LCD_WriteData(' ');
	LCD_WriteData(' ');
	LCD_WriteData('p');
	LCD_WriteData('a');
	LCD_WriteData('s');
	LCD_WriteData('s');
	LCD_WriteData('w');
	LCD_WriteData('o');
	LCD_WriteData('r');
	LCD_WriteData('d');
	LCD_WriteData(':');
	New_password[0] = 48 + keybad();
	_delay_ms(100);
	EEPROM_Write_Data(0x0f, New_password[0]);
	_delay_ms(100);
	LCD_WriteData(New_password[0]);
	_delay_ms(100);
	New_password[1] = 48 + keybad();
	_delay_ms(100);
	EEPROM_Write_Data(0x1f, New_password[1]);
	_delay_ms(100);
	LCD_WriteData(New_password[1]);
	_delay_ms(100);
	New_password[2] = 48 + keybad();
	_delay_ms(100);
	EEPROM_Write_Data(0x2f, New_password[2]);
	_delay_ms(100);
	LCD_WriteData(New_password[2]);
	_delay_ms(100);
	New_password[3] = 48 + keybad();
	_delay_ms(100);
	EEPROM_Write_Data(0x3f, New_password[3]);
	_delay_ms(100);
	LCD_WriteData(New_password[3]);
	_delay_ms(250);

}

void wrong_tryagain(void) { /*	 wrong password message and Try again	*/
	LCD_WriteCommand(0b00000001);
	LCD_WriteCommand(0b10000000);
	LCD_WriteData(' ');
	LCD_WriteData(' ');
	LCD_WriteData(' ');
	LCD_WriteData(' ');
	LCD_WriteData(' ');
	LCD_WriteData(' ');
	LCD_WriteData('W');
	LCD_WriteData('r');
	LCD_WriteData('o');
	LCD_WriteData('n');
	LCD_WriteData('g');
	LCD_WriteData(' ');
	LCD_WriteData(' ');
	_delay_ms(1000);
	LCD_WriteCommand(0b00000001);
	LCD_WriteCommand(0b10000000);
	LCD_WriteData(' ');
	LCD_WriteData(' ');
	LCD_WriteData(' ');
	LCD_WriteData('T');
	LCD_WriteData('r');
	LCD_WriteData('y');
	LCD_WriteData(' ');
	LCD_WriteData('a');
	LCD_WriteData('g');
	LCD_WriteData('a');
	LCD_WriteData('i');
	LCD_WriteData('n');
	LCD_WriteData(' ');
	_delay_ms(1000);

}
void welcome_change_password(void) { /*		Welcome message and password change message		*/
	u8 change_password;
	LCD_WriteCommand(0b00000001);
	LCD_WriteCommand(0b10000000);
	LCD_WriteData(' ');
	LCD_WriteData(' ');
	LCD_WriteData(' ');
	LCD_WriteData(' ');
	LCD_WriteData('W');
	LCD_WriteData('e');
	LCD_WriteData('l');
	LCD_WriteData('c');
	LCD_WriteData('o');
	LCD_WriteData('m');
	LCD_WriteData('e');
	LCD_WriteData(' ');
	LCD_WriteData(' ');
	LCD_WriteCommand(0b11000000);
	LCD_WriteData('p');
	LCD_WriteData('r');
	LCD_WriteData('e');
	LCD_WriteData('s');
	LCD_WriteData('s');
	LCD_WriteData('2');
	LCD_WriteData(' ');
	LCD_WriteData('t');
	LCD_WriteData('o');
	LCD_WriteData(' ');
	LCD_WriteData('c');
	LCD_WriteData('h');
	LCD_WriteData('a');
	LCD_WriteData('n');
	LCD_WriteData('g');
	LCD_WriteData('e');
	change_password = keybad();
	if (change_password == 2) {
		password_change();
	} else {

		_delay_ms(100);
	}

}
u8 y = 0;
void not_allowed(void) {
	while (1) {
		for (u8 i = 0; i < 50; i++) {
			if (y == 0) {
				sendSMS();
				y++;
			}
			LCD_WriteCommand(0b00000001);
			LCD_WriteCommand(0b10000000);
			LCD_WriteData(' ');
			LCD_WriteData(' ');
			LCD_WriteData(' ');
			LCD_WriteData('N');
			LCD_WriteData('o');
			LCD_WriteData('t');
			LCD_WriteData(' ');
			LCD_WriteData('a');
			LCD_WriteData('l');
			LCD_WriteData('l');
			LCD_WriteData('o');
			LCD_WriteData('w');
			LCD_WriteData('e');
			LCD_WriteData('d');
			LCD_WriteData(' ');
			LCD_WriteData(' ');
			LCD_WriteData('!');

			SETBIT(PORTD, 4); //Buzzer
			SETBIT(PORTD, 5); //LED
			_delay_ms(300);
			LCD_WriteCommand(0b00000001);
			CLRBIT(PORTD, 4);
			CLRBIT(PORTD, 5);
			_delay_ms(300);

		}
	}

}
