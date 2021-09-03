/*
 * ADC.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: sameh
 */

#include "ADC.h"
#include <avr/io.h>

extern void ADC_Init(void) {
	// Enable ADC On AVR
	SET_BIT(ADCSRA_Reg, 7);

	// Select Conversion Speed
	SET_BIT(ADCSRA_Reg, 0);
	SET_BIT(ADCSRA_Reg, 1);
	SET_BIT(ADCSRA_Reg, 2);

	// ADC Data Rgith Adjustment
	SET_BIT(ADMUX_Reg, 5);
}

u8 ADC_Read(u8 channel) {
	// Select Voltage Reference
	// Select ADC Channel
	ADMUX_Reg = 0x40 | (channel & 0b00000111);

	// Start ADC Conversion
	SET_BIT(ADCSRA_Reg, 6);

	//Wait for the conversion
	while (!(ADCSRA_Reg & (1 << 4)))
		;

	SET_BIT(ADCSRA_Reg, 4);

	return ADC;

}

void LM35(void) {

	u8 Temp[6] = { 'T', 'e', 'm', 'p', ':' };

	u8 celsius = (ADC_Read(0) * 4.88);

	celsius = (celsius / 10.00);

	Gotoxy(1, 0);

	LCD_String(Temp);

	Gotoxy(1, 6);

	lcd_writenumber(celsius);

	_delay_ms(1000);

	LCD_vidSendCommand(0x01);

	if(celsius==30)
	{
		DIO_SetPinValue(PORTB,PIN0,1);
	}
/*
	if (celsius>25 && celsius<=30) {
		PORTB = 0xff;
		TCCR0 = 0b01101001;
		TIMSK = 0b00000010;
		OCR0 = 0;	//duty cycle
		USART_SendData('0');
	} else if (celsius>30 && celsius<=35) {
		PORTB = 0xff;
		TCCR0 = 0b01101001;
		TIMSK = 0b00000010;
		OCR0 = 64;
		USART_SendData('1');
	} else if (celsius>35 && celsius<=40) {
		PORTB = 0xff;
		TCCR0 = 0b01101001;
		TIMSK = 0b00000010;
		OCR0 = 128;
		USART_SendData('2');
	}
*/
}
