#include "features/leader/leader.h"

void leader_end_user(void) {
#define F_INDEX 0
    // window management
    //   Fourths
    for (uint8_t i = 0; i < sizeof(fourths); i++) {
        FOURTHS(F_KEYS[F_INDEX + i], fourths[i]);
    }

#undef F_INDEX
#define F_INDEX 5
    //   thirds
    for (uint8_t i = 0; i < sizeof(thirds); i++) {
        THIRDS(F_KEYS[F_INDEX + i], thirds[i]);
    }

#undef F_INDEX
#define F_INDEX 15
    //   halves
    for (uint8_t i = 0; i < sizeof(halves); i++) {
        HALVES(F_KEYS[F_INDEX + i], halves[i]);
    }

#undef F_INDEX
#define F_INDEX 25
    //   misc
    for (uint8_t i = 0; i < sizeof(misc); i++) {
        MISC(F_KEYS[F_INDEX + i], misc[i]);
    }

    MISC(C(G(KC_F)), KC_F); // full

    if (leader_sequence_two_keys(KC_L, KC_S)) {
        ak_lock_screen();
        return;
    }

    if (leader_sequence_two_keys(KC_S, KC_S)) {
        ak_screen_saver();
        return;
    }
}
