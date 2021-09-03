/*
 * ADC.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: sameh
 */

#include "ADC.h"


extern void ADC_Init(void)
{
	// Enable ADC On AVR
		set_bit(ADCSRA_Reg,7);

	// Select Conversion Speed
		set_bit(ADCSRA_Reg,0);
		set_bit(ADCSRA_Reg,1);
		set_bit(ADCSRA_Reg,2);


	// ADC Data Rgith Adjustment
		set_bit(ADMUX_Reg,5);
}


u8 ADC_Read (u8 channel)
{
	// Select Voltage Reference
	// Select ADC Channel
	ADMUX_Reg = 0x40 | (channel & 0b00000111);

	// Start ADC Conversion
	set_bit(ADCSRA_Reg,6);

	//Wait for the conversion
	while(!(ADCSRA_Reg & (1<<4)));


	set_bit(ADCSRA_Reg,4);

	return ADC;

}


void LDR(void)
{

	int val = ADC_Read(0);

	int ADCE = (val * 5)/250;

			if ( ADCE > 3 )
			{
				set_bit(PORTC,0);
			}
			else
			{
				clr_bit(PORTC,0);
			}
}
