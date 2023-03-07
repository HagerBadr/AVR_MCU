/*
 * WTD_priv.h
 *
 *  Created on: Feb 15, 2023
 *      Author: hager
 */

#ifndef MCAL_WTD_WTD_PRIV_H_
#define MCAL_WTD_WTD_PRIV_H_

//REGISTERS
#define WDTCR_REG		(*((volatile u8 *)0x41))

//BITS
#define WDE_BIT			3		//WTD ENABLE
#define	WDTOE_BIT		4		//WTD TURN OFF (DISABLE)

// WDT PRESCALER
#define WDT_PRESCALER_MASK		0b11111000		//0XF8


#endif /* MCAL_WTD_WTD_PRIV_H_ */
