/*
 * Smarthome.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: sameh
 */

#include "Smarthome.h"

void Smarthome_Init(void)
{
	DDRA=0x00;
	DDRB=0xff;
	DDRC=0xff;
	DDRD=0b11100000;
	Bluetooth_intial();
}
