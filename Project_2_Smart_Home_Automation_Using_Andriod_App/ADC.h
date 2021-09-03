/*
 * ADC.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: sameh
 */

#ifndef ADC_H_
#define ADC_H_

#define ADMUX_Reg 	*((volatile u8*)0x27) 	// ADC Multiplexer Register
#define ADCSRA_Reg 	*((volatile u8*)0x26) 	// ADC Control And Status Register
#define ADCH_Reg 	*((volatile u8*)0x25) 		// ADC High Register
#define ADCL_Reg 	*((volatile u8*)0x24) 		// ADC Low Register
#define ADCW_Reg	*((volatile u8*)0x04)

#define degree_sysmbol 0xdf


#include "utilss.h"
#include "Types.h"
#include <avr/io.h>
#include <util/delay.h>

extern void ADC_Init (void); // ADC Initialization And Enable
u8 ADC_Read (u8 channel); // Read From The ADC Channel

void LDR(void);

#endif /* ADC_H_ */
