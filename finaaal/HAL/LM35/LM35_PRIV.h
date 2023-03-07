/*
 * LM35_PRIV.h
 *
 *  Created on: Feb 16, 2023
 *      Author: hager
 */

#ifndef HAL_LM35_LM35_PRIV_H_
#define HAL_LM35_LM35_PRIV_H_

#define ADMUX_REG		(*((volatile u8*)0x27))	//SELECT CHANNEL , LEFT Adjust ,Vref
#define ADCSRA_REG		(*((volatile u8*)0x26))		//SELECT Prescaler ,interrupt enable
#define ADC_REG			(*((volatile u16*)0x24))
#define SFIOR_REG		(*((volatile u8*)0x50))

//ADMUX_REG
//REFS1 REFS0 ADLAR		-->MASKING
#define ADLAR_BIT		5	//LEFT ADJUST
#define ADC_CHANNEL_MASK	0b11100000	//0xe3
#define ADC_VREF_MASK		0b00111111	//0x3F

//ADCSRA_REG
#define ADC_PRESCALER_MASK	0b11111000		//0xf8
#define ADIE_BIT		3		//INTERRUPT ENABLE
#define ADIF_BIT		4		//INTERRUPT FLAG
#define ADATE_BIT		5		//AUTO TRIGGER
#define ADSC_BIT		6		//start conversion
#define ADEN_BIT		7		//ADC enable

#define ADC_VREF_SHIFT	6

#endif /* HAL_LM35_LM35_PRIV_H_ */
