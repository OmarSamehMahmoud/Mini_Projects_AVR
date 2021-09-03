/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: sameh
 */

#include "ADC.h"

u8 Status[12] = "Person:";
u8 Name_Test_English[5] = "here";
u8 Namei_Test_English[9] = "Not here";

int main(void) {

	DIO_SetPortDirection(PORTC, HIGH);
	DIO_SetPinDirection(PORTA, PIN0, LOW);

	DIO_SetPinDirection(PORTB, PIN0, OUTPUT);
	DIO_SetPinDirection(PORTB, PIN1, OUTPUT);
	DIO_SetPinDirection(PORTB, PIN2, OUTPUT);

	DIO_SetPinDirection(PORTD, PIN0, INPUT);  //  D0: Rx ( input )
	DIO_SetPinDirection(PORTD, PIN1, OUTPUT); //  D1: Tx ( output )

	DIO_SetPinDirection(PORTD, PIN2, INPUT);  //  D2: Flame Sensor ( input )

	DIO_SetPinDirection(PORTB, PIN4, HIGH);
	ADC_Init();  // Init of ADC Function call
	LCD_vidInit(); // Init of LCD Function call
	USART_Init(); // Init of USART Function call

	while (1) {

		int val = ADC_Read(0);

		int ADCe = (val * 5) / 250;

		if (ADCe > 3) {
			LCD_String_xy(1, 0, Status);
			LCD_String_xy(2, 3, Namei_Test_English);
			_delay_ms(1000);
			DIO_SetPinValue(PORTB, PIN4, LOW);
			_delay_ms(1000);
			LCD_vidSendCommand(0x01);
		} else {
			DIO_SetPinValue(PORTB, PIN4, HIGH);
			LCD_String_xy(1, 0, Status);
			LCD_String_xy(2, 3, Name_Test_English);
			sendSMS();
			LCD_vidSendCommand(0x01);
		}
	}
}
