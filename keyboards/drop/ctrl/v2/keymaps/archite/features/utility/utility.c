#include "features/utility/utility.h"

#ifdef RGB_MATRIX_ENABLE
bool user_rgb_sleep = false;
#endif

void ak_lock_screen(void) {
    tap_code16(C(G(KC_Q)));
    tap_code16(RCS(KC_PWR));
#ifdef RGB_MATRIX_ENABLE
    if (rgb_matrix_is_enabled()) {
        rgb_matrix_disable_noeeprom();
        user_rgb_sleep = true;
    }
    // rgb_matrix_set_suspend_state(true);
#endif
}

void ak_screen_saver(void) {
    tap_code16(HYPR(KC_L));
#ifdef RGB_MATRIX_ENABLE
    if (rgb_matrix_is_enabled()) {
        rgb_matrix_disable_noeeprom();
        user_rgb_sleep = true;
    }
    // rgb_matrix_set_suspend_state(true);
#endif
}
