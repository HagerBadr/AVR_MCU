/*
 * Ultrasonic_int.h
 *
 *  Created on: Feb 19, 2023
 *      Author: hager
 */
#include	<math.h>
#include	"../../LIB/STD_TYPES.h"
#include	"../../MCAL/DIO/DIO_int.h"
#include	"../../MCAL/TIMER1/TIMER1_int.h"
#include 	<util/delay.h>

static u16 Reading1 	= 0;
static u16 Reading2 	= 0;
static u8  stateCounter = 0;
void ICU_HW(void);
void	H_ULTRASONIC_void_init			(void)
{
	// set direction for trigg to be OUTPUT
	M_DIO_void_setPinDir(PORTC_ID,PIN5_ID, OUPUT);
	// set ICP1 pin as INPUT
	M_DIO_void_setPinDir(PORTD_ID,PIN6_ID, INPUT);
	// ICU init
	M_TIMER1_ICU_void_init();
	// Call back
	M_TIMER1_ICU_void_setCallBack(ICU_HW);
	// Enable ICU int
	M_TIMER1_ICU_void_IntEnable();

	M_TIMER1_void_init(); // timer1 start
}
u16		H_ULTRASONIC_void_getDistance	(void)
{
	u16 Local_u16ON_Ticks;
	f32 Local_f32ON_Time;
	u16 Local_u16Distance;
	M_TIMER1_void_start();
	// trigg the trigger pin
	M_DIO_void_setPinVal(PORTC_ID,PIN5_ID, HIGH);
	_delay_us(10);
	M_DIO_void_setPinVal(PORTC_ID,PIN5_ID, LOW);
	while(stateCounter <= 1); // busy waiting
	stateCounter = 0;

	Local_u16ON_Ticks 		= Reading2 - Reading1;
	Local_f32ON_Time		= ((float)256 / F_CPU) * Local_u16ON_Ticks;
	Local_u16Distance		= ceil((Local_f32ON_Time / 2) * 34300);  // in cm

	return Local_u16Distance;
}
void ICU_HW(void)
{
	switch(stateCounter)
	{
	case 0:
		// take reading 1
		Reading1 = M_TIMER1_ICU_u16_takeReading();
		// change trigger to be falling edge
		M_TIMER1_ICU_void_setTrigg(TIMER1_ICU_FALLING_TRIGG);
		break;
	case 1:
		// take reading 2
		Reading2 = M_TIMER1_ICU_u16_takeReading();
		// stop ICU interrupt
		//M_TIMER1_ICU_void_IntDisable();
		M_TIMER1_ICU_void_setTrigg(TIMER1_ICU_RISING_TRIGG);
		M_TIMER1_void_stop();
		break;
	default:
		/* do nothing*/
		break;
	}
	stateCounter++;
}
