/*
 * GSM_Sender.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: sameh
 */

#include "GSM_Sender.h"

void sendSMS()
{
     senddata("AT+CMGD=1");
     USART_SendData(13);
     USART_SendData(10);
     _delay_ms(1000);

     senddata("AT+CMGF=1");
     USART_SendData(13);
     USART_SendData(10);
     _delay_ms(1000);

     senddata("AT+CMGW=");
     USART_SendData(34);
     senddata("+01281884580");  //My Mobile number
     USART_SendData(34);
     USART_SendData(13);
     USART_SendData(10);
     _delay_ms(1000);

     senddata("Alert: Thief here");
     USART_SendData(13);
     USART_SendData(10);
     _delay_ms(1000);

     USART_SendData(26); //Ctrl+Z
     _delay_ms(1000);
     _delay_ms(1000);

     senddata("AT+CMSS=1");
     USART_SendData(13);
     USART_SendData(10);
     _delay_ms(1000);

}
