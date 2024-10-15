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

void leader_end_user(void) {
    // window management
    //   Fourths
    FOURTHS(A(KC_F16), KC_F);    // first
    FOURTHS(A(C(KC_F16)), KC_L); // last

    //   thirds
    THIRDS(A(C(G(KC_F16))), KC_F);      // first
    THIRDS(A(C(G(S((KC_F16))))), KC_C); // center
    THIRDS(A(C(S((KC_F16)))), KC_L);    // last

    //   halves
    HALVES(A(G(KC_F16)), KC_F);    // first
    HALVES(A(G(S(KC_F16))), KC_C); // center
    HALVES(A(S(KC_F16)), KC_L);    // last
    HALVES(C(KC_F16), KC_B);       // bottom
    HALVES(C(G(KC_F16)), KC_T);    // top

    //   misc
    MISC(C(G(S(KC_F16))), KC_C); // center
    MISC(C(S(KC_F16)), KC_P);    // previous
    MISC(G(KC_F16), KC_M);       // center 2/3
    MISC(C(G(KC_F)), KC_F);      // full

    if (leader_sequence_two_keys(KC_L, KC_S)) {
        ak_lock_screen();
        return;
    }

    if (leader_sequence_two_keys(KC_S, KC_S)) {
        ak_screen_saver();
        return;
    }
}
