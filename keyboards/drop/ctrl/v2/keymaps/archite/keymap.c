#include "keymap_user.h"

#ifdef COMBO_ENABLE
#    include "g/keymap_combo.h" // IWYU pragma: export
#endif                          // COMBO_ENABLE

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_tkl_ansi(
        KC_ESC,           KC_BRID, KC_BRIU, KC_LPAD, AK_SPLT, AK_SIRI, AK_DND,  KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU,    AK_SCVR, KC_SCRL, KC_PAUS,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,    AK_LOCK, KC_HOME, KC_PGUP,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,    KC_DEL,  KC_END,  KC_PGDN,
        KC_LCTL, AK_A,    AK_S,    AK_D,    AK_F,    KC_G,    KC_H,    AK_J,    AK_K,    AK_L,    AK_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,             KC_UP,
        AK_CAPS, KC_LOPT, KC_LCMD,                            AK_SPC,                             KC_RCMD, MO(1),   AK_GLOB, KC_RCTL,    KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [1] = LAYOUT_tkl_ansi(
        _______,          KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,     _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______,
        _______, RGB_TOG, RGB_VAI, RGB_SPI, RGB_HUI, RGB_SAI, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______,
        _______, RGB_MOD, RGB_VAD, RGB_SPD, RGB_HUD, RGB_SAD, _______, _______, _______, _______, _______, _______,          _______,
        _______,          RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW,_______, NK_TOGG, _______, _______, _______, _______,          _______,             _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______,    _______, _______, _______
    ),
    [2] = LAYOUT_tkl_ansi(
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______,
        _______, _______, _______, KC_END,  _______, _______, _______, KC_PGUP, KC_UP,   _______, _______, _______, _______, _______,    _______, _______, _______,
        _______, _______, _______, KC_PGDN, _______, _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,             _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______,    _______, _______, _______
    )
};
// clang-format on

#ifdef RGB_MATRIX_ENABLE
void matrix_init_user(void) {
    rgb_matrix_init_user();
}

#    ifdef RGB_MATRIX_CAPS_LOCK_INDEX
bool rgb_matrix_indicators_user(void) {
    return false;
}
#    endif

extern void rgb_matrix_update_pwm_buffers(void);

bool shutdown_user(bool jump_to_bootloader) {
    if (jump_to_bootloader) {
        // red for bootloader
        rgb_matrix_set_color_all(RGB_RED);
    } else {
        // green for soft reset
        rgb_matrix_set_color_all(RGB_GREEN);
    }
    // force flushing -- otherwise will never happen
    rgb_matrix_update_pwm_buffers();
    // false to not process kb level
    return false;
}
#endif

uint8_t mod_state;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();

    switch (keycode) {
        case AK_DICTATION:
            AK_HCS(0xCF);
            return false;
        case AK_DO_NOT_DISTURB:
            AK_HSS(0x9B);
            return false;
        case AK_GLOBE:
            AK_HCS(0x29D);
            return false;
        case AK_LOCK_SCREEN:
            if (record->event.pressed) {
                ak_lock_screen();
            };
            return false;
        case AK_SCREEN_SAVER:
            if (record->event.pressed) {
                ak_screen_saver();
            };
            return false;
        case AK_SPOTLIGHT:
            AK_HCS(0x221);
            return false;
#ifdef RGB_MATRIX_ENABLE
        case RGB_TOG:
            if (rgb_matrix_get_flags() != LED_FLAG_NONE && (mod_state & MOD_MASK_SHIFT)) {
                rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
            }
            return true;
#endif
        default:
#ifdef RGB_MATRIX_ENABLE
            if (record->event.pressed) {
                if (rgb_matrix_get_suspend_state()) {
                    rgb_matrix_set_suspend_state(false);
                } else if (user_rgb_sleep) {
                    user_rgb_sleep = false;
                    if (!rgb_matrix_is_enabled()) {
                        rgb_matrix_enable_noeeprom();
                    }
                }
            }
#endif
            return true;
    }
}
