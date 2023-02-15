/*
 * ece453.c
 *
 *  Created on: Jan 18, 2022
 *      Author: Joe Krachey
 */

#include <leds.h>

/** Initialize the LED on the ECE453 MCU Dev Board
 *
 * @param
 *
 */
void leds_init(void)
{
	/* Initialize LED401.  You will need to examine the HAL API to determine how to
	 * initialize an IO pin an output
	 */

    cy_rslt_t rslt;

    // Initialize pin P5_5 GPIO as an output with strong drive mode and initial value = false
    rslt = cyhal_gpio_init(PIN_USER_LED, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG, false);

    if (rslt != CY_RSLT_SUCCESS) {
    	//exit(0);
    }

}



