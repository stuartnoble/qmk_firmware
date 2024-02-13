/* Copyright 2023 spacechips <spacechips@tuta.io>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

#include "enums.h"
#include "keymaps/keymaps.h"
#include "oled.c"

#define MACRO_LAYOUT(...)      LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [FUNCTIONS] = MACRO_LAYOUT(FUNCTIONS_LAYOUT),
    [SYMBOLS] = MACRO_LAYOUT(SYMBOLS_LAYOUT),
    [COLEMAK] = MACRO_LAYOUT(COLEMAK_LAYOUT),
    [NAVIGATION] = MACRO_LAYOUT(NAVIGATION_LAYOUT),
    [QWERTY] = MACRO_LAYOUT(QWERTY_LAYOUT)
};

void caps_word_set_user(bool active) {
    is_capsword_on = active;

    render_capsword_glyph(active);
}

// void mods_set_user(bool mods) {
//     bool shift_on = mods & MOD_MASK_SHIFT;
//     bool ctrl_on = mods & MOD_MASK_CTRL;
//     bool cmd_on = mods & MOD_MASK_GUI;
//     bool alt_on = mods & MOD_MASK_ALT;

//     render_top_modifier_glyphs(shift_on, ctrl_on, cmd_on, alt_on);
// }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    //mods_set_user(get_mods());
    
    switch (keycode) {
        case CK_QWRT:
            if (record->event.pressed) {
                set_single_persistent_default_layer(QWERTY);
            }
            return false;

        case CK_CLMK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(COLEMAK);
            }
            return false;

        case CK_PND:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_LSFT(SS_TAP(X_9)))); // Switch to UK
                SEND_STRING(SS_LSFT(SS_TAP(X_3)));
                SEND_STRING(SS_LALT(SS_LSFT(SS_TAP(X_8)))); // Switch back to US
            }
            return false;

        case CK_BSEL:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_LALT);
            } else {
                unregister_code(KC_LALT);
                unregister_code(KC_LSFT);
            }
            return false;
    }
    return true;
}

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [FUNCTIONS]  =  { ENCODER_CCW_CW(XXXXXXX,       TO(SYMBOLS)),    ENCODER_CCW_CW(_______,  _______) },
    [SYMBOLS]  =    { ENCODER_CCW_CW(TO(FUNCTIONS), TO(COLEMAK)),    ENCODER_CCW_CW(_______,  _______) },
    [COLEMAK] =     { ENCODER_CCW_CW(TO(SYMBOLS),   TO(NAVIGATION)), ENCODER_CCW_CW(_______,  _______) },
    [NAVIGATION]  = { ENCODER_CCW_CW(TO(COLEMAK),   XXXXXXX),        ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN) },
    [QWERTY] =      { ENCODER_CCW_CW(TO(SYMBOLS),   TO(NAVIGATION)), ENCODER_CCW_CW(FZ_LEFT,  FZ_RIGT), }
};
