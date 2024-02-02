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

#include <stdio.h>

#include QMK_KEYBOARD_H
#include "enums.h"
#include "oled.c"

#define LT_NAV  LT(_NAV, KC_TAB)
#define LT_SYM  LT(_SYM, KC_ENT)

#define SC_CUT  LCTL(KC_X)
#define SC_COPY LCTL(KC_C)
#define SC_PSTE LCTL(KC_V)
#define SC_SAVE LCTL(KC_S)

#define DT_SWTC LGUI(KC_TAB)
#define DT_LEFT LCTL(LGUI(KC_LEFT))
#define DT_RGHT LCTL(LGUI(KC_RIGHT))
#define DT_APPS LALT(KC_SPC)

#define FZ_LEFT MEH(KC_LEFT)
#define FZ_RIGT MEH(KC_RIGHT)

//MOD_TAP COLEMAK 
#define MT_LS_A LSFT_T(KC_A)
#define MT_LA_S LALT_T(KC_S)
#define MT_LC_T LCTL_T(KC_T)
#define MT_LG_G LGUI_T(KC_G)
#define MT_RG_M RGUI_T(KC_M)
#define MT_RC_N RCTL_T(KC_N)
#define MT_RA_E RALT_T(KC_E)
#define MT_RS_O RSFT_T(KC_O)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT(
  KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  SC_CUT,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINUS,
  SC_COPY,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                             KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  SC_PSTE,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_MUTE,         KC_MPLY, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, DT_APPS,
                      SC_SAVE, LT_SYM,  CK_BSEL, LT_NAV, KC_SPC,          KC_SPC,  LT_SYM,  DT_LEFT, DT_RGHT, DT_SWTC 
),

[_CLMK] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
  _______, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                            KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, _______,
  _______, MT_LS_A, KC_R,    MT_LA_S, MT_LC_T, MT_LG_G,                         MT_RG_M, MT_RC_N, MT_RA_E, KC_I,    MT_RS_O, _______,
  _______, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    _______,       _______, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, _______,
                    _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),

[_SYM] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
  _______, KC_EXLM, KC_AT ,  KC_HASH, KC_DLR,  KC_PERC,                         KC_CIRC, KC_AMPR, KC_ASTR, KC_PLUS, KC_EQL,  _______,
  _______, KC_LABK, KC_RABK, KC_LBRC, KC_RBRC, KC_BSLS,                         KC_SLSH, KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, _______,
  _______, KC_PIPE, KC_GRV,  KC_TILD, CK_PND,  XXXXXXX, _______,       _______, XXXXXXX, KC_QUOT, KC_DQUO, KC_MINS, KC_QUES, _______,
                    _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),

[_NAV] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, KC_DEL,
  _______, KC_ESC,  KC_7,    KC_8,    KC_9,    XXXXXXX,                         XXXXXXX, KC_HOME, KC_UP,   KC_END,  KC_PGUP, _______,
  _______, KC_TAB,  KC_4,    KC_5,    KC_6,    XXXXXXX,                         XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______,
  _______, KC_0,    KC_1,    KC_2,    KC_3,    XXXXXXX, _______,       _______, XXXXXXX, KC_BSPC, KC_ENT,  KC_DEL,  XXXXXXX, _______,
                    _______, _______, _______, _______, KC_LSFT,       _______,  _______, _______, _______, _______
),

[_FUN] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, CK_CLMK,
  _______, KC_INS,  KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   CK_QWRT,
  _______, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,                         XXXXXXX, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______,
  _______, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX, _______,       _______, XXXXXXX, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
                    _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
)
};

layer_state_t layer_state_set_user(layer_state_t state) {
   return update_tri_layer_state(state, _SYM, _NAV, _FUN);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CK_QWRT:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_BASE);
            }
            return false;

        case CK_CLMK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_CLMK);
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

#ifdef ENCODER_ENABLE

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_BASE] = { ENCODER_CCW_CW(LCTL(KC_Z), LCTL(KC_Y)), ENCODER_CCW_CW(FZ_LEFT,  FZ_RIGT),        },
    [_CLMK] = { ENCODER_CCW_CW(_______,  _______),      ENCODER_CCW_CW(_______,  _______) },
    [_SYM]  = { ENCODER_CCW_CW(KC_VOLD,  KC_VOLU),      ENCODER_CCW_CW(_______,  _______) },
    [_NAV]  = { ENCODER_CCW_CW(_______,  _______),      ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN) },
    [_FUN]  = { ENCODER_CCW_CW(_______,  _______),      ENCODER_CCW_CW(_______,  _______) }
};
#endif

#endif
