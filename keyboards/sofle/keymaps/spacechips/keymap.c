
 /* Copyright 2021 Dane Evans
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
  // SOFLE RGB
#include <stdio.h>

#include QMK_KEYBOARD_H
#include "enums.h"
#include "keymap_uk.h"
#include "oled.c"

// enum combos {
//   CB_ESC,
//   CB_TAB,
//   CB_BSPC,
//   CB_ENT,
//   CB_DEL,
// };

// const uint16_t PROGMEM combo_esc[]  = {KC_W, KC_E, COMBO_END};
// const uint16_t PROGMEM combo_tab[]  = {KC_X, KC_C, COMBO_END};
// const uint16_t PROGMEM combo_bspc[] = {KC_I, FI_O, COMBO_END};
// const uint16_t PROGMEM combo_ent[]  = {FI_COMM, FI_DOT, COMBO_END};
// const uint16_t PROGMEM combo_del[]  = {FI_DOT, FI_ADIA, COMBO_END};

// combo_t key_combos[COMBO_COUNT] = {
//   [CB_ESC]  = COMBO(combo_esc, KC_ESC),
//   [CB_TAB]  = COMBO(combo_tab, KC_TAB),
//   [CB_BSPC] = COMBO(combo_bspc, KC_BSPC),
//   [CB_ENT]  = COMBO(combo_ent, KC_ENT),
//   [CB_DEL]  = COMBO(combo_del, KC_DEL),
// };

#define MO_SYM  MO(_SYM)
#define MO_NAV  MO(_NAV)
#define DF_BASE DF(_BASE)
#define DF_CLMK DF(_CLMK)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT(
  XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    DF_CLMK,
  XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINUS,
  XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                            KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE,       KC_MPLY, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
                    KC_LALT, KC_LGUI, KC_LCTL, MO_SYM,  KC_SPC,        KC_SPC, MO_NAV,   KC_BSPC, XXXXXXX, XXXXXXX 
),

[_CLMK] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, DF_BASE,
  _______, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                            KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, _______,
  _______, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                            KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    _______,
  _______, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    _______,       _______, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, _______,
                    _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),

[_SYM] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
  _______, UK_EXLM, UK_AT,   UK_HASH, UK_DLR,  UK_PERC,                         UK_CIRC, UK_AMPR, UK_ASTR, UK_MINS, UK_EQL,  _______,
  _______, UK_LABK, UK_LCBR, UK_LBRC, UK_LPRN, UK_BSLS,                         UK_SLSH, UK_RPRN, UK_RBRC, UK_RCBR, UK_RABK, _______,
  _______, XXXXXXX, UK_GRV,  UK_TILD, UK_PND,  UK_PIPE, _______,       _______, XXXXXXX, UK_QUOT, UK_DQUO, UK_PLUS, UK_QUES, _______,
                    _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),

[_NAV] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
  _______, KC_ESC,  UK_7,    UK_8,    UK_9,    XXXXXXX,                         XXXXXXX, KC_HOME, KC_UP,   KC_END,  KC_PGUP, _______,
  _______, KC_TAB,  UK_4,    UK_5,    UK_6,    XXXXXXX,                         XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______,
  _______, UK_0,    UK_1,    UK_2,    UK_3,    XXXXXXX, _______,       _______, XXXXXXX, KC_BSPC, KC_ENT,  KC_DEL,  XXXXXXX, _______,
                    _______, _______, _______, _______, KC_LSFT,       _______, _______, _______, _______, _______
),

[_FUN] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
  _______, KC_F10,  KC_F7,   KC_F8,   KC_F9,   XXXXXXX,                         XXXXXXX, KC_INS,  KC_PSCR, XXXXXXX, XXXXXXX, _______,
  _______, KC_F11,  KC_F4,   KC_F5,   KC_F6,   XXXXXXX,                         XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, _______,
  _______, KC_F12,  KC_F1,   KC_F2,   KC_F3,   XXXXXXX, _______,       RGB_TOG, XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, _______,
                    _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
)
};

layer_state_t layer_state_set_user(layer_state_t state) {
   return update_tri_layer_state(state, _SYM, _NAV, _FUN);
}

#ifdef ENCODER_ENABLE

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_BASE] = { ENCODER_CCW_CW(KC_VOLD,  KC_VOLU),       ENCODER_CCW_CW(KC_PGUP,  KC_PGDN) },
    [_CLMK] = { ENCODER_CCW_CW(_______,  _______),       ENCODER_CCW_CW(_______,  _______) },
    [_SYM]  = { ENCODER_CCW_CW(_______,  _______),       ENCODER_CCW_CW(S(KC_TAB), KC_TAB) },
    [_NAV]  = { ENCODER_CCW_CW(LCTL(KC_Z), LCTL(KC_Y)),  ENCODER_CCW_CW(_______,  _______) },
    [_FUN]  = { ENCODER_CCW_CW(_______,  _______),       ENCODER_CCW_CW(_______,  _______) }
};
#endif

#endif
