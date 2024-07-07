/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2016 Priyadi Iman Nurcahyo <priyadi@priyadi.net>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/*
 * Pin and interrupt configuration
 */
// clock requires External Interrupt pin(INT*)
#define IBMPC_CLOCK_PORT  PORTD
#define IBMPC_CLOCK_PIN   PIND
#define IBMPC_CLOCK_DDR   DDRD
#define IBMPC_DATA_PORT   PORTD
#define IBMPC_DATA_PIN    PIND
#define IBMPC_DATA_DDR    DDRD

// primary interface
#define IBMPC_CLOCK_BIT   1
#define IBMPC_DATA_BIT    0

#define IBMPC_INT_INIT()  do {  \
    EICRA |= ((1<<ISC11) |      \
              (0<<ISC10));      \
} while (0)
#define IBMPC_INT_ON()  do {    \
    EIFR  |= (1<<INTF1);        \
    EIMSK |= (1<<INT1);         \
} while (0)
#define IBMPC_INT_OFF() do {    \
    EIMSK &= ~(1<<INT1);        \
} while (0)
#define IBMPC_INT_VECT    INT1_vect

// secondary interface
#ifdef IBMPC_SECONDARY
#define IBMPC_CLOCK_BIT1  3
#define IBMPC_DATA_BIT1   2

#define IBMPC_INT_INIT1()  do { \
    EICRA |= ((1<<ISC31) |      \
              (0<<ISC30));      \
} while (0)
#define IBMPC_INT_ON1()  do {   \
    EIFR  |= (1<<INTF3);        \
    EIMSK |= (1<<INT3);         \
} while (0)
#define IBMPC_INT_OFF1() do {   \
    EIMSK &= ~(1<<INT3);        \
} while (0)
#define IBMPC_INT_VECT1   INT3_vect
#endif

/* reset line */
#define IBMPC_RST_PORT    PORTB
#define IBMPC_RST_PIN     PINB
#define IBMPC_RST_DDR     DDRB
#define IBMPC_RST_BIT0    6
#define IBMPC_RST_BIT1    7

/* reset for XT Type-1 keyboard: low pulse for 500ms */
#define IBMPC_RST_HIZ() do { \
    IBMPC_RST_PORT &= ~(1<<IBMPC_RST_BIT0);  \
    IBMPC_RST_DDR  &= ~(1<<IBMPC_RST_BIT0);  \
    IBMPC_RST_PORT &= ~(1<<IBMPC_RST_BIT1);  \
    IBMPC_RST_DDR  &= ~(1<<IBMPC_RST_BIT1);  \
} while (0)

#define IBMPC_RST_LO() do { \
    IBMPC_RST_PORT &= ~(1<<IBMPC_RST_BIT0);  \
    IBMPC_RST_DDR  |=  (1<<IBMPC_RST_BIT0);  \
    IBMPC_RST_PORT &= ~(1<<IBMPC_RST_BIT1);  \
    IBMPC_RST_DDR  |=  (1<<IBMPC_RST_BIT1);  \
} while (0)

// Comment out HAPTIC_ENABLE_PIN if you don't have an enable pin:
#define HAPTIC_ENABLE_PIN B4
// We disable haptic feedbeck during USB low power conditions:
#define HAPTIC_OFF_IN_LOW_POWER 1
// Change this if you are using a different pin for the solenoid:
#define SOLENOID_PIN B5
// If you are not using a solenoid then comment out the above, and also in rules.mk, remove "HAPTIC_ENABLE += SOLENOID"
// You can also tune the following for your solenoid:
#define SOLENOID_DEFAULT_DWELL 4
#define SOLENOID_MIN_DWELL 4
#define NO_HAPTIC_MOD
