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
#include "keymap_uk.h"
#include "oled.c"

#define MO_SYM  MO(_SYM)
#define MO_NAV  MO(_NAV)
#define DF_BASE DF(_BASE)
#define DF_CLMK DF(_CLMK)
#define DT_SWTC LGUI(KC_TAB)
#define DT_LEFT LCTL(LGUI(KC_LEFT))
#define DT_RGHT LCTL(LGUI(KC_RIGHT))
#define DT_APPS LALT(KC_SPC)
#define FZ_LEFT MEH(KC_LEFT)
#define FZ_RIGT MEH(KC_RIGHT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT(
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    DF_CLMK,
  MO_NAV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINUS,
  MO_SYM,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                            KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE,       KC_MPLY, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSPC,
                    DT_APPS, XXXXXXX, KC_LALT, KC_LSFT, KC_ENT,        KC_SPC,  KC_RSFT, DT_LEFT, DT_RGHT, DT_SWTC 
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
  _______, XXXXXXX, UK_GRV,  UK_TILD, UK_PND,  UK_PIPE, _______,       _______, XXXXXXX, UK_QUOT, UK_DQUO, UK_PLUS, UK_QUES, KC_DEL,
                    _______, _______, _______, _______, _______,       KC_TAB, _______, _______, _______, _______
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
  _______, KC_INS,  KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______,
  _______, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,                         XXXXXXX, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______,
  _______, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX, _______,       _______, XXXXXXX, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
                    _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
)
};

layer_state_t layer_state_set_user(layer_state_t state) {
   return update_tri_layer_state(state, _SYM, _NAV, _FUN);
}

#ifdef ENCODER_ENABLE

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_BASE] = { ENCODER_CCW_CW(FZ_LEFT,  FZ_RIGT),       ENCODER_CCW_CW(KC_VOLD,  KC_VOLU) },
    [_CLMK] = { ENCODER_CCW_CW(_______,  _______),       ENCODER_CCW_CW(_______,  _______) },
    [_SYM]  = { ENCODER_CCW_CW(_______,  _______),       ENCODER_CCW_CW(LCTL(KC_Z), LCTL(KC_Y)) },
    [_NAV]  = { ENCODER_CCW_CW(_______,  _______),       ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN) },
    [_FUN]  = { ENCODER_CCW_CW(_______,  _______),       ENCODER_CCW_CW(_______,  _______) }
};
#endif

#endif
