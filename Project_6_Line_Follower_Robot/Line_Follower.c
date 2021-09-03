/*
 * Line_Follower.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: sameh
 */

#include "Line_Follower.h"

//This Function Will Control our robot direction
void Line_Follower(void)
{
	//if input of IR Sensor 1 is LOW & input of IR Sensor 2 is LOW then The Car moves Forward.
	if((DIO_GetPinValue(PORTA,PIN0)==LOW)&&(DIO_GetPinValue(PORTA,PIN1)==LOW))
	{
		Motor_Both_Forward();
	}
	//if input of IR Sensor 1 is LOW & input of IR Sensor 2 is HIGH then The Car moves Right.
	if((DIO_GetPinValue(PORTA,PIN0)==LOW)&&(DIO_GetPinValue(PORTA,PIN1)==HIGH))
	{
		Motor_Rotate_Right();
	}
	//if input of IR Sensor 1 is HIGH & input of IR Sensor 2 is LOW then The Car moves Left.
	if((DIO_GetPinValue(PORTA,PIN0)==HIGH)&&(DIO_GetPinValue(PORTA,PIN1)==LOW))
	{
		Motor_Rotate_Left();
	}
	//if input of IR Sensor 1 is HIGH & input of IR Sensor 2 is HIGH then The Car will Stop.
	if((DIO_GetPinValue(PORTA,PIN0)==HIGH)&&(DIO_GetPinValue(PORTA,PIN1)==HIGH))
	{
		Motor_Both_Stop();
	}
}

