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
#include "keycodes.h"
#include "oled.c"
#include "os_detection.h"
#include "coding.h"

const uint32_t PROGMEM unicode_map[] = {
    [UC_GBP]  = 0x00A3 // £
};

tap_dance_action_t tap_dance_actions[] = {
  [OSLAUNCH] = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, LALT(KC_SPC)),
  [RUNCODE] = ACTION_TAP_DANCE_DOUBLE(KC_F5, LCTL(KC_F5))
};

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
    
    // TODO: Consider using these:
    // https://github.com/qmk/qmk_firmware/blob/master/docs/feature_advanced_keycodes.md#alt--escape-for-alt--tab-idalt-escape-for-alt-tab
    // https://github.com/qmk/qmk_firmware/blob/master/docs/feature_grave_esc.md

    /*
    QWERTY
    Encoders move cursor
    ,-----------------------------------------.                    ,-----------------------------------------.
    |  ESC |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |   `  |
    |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    |<Dsktp|   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
    |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    |Dsktp>|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
    |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
    |   \  |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |  =   |
    `-----------------------------------------/       /     \      \-----------------------------------------'
               |RAISE |LCtrl |LAlt  |CODING| /LShift /       \RShift\  |LOWER | Bkspc| Del  |OS/   |
               |      |      |      |      |/ |Enter/         \|Space\ |      |      |      |Launch|
               `----------------------------------'           '------''----------------------------'
    */

    [QWERTY] = LAYOUT(
            KC_ESC,        KC_1, KC_2, KC_3, KC_4, KC_5,                    KC_6, KC_7, KC_8,    KC_9,   KC_0,    KC_GRV,
            LAG(KC_RIGHT), KC_Q, KC_W, KC_E, KC_R, KC_T,                    KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_MINUS,
            LAG(KC_LEFT),  KC_A, KC_S, KC_D, KC_F, KC_G,                    KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KC_QUOT,
            KC_BSLS,       KC_Z, KC_X, KC_C, KC_V, KC_B, XXXXXXX,  XXXXXXX, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_EQUAL,
         MO(RAISE), KC_LCTL, KC_LALT, MO(CODING),  LSFT_T(KC_ENTER), RSFT_T(KC_SPC), MO(LOWER), KC_BSPC, KC_DEL, TD(OSLAUNCH)
    ), // 0

    /*
    COLEMAK
    Encoders move cursor
    ,-----------------------------------------.                    ,-----------------------------------------.
    |  ESC |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |   `  |
    |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    |<Dsktp|   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   ;  |  -   |
    |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    |Dsktp>|   A  |   R  |   S  |   T  |   G  |-------.    ,-------|   M  |   N  |   E  |   I  |   O  |  '   |
    |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
    |   \  |   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,  |   .  |   /  |  =   |
    `-----------------------------------------/       /     \      \-----------------------------------------'
               |RAISE |LCtrl |LAlt  |CODING| /LShift /       \RShift\  |LOWER | Bkspc| Del  |OS/   |
               |      |      |      |      |/ |Enter/         \|Space\ |      |      |      |Launch|
               `----------------------------------'           '------''----------------------------'
    */

    [COLEMAK] = LAYOUT(
            KC_ESC,        KC_1, KC_2, KC_3, KC_4, KC_5,                    KC_6, KC_7, KC_8,    KC_9,   KC_0,    KC_GRV,
            LAG(KC_RIGHT), KC_Q, KC_W, KC_F, KC_P, KC_B,                    KC_M, KC_L, KC_U,    KC_Y,   KC_SCLN, KC_MINUS,
            LAG(KC_LEFT),  KC_A, KC_R, KC_S, KC_T, KC_G,                    KC_M, KC_N, KC_E,    KC_I,   KC_U,    KC_QUOT,
            KC_BSLS,       KC_Z, KC_X, KC_C, KC_D, KC_V, XXXXXXX,  XXXXXXX, KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_EQUAL,
         MO(RAISE), KC_LCTL, KC_LALT, MO(CODING),  LSFT_T(KC_ENTER), RSFT_T(KC_SPC), MO(LOWER), KC_BSPC, KC_DEL, TD(OSLAUNCH)
    ), // 1

    /* LOWER
    Encoders move cursor
    ,-----------------------------------------.                    ,-----------------------------------------.
    |  F1  |  F2  |  F3  |  F4  | F5   | F6   |                    |  F7  |  F8  |  F9  |  F10 | F11  | F12  |
    |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    |      |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |   `  |
    |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    |   £  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
    |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
    |      |Ctrl-Z|Ctrl-X|Ctrl-C|Ctrl-V|      |-------|    |-------|      |      |      |      |      |      |
    `-----------------------------------------/       /     \      \-----------------------------------------'
               |RAISE |LCtrl |LAlt  |CODING| /LShift /       \RShift\  |LOWER | Bkspc| Del  |OS/   |
               |      |      |      |      |/ |Enter/         \|Space\ |      |      |      |Launch|
               `----------------------------------'           '------''----------------------------'
    */

    [LOWER] = LAYOUT(
            KC_F1,   KC_F2,   KC_F3, KC_F4,   KC_F5,     KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
            XXXXXXX, KC_1,    KC_1,  KC_3,    KC_4,      KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
            UC_GBP,  KC_EXLM, KC_AT, KC_HASH, KC_DLR,    KC_PERC,                   KC_GRV,  KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
            XXXXXXX, KC_UNDO, KC_CUT, KC_COPY, KC_PASTE, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                     _______, _______, _______, _______,          _______, _______,       _______, _______, _______, _______
    ), // 2

    /* CODING
    ,-----------------------------------------.                    ,-----------------------------------------.
    |      |      |      |      |      |      |                    |      | F10  | F-11 |      |      |      |
    |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    |      |      |      |      |      |      |                    | F12  |  ==  |  <=  |  >=  |Ctrl-P|      |
    |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    |      |      |      |      |      |      |-------.    ,-------|CODERN|  {}  |  !=  |  =>  |Ctrl-T|      |
    |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
    |      |      |      |      |      |      |-------|    |-------| F1  |  []  |  <>  |   ()  |      |      |
    `-----------------------------------------/       /     \      \-----------------------------------------'
               |RAISE |LCtrl |LAlt  |CODING| /LShift /       \RShift\  |LOWER | Bkspc| Del  |OS/   |
               |      |      |      |      |/ |Enter/         \|Space\ |      |      |      |Launch|
               `----------------------------------'           '------''----------------------------'
    */

    [CODING] = LAYOUT(
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX,     KC_F10,   KC_F11,   XXXXXXX,  XXXXXXX,    XXXXXXX,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_F12,      CL_EQUAL, CL_EQLT,  CL_EQGT,  LCTL(KC_P), XXXXXXX,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   TD(RUNCODE), CL_BRACE, CL_NOTEQ, CL_LMBDA, LCTL(KC_T), XXXXXXX,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, KC_F1,       CL_INDEX, CL_GNRIC, CL_PAREN, XXXXXXX,    XXXXXXX,
                     _______, _______, _______,   _______,        _______, _______,       _______, _______, _______, _______
    ), // 3

    /* RAISE
    ,-----------------------------------------.                   ,-----------------------------------------.
    |      |      |      |      |      |      |                   | Home |      |      |      |      |      |
    |------+------+------+------+------+------|                   |------+------+------+------+------+------|
    |      |      |      |      |      |      |                   | End  | PWrd |  Up  | NWrd |      |      |
    |------+------+------+------+------+------|                   |------+------+------+------+------+------|
    |      |      |      |      |      |      |-------.   ,-------| PgUp | Left | Down | Right|      |      |
    |------+------+------+------+------+------|       |   |       |------+------+------+------+------+------|
    |      |      |      |      |      |      |-------|   |-------| PgDn |      |      |      |      |      |
    `-----------------------------------------/       /    \      \-----------------------------------------'
               |RAISE |LCtrl |LAlt  |CODING| /LShift /       \RShift\  |LOWER | Bkspc| Del  |OS/   |
               |      |      |      |      |/ |Enter/         \|Space\ |      |      |      |Launch|
               `----------------------------------'           '------''---------------------------'
 */

    [RAISE] = LAYOUT(
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_HOME, XXXXXXX,       XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_END,  LCTL(KC_LEFT), KC_UP,   LCTL(KC_RGHT), XXXXXXX, XXXXXXX,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_PGUP, KC_LEFT,       KC_DOWN, KC_RGHT,       XXXXXXX, XXXXXXX,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, KC_PGDN, XXXXXXX,       XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX,
                     _______, _______, _______,   _______,        _______, _______,       _______, _______, _______, _______
    ), // 4

    /* SYSTEM
    Accessed by tapping RAISE AND LOWER together
    ,----------------------------------------.                    ,-----------------------------------------.
    |      |      |      |      |      |      |                    | UC>  |QWERTY|ENGRAM|      |      | Sleep|
    |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    |      |      |      |      |      |      |                    |      |      |      |      |      | Wake |
    |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    |      |      |      |      |      |      | -------.   ,-------|      |      |      | Lock |      |      |
    |------+------+------+------+------+------|        |   |       |------+------+------+------+------+------|
    |      |      |      |      |      |      |--------|   |-------|      |      |      |      |      |      |
    |------+------+------+------+------+------/       /     \      \-----------------------------------------'
               |      |      |      |      | /       /       \      \  |      |      |       |     |
               |      |      |      |      |/       /         \      \ |      |      |      |      |
               `----------------------------------'           '------''---------------------------'
    */

    [SYSTEM] = LAYOUT(
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   UC_NEXT, DF(QWERTY), DF(COLEMAK), XXXXXXX,    XXXXXXX, KC_SLEP,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX,    XXXXXXX,     XXXXXXX,    XXXXXXX, KC_WAKE,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX,    XXXXXXX,     LGUI(KC_L), XXXXXXX, XXXXXXX,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,     XXXXXXX,    XXXXXXX, XXXXXXX,
                     _______, _______, _______,   _______,        _______, _______,       _______, _______, _______, _______
    ) // 6
};

// Configure encoders
#ifdef ENCODER_ENABLE

enum encoders {
    LEFT = 0,
    RIGHT
};

typedef struct encoder_config_s {
    uint8_t anticlockwise;
    uint8_t clockwise;
} encoder_config;

const encoder_config encoder_configs[] = {
    [0] = { KC_UP, KC_DOWN },
    [1] = { KC_LEFT, KC_RIGHT }
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    encoder_config active_encoder = encoder_configs[index];
    
    //switch (get_highest_layer(layer_state)) {

    uint16_t keycode = clockwise
        ? active_encoder.clockwise 
        : active_encoder.anticlockwise;

    tap_code(keycode);
    
    return false;
}

#endif

// Send some extra characters after the key is released
static void keyup_event(uint16_t keycode) {
    switch (keycode) {
        case CL_EQUAL:
        case CL_NOTEQ:
        case CL_LMBDA:
        case CL_EQLT:
        case CL_EQGT:
            SEND_STRING(SS_TAP(X_SPACE));
            break;
  
        case CL_BRACE:
            SEND_STRING(SS_TAP(X_LEFT) SS_TAP(X_ENTER) SS_TAP(X_ENTER) SS_TAP(X_UP));
            break;

        case CL_PAREN:
        case CL_INDEX:
        case CL_GNRIC:
            SEND_STRING(SS_TAP(X_LEFT));
            break;
    }    
}

// Process custom keycodes
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode >= CL_EQUAL && keycode <= CL_GNRIC) {
        if (record->event.pressed) {
            uint16_t symbol_index = get_code_index(keycode);
            send_string(code_symbols[symbol_index]);
        } else {
            keyup_event(keycode);
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