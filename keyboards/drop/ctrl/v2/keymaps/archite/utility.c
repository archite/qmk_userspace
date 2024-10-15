#include "utility.h"

void ak_lock_screen(void) {
    tap_code16(C(G(KC_Q)));
    tap_code16(RCS(KC_PWR));
    rgb_matrix_set_suspend_state(true);
}

void ak_screen_saver(void) {
    tap_code16(HYPR(KC_L));
    rgb_matrix_set_suspend_state(true);
}
