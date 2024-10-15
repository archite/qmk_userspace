#pragma once

#define KEY_FLAGS (LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER | LED_FLAG_INDICATOR)

#include "keymap_user.h" // IWYU pragma: export

void rgb_matrix_init_user(void);

void rgb_matrix_set_color_by_keycode(uint8_t led_min, uint8_t led_max, uint8_t layer, bool (*is_keycode)(uint16_t), uint8_t red, uint8_t green, uint8_t blue);
void rgb_matrix_set_underglow_color(uint8_t led_min, uint8_t led_max, uint8_t red, uint8_t green, uint8_t blue);

bool is_caps_lock_indicator(uint16_t keycode);
bool not_caps_lock_indicator(uint16_t keycode);
bool is_transparent(uint16_t keycode);
bool not_transparent(uint16_t keycode);
