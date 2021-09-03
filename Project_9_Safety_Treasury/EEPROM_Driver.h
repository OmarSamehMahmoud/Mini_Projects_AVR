
#ifndef EEPROM_DRIVER_H_
#define EEPROM_DRIVER_H_

void EEPROM_init(void);
void EEPROM_Write_Data(u8 u8address,u8 u8data);
u8 EEPROM_Read_Data(u8 u8data);


#endif /* EEPROM_DRIVER_H_ */
