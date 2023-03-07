/*
 * LED_int.h
 *
 *  Created on: Jan 31, 2023
 *      Author: hager
 */

#ifndef LED_LED_INT_H_
#define LED_LED_INT_H_



#define RED_LED  0
#define GRN_LED  1
#define BLU_LED  2

void H_Led_void_ledInit(u8 LedID);
void H_Led_void_setON(u8 LedID);
void H_Led_void_setOFF(u8 LedID);
void H_Led_void_toggle(u8 LedID);

#endif /* LED_LED_INT_H_ */
