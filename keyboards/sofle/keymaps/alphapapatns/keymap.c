/* Copyright 2023 Stuart Noble <sofle@stuartnoble.com>
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
#include "layers/layers.h"

// Helper macro to enable layer defines
#define MACRO_LAYOUT(...)      LAYOUT(__VA_ARGS__)

// Defines keymap layers
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [QWERTY]    = MACRO_LAYOUT(QWERTY_LAYOUT),
    [COLEMAK]   = MACRO_LAYOUT(COLEMAK_LAYOUT),
    [FUNCTIONS] = MACRO_LAYOUT(FUNCTIONS_LAYOUT),
    [NUMBERS]   = MACRO_LAYOUT(NUMBERS_LAYOUT),
    [SYMBOLS]   = MACRO_LAYOUT(SYMBOLS_LAYOUT),
    [SPARE]     = MACRO_LAYOUT(SPARE_LAYOUT)
};

enum combo_events {
    COMBO_EOL
  };

const uint16_t PROGMEM eol_combo[] = {KC_SPACE, KC_ENTER, COMBO_END};

combo_t key_combos[] = {
    [COMBO_EOL] = COMBO_ACTION(eol_combo)
};

// Process user key presses
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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

        case CK_BASE:
            if (record->event.pressed) {
                int base_layer = get_highest_layer(default_layer_state);
                layer_move(base_layer);
            }
            return false;

        // case CK_PND:
        //     if (record->event.pressed) {
        //         SEND_STRING(SS_LALT(SS_LSFT(SS_TAP(X_9)))); // Switch to UK
        //         SEND_STRING(SS_LSFT(SS_TAP(X_3)));
        //         SEND_STRING(SS_LALT(SS_LSFT(SS_TAP(X_8)))); // Switch back to US
        //     }
        //     return false;

        // case CK_BSEL:
        //     if (record->event.pressed) {
        //         register_code(KC_LSFT);
        //         register_code(KC_LALT);
        //     } else {
        //         unregister_code(KC_LALT);
        //         unregister_code(KC_LSFT);
        //     }
        //     return false;
    }
    return true;
}

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch(combo_index) {
      case COMBO_EOL:
        if (pressed) {
          tap_code16(UK_SCLN);
          tap_code16(KC_ENT);
        }
        break;
    }
  }

// Maps rotary encoder settings
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    // { left_encoder(scroll_left, scroll_right), right_encoder(scroll_left, scroll_right) }
    [QWERTY]    = { ENCODER_CCW_CW(TO(SYMBOLS), XXXXXXX),       ENCODER_CCW_CW(FZ_LEFT, FZ_RIGT)           },
    [COLEMAK]   = { ENCODER_CCW_CW(TO(SYMBOLS), XXXXXXX),       ENCODER_CCW_CW(FZ_LEFT, FZ_RIGT)           },
    [SYMBOLS]   = { ENCODER_CCW_CW(TO(NUMBERS), CK_BASE),       ENCODER_CCW_CW(_______,  _______)          },
    [NUMBERS]   = { ENCODER_CCW_CW(TO(FUNCTIONS), TO(SYMBOLS)), ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN) },
    [FUNCTIONS] = { ENCODER_CCW_CW(XXXXXXX, TO(NUMBERS)),       ENCODER_CCW_CW(_______,  _______)          },
    [SPARE]     = { ENCODER_CCW_CW(XXXXXXX, XXXXXXX),           ENCODER_CCW_CW(_______,  _______)          }
};
