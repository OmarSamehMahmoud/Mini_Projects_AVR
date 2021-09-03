/*
 * Motor_Control.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: sameh
 */

#include "Motor_Control.h"


void Motor_Both_Forward(void) {
	//Motor Right Forward
	DIO_SetPinDirection(PORTB, PIN0, HIGH);
	DIO_SetPinDirection(PORTB, PIN1, LOW);
	//Motor Left Forward
	DIO_SetPinDirection(PORTB, PIN2, HIGH);
	DIO_SetPinDirection(PORTB, PIN3, LOW);
}

void Motor_Both_Reverse(void) {
	//Motor Right Reverse
	DIO_SetPinDirection(PORTB, PIN0, LOW);
	DIO_SetPinDirection(PORTB, PIN1, HIGH);
	//Motor Left Reverse
	DIO_SetPinDirection(PORTB, PIN2, LOW);
	DIO_SetPinDirection(PORTB, PIN3, HIGH);
}

void Motor_Rotate_Left(void) {
	//Motor Right Forward
	DIO_SetPinDirection(PORTB, PIN0, HIGH);
	DIO_SetPinDirection(PORTB, PIN1, LOW);
	//Motor Left Reverse
	DIO_SetPinDirection(PORTB, PIN2, LOW);
	DIO_SetPinDirection(PORTB, PIN3, HIGH);
}

void Motor_Rotate_Right(void) {
	//Motor Right Reverse
	DIO_SetPinDirection(PORTB, PIN0, LOW);
	DIO_SetPinDirection(PORTB, PIN1, HIGH);
	//Motor Left Forward
	DIO_SetPinDirection(PORTB, PIN2, HIGH);
	DIO_SetPinDirection(PORTB, PIN3, LOW);
}
