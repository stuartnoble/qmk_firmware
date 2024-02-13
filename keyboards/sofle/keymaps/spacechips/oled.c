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

#include "logos.h"
#include "sofle-logo.c"
#include "decompress.c"
#include "glyphs/glyphs.h"

bool is_shift_on = 0;

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

// static void display_os_logo(void) {
//     oled_set_cursor(0, 0);

//     if (unicode_config.input_mode == UNICODE_MODE_LINUX) {
//         oled_write_raw_P(linux_logo, 160);
//     } else if (unicode_config.input_mode == UNICODE_MODE_WINCOMPOSE) {
//        oled_write_raw_P(windows_logo, 128);
//     } 
//     else {
//        oled_write_ln_P(PSTR("?????"), false);
//     }
// }

// static void primary_oled(void) {
//     //display_os_logo();
//     oled_set_cursor(0, 0);

//     // Show current keyboard layout
//     int base_layer = get_highest_layer(default_layer_state);
//     int current_layer = get_highest_layer(layer_state);

//     oled_write_P(PSTR("MODE"), false);
//     oled_set_cursor(0, 1);
//     switch (base_layer) {
//         case _BASE:
//             oled_write_P(PSTR("qwrty"), false);
//             break;
//         case _CLMK:
//             oled_write_P(PSTR("colmk"), false);
//             break;
//         default:
//             break;
//     }
    
//     oled_set_cursor(0, 3);
//     oled_write_P(PSTR("LAYER"), false);

//     oled_set_cursor(0, 4);
//     switch (current_layer) {
//         case _BASE:
//         case _CLMK:
//             oled_write_P(PSTR("Base "), false);
//             break;
//         case _SYM:
//             oled_write_P(PSTR("!@#$%"), false);
//             break;
//         // case CODING:
//         //     oled_write_P(PSTR("Code "), false);
//         //     break;
//         case _NAV:
//             oled_write_P(PSTR("Nav  "), false);
//             break;
//         case _FUN:
//             oled_write_P(PSTR("Func "), false);
//             break;
//         default:
//             oled_write_P(PSTR("???  "), false);
//     }

//     oled_set_cursor(0, 6);
//     oled_write_P(PSTR("WPM"), false);

//     oled_set_cursor(0, 7);
//     oled_write(get_u8_str(get_current_wpm(), '0'), false);
// }

//static void secondary_oled(void) {
//    oled_set_cursor(0, 0);
//    oled_write(get_u8_str(get_current_wpm(), '0'), false);
    //render_space();
//}

//  bool oled_task_user(void) {
//     //if (is_keyboard_master()) {
//         primary_oled(); 
//     //} else {
//     //    secondary_oled();
//     //}
//     return false;
// }

// void render_layer_state(void) {
//     static const char PROGMEM default_layer[] = {
//         0x20, 0x94, 0x95, 0x96, 0x20,
//         0x20, 0xb4, 0xb5, 0xb6, 0x20,
//         0x20, 0xd4, 0xd5, 0xd6, 0x20, 0};
//     static const char PROGMEM raise_layer[] = {
//         0x20, 0x97, 0x98, 0x99, 0x20,
//         0x20, 0xb7, 0xb8, 0xb9, 0x20,
//         0x20, 0xd7, 0xd8, 0xd9, 0x20, 0};
//     static const char PROGMEM lower_layer[] = {
//         0x20, 0x9a, 0x9b, 0x9c, 0x20,
//         0x20, 0xba, 0xbb, 0xbc, 0x20,
//         0x20, 0xda, 0xdb, 0xdc, 0x20, 0};
//     static const char PROGMEM adjust_layer[] = {
//         0x20, 0x9d, 0x9e, 0x9f, 0x20,
//         0x20, 0xbd, 0xbe, 0xbf, 0x20,
//         0x20, 0xdd, 0xde, 0xdf, 0x20, 0};
//     if(layer_state_is(_SYM)) {
//         oled_write_P(adjust_layer, false);
//     } else if(layer_state_is(_NAV)) {
//         oled_write_P(lower_layer, false);
//     } else if(layer_state_is(_FUN)) {
//         oled_write_P(raise_layer, false);
//     } else {
//         oled_write_P(default_layer, false);
//     }
// }

void render_layer_glyph(int current_layer) {
    //char glyph_buffer [128];

    return;
}

void render_modifier_glyphs(bool is_shift_on, bool is_ctrl_on, bool is_command_on, bool is_alt_on) {
    char glyph_buffer[128]; // Add a const for number of glyphs to calculate this
    
    for (int i = 0; i < MODIFIER_GLYPH_ROWS; i++) {
        for (int j = 0; j < MODIFIER_GLYPH_SIZE; j++) {
            int byte_index = (i * (MODIFIER_GLYPH_SIZE * 2)) + j; // MODIFIER_GLYPH_SIZE * 2 cos we have two glyphs per row

            // top row
            glyph_buffer[byte_index] = pgm_read_byte(shift_glyph[is_shift_on][i] + j);
            glyph_buffer[MODIFIER_GLYPH_SIZE + byte_index] = pgm_read_byte(ctrl_glyph[is_ctrl_on][i] + j);

            // bottom row
            glyph_buffer[64 + byte_index] = pgm_read_byte(command_glyph[is_command_on][i] + j);
            glyph_buffer[64 + MODIFIER_GLYPH_SIZE + byte_index] = pgm_read_byte(alt_glyph[is_alt_on][i] + j);
        }
    }

    oled_write_raw(glyph_buffer, sizeof(glyph_buffer));
}

void render_capsword_glyph(bool is_capsword_on) {
    oled_write_raw_P(capsword_glyph[is_capsword_on], sizeof(capsword_glyph[is_capsword_on]));
}

void render_base_layout(void) { 
    bool isShifted = get_mods() & MOD_MASK_SHIFT;
    bool isCtrl = get_mods() & MOD_MASK_CTRL;
    bool isCommand = get_mods() & MOD_MASK_GUI;
    bool isAlt = get_mods() & MOD_MASK_ALT;

    int base_layer = get_highest_layer(default_layer_state);
    
    oled_set_cursor(0, 0);
    oled_write_P(PSTR("13Feb"), false);

    oled_set_cursor(0, 1);
    oled_write_P(PSTR("16:07"), false);

    oled_set_cursor(0, 3);
    switch (base_layer) {
        case QWERTY:
            oled_write_raw_P(qwerty_glyph, sizeof(qwerty_glyph));
            break;
        case COLEMAK:
            oled_write_raw_P(colemak_glyph, sizeof(colemak_glyph));
            break;
        default:
            break;
    }

    oled_set_cursor(0, 5);
    int current_layer = get_highest_layer(layer_state);   
    render_layer_glyph(current_layer);

    oled_set_cursor(0, 10);
    render_modifier_glyphs(isShifted, isCtrl, isCommand, isAlt);

    oled_set_cursor(0, 14);
    render_capsword_glyph(is_capsword_on);
}

void render_status_primary(void) {
    render_base_layout();
}

void render_status_secondary(void) {
    oled_write_compressed_P(logo);
}

bool oled_task_user(void) {
//     if (timer_elapsed32(oled_timer) > 30000) {
//         oled_off();
//         return;
//     }
// #ifndef SPLIT_KEYBOARD
//     else { oled_on(); }
// #endif

    if (is_keyboard_master()) {
        render_status_primary();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_status_secondary();
    }

    return false;
}

#endif