// Copyright 2026 jlpoltrack
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * WeAct STM32G431CoreBoard (STM32G431CBU6)
 * PB7/PB9 are 5V tolerant; avoid PB4/PB6 (UCPD dead-battery pull-downs),
 * PA11/PA12 (USB), PA13/PA14 (SWD) and PB8 (BOOT0).
 */
// clock requires an EXTI-capable pin
#define IBMPC_CLOCK_PIN   B7
#define IBMPC_DATA_PIN    B9

/* reset line, only used by XT Type-1 keyboards */
#define IBMPC_RST_PIN0    B5
#define IBMPC_RST_PIN1    A8
