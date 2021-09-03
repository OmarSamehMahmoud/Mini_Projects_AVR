/*
 * Smart_Car.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: sameh
 */

#include "Smart_Car.h"

void Smart_Car_Init(void)
{

	DIO_SetPinDirection(PORTB,PIN4,HIGH);
	DIO_SetPinDirection(PORTB,PIN5,HIGH);
	DIO_SetPinDirection(PORTB,PIN6,HIGH);

	DIO_SetPinDirection(PORTA,PIN0,LOW);
	DIO_SetPinDirection(PORTA,PIN1,LOW);
	DIO_SetPinDirection(PORTA,PIN2,LOW);

	DIO_SetPinDirection(PORTD,PIN0,LOW);
	DIO_SetPinDirection(PORTD,PIN1,HIGH);
	DIO_SetPinDirection(PORTD,PIN4,HIGH);
	DIO_SetPinDirection(PORTD,PIN5,HIGH);


	DIO_SetPortDirection(PORTC,HIGH);

	DIO_SetPinDirection(PORTD,PIN5,HIGH);
	DIO_SetPinDirection(PORTD,PIN6,HIGH);
	DIO_SetPinDirection(PORTD,PIN7,HIGH);

	USART_Init();


	LCD_vidInit();

	ADC_Init();

}
