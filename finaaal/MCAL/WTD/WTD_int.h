/*
 * WTD_int.h
 *
 *  Created on: Feb 15, 2023
 *      Author: hager
 */

#ifndef MCAL_WTD_WTD_INT_H_
#define MCAL_WTD_WTD_INT_H_

#include "STD_TYPES.h"

#define WDT_TIMEOUT_16_3_MS		0		//000
#define WDT_TIMEOUT_32_5_MS		1		//001
#define WDT_TIMEOUT_65_MS		2		//010
#define WDT_TIMEOUT_0_13_S		3
#define WDT_TIMEOUT_0_26_S		4
#define WDT_TIMEOUT_0_52_S		5
#define WDT_TIMEOUT_1_S			6
#define WDT_TIMEOUT_2_1_S		7


void M_WDT_void_enable(void);		//TURN ON WTD
void M_WDT_void_disable(void);		//TURN OFF
void M_WDT_void_sleep(u8 copy_timeout);		//TIMEOUT
void M_WDT_void_refresh(void);

#endif /* MCAL_WTD_WTD_INT_H_ */
