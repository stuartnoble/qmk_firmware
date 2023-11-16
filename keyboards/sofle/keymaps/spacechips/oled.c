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
//#include "animation.c"

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

static void primary_oled(void) {
    //display_os_logo();
    oled_set_cursor(0, 0);

    // Show current keyboard layout
    int base_layer = get_highest_layer(default_layer_state);
    int current_layer = get_highest_layer(layer_state);

    oled_write_P(PSTR("MODE"), false);
    oled_set_cursor(0, 1);
    switch (base_layer) {
        case _BASE:
            oled_write_P(PSTR("qwrty"), false);
            break;
        case _CLMK:
            oled_write_P(PSTR("colmk"), false);
            break;
        default:
            break;
    }
    
    oled_set_cursor(0, 3);
    oled_write_P(PSTR("LAYER"), false);

    oled_set_cursor(0, 4);
    switch (current_layer) {
        case _BASE:
        case _CLMK:
            oled_write_P(PSTR("Base "), false);
            break;
        case _SYM:
            oled_write_P(PSTR("!@#$%"), false);
            break;
        // case CODING:
        //     oled_write_P(PSTR("Code "), false);
        //     break;
        case _NAV:
            oled_write_P(PSTR("Nav  "), false);
            break;
        case _FUN:
            oled_write_P(PSTR("Func "), false);
            break;
        default:
            oled_write_P(PSTR("???  "), false);
    }

    oled_set_cursor(0, 6);
    oled_write_P(PSTR("WPM"), false);

    oled_set_cursor(0, 7);
    oled_write(get_u8_str(get_current_wpm(), '0'), false);
}

static void secondary_oled(void) {
    oled_set_cursor(0, 0);
    oled_write(get_u8_str(get_current_wpm(), '0'), false);
    //render_space();
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