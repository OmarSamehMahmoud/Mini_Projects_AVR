#include"keypad.h"
#define keybad_port PORTB
#define keybad_port_direction DDRB

u8 keybad(void)
{
	u8 array[4][4]={{1,2,3,'*'},{4,5,6,'/'},{7,8,9,'-'},{'%',0,'+','='}} ;
	u8 i,j;

	keybad_port_direction=0x0f;
	keybad_port=0xff ;
	while(1)

	{
		for(i=0;i<4;i++)

		{
			//DIO_u8_SetPinValue(keybad_port_num,0,1) ;
			SETBIT(keybad_port,0);
			//DIO_u8_SetPinValue(keybad_port_num,1,1) ;
			SETBIT(keybad_port,1);
			//DIO_u8_SetPinValue(keybad_port_num,2,1) ;
			SETBIT(keybad_port,2);
			//DIO_u8_SetPinValue(keybad_port_num,3,1) ;
			SETBIT(keybad_port,3);
			//DIO_u8_SetPinValue(keybad_port_num,i,0) ;
			CLRBIT(keybad_port,i);



			for(j=0;j<4;j++)

			{
				if((GETBIT(PINB,(j+4)))==0)
				{
					_delay_ms(250);
					return array[i][j];
				}
			}
		}
	}
	return 0;
}
