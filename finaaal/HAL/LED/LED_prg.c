/*
 * LED_prg.c
 *
 *  Created on: Jan 31, 2023
 *      Author: hager
 */
#include "STD_TYPES.h"
#include "Dio_int.h"
#include "LED_priv.h"
#include "LED_config.h"
#include "LED_int.h"

void H_Led_void_ledInit(u8 LedID)
{
  switch(LedID)
  {
  case RED_LED :
	 M_Dio_void_setPinDir(LED_RED_PORT,LED_RED_PIN,OUPUT);
	  break;
  case GRN_LED:
	  M_Dio_void_setPinDir(LED_GRN_PORT,LED_GRN_PIN,OUPUT);
	  break;
  case BLU_LED :
	  M_Dio_void_setPinDir(LED_BLU_PORT,LED_BLU_PIN,OUPUT);
	  break;
  }
}
void H_Led_void_setON(u8 LedID)
{
	 switch(LedID)
	  {
	  case RED_LED :
#if(LED_RED_DIRECTION  ==   LED_FORWARD)
		  M_Dio_void_setPinValue(LED_RED_PORT,LED_RED_PIN,HIGH);
#elif(LED_RED_DIRECTION  ==   LED_REVERSE)
		  M_Dio_void_setPinValue(LED_RED_PORT,LED_RED_PIN,LOW);
#endif
		  break;
	  case GRN_LED:
#if(LED_GRN_DIRECTION  ==   LED_FORWARD)
		  M_Dio_void_setPinValue(LED_GRN_PORT,LED_GRN_PIN,HIGH);
#elif(LED_GRN_DIRECTION  ==   LED_REVERSE)
		  M_Dio_void_setPinValue(LED_GRN_PORT,LED_GRN_PIN,LOW);
#endif
		  break;
	  case BLU_LED :
#if(LED_BLU_DIRECTION  ==   LED_FORWARD)
		  M_Dio_void_setPinValue(LED_BLU_PORT,LED_BLU_PIN,HIGH);
#elif(LED_BLU_DIRECTION  ==   LED_REVERSE)
		  M_Dio_void_setPinValue(LED_BLU_PORT,LED_BLU_PIN,LOW);
#endif
		  break;
	  }
}
void H_Led_void_setOFF(u8 LedID)
{
	 switch(LedID)
		  {
		  case RED_LED :
#if(LED_RED_DIRECTION  ==   LED_FORWARD)
		  M_Dio_void_setPinValue(LED_RED_PORT,LED_RED_PIN,LOW);
#elif(LED_RED_DIRECTION  ==   LED_REVERSE)
		  M_Dio_void_setPinValue(LED_RED_PORT,LED_RED_PIN,HIGH);
#endif
			  break;
		  case GRN_LED:
#if(LED_GRN_DIRECTION  ==   LED_FORWARD)
		  M_Dio_void_setPinValue(LED_GRN_PORT,LED_GRN_PIN,LOW);
#elif(LED_GRN_DIRECTION  ==   LED_REVERSE)
		  M_Dio_void_setPinValue(LED_GRN_PORT,LED_GRN_PIN,HIGH);
#endif
			  break;
		  case BLU_LED :
#if(LED_BLU_DIRECTION  ==   LED_FORWARD)
		  M_Dio_void_setPinValue(LED_BLU_PORT,LED_BLU_PIN,LOW);
#elif(LED_BLU_DIRECTION  ==   LED_REVERSE)
		  M_Dio_void_setPinValue(LED_BLU_PORT,LED_BLU_PIN,HIGH);
#endif
			  break;
		  }

}
void H_Led_void_toggle(u8 LedID)
{
	 switch(LedID)
		  {
		  case RED_LED :
			  M_Dio_void_TogPinValue(LED_RED_PORT,LED_RED_PIN);
			  break;
		  case GRN_LED:
			  M_Dio_void_TogPinValue(LED_GRN_PORT,LED_GRN_PIN);
			  break;
		  case BLU_LED :
			  M_Dio_void_TogPinValue(LED_BLU_PORT,LED_BLU_PIN);
			  break;
		  }

}
