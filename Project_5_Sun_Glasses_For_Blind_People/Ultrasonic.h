#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#define F_CPU 8000000UL

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "LCD_interface.h"
#include <avr/io.h>
#include <avr/interrupt.h>

#include "DIO_int.h"
#include <util/delay.h>

void Ultrasonic_init(void);
void Check_All_UltraSonic(void);

#endif /* ULTRASONIC_H_ */
