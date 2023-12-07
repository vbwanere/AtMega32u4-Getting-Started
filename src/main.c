/* Name: main.c
 * Author: <insert your name here>
 * Copyright: <insert your copyright message here>
 * License: <insert your license reference here>
 */

#include "MEAM_general.h"  // includes the resources included in the MEAM_general.h file

int main(void)
{
    _clockdivide(0); //set the clock speed to 16Mhz
    set_led(ON);			// turn on the on board LED
    _delay_ms(1000);		// wait 1000 ms when at 16 MHz

    /* insert your hardware initialization here */
    for(;;){
        /* insert your main loop code here */
        set_led(TOGGLE);	// switch the led state
        _delay_ms(1000);		// wait
    }
    return 0;   /* never reached */
}
