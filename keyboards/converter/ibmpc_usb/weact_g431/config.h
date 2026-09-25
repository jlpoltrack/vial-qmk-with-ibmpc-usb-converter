// Copyright 2026 jlpoltrack
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * WeAct STM32G431CoreBoard (STM32G431CBU6)
 * Header P1 order: PB7 data, PB6 ground (driven low), PB5 clock.
 * Avoid PA11/PA12 (USB), PA13/PA14 (SWD) and PB8 (BOOT0).
 */
// clock requires an EXTI-capable pin
#define IBMPC_CLOCK_PIN   B5
#define IBMPC_DATA_PIN    B7

// GPIO held low as a signal ground; not rated to carry keyboard supply current
#define IBMPC_GND_PIN     B6

// 50us per-bit send timeout is too tight at 170MHz for terminal keyboards
#define IBMPC_BIT_TIMEOUT_US 150

// 4 Vial layers and 4KB of macros; flash-emulated EEPROM sized to hold both
#define DYNAMIC_KEYMAP_LAYER_COUNT 4
#define DYNAMIC_KEYMAP_MACRO_EEPROM_SIZE 4096
#define WEAR_LEVELING_LOGICAL_SIZE 8192
#define WEAR_LEVELING_BACKING_SIZE 16384

/* Solenoid (haptic). PB12/PB13 have no pull-ups at reset, so no misfire while booting. */
#define SOLENOID_PIN              B13
#define HAPTIC_ENABLE_PIN         B12   // driver/boost enable; remove if unused
#define HAPTIC_OFF_IN_LOW_POWER   1
#define SOLENOID_DEFAULT_DWELL    4
#define SOLENOID_MIN_DWELL        4
#define NO_HAPTIC_MOD
