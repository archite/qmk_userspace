#pragma once

// clang-format off
#include QMK_KEYBOARD_H // IWYU pragma: export

#include "features/utility/utility.h" // IWYU pragma: export

#ifdef RGB_MATRIX_ENABLE
#    include "features/rgb/rgb_matrix_user.h" // IWYU pragma: export
#endif // RGB_MATRIX_ENABLE

#define AC_DICT 0xCF
#define AC_DND 0x9B
#define AC_GLOBE 0x29D

enum custom_layers {
    _MAIN = 0,
    _ALTERNATE,
    _SPECIAL,
};

enum custom_keycodes {
    AK_CMD_TAB_NEXT = SAFE_RANGE,
    AK_CMD_TAB_LAST,
    AK_DICTATION,
    AK_DO_NOT_DISTURB,
    AK_GLOBE,
    AK_LOCK_SCREEN,
    AK_SCREEN_SAVER,
    AK_SPOTLIGHT,
};

#define AK_TABL AK_CMD_TAB_LAST
#define AK_TABN AK_CMD_TAB_NEXT
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

// Navigation
#define AK_NXTB G(S(KC_RBRC))
#define AK_PRTB G(S(KC_LBRC))
#define AK_BACK G(KC_LBRC)
#define AK_FWD G(KC_RBRC)

// screenshots
#define AK_SPSF G(S(KC_3))
#define AK_SPSC C(AK_SPSF)
#define AK_SPAF G(S(KC_4))
#define AK_SPAC C(AK_SPAF)
// clang-format on
