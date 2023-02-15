/*
 * push_button.c
 *
 *  Created on: Aug 16, 2022
 *      Author: Joe Krachey
 */

#include "push_button.h"

volatile bool ALERT_PUSH_BUTTON = false;
volatile bool LED_ON = false;

/* IO Pin Handler Struct */
cyhal_gpio_callback_data_t push_button_cb_data = {
		.callback = push_button_handler,
		.callback_arg = (void*) NULL
};

/** IRQ handler for SW401
 *
 * @param
 *
 */
void push_button_handler(void *handler_arg, cyhal_gpio_event_t event) {
	ALERT_PUSH_BUTTON = true;

	/* Toggle LED401 when an interrupt has been detected */
//	LED_ON = !LED_ON;
//	bool write_val = LED_ON;

	// Write the value to the output pin
//	cyhal_gpio_write(PIN_USER_LED, LED_ON);
	cyhal_gpio_toggle(PIN_USER_LED);
}

/** Configure SW401 to generate an interrupt when the push button
 * has been pressed
 *
 * @param
 *
 */
static void push_button_irq_init(void) {
	/* You will need to examine the HAL API to determine how to
	 * register a callback function when an interrupt has been detected
	 */
    // Register callback function - gpio_interrupt_handler and pass the value global_count
    cyhal_gpio_register_callback(PIN_PUSH_BUTTON, &push_button_cb_data);

	/* You will need to examine the HAL API to enable falling edge event to
	 * generate an interrupt
	 */
    // Enable falling edge interrupt event with interrupt priority set to 3
    cyhal_gpio_enable_event(PIN_PUSH_BUTTON, CYHAL_GPIO_IRQ_FALL, INT_PRIORITY_PUSH_BUTTON, true);
}

/** Initialize the pin connected to SW401 to be an input pin
 *
 * @param
 *
 */
static void push_button_io_init(void) {
	/* Initialize SW401.  You will need to examine the HAL API to determine how to
	 * initialize an IO pin an input
	 */
    cy_rslt_t rslt;

    // Initialize pin P5_6 GPIO as an input with strong drive mode and initial value = false
    rslt = cyhal_gpio_init(PIN_PUSH_BUTTON, CYHAL_GPIO_DIR_INPUT, CYHAL_GPIO_DRIVE_STRONG, false);

    if (rslt != CY_RSLT_SUCCESS) {
    	// exit(0);
    }
}

/** Initialize the push button on the ECE453 MCU Dev Board
 *  to generate interrupts
 *
 * @param
 *
 */
void push_button_init(void) {
	push_button_io_init();
	push_button_irq_init();
}
