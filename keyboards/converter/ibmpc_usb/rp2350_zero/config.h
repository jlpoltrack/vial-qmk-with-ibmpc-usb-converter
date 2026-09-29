// Copyright 2026 jlpoltrack
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Waveshare RP2350-Zero (RP2350A). Same GPIOs as the Pico 2 target:
 * clock GP2, data GP3. See readme.md for 5V notes.
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

/* Onboard WS2812 shows lock state: Caps red, Num green, Scroll blue (colors mix).
 * Waveshare's LED takes RGB order; use GRB if Caps shows green. */
#define WS2812_DI_PIN          GP16
#define WS2812_LED_COUNT       1
#define WS2812_BYTE_ORDER      WS2812_BYTE_ORDER_RGB
#define LOCK_LED_BRIGHTNESS    32

/* Solenoid (haptic). RP2350 erratum E9 can hold an input pad near 2.2V, so the
 * MOSFET gate needs an external pull-down (<= 8.2k) to stay off while booting. */
#define SOLENOID_PIN              GP6
#define HAPTIC_ENABLE_PIN         GP7   // driver/boost enable; remove if unused
#define HAPTIC_OFF_IN_LOW_POWER   1
#define SOLENOID_DEFAULT_DWELL    4
#define SOLENOID_MIN_DWELL        4
#define NO_HAPTIC_MOD

// double-tap RESET to enter the UF2 bootloader (no plain LED to show it)
#define RP2350_BOOTLOADER_DOUBLE_TAP_RESET
