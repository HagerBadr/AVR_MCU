/*
 * TIMER_int.h
 *
 *  Created on: Feb 8, 2023
 *      Author: aya_enan
 */

#ifndef TIMER_TIMER_INT_H_
#define TIMER_TIMER_INT_H_

#define TIMER0_OVF_INT_ID    0
#define TIMER0_CMP_INT_ID    1

void M_TIMER0_void_Init(void);  // set timer mode, set OC0 pin mode
void M_TIMER0_void_start(void); // set clock prescaler
void M_TIMER0_void_stop(void);  // No clock
void M_TIMER0_void_setTime(u32 copy_u32timeMS); // time in milli Second
void M_TIMER0_void_EnableInt(u8 copy_u8IntID);
void M_TIMER0_void_DisableInt(u8 copy_u8IntID);
void M_TIMER0_void_setCallBack(void (*ptrfn)(void),u8 copy_u8IntID);
void M_TIMER0_void_setFastPWM(u8 copy_u8Duty);
void M_TIMER0_void_setphaseCorrectPWM(u8 copy_u8Duty);
#endif /* TIMER_TIMER_INT_H_ */
