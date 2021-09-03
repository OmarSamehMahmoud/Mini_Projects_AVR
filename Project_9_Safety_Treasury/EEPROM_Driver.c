
#include<avr/io.h>
#include"Types.h"
#include"Bit_Math.h"
#include"TWI.h"
#include<util/delay.h>

void EEPROM_init(void)
{
	TWI_init();
}

void EEPROM_Write_Data(u8 u8address,u8 u8data)
{
	TWI_StartCond();
	TWI_Write(0b10100000);
	TWI_Write(u8address);
	TWI_Write(u8data);
	TWI_StopCond();

}


u8 EEPROM_Read_Data(u8 u8address)
{
	u8 x;
	TWI_StartCond();
	TWI_Write(0b10100000);
	TWI_Write(u8address);
	TWI_StartCond();
	TWI_Write(0b10100001);
	x=TWI_Read_NACK();
	TWI_StopCond();
	return x;
}


