/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: sameh
 */

#include "Flame_Sensor.h"

int main(void) {

	DIO_SetPortDirection(PORTC, HIGH);
	DIO_SetPinDirection(PORTA, PIN0, HIGH);
	DIO_SetPinDirection(PORTA, PIN1, HIGH);
	DIO_SetPinDirection(PORTA, PIN2, HIGH);

	DIO_SetPinDirection(PORTD, PIN0, INPUT);  //  D0: Rx ( input )
	DIO_SetPinDirection(PORTD, PIN1, OUTPUT); //  D1: Tx ( output )

	DIO_SetPinDirection(PORTD, PIN2, INPUT);  //  D2: Flame Sensor ( input )

	DIO_SetPinDirection(PORTB, PIN0, OUTPUT); // PORTC | Pin 0 : Buzzer for flame

	DIO_SetPinValue(PORTB, PIN0, LOW);  // PORTC | Pin 0 : Buzzer Off

	USART_Init(); // Init of USART Function call
	LCD_vidInit();

	while (1) {

		Fire_Alarm();

	}
}
