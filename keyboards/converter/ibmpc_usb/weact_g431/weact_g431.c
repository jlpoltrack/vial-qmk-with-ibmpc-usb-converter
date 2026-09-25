// Copyright 2026 jlpoltrack
// SPDX-License-Identifier: GPL-2.0-or-later

#include "quantum.h"

void keyboard_pre_init_kb(void) {
    // latch low before enabling the output to avoid a high glitch
    gpio_write_pin_low(IBMPC_GND_PIN);
    gpio_set_pin_output_push_pull(IBMPC_GND_PIN);
    keyboard_pre_init_user();
}
