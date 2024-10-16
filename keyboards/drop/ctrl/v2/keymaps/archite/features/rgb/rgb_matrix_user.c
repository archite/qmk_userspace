#include "features/rgb/rgb_matrix_user.h"

keypos_t led_index_key_position[RGB_MATRIX_LED_COUNT];

void rgb_matrix_init_user(void) {
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        for (uint8_t col = 0; col < MATRIX_COLS; col++) {
            uint8_t led_index = g_led_config.matrix_co[row][col];
            if (led_index != NO_LED) {
                led_index_key_position[led_index] = (keypos_t){.row = row, .col = col};
            }
        }
    }
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    led_flags_t cflags        = rgb_matrix_get_flags();
    uint8_t     current_layer = get_highest_layer(layer_state);
    if (cflags != LED_FLAG_NONE) {
        switch (current_layer) {
            case 0:
#ifdef LEADER_INDICATOR_COLOR
                if (leader_sequence_active()) {
                    rgb_matrix_set_color_all(LEADER_INDICATOR_COLOR);
                }
#endif
#ifdef CAPS_LOCK_INDICATOR_COLOR
                if (host_keyboard_led_state().caps_lock) {
                    rgb_matrix_set_color_by_keycode(led_min, led_max, current_layer, not_transparent, CAPS_LOCK_INDICATOR_COLOR);
                } else if (is_caps_word_on()) {
                    rgb_matrix_set_color_by_keycode(led_min, led_max, current_layer, is_caps_lock_indicator, CAPS_LOCK_INDICATOR_COLOR);
                    // rgb_matrix_set_color_by_keycode(led_min, led_max, current_layer, not_caps_lock_indicator, RGB_OFF);
                }
#    ifdef CAPS_LOCK_INDICATOR_UNDERGLOW
                if (host_keyboard_led_state().caps_lock | is_caps_word_on()) {
                    rgb_matrix_set_underglow_color(led_min, led_max, CAPS_LOCK_INDICATOR_COLOR);
                }
#    endif
#endif
                break;
            case 1:
            case 2:
#ifdef FN_LAYER_INDICATOR_COLOR
                rgb_matrix_set_color_by_keycode(led_min, led_max, current_layer, not_transparent, FN_LAYER_INDICATOR_COLOR);
#    ifdef CAPS_LOCK_INDICATOR_UNDERGLOW
                rgb_matrix_set_underglow_color(led_min, led_max, FN_LAYER_INDICATOR_COLOR);
#    endif
#endif
#ifdef FN_LAYER_TRANSPARENT_KEYS_OFF
                rgb_matrix_set_color_by_keycode(led_min, led_max, current_layer, is_transparent, RGB_OFF);
#endif
                break;
        }
    }
    return false;
}

void rgb_matrix_set_color_by_keycode(uint8_t led_min, uint8_t led_max, uint8_t layer, bool (*is_keycode)(uint16_t), uint8_t red, uint8_t green, uint8_t blue) {
    led_flags_t cflags = rgb_matrix_get_flags();
    for (uint8_t i = led_min; i < led_max; i++) {
        bool     is_key  = g_led_config.flags[i] & KEY_FLAGS;
        uint16_t keycode = keymap_key_to_keycode(layer, led_index_key_position[i]);
        if ((*is_keycode)(keycode)) {
            if (is_key && cflags & KEY_FLAGS) {
                rgb_matrix_set_color(i, red, green, blue);
            }
        }
    }
}

void rgb_matrix_set_underglow_color(uint8_t led_min, uint8_t led_max, uint8_t red, uint8_t green, uint8_t blue) {
    bool use_underglow = rgb_matrix_get_flags() & LED_FLAG_UNDERGLOW;
    for (uint8_t i = led_min; i < led_max; i++) {
        bool is_underglow = g_led_config.flags[i] & LED_FLAG_UNDERGLOW;
        if (use_underglow && is_underglow) {
            rgb_matrix_set_color(i, red, green, blue);
        }
    }
}

bool is_caps_lock_indicator(uint16_t keycode) {
#ifdef CAPS_LOCK_INDICATOR_LIGHT_ALPHAS
    switch (keycode) {
        case KC_A ... KC_Z:
        case KC_MINS:
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        case KC_CAPS:
        case AK_CAPS:
            return true;
        default:
            return false;
    }
#else
    return keycode == KC_CAPS;
#endif
}

bool not_caps_lock_indicator(uint16_t keycode) {
    return !is_caps_lock_indicator(keycode);
}

bool is_transparent(uint16_t keycode) {
    return keycode == KC_TRNS;
}

bool not_transparent(uint16_t keycode) {
    return !is_transparent(keycode);
}
