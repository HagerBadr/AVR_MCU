/*
 * WTD_prg.c
 *
 *  Created on: Feb 15, 2023
 *      Author: hager
 */
#include "WTD_int.h"
#include "WTD_priv.h"
#include "WTD_config.h"

#include"STD_TYPES.h"

#include"BIT_MATH.h"
void M_WDT_void_enable(void)
{
	SET_BIT(WDTCR_REG,WDE_BIT);
}
void M_WDT_void_disable(void)
{
	/* Write logical one to WDTOE and WDE */
	WDTCR_REG |= (1<<WDTOE_BIT) | (1<<WDE_BIT);
	/* Turn off WDT */
	WDTCR_REG = 0x00;
}
void M_WDT_void_sleep(u8 copy_timeout)
{
	if(copy_timeout >= WDT_TIMEOUT_16_3_MS || copy_timeout<=WDT_TIMEOUT_2_1_S)
	//step1: apply mask
	WDTCR_REG &= WDT_PRESCALER_MASK;
	//step2: set value
	WDTCR_REG |=copy_timeout;

}
void M_WDT_void_refresh(void)
{
	asm("WDR");
}
