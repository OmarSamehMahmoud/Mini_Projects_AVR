/*
 * 	Traffic.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: sameh
 */

#ifndef TRAFFIC_H_
#define TRAFFIC_H_

extern void lcd_init(void);
extern void lcd_writecommand(u8 command);
extern void lcd_writedata(u8 data);
extern void seven(u8 segarr[],u8 i,u8 seg[],u8 y);


#endif /* TRAFFIC_H_ */
