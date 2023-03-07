/*
 * PB_prg.c
 *
 *  Created on: Feb 2, 2023
 *      Author: hager
 */
#include <avr/delay.h>
#include "STD_TYPES.h"
#include "Dio_int.h"

#include "PB_priv.h"
#include "PB_config.h"
#include "PB_int.h"

void H_PB_void_init(const PB_t * ptr)
{
  // set direction
	M_Dio_void_setPinDir(ptr->PB_port,ptr->PB_pin, INPUT);
}


void H_PB_void_read (const PB_t * ptr,u8 *pvalue )
{
	u8  read;
   if(ptr->PB_ActiveMode == ACTIVE_LOW)
   {
	   *pvalue = NOT_PRESSED_ACTIVE_LOW;
       // get pin value
	   M_Dio_void_getPinValue(ptr->PB_port,ptr->PB_pin,&read);
	   if(read == PRESSED_ACTIVE_LOW)
	   {
		   // debouncing delay
		   _delay_ms(200);
		   //get 2nd reading to make sure it is not noise
		   M_Dio_void_getPinValue(ptr->PB_port,ptr->PB_pin,&read);

		   if(read == PRESSED_ACTIVE_LOW)
		   {
			   // to register a single press
			  while(read == PRESSED_ACTIVE_LOW)
			  {
				  M_Dio_void_getPinValue(ptr->PB_port,ptr->PB_pin,&read);
			  }// while (single press )
			  *pvalue = PRESSED_ACTIVE_LOW;

		   }// if 2nd reading is low

	   }// if 1st reading is low

   }// if Active_LOW
   else if(ptr->PB_ActiveMode == ACTIVE_HIGH)
   {
	   *pvalue = NOT_PRESSED_ACTIVE_HIGH;
   // get pin value
	   M_Dio_void_getPinValue(ptr->PB_port,ptr->PB_pin,&read);
	   if(read == PRESSED_ACTIVE_HIGH)
	   {
		   // debouncing delay
		   _delay_ms(200);
		   //get 2nd reading to make sure it is not noise
		   M_Dio_void_getPinValue(ptr->PB_port,ptr->PB_pin,&read);

		   if(read == PRESSED_ACTIVE_HIGH)
		   {
			   // to register a single press
			  while(read == PRESSED_ACTIVE_HIGH)
			  {
				  M_Dio_void_getPinValue(ptr->PB_port,ptr->PB_pin,&read);
			  }// while (single press )
			  *pvalue = PRESSED_ACTIVE_HIGH;

		   }// if 2nd reading is low

	   }// if 1st reading is low
   }// if Active_HIGH

}

