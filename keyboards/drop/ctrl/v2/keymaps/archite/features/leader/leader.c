#include "features/leader/leader.h"

void leader_end_user(void) {
#define F_INDEX 0
    // window management
    //   Fourths
    for (uint8_t i = 0; i < sizeof(fourths); i++) {
        FOURTHS(F_KEYS[F_INDEX + i], fourths[i]);
    }

#undef F_INDEX
#define F_INDEX 10
    //   thirds
    for (uint8_t i = 0; i < sizeof(thirds); i++) {
        THIRDS(F_KEYS[F_INDEX + i], thirds[i]);
    }

#undef F_INDEX
#define F_INDEX 20
    //   halves
    for (uint8_t i = 0; i < sizeof(halves); i++) {
        HALVES(F_KEYS[F_INDEX + i], halves[i]);
    }

#undef F_INDEX
#define F_INDEX 30
    //   misc
    for (uint8_t i = 0; i < sizeof(misc); i++) {
        MISC(F_KEYS[F_INDEX + i], misc[i]);
    }

    MISC(C(G(KC_F)), KC_F); // full

    //   qmk
    if (leader_sequence_two_keys(KC_Q, KC_B)) {
        reset_keyboard();
        return;
    }

    if (leader_sequence_two_keys(KC_Q, KC_E)) {
        eeconfig_disable();
        soft_reset_keyboard();
        return;
    }

    if (leader_sequence_two_keys(KC_Q, KC_M)) {
        SEND_STRING_DELAY("qmk", TAP_CODE_DELAY);
        SEND_STRING_DELAY(" compile ", TAP_CODE_DELAY);
        SEND_STRING_DELAY("-kb " QMK_KEYBOARD " -km " QMK_KEYMAP SS_TAP(X_ENTER), TAP_CODE_DELAY);
        return;
    }

    if (leader_sequence_two_keys(KC_Q, KC_F)) {
        SEND_STRING_DELAY("qmk", TAP_CODE_DELAY);
        SEND_STRING_DELAY(" flash ", TAP_CODE_DELAY);
        SEND_STRING_DELAY("-kb " QMK_KEYBOARD " -km " QMK_KEYMAP SS_TAP(X_ENTER), TAP_CODE_DELAY);
        return;
    }

    // screen locking
    if (leader_sequence_two_keys(KC_L, KC_S)) {
        ak_lock_screen();
        return;
    }

    if (leader_sequence_two_keys(KC_S, KC_S)) {
        ak_screen_saver();
        return;
    }
}
