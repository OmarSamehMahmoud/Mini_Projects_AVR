/*
 * USART.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: sameh
 */

#ifndef USART_H_
#define USART_H_


#include "Types.h"
#include  "Bit_Math.h"
#include <string.h>

#define 	UDR_Reg		 		   *((volatile u8*)0x2C)
#define 	UCSRA_Reg			   *((volatile u8*)0x2B)
#define 	UCSRB_Reg		       *((volatile u8*)0x2A)
#define 	UBRRL_Reg		       *((volatile u8*)0x29)
#define 	UBRRH_Reg		       *((volatile u8*)0x40)
#define 	UCSRC_Reg		       *((volatile u8*)0x40)

void USART_Init(void);
void USART_SendData(u8 Data);
u8   USART_ReceiveData(void);
void senddata(char string[16]);

#endif /* USART_H_ */
