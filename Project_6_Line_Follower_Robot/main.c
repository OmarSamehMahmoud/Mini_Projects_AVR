/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: sameh
 */

#include "Line_Follower.h"

int main(void) {
	//Initialization For Line Follower Robot
	DIO_SetPinDirection(PORTB, PIN0, HIGH); 	// B0 : OUTPUT : IN1 for Motor 1
	DIO_SetPinDirection(PORTB, PIN1, HIGH);	// B1 : OUTPUT : IN2 for Motor 1
	DIO_SetPinDirection(PORTB, PIN2, HIGH);	// B2 : OUTPUT : IN3 for Motor 2
	DIO_SetPinDirection(PORTB, PIN3, HIGH);	// B3 : OUTPUT : IN4 for Motor 2

	DIO_SetPinDirection(PORTA, PIN0, LOW);	// A0 : Input : IR_Sensor
	DIO_SetPinDirection(PORTA, PIN1, LOW);	// A1 : Input : IR_Sensor

	while (1) {
		//Function of Line Follower which will be stuck on infinite loop
		Line_Follower();
	}

}
