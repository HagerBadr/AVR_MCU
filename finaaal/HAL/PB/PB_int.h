/*
 * PB_int.h
 *
 *  Created on: Feb 2, 2023
 *      Author: hager
 */

#ifndef PB_PB_INT_H_
#define PB_PB_INT_H_

/*
 *  choose from :
 *  PB_ID  : 1, 2, ,3 ,4
 *  PB_port : PORTA_ID .... PORTAD_ID
 *  PB_pin  : PIN0_ID .... PIN7_ID
 *
 */

#define  NOT_PRESSED_ACTIVE_LOW  1
#define  PRESSED_ACTIVE_LOW      0

#define  NOT_PRESSED_ACTIVE_HIGH  0
#define  PRESSED_ACTIVE_HIGH      1

typedef enum { ACTIVE_LOW , ACTIVE_HIGH} Active_t;
typedef struct PushButton{
	u8 PB_ID;
	u8 PB_port;
	u8 PB_pin;
	Active_t PB_ActiveMode;
}PB_t;
void H_PB_void_init(const PB_t * ptr);

void H_PB_void_read (const PB_t * ptr,u8 *pvalue );
#endif /* PB_PB_INT_H_ */
