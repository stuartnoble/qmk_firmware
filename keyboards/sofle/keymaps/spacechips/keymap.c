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
#include "oled.c"
#include "os_detection.h"

const uint32_t PROGMEM unicode_map[] = {
    [UC_GBP]  = 0x00A3 // £
};

// Tap dance
tap_dance_action_t tap_dance_actions[] = {
    [TD_LAMBDAFUNC] = ACTION_TAP_DANCE_DOUBLE(CODE_LAMBDA, CODE_LAMBDAFUNC)
};

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
    /*
    * QWERTY
    * ,-----------------------------------------.                    ,-----------------------------------------.
    * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  +   |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * | LGUI |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
    * |------+------+------+------+------+------|  Mute      |  Wake |------+------+------+------+------+------|
    * |LCtrl |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |Enter |
    * `-----------------------------------------/       /     \      \-----------------------------------------'
    *            | LAlt | Go   |MO(3) |MO(2) | /LShift /       \Space \  | TT(4)| Bspc |       | ESC |
    *            |      |      |      |      |/       /         \      \ |      |      |      |      |
    *            `----------------------------------'           '------''---------------------------'
    */

    [_QWERTY] = LAYOUT(
        KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,      KC_0,  KC_EQUAL,
        KC_LGUI,  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,      KC_P,  KC_MINUS,
        KC_TAB,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN,  KC_QUOT,
        KC_LCTL,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,   KC_WAKE, KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH,  KC_ENT,
                    KC_LALT, LALT(KC_SPC), MO(3), MO(2), KC_LSFT, KC_SPC, TT(4), KC_BSPC, XXXXXXX, KC_ESC
    ),

    /*
    * ENGRAM
    * ,-----------------------------------------.                    ,-----------------------------------------.
    * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | ESC  |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * | LGUI |   B  |   Y  |   O  |   U  |   '  |                    |   "  |   L  |   D  |   W  |   V  |  Z   |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * | TAB  |   C  |   I  |   E  |   A  |   ,  |-------.    ,-------|   .  |   H  |   T  |   S  |   N  |  Q   |
    * |------+------+------+------+------+------|  MUTE |    |  Wake |------+------+------+------+------+------|
    * |LCtrl |   G  |   X  |   J  |   K  |   ;  |-------|    |-------|   ?  |   R  |   M  |   F  |   P  |Enter |
    * `-----------------------------------------/       /     \      \-----------------------------------------'
    *            | LAlt |      | Go   |TT(3) | /LShift /       \Space \  |MO(2) | Bspc |       |     |
    *            |      |      |      |      |/       /         \      \ |      |      |      |      |
    *            `----------------------------------'           '------''---------------------------'
    */

    [_ENGRAM] = LAYOUT(
        KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,   KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_ESC,
        KC_LGUI,  KC_B,   KC_Y,    KC_O,    KC_U,   KC_QUOT,                   KC_DQUO, KC_L,    KC_D,    KC_W,    KC_V,    KC_Z,
        KC_TAB,   KC_C,   KC_I,    KC_E,    KC_A,   KC_COMM,                   KC_DOT,  KC_H,    KC_T,    KC_S,    KC_N,    KC_Q,
        KC_LCTL,  KC_G,   KC_X,    KC_J,    KC_K,   KC_SCLN, KC_MUTE, KC_WAKE, KC_QUES, KC_R,    KC_M,    KC_F,    KC_P,    KC_ENT,
                    KC_LALT, XXXXXXX, LALT(KC_SPC), TT(3), KC_LSFT, KC_SPC, MO(2), KC_BSPC, XXXXXXX, KC_ESC
    ),

    /* CODING
    * ,-----------------------------------------.                    ,-----------------------------------------.
    * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  |  F10 | F11  | F12  |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * | LGUI |   !  |   @  |   #  |   $  |   %  |                    |      |  ()  |   ==  |  <= |  >=  |      |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * | Tab  |   |  |      |      |      |   £  |-------.    ,-------|  =>  |  {}  |   !=  |     |      |      |
    * |------+------+------+------+------+------|  MUTE |    |  Wake |------+------+------+------+------+------|
    * | Shift|  =   |      |      |   ]  |      |-------|    |-------|      |  []  |  <>  |      |      |Enter |
    * `-----------------------------------------/       /     \      \-----------------------------------------'
    *            | LAlt |      | Go   |MO(4) | /LShift /       \Space \  |MO(2) | Bspc |       | ESC |
    *            |      |      |      |      |/       /         \      \ |      |      |      |      |
    *            `----------------------------------'           '------''---------------------------'
    */

    [_CODING] = LAYOUT(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                           KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,
        XXXXXXX, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                         KC_CIRC, CODE_PARENS, CODE_EQUAL, CODE_LESSTHAN,  CODE_GREATERTHAN,  KC_NO,
        XXXXXXX, KC_PIPE, XXXXXXX, KC_LCBR, KC_RCBR, UM(UC_GBP),                      CODE_LAMBDAFUNC, CODE_BRACES, CODE_NOTEQUAL, XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX, KC_BSLS, XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX,    XXXXXXX,    XXXXXXX, CODE_INDEX, CODE_GENERIC, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,
                                     XXXXXXX, XXXXXXX, XXXXXXX, MO(4), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    /* SYMBOLS
    * ,-----------------------------------------.                    ,-----------------------------------------.
    * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  |  F10 | F11  | F12  |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * | LGUI |   !  |   @  |   #  |   $  |   %  |                    |   ^  |   &  |   *  |   (  |   )  |  Z   |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * | Tab  |   |  |      |   {  |   }  |   £  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
    * |------+------+------+------+------+------|  MUTE |    |  Wake |------+------+------+------+------+------|
    * | Shift|  =   |      |  [   |   ]  |      |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |Enter |
    * `-----------------------------------------/       /     \      \-----------------------------------------'
    *            | LAlt |      | Go   |MO(4) | /LShift /       \Space \  |MO(2) | Bspc |       | ESC |
    *            |      |      |      |      |/       /         \      \ |      |      |      |      |
    *            `----------------------------------'           '------''---------------------------'
    */

    [_SYMBOLS] = LAYOUT(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                        KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,
        XXXXXXX, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN,  KC_RPRN,  KC_NO,
        XXXXXXX, KC_PIPE, XXXXXXX, KC_LCBR, KC_RCBR, UM(UC_GBP),                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX, KC_BSLS, XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,
                                     XXXXXXX, XXXXXXX, XXXXXXX, MO(4), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

//     /* NAV
//     * ,----------------------------------------.                    ,-----------------------------------------.
//     * |  `   |      |      |      |      |      |                    |      |      |      |      |      |      |
//     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
//     * | LGUI | Ins  | Pscr |      |      |      |                    | PgUp | PWrd |  Up  | NWrd | DLine|      |
//     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
//     * | Tab  | LAlt | LCtl |LShift|      |      |-------.    ,-------| PgDn | Left | Down | Right|      |      |
//     * |------+------+------+------+------+------|  MUTE  |   |  Wake |------+------+------+------+------+------|
//     * |LCtrl | Undo |  Cut | Copy | Paste|      |--------|   |-------|      | Home |      | End  |      |      |
//     * `-----------------------------------------/       /     \      \-----------------------------------------'
//     *            | LAlt |      | Go   |TT(3) | /LShift /       \Space \  |MO(4)| Del  |       | ESC |
//     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
//     *            `----------------------------------'           '------''---------------------------'
//  */

//     [_NAV] = LAYOUT(
//         XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                   XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX,       XXXXXXX,       XXXXXXX,
//         XXXXXXX, KC_INS,     KC_PSCR,    XXXXXXX,    XXXXXXX,    XXXXXXX,                   KC_PGUP, LCTL(KC_LEFT), KC_UP,   LCTL(KC_RGHT), LCTL(KC_BSPC), XXXXXXX,
//         XXXXXXX, KC_LALT,    KC_LCTL,    KC_LSFT,    XXXXXXX,    XXXXXXX,                   KC_PGDN, KC_LEFT,       KC_DOWN, KC_RGHT,       XXXXXXX,       XXXXXXX,
//         XXXXXXX, LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_HOME,     XXXXXXX, KC_END,        XXXXXXX,       XXXXXXX,
//                                        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),

    /*
    * MOUS
    * ,-----------------------------------------.                    ,-----------------------------------------.
    * |CTRL+W|ALT+A |      |      |      |      |                    |      |      |      |      |      |      |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * | TRNS |PRNTSC|      | M UP | HOME | PGUP |                    |M Wl U|M Wl D|M Wl L|M Wl R|      |      |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * | TRNS |SC LCK|M LFT |M DWN |M RGHT|      |-------.    ,-------|  UP  | DOWN | LEFT |RIGHT |      |      |
    * |------+------+------+------+------+------| TRNS  |    | TRNS  |------+------+------+------+------+------|
    * | TRNS |PAUSE |      |      | END  | PGDN |-------|    |-------|MOUS1 |MOUS2 |      |      |      |      |
    * `-----------------------------------------/       /     \      \-----------------------------------------'
    *            |      | TRNS | TRNS |TRNS  | / TRNS  /       \ TRNS \  |MOUS3 |MOUS4 |MOUS5 |      |
    *            |      |      |      |      |/       /         \      \ |      |      |      |      |
    *            `----------------------------------'           '------''---------------------------'
    */
    [_MOUSE] = LAYOUT(
        LCTL(KC_W), LALT(KC_A), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,
        _______,    KC_PSCR,    XXXXXXX, KC_MS_U, KC_HOME, KC_PGUP,                   KC_WH_U, KC_WH_D, KC_WH_L, KC_WH_R,  XXXXXXX, XXXXXXX,
        _______,    KC_SCRL,    KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, XXXXXXX, XXXXXXX,
        _______,    KC_PAUS,    XXXXXXX, XXXXXXX, KC_END,  KC_PGDN, _______, _______, KC_BTN1, KC_BTN2, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,
                                XXXXXXX, _______, _______, _______, _______, _______, KC_BTN3, KC_BTN4, KC_BTN5, XXXXXXX
    ),

    /* SYSTEM
    * ,----------------------------------------.                    ,-----------------------------------------.
    * |      |QWERTY|ENGRAM|      |      |      |                    |      |      |      |      |      | Sleep|
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |      |      |      |      |      |      | -------.   ,-------|      | Vol- | Mute | Vol+ |  Del |      |
    * |------+------+------+------+------+------|        |   |       |------+------+------+------+------+------|
    * |      |      |      |      |      |      |--------|   |-------|      | Prev | Play | Next |      | Wake |
    * |------+------+------+------+------+------/       /     \      \-----------------------------------------'
    *            | LAlt |      | Go   |TT(3) | /LShift /       \Space \  |MO(2) | Bspc |       | ESC |
    *            |      |      |      |      |/       /         \      \ |      |      |      |      |
    *            `----------------------------------'           '------''---------------------------'
    */

    [_SYSTEM] = LAYOUT(
    XXXXXXX, DF(_QWERTY), DF(_ENGRAM), XXXXXXX, XXXXXXX, XXXXXXX,                           XXXXXXX, XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX, KC_SLEP,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, KC_VOLD,   KC_MUTE,   KC_VOLU,   XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, KC_MPRV,   KC_MPLY,   KC_MNXT,   XXXXXXX, KC_WAKE,
                    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    )
};



// Configure encoders
#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return true;
}

#endif

static void create_space(void) {
    SEND_STRING(SS_TAP(X_LEFT) SS_TAP(X_ENTER) SS_TAP(X_ENTER) SS_TAP(X_UP));
}

// Process custom keycodes
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CODE_EQUAL:
            if (record->event.pressed) {
                SEND_STRING("== ");
            } 

            return false;

       case CODE_NOTEQUAL:
            if (record->event.pressed) {
                SEND_STRING("!= ");
            }

            return false; 

       case CODE_LAMBDA:
            if (record->event.pressed) {
                SEND_STRING("=> ");
            } 

            return false; 

        case CODE_LAMBDAFUNC:
            if (record->event.pressed) {
                SEND_STRING("() => {}");
            } else {
                create_space();
            }

            return false; 

       case CODE_LESSTHAN:
            if (record->event.pressed) {
                SEND_STRING("<= ");
            } 

            return false; 

       case CODE_GREATERTHAN:
            if (record->event.pressed) {
                SEND_STRING(">=");
            } 

            return false; 

       case CODE_PARENS:
            if (record->event.pressed) {
                SEND_STRING("()");
            } 

            return false; 

       case CODE_BRACES:
            if (record->event.pressed) {
                SEND_STRING("{}");
            } else {
                create_space();
            }

            return false; 

       case CODE_INDEX:
            if (record->event.pressed) {
                SEND_STRING("[]");
            } 

            return false; 
            
       case CODE_GENERIC:
            if (record->event.pressed) {
                SEND_STRING("<>");
            } 

            return false; 
    }

    return true;
};

// Setup unicode for host
void set_unicode_mode(void) {
    os_variant_t host_os = detected_host_os();

    // Set unicode_config.input_mode directly, rather than calling
    // set_unicode_input_mode, to avoid extra load on the EEPROMs.
    unicode_config.input_mode = (host_os == OS_WINDOWS ? UNICODE_MODE_WINCOMPOSE : UNICODE_MODE_LINUX);
}

// Initialise
void matrix_init_user(void) {
    set_unicode_mode();
}