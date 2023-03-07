/*
 * LM35_PRG.c
 *
 *  Created on: Feb 16, 2023
 *      Author: hager
 */
#include "LM35_INT.h"
#include "LM35_CONFIG.h"
#include "LM35_PRIV.h"

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include <avr/interrupt.h>

#include<avr/io.h>



void M_ADC_void_Init(prescaler_t copy_prescaler, vref_t copy_vref)
{
	//step1: configer prescaler
		//step1: apply mask
	ADCSRA_REG &= ADC_PRESCALER_MASK;
		//step2: insert value
	ADCSRA_REG |= copy_prescaler;
	//step2: disable interrupt
	CLR_BIT(ADCSRA_REG,ADIE_BIT);
	//step3: configer right adjust
	CLR_BIT(ADMUX_REG,ADLAR_BIT);
	//step4: disable auto reg
	CLR_BIT(ADCSRA_REG, ADATE_BIT);
	//step5: choose vref
		//step1: apply mask
	ADMUX_REG &=ADC_VREF_MASK;
		//step2: insert value
	ADMUX_REG =copy_vref <<ADC_VREF_SHIFT;
	//step6: enable ADC
	SET_BIT(ADCSRA_REG,ADEN_BIT);
}
u16 M_ADC_void_adcRead(channel_t copy_channel)
{
	//step1:	config channel
		//step1: apply mask
	ADMUX_REG &= ADC_CHANNEL_MASK;
		//step2:	insert value
	ADMUX_REG |=copy_channel;
	// STEP 2:	for single conversion
	SET_BIT(ADCSRA_REG,ADSC_BIT);
	//step2:		polling wait until conversion is done
	//while(GET_BIT(ADCSRA_REG,ADIF_BIT) == 0);
	//SET_BIT(GET_BIT(ADCSRA_REG,ADIF_BIT);
	//step3:		return digital value
	return ADC_REG;
}
