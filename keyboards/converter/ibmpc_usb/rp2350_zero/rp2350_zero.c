// Copyright 2026 jlpoltrack
// SPDX-License-Identifier: GPL-2.0-or-later

#include "quantum.h"
#include "ws2812.h"

static bool rgb_ready = false;

static void lock_led_show(led_t s) {
    if (!rgb_ready) return;
    ws2812_set_color(0, s.caps_lock ? LOCK_LED_BRIGHTNESS : 0,
                        s.num_lock ? LOCK_LED_BRIGHTNESS : 0,
                        s.scroll_lock ? LOCK_LED_BRIGHTNESS : 0);
    ws2812_flush();
}

void keyboard_post_init_kb(void) {
    ws2812_init();
    rgb_ready = true;
    lock_led_show(host_keyboard_led_state());
#ifdef CONSOLE_ENABLE
    // console builds are for bring-up, so turn protocol logging on by default
    debug_enable = true;
#endif
    keyboard_post_init_user();
}

bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);
    if (res) {
        led_update_ports(led_state);    // Num/Scroll GPIOs from keyboard.json
        lock_led_show(led_state);
    }
    return res;
}
