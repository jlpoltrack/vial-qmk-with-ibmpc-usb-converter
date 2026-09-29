// Copyright 2026 jlpoltrack
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Raspberry Pi Pico 2 (RP2350A, ARM mode). Same wiring as the Pico:
 * GND pin 3, clock GP2 pin 4, data GP3 pin 5. See readme.md for 5V notes.
 */
#define IBMPC_CLOCK_PIN   GP2
#define IBMPC_DATA_PIN    GP3

// 50us per-bit send timeout is too tight on fast MCUs for terminal keyboards
#define IBMPC_BIT_TIMEOUT_US 150

// 4 Vial layers and 4KB of macros; flash-emulated EEPROM sized to hold both
#define DYNAMIC_KEYMAP_LAYER_COUNT 4
#define DYNAMIC_KEYMAP_MACRO_EEPROM_SIZE 4096
#define WEAR_LEVELING_LOGICAL_SIZE 8192
#define WEAR_LEVELING_BACKING_SIZE 16384

/* Solenoid (haptic). RP2350 erratum E9 can hold an input pad near 2.2V, so the
 * MOSFET gate needs an external pull-down (<= 8.2k) to stay off while booting. */
#define SOLENOID_PIN              GP6
#define HAPTIC_ENABLE_PIN         GP7   // driver/boost enable; remove if unused
#define HAPTIC_OFF_IN_LOW_POWER   1
#define SOLENOID_DEFAULT_DWELL    4
#define SOLENOID_MIN_DWELL        4
#define NO_HAPTIC_MOD

// double-tap RUN (reset) to enter the UF2 bootloader; onboard LED shows it
#define RP2350_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2350_BOOTLOADER_DOUBLE_TAP_RESET_LED GP25
