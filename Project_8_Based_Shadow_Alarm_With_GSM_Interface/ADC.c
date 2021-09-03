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

void LDR(void) {
	u8 Status[12] = "Person:";
	u8 Name_Test_English[5] = "here";
	u8 Namei_Test_English[9] = "Not here";

	int val = ADC_Read(0);

	int ADCe = (val * 5) / 250;

	if (ADCe > 3) {
		LCD_String_xy(1, 0, Status);
		LCD_String_xy(2, 3, Namei_Test_English);
		_delay_ms(1000);
		DIO_SetPinValue(PORTB,PIN4,LOW);
		_delay_ms(1000);
		LCD_vidSendCommand(0x01);
	} else {
		DIO_SetPinValue(PORTB,PIN4,HIGH);
		LCD_String_xy(1, 0, Status);
		LCD_String_xy(2, 3, Name_Test_English);
		//sendSMS();
		LCD_vidSendCommand(0x01);
	}
}
