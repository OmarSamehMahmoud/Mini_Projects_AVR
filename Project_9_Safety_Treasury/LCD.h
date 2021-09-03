/*
 * 	Traffic.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: sameh
 */

#ifndef LCD_H_
#define LCD_H_

#include <avr\io.h>
#include <util\delay.h>
#include"Types.h"
#include "Bit_Math.h"

extern void LCD_Init(void);
extern void LCD_WriteCommand(u8 command);
extern void LCD_WriteData(u8 data);



#endif /* LCD_H_ */
