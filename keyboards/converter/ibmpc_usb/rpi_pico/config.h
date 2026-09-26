// Copyright 2026 jlpoltrack
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Raspberry Pi Pico (RP2040). GPIOs are NOT 5V tolerant: the keyboard's
 * clock/data pull-ups must go to 3.3V (or use a bidirectional level shifter).
 * Same wiring as the M122 PlatformIO project: GND pin 3, GP2 pin 4, GP3 pin 5.
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

/* Solenoid (haptic). RP2040 pads reset with pull-downs, so no misfire while booting. */
#define SOLENOID_PIN              GP6
#define HAPTIC_ENABLE_PIN         GP7   // driver/boost enable; remove if unused
#define HAPTIC_OFF_IN_LOW_POWER   1
#define SOLENOID_DEFAULT_DWELL    4
#define SOLENOID_MIN_DWELL        4
#define NO_HAPTIC_MOD

// double-tap RUN (reset) to enter the UF2 bootloader; onboard LED shows it
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP25
