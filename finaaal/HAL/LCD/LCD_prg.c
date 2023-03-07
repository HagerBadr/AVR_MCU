/*
 * LCD_prg.c
 *
 *  Created on: Feb 5, 2023
 *      Author: hager
 */
#include <avr/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Dio_int.h"


#include "LCD_priv.h"
#include "LCD_config.h"
#include "LCD_int.h"
void H_LCD_void_Init(void)
{

	// set direction Rs, EN
	M_Dio_void_setPinDir(LCD_RS_PORT, LCD_RS_PIN,OUPUT);
	M_Dio_void_setPinDir(LCD_EN_PORT,LCD_EN_PIN,OUPUT);
	//set direction D4 .. D7
	M_Dio_void_setPinDir(LCD_D7_PORT,LCD_D7_PIN,OUPUT);
	M_Dio_void_setPinDir(LCD_D6_PORT,LCD_D6_PIN,OUPUT);
	M_Dio_void_setPinDir(LCD_D5_PORT,LCD_D5_PIN,OUPUT);
	M_Dio_void_setPinDir(LCD_D4_PORT,LCD_D4_PIN,OUPUT);
#if(LCD_MODE ==  LCD_8BIT_MODE_)
	//set direction D3 .. D0
	M_Dio_void_setPinDir(LCD_D3_PORT,LCD_D3_PIN,OUPUT);
	M_Dio_void_setPinDir(LCD_D2_PORT,LCD_D2_PIN,OUPUT);
	M_Dio_void_setPinDir(LCD_D1_PORT,LCD_D1_PIN,OUPUT);
	M_Dio_void_setPinDir(LCD_D0_PORT,LCD_D0_PIN,OUPUT);
#endif


	// send Init Sequence
#if(LCD_MODE  == LCD_8BIT_MODE_)
	_delay_ms(35);
	H_LCD_void_sendCommand(LCD_8BIT_MODE_2LINES_5X7);
#elif(LCD_MODE ==  LCD_4BIT_MODE_)
	_delay_ms(35);
	// Rs = command = 0
	M_Dio_void_setPinValue(LCD_RS_PORT,LCD_RS_PIN,LOW);
	// EN = 0 disabled
	M_Dio_void_setPinValue(LCD_EN_PORT,LCD_EN_PIN,LOW);
	// prepare data
	M_Dio_void_setPinValue(LCD_D7_PORT,LCD_D7_PIN,0);
	M_Dio_void_setPinValue(LCD_D6_PORT,LCD_D6_PIN,0);
	M_Dio_void_setPinValue(LCD_D5_PORT,LCD_D5_PIN,1);
	M_Dio_void_setPinValue(LCD_D4_PORT,LCD_D4_PIN,0);
	//EN = 1
	M_Dio_void_setPinValue(LCD_EN_PORT,LCD_EN_PIN,HIGH);
	// delay 1 msec (to allow latching)
	_delay_ms(1);
	// EN = 0
	M_Dio_void_setPinValue(LCD_EN_PORT,LCD_EN_PIN,LOW);
	// delay to allow processing
	_delay_ms(5);
	H_LCD_void_sendCommand(LCD_4BIT_MODE_2LINES_5X7);
#else
  #error("wrong LCD Mode")
#endif
	// display ON/OFF
	H_LCD_void_sendCommand(LCD_DISPON_CURSON_BLINKOFF);
	// display Clear
	H_LCD_void_sendCommand(LCD_CLEAR_DISPALY);
	// Entry Mode Set
	H_LCD_void_sendCommand(LCD_ENTRY_MODE_SET);

}
void H_LCD_void_sendData(u8 copy_u8data)
{
  // step 1 : select RS to be in data mode (RS = 1)
   M_Dio_void_setPinValue(LCD_RS_PORT,LCD_RS_PIN,HIGH);
  // step 2 : write data
   H_LCD_void_writeNlatch(copy_u8data);
}
void H_LCD_void_sendCommand(u8 copy_u8Command)
{
	// step 1 : select RS to be in command mode (RS = 0)
	M_Dio_void_setPinValue(LCD_RS_PORT,LCD_RS_PIN,LOW);
	// step 2 : write command
	H_LCD_void_writeNlatch(copy_u8Command);

}
void H_LCD_void_sendString(const s8 * pstr)
{
   while(*pstr)
   {
	   H_LCD_void_sendData(*pstr);
	   pstr++;
   }
}
void H_LCD_void_clear(void)
{
	H_LCD_void_sendCommand(LCD_CLEAR_DISPALY);
}
void H_LCD_void_sendIntNum(s32 copy_s32Num)
{
   u8 Loc_Arr[10]= {0};
   s8 i = 0;
   if(copy_s32Num == 0)
   {
	   H_LCD_void_sendData('0');
	   return ;
   }
   else if(copy_s32Num < 0)//negative
   {
	   H_LCD_void_sendData('-');
	   copy_s32Num *= -1;
   }
   while(copy_s32Num != 0)
   {
	   Loc_Arr[i] = copy_s32Num % 10;
	   copy_s32Num = copy_s32Num /10 ;
	   i++;
   }
   i--;
   while(i>=0)
   {
	   H_LCD_void_sendData(Loc_Arr[i]+'0');
	   i--;
   }
}
void H_LCD_void_gotXY(u8 copy_u8Row,u8 copy_u8Col)
{
  if(copy_u8Row == 0 || copy_u8Row == 1) //check on row
  {
	  if(copy_u8Col >= 0 && copy_u8Col <= 15)// check on col
	  {
          switch(copy_u8Row)
          {
          case 0 :
        	  H_LCD_void_sendCommand(LCD_SET_R0C0_ + copy_u8Col);
        	  break;
          case 1 :
        	  H_LCD_void_sendCommand(LCD_SET_R1C0_ + copy_u8Col);
        	  break;
          }
	  }
  }
}
void H_LCD_void_creatCustomChar(const u8 * ArrPattern,u8 copy_u8charCode)
{

}
void H_LCD_void_displayCustomChar(u8 copy_u8charCode)
{

}
static void H_LCD_void_writeNlatch(u8 copy_u8Byte)
{
#if(LCD_MODE  == LCD_8BIT_MODE_)
	// EN = 0 disabled
	M_Dio_void_setPinValue(LCD_EN_PORT,LCD_EN_PIN,LOW);
  // step 1 : prepare Data (D7 .. D0)
	M_Dio_void_setPinValue(LCD_D0_PORT ,LCD_D0_PIN  , GET_BIT(copy_u8Byte,0));
	M_Dio_void_setPinValue(LCD_D1_PORT ,LCD_D1_PIN  , GET_BIT(copy_u8Byte,1));
	M_Dio_void_setPinValue(LCD_D2_PORT ,LCD_D2_PIN  , GET_BIT(copy_u8Byte,2));
	M_Dio_void_setPinValue(LCD_D3_PORT ,LCD_D3_PIN  , GET_BIT(copy_u8Byte,3));
	M_Dio_void_setPinValue(LCD_D4_PORT ,LCD_D4_PIN  , GET_BIT(copy_u8Byte,4));
	M_Dio_void_setPinValue(LCD_D5_PORT ,LCD_D5_PIN  , GET_BIT(copy_u8Byte,5));
	M_Dio_void_setPinValue(LCD_D6_PORT ,LCD_D6_PIN  , GET_BIT(copy_u8Byte,6));
	M_Dio_void_setPinValue(LCD_D7_PORT ,LCD_D7_PIN  , GET_BIT(copy_u8Byte,7));
  //step 2 : Activate Enable ,( E = 1)
 	M_Dio_void_setPinValue(LCD_EN_PORT, LCD_EN_PIN,HIGH);
  // step 3 : delay for 1 msec 	to allow latching
 	_delay_ms(1);
  // step 4 : deactivate Enable (E = 0)
 	M_Dio_void_setPinValue(LCD_EN_PORT, LCD_EN_PIN,LOW);
  // step 5 : delay to allow LCD to process
 	_delay_ms(5);
#elif(LCD_MODE ==  LCD_4BIT_MODE_)
 	// EN = 0 disabled
 	M_Dio_void_setPinValue(LCD_EN_PORT,LCD_EN_PIN,LOW);
 	// devide Byte to 2 (4 bits )
 	// step 1 :send high order bits on pins (D7 .. D4)
 	M_Dio_void_setPinValue(LCD_D4_PORT ,LCD_D4_PIN  , GET_BIT(copy_u8Byte,4));
 	M_Dio_void_setPinValue(LCD_D5_PORT ,LCD_D5_PIN  , GET_BIT(copy_u8Byte,5));
 	M_Dio_void_setPinValue(LCD_D6_PORT ,LCD_D6_PIN  , GET_BIT(copy_u8Byte,6));
 	M_Dio_void_setPinValue(LCD_D7_PORT ,LCD_D7_PIN  , GET_BIT(copy_u8Byte,7));
 	  //step 2 : Activate Enable ,( E = 1)
 	 	M_Dio_void_setPinValue(LCD_EN_PORT, LCD_EN_PIN,HIGH);
 	  // step 3 : delay for 1 msec 	to allow latching
 	 	_delay_ms(1);
 	  // step 4 : deactivate Enable (E = 0)
 	 	M_Dio_void_setPinValue(LCD_EN_PORT, LCD_EN_PIN,LOW);
 	  // step 5 : delay to allow LCD to process
 	 	_delay_ms(5);
 	 	// step 6 :send Low order bits on pins (D7 .. D4)
 	 	M_Dio_void_setPinValue(LCD_D4_PORT ,LCD_D4_PIN  , GET_BIT(copy_u8Byte,0));
 	 	M_Dio_void_setPinValue(LCD_D5_PORT ,LCD_D5_PIN  , GET_BIT(copy_u8Byte,1));
 	 	M_Dio_void_setPinValue(LCD_D6_PORT ,LCD_D6_PIN  , GET_BIT(copy_u8Byte,2));
 	 	M_Dio_void_setPinValue(LCD_D7_PORT ,LCD_D7_PIN  , GET_BIT(copy_u8Byte,3));
 	 	 //step 7 : Activate Enable ,( E = 1)
 	 	M_Dio_void_setPinValue(LCD_EN_PORT, LCD_EN_PIN,HIGH);
 	 	 // step 8 : delay for 1 msec 	to allow latching
 	 	_delay_ms(1);
 	 	 // step 9 : deactivate Enable (E = 0)
 	 	M_Dio_void_setPinValue(LCD_EN_PORT, LCD_EN_PIN,LOW);
 	 	 // step 10 : delay to allow LCD to process
 	 	_delay_ms(5);
#else
  #error("Wrong LCD mode")
#endif

}
