
#include "Smarthome.h"

char res; //Received Data
char o,m,f;



int main (void)
{
	ADC_Init();
	Smarthome_Init();
	while (1)
	{
		LDR();
		_delay_ms(50);
		res=Bluetooth_rx_data(); //received command
		switch (res)
		{
		case '1':
			Toogle_Led();
			break;
		case '2': //led intensity change
			Led_25_Intensity();
			break;
		case '3':
			Led_50_Intensity();
			break;
		case '4':
			Led_100_Intensity();
			break;
		case '5': //door dc motor
			Door_Open();
			break;
		case '6':
			Door_Close();
			break;
		case '7':  //servo window
			Window_Init();
			break;
		}
	}
}



