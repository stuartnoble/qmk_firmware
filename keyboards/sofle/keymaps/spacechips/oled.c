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

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

static void display_os_logo(void) {
    if (unicode_config.input_mode == UNICODE_MODE_LINUX) {
        oled_write_raw_P(linux_logo, 160);
    } else if (unicode_config.input_mode == UNICODE_MODE_WINCOMPOSE) {
        oled_write_raw_P(windows_logo, 128);
    } 
    else {
       oled_write_ln_P(PSTR("?????"), false);
    }
}

static void primary_oled(void) {
    int current_layer = get_highest_layer(layer_state);

    oled_set_cursor(0, 0);
    oled_write_P(PSTR("STATE"), true);

    // Show current keyboard mode
    oled_set_cursor(0, 2);
    oled_write_P(PSTR("TYPE:"), false);

    oled_set_cursor(0, 3);
    switch (current_layer) {
        case _QWERTY:
            oled_write_P(PSTR("QWRTY"), false);
            break;
        case _ENGRAM:
            oled_write_P(PSTR("ENGRM"), false);
            break;
        default:
            break;
    }
    
    oled_set_cursor(0, 5);
    oled_write_P(PSTR("MODE:"), false);

    oled_set_cursor(0, 6);
    switch (current_layer) {
        case _CODING:
            oled_write_P(PSTR("Code"), false);
            break;
        case _SYMBOLS:
            oled_write_P(PSTR("@$*&#"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("Nav  "), false);
            break;
        case _MOUSE:
            oled_write_P(PSTR("Mouse"), false);
            break;
        case _SYSTEM:
            oled_write_P(PSTR("Sys  "), false);
            break;
        default:
            oled_write_P(PSTR("Base "), false);
    }

    oled_set_cursor(0, 8);
    oled_write(get_u8_str(get_current_wpm(), '0'), false);
}

static void secondary_oled(void) {
    display_os_logo();
    
    oled_set_cursor(0, 8);
    oled_write(get_u8_str(get_current_wpm(), '0'), false);
}

 bool oled_task_user(void) {
    if (is_keyboard_master()) {
        primary_oled();
    } else {
        secondary_oled();
    }
    return false;
}

#endif