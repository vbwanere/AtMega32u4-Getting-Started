// ----------------------------------------------------------------------------
// General macros adapted from m_general.h by J. Fiene 
// version: 3
// date: August 5, 2022
// author: adapted by P. Stegall / Mark Yim
// ----------------------------------------------------------------------------
#ifndef _MEAM_general_h_
#define _MEAM_general_h_

// ----------------------------------------------------------------------------
// Useful pre-compile constants
// ----------------------------------------------------------------------------

#define TRUE	1
#define FALSE	0

#define OFF		0
#define ON		1
#define TOGGLE		2

// ----------------------------------------------------------------------------
// General AVR libraries:
// ----------------------------------------------------------------------------

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

// ----------------------------------------------------------------------------
// Bit manipulation and validation:
// ----------------------------------------------------------------------------

#define set(reg,bit)		(reg) |= (1<<(bit))
#define clear(reg,bit)		(reg) &= ~(1<<(bit))
#define toggle(reg,bit)		(reg) ^= (1<<(bit))

// ----------------------------------------------------------------------------
// Disable JTAG to access F4-F7:
// ----------------------------------------------------------------------------

#define _disableJTAG()		MCUCR = (1 << JTD); MCUCR = (1 << JTD)
// Setting the JTD bit in MCUCR twice within four clock cycles will allow user
// access to F4-F7 as normal port pins. Note that using |= is too slow for this
// operation to work correctly, so we are setting the entire register 
// (fortunately, all other bits in MCUCR are 0 anyway).


// ----------------------------------------------------------------------------
// Set the system clock:
// ----------------------------------------------------------------------------

#define _clockdivide(val)	CLKPR = (1<<CLKPCE); CLKPR=val
// "val" must be an integer from 0 to 8
// this will divide the 16MHz system clock by 2^val:
// 0 = 16 MHz
// 1 = 8 MHz
// 2 = 4 MHz
// 3 = 2 MHz
// 4 = 1 MHz
// 5 = 500 kHz
// 6 = 250 kHz
// 7 = 125 kHz
// 8 = 62.5 kHz

// ----------------------------------------------------------------------------
// Change the state of the on-board LED on pin C7:
// (included here for educational purposes)
// ----------------------------------------------------------------------------

#define set_led(val)		set(DDRC,7); if((val)==ON){set(PORTC,7);}else if((val)==OFF){clear(PORTC,7);}else if((val)==TOGGLE){toggle(PORTC,7);}
// "val" must be either OFF, ON, or TOGGLE, as defined above


#endif  // _MEAM_general_h_
