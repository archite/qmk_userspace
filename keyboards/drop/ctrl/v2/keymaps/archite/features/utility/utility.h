#pragma once

#include QMK_KEYBOARD_H // IWYU pragma: export

#ifdef RGB_MATRIX_ENABLE
extern bool user_rgb_sleep;
#endif // RGB_MATRIX_ENABLE

void ak_lock_screen(void);
void ak_screen_saver(void);
