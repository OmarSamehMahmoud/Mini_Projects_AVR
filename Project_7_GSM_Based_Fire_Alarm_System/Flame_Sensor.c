/*
 * Flame_Sensor.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: sameh
 */

#include "Flame_Sensor.h"

u8 Flame[10] = "Attention";
u8 Flamei[14] = "Fire Detected";
void Fire_Alarm(void) {
	if (DIO_GetPinValue(PORTD, PIN2) == 1) {
		LCD_String_xy(1, 3, Flame);
		LCD_String_xy(2, 1, Flamei);
		DIO_SetPinValue(PORTB, PIN0, HIGH);  // Buzzer ON
		sendSMS();
		LCD_vidSendCommand(0x01);

	} else {
		DIO_SetPinValue(PORTB, PIN0, LOW);  // Buzzer OFF

	}
}
