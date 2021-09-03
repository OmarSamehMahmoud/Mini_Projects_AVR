/*
 * Bluetooth.c

 *
 *  Created on: ??þ/??þ/????
 *      Author: sameh
 */

#include "Bluetooth.h"

void Bluetooth_intial (void)
{
	UCSRB=0b00011000;
	UCSRC=0b10000110;
	UBRRL=51; //boudrate of bluetooth module required
}

void Bluetooth_tx_data (char data)
{
	while ((UCSRA& (1<<UDRE))==0);
	UDR=data;
}
char Bluetooth_rx_data (void)
{
	char x;
	while ((UCSRA & (1<<RXC))==0);
	x=UDR;
	return x;
}

