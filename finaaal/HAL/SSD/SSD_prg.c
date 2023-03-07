/*
 * SSD_prg.c
 *
 *  Created on: Feb 1, 2023
 *      Author: hager
 */
#include <avr/delay.h>
#include "STD_TYPES.h"
#include "Dio_int.h"

#include "SSD_priv.h"
#include "SSD_config.h"
#include "SSD_int.h"
// u8 arr[]={0x3F, };
void H_SSD_void_init(void)
{
	// set all SSD pins as output
	M_Dio_void_setPinDir(SSD_LED_A_PORT,SSD_LED_A_PIN,OUPUT );
	M_Dio_void_setPinDir(SSD_LED_B_PORT,SSD_LED_B_PIN,OUPUT );
	M_Dio_void_setPinDir(SSD_LED_C_PORT,SSD_LED_C_PIN,OUPUT );
	M_Dio_void_setPinDir(SSD_LED_D_PORT,SSD_LED_D_PIN,OUPUT );
	M_Dio_void_setPinDir(SSD_LED_E_PORT,SSD_LED_E_PIN,OUPUT );
	M_Dio_void_setPinDir(SSD_LED_F_PORT,SSD_LED_F_PIN,OUPUT );
	M_Dio_void_setPinDir(SSD_LED_G_PORT,SSD_LED_G_PIN,OUPUT );
	M_Dio_void_setPinDir(SSD_LED_DOT_PORT,SSD_LED_DOT_PIN,OUPUT );

	// set Enable pins as output
	M_Dio_void_setPinDir(SSD_DIG_1_EN_PORT,SSD_DIG_1_EN_PIN,OUPUT );
	M_Dio_void_setPinDir(SSD_DIG_2_EN_PORT,SSD_DIG_2_EN_PIN,OUPUT );
}
void H_SSD_void_DisplayNumber(u8 number)
{
	if(number > 99 )
	{
		return ;
	}
	u32 i ;
	u8 units = number % 10;
	u8 tens = number / 10 ;
	for(i= 0;i< SSD_DISPLAY_TIME ;i++)
	{
		switch(units)
			{
			case 0:
				M_Dio_void_setPinValue(SSD_LED_A_PORT , SSD_LED_A_PIN , HIGH);
				M_Dio_void_setPinValue(SSD_LED_B_PORT , SSD_LED_B_PIN , HIGH);
				M_Dio_void_setPinValue(SSD_LED_C_PORT , SSD_LED_C_PIN , HIGH);
				M_Dio_void_setPinValue(SSD_LED_D_PORT , SSD_LED_D_PIN , HIGH);
				M_Dio_void_setPinValue(SSD_LED_E_PORT , SSD_LED_E_PIN , HIGH);
				M_Dio_void_setPinValue(SSD_LED_F_PORT , SSD_LED_F_PIN , HIGH);
				M_Dio_void_setPinValue(SSD_LED_G_PORT , SSD_LED_G_PIN , LOW);
				break;
			case 1:
				M_Dio_void_setPinValue(SSD_LED_A_PORT , SSD_LED_A_PIN , LOW);
				M_Dio_void_setPinValue(SSD_LED_B_PORT , SSD_LED_B_PIN , HIGH);
				M_Dio_void_setPinValue(SSD_LED_C_PORT , SSD_LED_C_PIN , HIGH);
				M_Dio_void_setPinValue(SSD_LED_D_PORT , SSD_LED_D_PIN , LOW);
				M_Dio_void_setPinValue(SSD_LED_E_PORT , SSD_LED_E_PIN , LOW);
				M_Dio_void_setPinValue(SSD_LED_F_PORT , SSD_LED_F_PIN , LOW);
				M_Dio_void_setPinValue(SSD_LED_G_PORT , SSD_LED_G_PIN , LOW);
				break;
			case 2 :
				M_Dio_void_setPinValue(SSD_LED_A_PORT , SSD_LED_A_PIN , HIGH);
				M_Dio_void_setPinValue(SSD_LED_B_PORT , SSD_LED_B_PIN , HIGH);
				M_Dio_void_setPinValue(SSD_LED_C_PORT , SSD_LED_C_PIN , LOW);
				M_Dio_void_setPinValue(SSD_LED_D_PORT , SSD_LED_D_PIN , HIGH);
				M_Dio_void_setPinValue(SSD_LED_E_PORT , SSD_LED_E_PIN , HIGH);
				M_Dio_void_setPinValue(SSD_LED_F_PORT , SSD_LED_F_PIN , LOW);
				M_Dio_void_setPinValue(SSD_LED_G_PORT , SSD_LED_G_PIN , HIGH);
				break;
			case 3:
				M_Dio_void_setPinValue(SSD_LED_A_PORT , SSD_LED_A_PIN , HIGH);
				M_Dio_void_setPinValue(SSD_LED_B_PORT , SSD_LED_B_PIN , HIGH);
				M_Dio_void_setPinValue(SSD_LED_C_PORT , SSD_LED_C_PIN , HIGH);
				M_Dio_void_setPinValue(SSD_LED_D_PORT , SSD_LED_D_PIN , HIGH);
				M_Dio_void_setPinValue(SSD_LED_E_PORT , SSD_LED_E_PIN , LOW);
				M_Dio_void_setPinValue(SSD_LED_F_PORT , SSD_LED_F_PIN , LOW);
				M_Dio_void_setPinValue(SSD_LED_G_PORT , SSD_LED_G_PIN , HIGH);
				break;
			case 4:
				M_Dio_void_setPinValue(SSD_LED_A_PORT , SSD_LED_A_PIN , LOW);
				M_Dio_void_setPinValue(SSD_LED_B_PORT , SSD_LED_B_PIN , HIGH);
				M_Dio_void_setPinValue(SSD_LED_C_PORT , SSD_LED_C_PIN , HIGH);
				M_Dio_void_setPinValue(SSD_LED_D_PORT , SSD_LED_D_PIN , LOW);
				M_Dio_void_setPinValue(SSD_LED_E_PORT , SSD_LED_E_PIN , LOW);
				M_Dio_void_setPinValue(SSD_LED_F_PORT , SSD_LED_F_PIN , HIGH);
				M_Dio_void_setPinValue(SSD_LED_G_PORT , SSD_LED_G_PIN , HIGH);
				break;
			case 5:
				M_Dio_void_setPinValue(SSD_LED_A_PORT , SSD_LED_A_PIN , HIGH);
				M_Dio_void_setPinValue(SSD_LED_B_PORT , SSD_LED_B_PIN , LOW);
				M_Dio_void_setPinValue(SSD_LED_C_PORT , SSD_LED_C_PIN , HIGH);
				M_Dio_void_setPinValue(SSD_LED_D_PORT , SSD_LED_D_PIN , HIGH);
				M_Dio_void_setPinValue(SSD_LED_E_PORT , SSD_LED_E_PIN , LOW);
				M_Dio_void_setPinValue(SSD_LED_F_PORT , SSD_LED_F_PIN , HIGH);
				M_Dio_void_setPinValue(SSD_LED_G_PORT , SSD_LED_G_PIN , HIGH);
				break;
			case 6:
				M_Dio_void_setPinValue(SSD_LED_A_PORT , SSD_LED_A_PIN , HIGH);
				M_Dio_void_setPinValue(SSD_LED_B_PORT , SSD_LED_B_PIN , LOW);
				M_Dio_void_setPinValue(SSD_LED_C_PORT , SSD_LED_C_PIN , HIGH);
				M_Dio_void_setPinValue(SSD_LED_D_PORT , SSD_LED_D_PIN , HIGH);
				M_Dio_void_setPinValue(SSD_LED_E_PORT , SSD_LED_E_PIN , HIGH);
				M_Dio_void_setPinValue(SSD_LED_F_PORT , SSD_LED_F_PIN , HIGH);
				M_Dio_void_setPinValue(SSD_LED_G_PORT , SSD_LED_G_PIN , HIGH);
				break;
			case 7:
				M_Dio_void_setPinValue(SSD_LED_A_PORT , SSD_LED_A_PIN , HIGH);
				M_Dio_void_setPinValue(SSD_LED_B_PORT , SSD_LED_B_PIN , HIGH);
				M_Dio_void_setPinValue(SSD_LED_C_PORT , SSD_LED_C_PIN , HIGH);
				M_Dio_void_setPinValue(SSD_LED_D_PORT , SSD_LED_D_PIN , LOW);
				M_Dio_void_setPinValue(SSD_LED_E_PORT , SSD_LED_E_PIN , LOW);
				M_Dio_void_setPinValue(SSD_LED_F_PORT , SSD_LED_F_PIN , LOW);
				M_Dio_void_setPinValue(SSD_LED_G_PORT , SSD_LED_G_PIN , LOW);
				break;
			case 8:
				M_Dio_void_setPinValue(SSD_LED_A_PORT , SSD_LED_A_PIN , HIGH);
				M_Dio_void_setPinValue(SSD_LED_B_PORT , SSD_LED_B_PIN , HIGH);
				M_Dio_void_setPinValue(SSD_LED_C_PORT , SSD_LED_C_PIN , HIGH);
				M_Dio_void_setPinValue(SSD_LED_D_PORT , SSD_LED_D_PIN , HIGH);
				M_Dio_void_setPinValue(SSD_LED_E_PORT , SSD_LED_E_PIN , HIGH);
				M_Dio_void_setPinValue(SSD_LED_F_PORT , SSD_LED_F_PIN , HIGH);
				M_Dio_void_setPinValue(SSD_LED_G_PORT , SSD_LED_G_PIN , HIGH);
				break;
			case 9 :
				M_Dio_void_setPinValue(SSD_LED_A_PORT , SSD_LED_A_PIN , HIGH);
				M_Dio_void_setPinValue(SSD_LED_B_PORT , SSD_LED_B_PIN , HIGH);
				M_Dio_void_setPinValue(SSD_LED_C_PORT , SSD_LED_C_PIN , HIGH);
				M_Dio_void_setPinValue(SSD_LED_D_PORT , SSD_LED_D_PIN , HIGH);
				M_Dio_void_setPinValue(SSD_LED_E_PORT , SSD_LED_E_PIN , LOW);
				M_Dio_void_setPinValue(SSD_LED_F_PORT , SSD_LED_F_PIN , HIGH);
				M_Dio_void_setPinValue(SSD_LED_G_PORT , SSD_LED_G_PIN , HIGH);
				break;
			}
			// enable Dig 1 (units)
			M_Dio_void_setPinValue(SSD_DIG_1_EN_PORT , SSD_DIG_1_EN_PIN , HIGH);
			// disable Dig 2 (tens)
			M_Dio_void_setPinValue(SSD_DIG_2_EN_PORT , SSD_DIG_2_EN_PIN , LOW);
			// delay
			_delay_ms(1);
			// disable Dig 1(units )
			M_Dio_void_setPinValue(SSD_DIG_1_EN_PORT , SSD_DIG_1_EN_PIN , LOW);

			switch(tens)
				{
				case 0:
					M_Dio_void_setPinValue(SSD_LED_A_PORT , SSD_LED_A_PIN , HIGH);
					M_Dio_void_setPinValue(SSD_LED_B_PORT , SSD_LED_B_PIN , HIGH);
					M_Dio_void_setPinValue(SSD_LED_C_PORT , SSD_LED_C_PIN , HIGH);
					M_Dio_void_setPinValue(SSD_LED_D_PORT , SSD_LED_D_PIN , HIGH);
					M_Dio_void_setPinValue(SSD_LED_E_PORT , SSD_LED_E_PIN , HIGH);
					M_Dio_void_setPinValue(SSD_LED_F_PORT , SSD_LED_F_PIN , HIGH);
					M_Dio_void_setPinValue(SSD_LED_G_PORT , SSD_LED_G_PIN , LOW);
					break;
				case 1:
					M_Dio_void_setPinValue(SSD_LED_A_PORT , SSD_LED_A_PIN , LOW);
					M_Dio_void_setPinValue(SSD_LED_B_PORT , SSD_LED_B_PIN , HIGH);
					M_Dio_void_setPinValue(SSD_LED_C_PORT , SSD_LED_C_PIN , HIGH);
					M_Dio_void_setPinValue(SSD_LED_D_PORT , SSD_LED_D_PIN , LOW);
					M_Dio_void_setPinValue(SSD_LED_E_PORT , SSD_LED_E_PIN , LOW);
					M_Dio_void_setPinValue(SSD_LED_F_PORT , SSD_LED_F_PIN , LOW);
					M_Dio_void_setPinValue(SSD_LED_G_PORT , SSD_LED_G_PIN , LOW);
					break;
				case 2 :
					M_Dio_void_setPinValue(SSD_LED_A_PORT , SSD_LED_A_PIN , HIGH);
					M_Dio_void_setPinValue(SSD_LED_B_PORT , SSD_LED_B_PIN , HIGH);
					M_Dio_void_setPinValue(SSD_LED_C_PORT , SSD_LED_C_PIN , LOW);
					M_Dio_void_setPinValue(SSD_LED_D_PORT , SSD_LED_D_PIN , HIGH);
					M_Dio_void_setPinValue(SSD_LED_E_PORT , SSD_LED_E_PIN , HIGH);
					M_Dio_void_setPinValue(SSD_LED_F_PORT , SSD_LED_F_PIN , LOW);
					M_Dio_void_setPinValue(SSD_LED_G_PORT , SSD_LED_G_PIN , HIGH);
					break;
				case 3:
					M_Dio_void_setPinValue(SSD_LED_A_PORT , SSD_LED_A_PIN , HIGH);
					M_Dio_void_setPinValue(SSD_LED_B_PORT , SSD_LED_B_PIN , HIGH);
					M_Dio_void_setPinValue(SSD_LED_C_PORT , SSD_LED_C_PIN , HIGH);
					M_Dio_void_setPinValue(SSD_LED_D_PORT , SSD_LED_D_PIN , HIGH);
					M_Dio_void_setPinValue(SSD_LED_E_PORT , SSD_LED_E_PIN , LOW);
					M_Dio_void_setPinValue(SSD_LED_F_PORT , SSD_LED_F_PIN , LOW);
					M_Dio_void_setPinValue(SSD_LED_G_PORT , SSD_LED_G_PIN , HIGH);
					break;
				case 4:
					M_Dio_void_setPinValue(SSD_LED_A_PORT , SSD_LED_A_PIN , LOW);
					M_Dio_void_setPinValue(SSD_LED_B_PORT , SSD_LED_B_PIN , HIGH);
					M_Dio_void_setPinValue(SSD_LED_C_PORT , SSD_LED_C_PIN , HIGH);
					M_Dio_void_setPinValue(SSD_LED_D_PORT , SSD_LED_D_PIN , LOW);
					M_Dio_void_setPinValue(SSD_LED_E_PORT , SSD_LED_E_PIN , LOW);
					M_Dio_void_setPinValue(SSD_LED_F_PORT , SSD_LED_F_PIN , HIGH);
					M_Dio_void_setPinValue(SSD_LED_G_PORT , SSD_LED_G_PIN , HIGH);
					break;
				case 5:
					M_Dio_void_setPinValue(SSD_LED_A_PORT , SSD_LED_A_PIN , HIGH);
					M_Dio_void_setPinValue(SSD_LED_B_PORT , SSD_LED_B_PIN , LOW);
					M_Dio_void_setPinValue(SSD_LED_C_PORT , SSD_LED_C_PIN , HIGH);
					M_Dio_void_setPinValue(SSD_LED_D_PORT , SSD_LED_D_PIN , HIGH);
					M_Dio_void_setPinValue(SSD_LED_E_PORT , SSD_LED_E_PIN , LOW);
					M_Dio_void_setPinValue(SSD_LED_F_PORT , SSD_LED_F_PIN , HIGH);
					M_Dio_void_setPinValue(SSD_LED_G_PORT , SSD_LED_G_PIN , HIGH);
					break;
				case 6:
					M_Dio_void_setPinValue(SSD_LED_A_PORT , SSD_LED_A_PIN , HIGH);
					M_Dio_void_setPinValue(SSD_LED_B_PORT , SSD_LED_B_PIN , LOW);
					M_Dio_void_setPinValue(SSD_LED_C_PORT , SSD_LED_C_PIN , HIGH);
					M_Dio_void_setPinValue(SSD_LED_D_PORT , SSD_LED_D_PIN , HIGH);
					M_Dio_void_setPinValue(SSD_LED_E_PORT , SSD_LED_E_PIN , HIGH);
					M_Dio_void_setPinValue(SSD_LED_F_PORT , SSD_LED_F_PIN , HIGH);
					M_Dio_void_setPinValue(SSD_LED_G_PORT , SSD_LED_G_PIN , HIGH);
					break;
				case 7:
					M_Dio_void_setPinValue(SSD_LED_A_PORT , SSD_LED_A_PIN , HIGH);
					M_Dio_void_setPinValue(SSD_LED_B_PORT , SSD_LED_B_PIN , HIGH);
					M_Dio_void_setPinValue(SSD_LED_C_PORT , SSD_LED_C_PIN , HIGH);
					M_Dio_void_setPinValue(SSD_LED_D_PORT , SSD_LED_D_PIN , LOW);
					M_Dio_void_setPinValue(SSD_LED_E_PORT , SSD_LED_E_PIN , LOW);
					M_Dio_void_setPinValue(SSD_LED_F_PORT , SSD_LED_F_PIN , LOW);
					M_Dio_void_setPinValue(SSD_LED_G_PORT , SSD_LED_G_PIN , LOW);
					break;
				case 8:
					M_Dio_void_setPinValue(SSD_LED_A_PORT , SSD_LED_A_PIN , HIGH);
					M_Dio_void_setPinValue(SSD_LED_B_PORT , SSD_LED_B_PIN , HIGH);
					M_Dio_void_setPinValue(SSD_LED_C_PORT , SSD_LED_C_PIN , HIGH);
					M_Dio_void_setPinValue(SSD_LED_D_PORT , SSD_LED_D_PIN , HIGH);
					M_Dio_void_setPinValue(SSD_LED_E_PORT , SSD_LED_E_PIN , HIGH);
					M_Dio_void_setPinValue(SSD_LED_F_PORT , SSD_LED_F_PIN , HIGH);
					M_Dio_void_setPinValue(SSD_LED_G_PORT , SSD_LED_G_PIN , HIGH);
					break;
				case 9 :
					M_Dio_void_setPinValue(SSD_LED_A_PORT , SSD_LED_A_PIN , HIGH);
					M_Dio_void_setPinValue(SSD_LED_B_PORT , SSD_LED_B_PIN , HIGH);
					M_Dio_void_setPinValue(SSD_LED_C_PORT , SSD_LED_C_PIN , HIGH);
					M_Dio_void_setPinValue(SSD_LED_D_PORT , SSD_LED_D_PIN , HIGH);
					M_Dio_void_setPinValue(SSD_LED_E_PORT , SSD_LED_E_PIN , LOW);
					M_Dio_void_setPinValue(SSD_LED_F_PORT , SSD_LED_F_PIN , HIGH);
					M_Dio_void_setPinValue(SSD_LED_G_PORT , SSD_LED_G_PIN , HIGH);
					break;
				}
			    // enable Dig 2 (tens)
				M_Dio_void_setPinValue(SSD_DIG_2_EN_PORT , SSD_DIG_2_EN_PIN , HIGH);
					// delay
				_delay_ms(1);
				// disable Dig 1(units )
				M_Dio_void_setPinValue(SSD_DIG_1_EN_PORT , SSD_DIG_1_EN_PIN , LOW);
				//disable Dig 2 (tens )
				M_Dio_void_setPinValue(SSD_DIG_2_EN_PORT , SSD_DIG_2_EN_PIN , LOW);
	}

}
