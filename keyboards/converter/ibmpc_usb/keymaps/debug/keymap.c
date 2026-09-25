// Copyright 2026 jlpoltrack
// SPDX-License-Identifier: GPL-2.0-or-later

// Bring-up keymap: protocol trace on the console, no keys sent to the host.
#include QMK_KEYBOARD_H
#include "raw_hid.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {{{KC_NO}}};

void keyboard_post_init_user(void) {
    debug_enable = true;
}

// Same command id as VIA/Vial bootloader jump, so flash_g431.sh works unchanged.
void raw_hid_receive(uint8_t *data, uint8_t length) {
    if (data[0] == 0x0B) {
        bootloader_jump();
    }
}
