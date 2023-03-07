/*
 * TIMER_prg.c
 *
 *  Created on: Feb 8, 2023
 *      Author: aya_enan
 */
#include <stdlib.h>
#include <avr/interrupt.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMER_priv.h"
#include "TIMER_config.h"
#include "TIMER_int.h"

static u32 NumberOFOverflows = 0;
static u32 NumberOFRemainingTicks = 0;
static void (*Arr_CallBack[2])(void)={NULL, NULL};
void M_TIMER0_void_Init(void)  // set timer mode, set OC0 pin mode
{
  // step 1 : config Timer Mode
#if(TIMER0_MODE == TIMER0_NORMAL_MODE )
	 CLR_BIT(TCCR0_REG,WGM00_BIT);
	 CLR_BIT(TCCR0_REG,WGM01_BIT);
// step 2 : choose OC0  pin mode
     #if(TIMER0_OC0_MODE >= TIMER0_OC0_MODE_DISSCONECTED && TIMER0_OC0_MODE <=TIMER0_OC0_MODE_SET )

	 //STep 1 : apply mask
	TCCR0_REG &= TIMER0_OC0_MASK ;
	// step 2 : insert value
	TCCR0_REG |=(TIMER0_OC0_MODE << TIMER0_OC0_SHIFT);
    #else
      #error ("wrong OC0 Mode")
    #endif
#elif(TIMER0_MODE ==  TIMER0_CTC_MODE)
	 CLR_BIT(TCCR0_REG,WGM00_BIT);
	 SET_BIT(TCCR0_REG,WGM01_BIT);
	 // step 2 : choose OC0  pin mode
	 #if(TIMER0_OC0_MODE >= TIMER0_OC0_MODE_DISSCONECTED && TIMER0_OC0_MODE <=TIMER0_OC0_MODE_SET )

	 //STep 1 : apply mask
	 TCCR0_REG &= TIMER0_OC0_MASK ;
	 // step 2 : insert value
	 TCCR0_REG |=(TIMER0_OC0_MODE << TIMER0_OC0_SHIFT);
	  #else
	     #error ("wrong OC0 Mode")
	  #endif
#elif(TIMER0_MODE == TIMER0_FAST_PWM_MODE)
	 SET_BIT(TCCR0_REG,WGM00_BIT);
	 SET_BIT(TCCR0_REG,WGM01_BIT);
   #if(TIMER0_OC0_MODE  == TIMER0_PWM_NON_INVERTED || TIMER0_OC0_MODE ==  TIMER0_PWM_INVERTED)
   	 // step 1 : apply mask
	 TCCR0_REG &= TIMER0_OC0_MASK ;
	 // step 2 : insert value
	 TCCR0_REG |= TIMER0_OC0_MODE ;
   #else
       #error ("wrong Timer Mode")
   #endif
#elif(TIMER0_MODE == TIMER0_PHASECORRECT_MODE)
	 SET_BIT(TCCR0_REG,WGM00_BIT);
	 CLR_BIT(TCCR0_REG,WGM01_BIT);
	 // step2 : config OC0 pin Mode
  #if(TIMER0_OC0_MODE  == TIMER0_PWM_NON_INVERTED || TIMER0_OC0_MODE ==  TIMER0_PWM_INVERTED)
  	 // step 1 : apply mask
	 TCCR0_REG &= TIMER0_OC0_MASK ;
	 // step 2 : insert value
	 TCCR0_REG |= TIMER0_OC0_MODE ;
  #else
      #error ("wrong Timer Mode")
  #endif
#else
 #error ("wrong Timer Mode")
#endif
 }
void M_TIMER0_void_start(void) // set clock prescaler
{
#if(TIMER0_PRESCALER >= TIMER0_PRESCALER_NO_CLK && TIMER0_PRESCALER <= TIMER0_PRESCALER_EXTCLK_RAIS_EDGE)
 // step 1 : apply Mask
	TCCR0_REG &= TIMER0_PRESCALER_MASK ;
 // step 2 : insert value
	TCCR0_REG |= TIMER0_PRESCALER ;
#else
#error("Wong Prescler")
#endif
}
void M_TIMER0_void_stop(void)  // No clock
{
	// step 1 : apply Mask
		TCCR0_REG &= TIMER0_PRESCALER_MASK ;
	 // step 2 : insert value
	//	TCCR0_REG |= TIMER0_PRESCALER_NO_CLK ;
}
void M_TIMER0_void_setTime(u32 copy_u32timeMS) // time in milli Second
{
	u32 Loc_prescalerArr[]={1,8,64,256,1024};
    f32 Loc_TickTime  = (f32)Loc_prescalerArr[TIMER0_PRESCALER-1] / FCPU;
    u32 NoOFDesiredTicks = (copy_u32timeMS * 1000)/ Loc_TickTime;
#if(TIMER0_MODE  == TIMER0_NORMAL_MODE)
    NumberOFOverflows = NoOFDesiredTicks / 256 ;
    NumberOFRemainingTicks = NoOFDesiredTicks % 256;
    if( NumberOFRemainingTicks != 0)
    {
    	TCNT0_REG  = 256  - NumberOFRemainingTicks;
    	NumberOFOverflows++;
    }
#elif(TIMER0_MODE == TIMER0_CTC_MODE)


#endif
}
void M_TIMER0_void_EnableInt(u8 copy_u8IntID)
{
	// method 1
	/*switch(copy_u8IntID)
	{
	case TIMER0_OVF_INT_ID:
		SET_BIT(TIMSK_REG,TOIE0_BIT);
		break;
	case TIMER0_CMP_INT_ID:
		SET_BIT(TIMSK_REG,OCIE0_BIT);
		break;
	}*/
	// Method 2
	SET_BIT(TIMSK_REG,copy_u8IntID);
}
void M_TIMER0_void_DisableInt(u8 copy_u8IntID)
{
	// method 1
		/*switch(copy_u8IntID)
		{
		case TIMER0_OVF_INT_ID:
			CLR_BIT(TIMSK_REG,TOIE0_BIT);
			break;
		case TIMER0_CMP_INT_ID:
			CLR_BIT(TIMSK_REG,OCIE0_BIT);
			break;
		}*/
	// Method 2
	CLR_BIT(TIMSK_REG,copy_u8IntID);
}
void M_TIMER0_void_setCallBack(void (*ptrfn)(void),u8 copy_u8IntID)
{
	// Method 1
   /* switch(copy_u8IntID)
    {
    case TIMER0_OVF_INT_ID:
    	Arr_CallBack[0]= ptrfn;
    	break;
    case TIMER0_CMP_INT_ID:
    	Arr_CallBack[1]= ptrfn;
    	break;
    }*/
    // Method 2
    Arr_CallBack[copy_u8IntID] = ptrfn;
}
void M_TIMER0_void_setFastPWM(u8 copy_u8Duty)
{
#if(TIMER0_MODE  == TIMER0_FAST_PWM_MODE)
	#if(TIMER0_OC0_MODE  == TIMER0_PWM_NON_INVERTED)
	   OCR0_REG  =  abs (((copy_u8Duty * 256)/100 ) -1 );
	#elif(TIMER0_OC0_MODE ==  TIMER0_PWM_INVERTED)
	   OCR0_REG  = 255 - ((copy_u8Duty * 256)/100 );
	#else
       #error("wrong OC0 Mode")
	#endif
#endif
}
void M_TIMER0_void_setphaseCorrectPWM(u8 copy_u8Duty)
{
#if(TIMER0_MODE  == TIMER0_PHASECORRECT_MODE)
	#if(TIMER0_OC0_MODE  == TIMER0_PWM_NON_INVERTED)
	OCR0_REG = ((copy_u8Duty * 255)/100);
	#elif(TIMER0_OC0_MODE ==  TIMER0_PWM_INVERTED)
	OCR0_REG = 255 - ((copy_u8Duty * 255)/100);
	#else
       #error("wrong OC0 Mode")
	#endif
#endif
}
ISR(TIMER0_OVF_vect	)
{
	static u32 Loc_OVFCaounter = 0;
	Loc_OVFCaounter++;
	if(Loc_OVFCaounter == NumberOFOverflows)
	{
		// reload TCNT with preload value
		TCNT0_REG  = 256  - NumberOFRemainingTicks;
		// Couter = 0
		Loc_OVFCaounter = 0;
		// take Action
		if(Arr_CallBack[TIMER0_OVF_INT_ID] != NULL)
			Arr_CallBack[TIMER0_OVF_INT_ID]();
	}


}
ISR(TIMER0_COMP_vect)
{
	if(Arr_CallBack[TIMER0_CMP_INT_ID] != NULL)
		Arr_CallBack[TIMER0_CMP_INT_ID]();
}
