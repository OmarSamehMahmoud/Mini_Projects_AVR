
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "LCD_interface.h"
#include "ADC.h"

//#include "USART.h"
#include "DIO_int.h"

int main()
{

		DIO_SetPinDirection(PORTD,PIN0,INPUT);  //  D0: Rx ( input )
		DIO_SetPinDirection(PORTD,PIN1,OUTPUT); //  D1: Tx ( output )

		DIO_SetPortDirection(PORTB,HIGH);
		DIO_SetPortDirection(PORTC,HIGH);
		DIO_SetPortDirection(PORTA,LOW);

		ADC_Init();
		LCD_vidInit();
	//	USART_Init();
	
	while(1)
	{

		LM35();
	}
	return 0;
}

