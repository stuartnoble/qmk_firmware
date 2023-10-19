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

#ifdef UNICODEMAP_ENABLE
    #define UNICODE_KEY_MAC KC_LEFT_ALT
    #define UNICODE_KEY_LNX LCTL(LSFT(KC_U))
    #define UNICODE_KEY_WINC KC_RIGHT_ALT // Requires WinCompose (https://github.com/samhocevar/wincompose)
    #define UNICODE_SELECTED_MODES UNICODE_MODE_WINCOMPOSE, UNICODE_MODE_LINUX
    #define UNICODE_CYCLE_PERSIST true
    #define UNICODE_TYPE_DELAY 10 
#endif

#ifdef TAP_DANCE_ENABLE
    // Change "hold" time (default is 200 ms)
    // -- used for tap dance and other tap mods
    #undef TAPPING_TERM
    #define TAPPING_TERM 175
#endif

#ifdef ENCODER_ENABLE
    #define ENCODER_DIRECTION_FLIP
#endif

#ifdef OLED_ENABLE
    #define SPLIT_WPM_ENABLE
    #define SPLIT_OLED_ENABLE
#endif