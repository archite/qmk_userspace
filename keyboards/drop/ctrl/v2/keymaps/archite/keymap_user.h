#pragma once

#include QMK_KEYBOARD_H // IWYU pragma: export

#include "features/utility/utility.h" // IWYU pragma: export

#ifdef RGB_MATRIX_ENABLE
#    include "features/rgb/rgb_matrix_user.h"
#endif // RGB_MATRIX_ENABLE

// clang-format off
enum custom_keycodes {
    AK_DICTATION = SAFE_RANGE,
    AK_DO_NOT_DISTURB,
    AK_GLOBE,
    AK_LOCK_SCREEN,
    AK_SCREEN_SAVER,
    AK_SPOTLIGHT,
};

#define AK_DND  AK_DO_NOT_DISTURB
#define AK_GLOB AK_GLOBE
#define AK_LOCK AK_LOCK_SCREEN
#define AK_SCVR AK_SCREEN_SAVER
#define AK_SIRI AK_DICTATION
#define AK_SPLT AK_SPOTLIGHT

#define AK_CAPS LT(1, KC_CAPS_LOCK)

#define AK_HCS(x) host_consumer_send(record->event.pressed ? x : 0)
#define AK_HSS(x) host_system_send(record->event.pressed ? x : 0)

// mod-tap homerow
//   Left
#define AK_A LSFT_T(KC_A)
#define AK_S RCTL_T(KC_S)
#define AK_D LOPT_T(KC_D)
#define AK_F LCMD_T(KC_F)

//   Right
#define AK_J LCMD_T(KC_J)
#define AK_K LOPT_T(KC_K)
#define AK_L RCTL_T(KC_L)
#define AK_SCLN LSFT_T(KC_SCLN)

// movement
#define AK_SPC LT(2, KC_SPC)
// clang-format on
