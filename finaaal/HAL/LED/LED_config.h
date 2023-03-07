/*
 * LED_config.h
 *
 *  Created on: Jan 31, 2023
 *      Author: hager
 */

#ifndef LED_LED_CONFIG_H_
#define LED_LED_CONFIG_H_

/*please choose
 *   LED_PORT : PORTA_ID ... PORTD_ID
 *   LED_PIN  : PIN0_ID  ... PIN7_ID
 *   LED_DIRECTION: LED_FORWARD ,LED_REVERSE
 */


#define LED_RED_PORT          PORTC_ID
#define LED_RED_PIN           PIN0_ID
#define LED_RED_DIRECTION     LED_FORWARD

#define LED_GRN_PORT          PORTC_ID
#define LED_GRN_PIN           PIN1_ID
#define LED_GRN_DIRECTION     LED_FORWARD

#define LED_BLU_PORT           PORTC_ID
#define LED_BLU_PIN            PIN2_ID
#define LED_BLU_DIRECTION     LED_FORWARD


#endif /* LED_LED_CONFIG_H_ */
