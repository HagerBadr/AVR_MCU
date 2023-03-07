/*
 * main.c
 *
 *  Created on: Feb 19, 2023
 *      Author: hager
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"TIMER1_int.h"
#include"GIE_int.h"
#include"Keypad_int.h"
#include"LCD_int.h"
#include"Ultrasonic_int.h"
#include <util/delay.h>

#if 0
void main()
{
	H_KEYPAD_void_init();
	H_LCD_void_Init();
	_delay_ms(50);
	u8 key_press;
	H_LCD_void_sendString("Enter password: ");
	_delay_ms(3000);

	while(1)
	{

		H_LCD_void_clear();
		key_press = H_KEYPAD_void_getPressesKey();

		 H_LCD_void_sendIntNum(key_press);

	}
}
#endif
#if 0
void main()
{
	u16 KP_Value;
		// init LCD
		H_LCD_void_Init();
		// init KeyPad
		H_KEYPAD_void_init();


		while(1)
		{
			KP_Value = H_KEYPAD_void_getPressesKey();

			if(KP_Value != NO_PRESSED_KEY)
			{
				H_LCD_void_sendData(KP_Value);
			}

		}
}
#endif
#if 1
void main()
{
	u16 Distance;
	// enable GIE
	M_GIE_void_enable();
	// init LCD
	H_LCD_void_Init();
	// Ultrasonic init
	H_ULTRASONIC_void_init();
	while(1)
	{
		Distance = H_ULTRASONIC_void_getDistance();

		// display Duty cycle
	//	H_LCD_void_sendString("Distance= ");
		H_LCD_void_sendIntNum(Distance);
		//H_LCD_void_sendString(" cm");
		_delay_ms(1000);
		H_LCD_void_clear();
	}
}
#endif
