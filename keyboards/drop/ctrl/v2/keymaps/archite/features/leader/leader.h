#include "keymap_user.h" // IWYU pragma: keep

#define LS2KD(key, delay, first, second)           \
    if (leader_sequence_two_keys(first, second)) { \
        tap_code16_delay(key, delay);              \
        return;                                    \
    }

#define LS2K(key, first, second) LS2KD(key, 0, first, second)

#define LS3KD(key, delay, first, second, third)             \
    if (leader_sequence_three_keys(first, second, third)) { \
        tap_code16_delay(key, delay);                       \
        return;                                             \
    }

#define LS3K(key, first, second, third) LS3KD(key, 0, first, second, third)

#define WIN_2K(key, ...) LS2K(key, KC_W, __VA_ARGS__)

#define WIN_3K(key, ...) LS3K(key, KC_W, __VA_ARGS__)

#define FOURTHS(key, third) WIN_3K(key, KC_F, third)
#define THIRDS(key, third) WIN_3K(key, KC_T, third)
#define HALVES(key, third) WIN_3K(key, KC_H, third)
#define MISC(key, third) WIN_3K(key, KC_M, third)

uint8_t fourths[] = {
    KC_F, // first
    KC_V, // first 3/4
    KC_L, // last
    KC_N, // last 3/4
};

uint8_t thirds[] = {
    KC_F, // first
    KC_V, // first 2/3
    KC_C, // center
    KC_M, // center 2/3
    KC_L, // last
    KC_N, // last 2/3
};

uint8_t halves[] = {
    KC_B, // bottom
    KC_F, // first
    KC_C, // center
    KC_L, // last
    KC_T, // TOP
};

uint8_t misc[] = {
    KC_C, // center
    KC_P, // previous
    KC_R, // reset
    KC_M, // almost max
};

// clang-format off
#define GEN_F_KEYS(key) \
    KC_ ## key, \
    A(KC_ ## key), \
    A(C(KC_ ## key)), \
    A(C(G(KC_ ## key))), \
    A(C(G(S(KC_ ## key)))), \
    A(C(S(KC_ ## key))), \
    A(G(KC_ ## key)), \
    A(G(S(KC_ ## key))), \
    A(S(KC_ ## key)), \
    C(KC_ ## key), \
    C(G(KC_ ## key)), \
    C(G(S(KC_ ## key))), \
    C(S(KC_ ## key)), \
    G(KC_ ## key), \
    G(S(KC_ ## key))

uint16_t F_KEYS[] = {
    GEN_F_KEYS(F16),
    GEN_F_KEYS(F17),
    GEN_F_KEYS(F18),
    GEN_F_KEYS(F19),
    GEN_F_KEYS(F20),
};
// clang-format on

// Order
// A
// AC
// ACG
// ACGS
// ACS
// AG
// AGS
// AS
// C
// CG
// CGS
// CS
// G
// GS

// uint8_t fourths[] = {
//     KC_G,
//     // KC_L,
// };
