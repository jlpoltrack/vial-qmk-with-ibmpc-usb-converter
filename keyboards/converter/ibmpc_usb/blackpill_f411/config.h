/* Copyright 2019
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "config_common.h"

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

// Can borrow from: https://github.com/qmk/qmk_firmware/tree/master/keyboards/handwired/onekey/blackpill_f411

/*
 * Pin configuration
 */
// clock requires External Interrupt pin(INT*)
#define IBMPC_CLOCK_PIN   A1        // A0 not 5 volt tolerant
#define IBMPC_DATA_PIN    A2

/* reset line */
#define IBMPC_RST_PIN0    A3
#define IBMPC_RST_PIN1    A4

#define EEPROM_SIZE 8192
