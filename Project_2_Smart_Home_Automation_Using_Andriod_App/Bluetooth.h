/*
 * Project.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: sameh
 */
#ifndef BLUETOOTH_H_
#define BLUETOOTH_H_

#include <avr/io.h>

char Bluetooth_rx_data (void);
void Bluetooth_tx_data (char data);
void Bluetooth_intial (void);

#endif /* BLUETOOTH_H_ */
