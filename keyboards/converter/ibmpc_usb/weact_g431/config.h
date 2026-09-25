// Copyright 2026 jlpoltrack
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * WeAct STM32G431CoreBoard (STM32G431CBU6)
 * Header P1 order: PB7 clock, PB6 ground (driven low), PB5 data.
 * Avoid PA11/PA12 (USB), PA13/PA14 (SWD) and PB8 (BOOT0).
 */
// clock requires an EXTI-capable pin
#define IBMPC_CLOCK_PIN   B7
#define IBMPC_DATA_PIN    B5

// GPIO held low as a signal ground; not rated to carry keyboard supply current
#define IBMPC_GND_PIN     B6
