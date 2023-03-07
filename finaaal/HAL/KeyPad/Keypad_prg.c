/*
 * Keypad_prg.c
 *
 *  Created on: Feb 2, 2023
 *      Author: hager
 */
#include <avr/delay.h>
#include "STD_TYPES.h"
#include "Dio_int.h"

#include "Keypad_priv.h"
#include "Keypad_config.h"
#include "Keypad_int.h"
void H_KEYPAD_void_init(void)
{
    // set all rows direction as output
	M_Dio_void_setPinDir(KEYPAD_R0_PORT,KEYPAD_R0_PIN,OUPUT);
	M_Dio_void_setPinDir(KEYPAD_R1_PORT,KEYPAD_R1_PIN,OUPUT);
	M_Dio_void_setPinDir(KEYPAD_R2_PORT,KEYPAD_R2_PIN,OUPUT);
	M_Dio_void_setPinDir(KEYPAD_R3_PORT,KEYPAD_R3_PIN,OUPUT);
    // set all coloumns direction as inputs
    M_Dio_void_setPinDir(KEYPAD_C0_PORT,KEYPAD_C0_PIN, INPUT);
    M_Dio_void_setPinDir(KEYPAD_C1_PORT,KEYPAD_C1_PIN, INPUT);
    M_Dio_void_setPinDir(KEYPAD_C2_PORT,KEYPAD_C2_PIN, INPUT);
    M_Dio_void_setPinDir(KEYPAD_C3_PORT,KEYPAD_C3_PIN, INPUT);
    // deactivate rows (HIGH)
    M_Dio_void_setPinValue(KEYPAD_R0_PORT,KEYPAD_R0_PIN,HIGH);
    M_Dio_void_setPinValue(KEYPAD_R1_PORT,KEYPAD_R1_PIN,HIGH);
    M_Dio_void_setPinValue(KEYPAD_R2_PORT,KEYPAD_R2_PIN,HIGH);
    M_Dio_void_setPinValue(KEYPAD_R3_PORT,KEYPAD_R3_PIN,HIGH);
#if(KEYPAD_TYPE == KEYPAD_TYPE_KIT)
    M_Dio_void_setPinValue(KEYPAD_C0_PORT,KEYPAD_C0_PIN, HIGH);
	M_Dio_void_setPinValue(KEYPAD_C1_PORT,KEYPAD_C1_PIN, HIGH);
	M_Dio_void_setPinValue(KEYPAD_C2_PORT,KEYPAD_C2_PIN, HIGH);
	M_Dio_void_setPinValue(KEYPAD_C3_PORT,KEYPAD_C3_PIN, HIGH);
#endif
}
u8   H_KEYPAD_void_getPressesKey(void)
{
	 u8 Loc_key = NO_PRESSED_KEY;
	 u8 Loc_row_indx;
	 u8 Loc_col_indx;
	 u8 Loc_KEYPAD_ARR [4][4]= KEYPAD_ARR_MAP;
	 u8 read;

     for(Loc_row_indx = KEYPAD_R0_PIN ; Loc_row_indx<= KEYPAD_R3_PIN  ; Loc_row_indx++)
     {
    	 // Activate row (LOW)
    	 M_Dio_void_setPinValue(KEYPAD_ROWS_PORT,Loc_row_indx,LOW);
    	 for(Loc_col_indx= KEYPAD_C0_PIN ;Loc_col_indx<= KEYPAD_C3_PIN ; Loc_col_indx++)
    	 {
    		 // get 1st reading
             M_Dio_void_getPinValue(KEYPAD_COLS_PORT,Loc_col_indx, &read);
             if(read == ACTIVE_LOW_PRESSED)
             {
            	 // debouncing delay
            	 _delay_ms(100);
            	 //get 2nd reading
            	 M_Dio_void_getPinValue(KEYPAD_COLS_PORT,Loc_col_indx, &read);
            	 if(read == ACTIVE_LOW_PRESSED)
            	 {
            		 // single press only
            		 while(read == ACTIVE_LOW_PRESSED)
            		 {
            			 M_Dio_void_getPinValue(KEYPAD_COLS_PORT,Loc_col_indx, &read);
            		 }//while
            		 Loc_key = Loc_KEYPAD_ARR[Loc_row_indx - KEYPAD_R0_PIN][Loc_col_indx - KEYPAD_C0_PIN];
            		 return Loc_key;
            	 }// if 2nd reading

             }// if 1st reading
    	 }// for
    	 // Deactivate row (HIGH )
    	 M_Dio_void_setPinValue(KEYPAD_ROWS_PORT,Loc_row_indx,HIGH);
     }
     return Loc_key;
}
