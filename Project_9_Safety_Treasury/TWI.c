
#include<avr/io.h>
#include"Types.h"
#include"Bit_Math.h"
#include"TWI.h"
void TWI_init(void)
{
	TWBR=0x02;//value for clk freq eq in page 175
	TWSR=0x00;//value for clk freq eq in page 175
	TWAR=0b10101010;//the first 7 bits is address and the last bit is for enable Broad cast or no as a slave lw 7d hyb3tli 7aga
	TWCR = (1 << TWEN) | (1 << TWEA);
	//Control regester to enable I2C
	//to enable ACK flag "slave"
}
void TWI_StartCond(void)
{
	//CLR flag of interrupt by force it by one
	//start condition
	//3shn akon ana l b take control on bus"Control over the bus"*/
	TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
	while(!GETBIT(TWCR,TWINT));//wait util flag rised up"l flag lma b2rah bynzl"

}
void TWI_StopCond(void)
{
	//CLR flag of interrupt m3 an msh m7tageet nndfo
	//stop condition
	//3shn akon ana l b take control on bus"Control over the bus"*/
/* lan l flag mbytrf3sh f l stop*/
	TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);
}
void TWI_Write(u8 u8data)
{
	TWDR=u8data;//move data to buffer
	//CLR flag which rised after tx byte
	TWCR = (1 << TWINT) | (1 << TWEN);
	while(!GETBIT(TWCR,TWINT));
}
u8 TWI_Read(void)
{
	SETBIT(TWCR,TWINT);//CLr flag
	SETBIT(TWCR,TWEN);//take control
	SETBIT(TWCR,TWEA);//ack enable
    while(!GETBIT(TWCR,TWINT));
    return TWDR;
}
u8 TWI_Read_NACK(void)
{
	//CLr flag
	//take control
	TWCR = (1 << TWINT)| (1 << TWEN);
    while(!GETBIT(TWCR,TWINT));
    return TWDR;
}
u8 TWI_GetStatues(void)
{
	//page 191 in data sheet
	u8 Statues;
	Statues= (TWSR & (0xf8));//Mask for needed 5 bits
	return Statues;
}

