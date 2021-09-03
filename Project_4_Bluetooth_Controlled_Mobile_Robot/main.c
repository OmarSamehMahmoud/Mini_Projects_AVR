/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: sameh
 */

#include "Smart_Car.h"


volatile u16 Sensor_Readings_Tx[3];

char res; //Received Data

int main(void) {

	Smart_Car_Init();

	while (1)

	{
		LCD_ADC();
		UART_SendReadings(Sensor_Readings_Tx);
		res = USART_ReceiveData(); //received command
		switch (res) {
		case '1':
			LCD_ADC();
			Motor_Both_Forward();
			break;
		case '2': //led intensity change
			LCD_ADC();
			Motor_Both_Reverse();
			break;
		case '3':
			LCD_ADC();
			Motor_Rotate_Left();
			break;
		case '4':
			LCD_ADC();
			Motor_Rotate_Right();
			break;
		}
	}

}
