/*
 * Dio_prg.c
 *
 *  Created on: Jan 30, 2023
 *      Author: aya_enan
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "Dio_priv.h"
#include "Dio_config.h"
#include "Dio_int.h"


void M_Dio_void_setPinDir(u8 port,u8 pin,u8 dir )
{
  switch (port)
  {
  case PORTA_ID:
	  switch(dir)
	  {
	  case  INPUT:
		  CLR_BIT(DDRA_REG,pin);
		  break;
	  case  OUPUT:
		  SET_BIT(DDRA_REG,pin);
		  break;

	  }
	  break;
  case PORTB_ID:
	  switch(dir)
	  	  {
	  	  case  INPUT:
	  		  CLR_BIT(DDRB_REG,pin);
	  		  break;
	  	  case  OUPUT:
	  		  SET_BIT(DDRB_REG,pin);
	  		  break;

	  	  }
 	  break;
  case PORTC_ID:
	  switch(dir)
	  	  {
	  	  case  INPUT:
	  		  CLR_BIT(DDRC_REG,pin);
	  		  break;
	  	  case  OUPUT:
	  		  SET_BIT(DDRC_REG,pin);
	  		  break;

	  	  }
 	  break;
  case PORTD_ID:
	  switch(dir)
	  	  {
	  	  case  INPUT:
	  		  CLR_BIT(DDRD_REG,pin);
	  		  break;
	  	  case  OUPUT:
	  		  SET_BIT(DDRD_REG,pin);
	  		  break;

	  	  }
 	  break;
  }


}
void M_Dio_void_setPinValue(u8 port,u8 pin,u8 value)
{
	// this function used to set output
 // I will Access PORT register
	// according to value (high , low) -->(SET_BIT ,CLR_BIT )
	switch(port)
	{
	case PORTA_ID:
		switch(value)
		{
		case HIGH:
			SET_BIT(PORTA_REG,pin);
			break;
		case LOW:
			CLR_BIT(PORTA_REG,pin);
			break;
		}
		break;
	case PORTB_ID:
		switch(value)
		{
		case HIGH:
			SET_BIT(PORTB_REG,pin);
			break;
		case LOW:
			CLR_BIT(PORTB_REG,pin);
			break;
		}
			break;
	case PORTC_ID:
		switch(value)
		{
		case HIGH:
			SET_BIT(PORTC_REG,pin);
			break;
		case LOW:
			CLR_BIT(PORTC_REG,pin);
			break;
		}
			break;
	case PORTD_ID:
		switch(value)
		{
		case HIGH:
			SET_BIT(PORTD_REG,pin);
			break;
		case LOW:
			CLR_BIT(PORTD_REG,pin);
			break;
		}
			break;
	}
}
void M_Dio_void_getPinValue(u8 port,u8 pin, u8* pvalue)
{
	// this function used to get input
	// I will Access PIN register
	// return (high, low)
	// GET_BIT
	switch(port)
		{
		case PORTA_ID:
			*pvalue = GET_BIT(PINA_REG,pin);
			break;
		case PORTB_ID:
			*pvalue = GET_BIT(PINB_REG,pin);
				break;
		case PORTC_ID:
			*pvalue = GET_BIT(PINC_REG,pin);
				break;
		case PORTD_ID:
			*pvalue = GET_BIT(PIND_REG,pin);
				break;
		}
}
void M_Dio_void_TogPinValue(u8 port,u8 pin )
{
    // TOG_BIT
	switch(port)
	{
	 case PORTA_ID:
		 TOG_BIT(PORTA_REG,pin);
		 break;
	 case PORTB_ID:
		 TOG_BIT(PORTB_REG,pin);
	 		 break;
	 case PORTC_ID:
		 TOG_BIT(PORTC_REG,pin);
	 		 break;
	 case PORTD_ID:
		 TOG_BIT(PORTA_REG,pin);
	 		 break;
	}

}
