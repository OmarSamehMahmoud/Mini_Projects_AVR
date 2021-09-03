

#ifndef TWI_H_
#define TWI_H_

void TWI_init(void);
void TWI_StartCond(void);
void TWI_StopCond(void);
void TWI_Write(u8 u8data);
u8 TWI_Read_NACK(void);
u8 TWI_Read(void);
u8 TWI_GetStatues(void);

#endif /* TWI_H_ */
