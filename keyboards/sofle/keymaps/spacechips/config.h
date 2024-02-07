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
#pragma once

#define ENCODER_DIRECTION_FLIP

#undef ENCODER_RESOLUTION
#define ENCODER_RESOLUTION 4

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

#define TAPPING_FORCE_HOLD
#undef TAPPING_TERM
#define TAPPING_TERM 200

// #undef OLED_FONT_HEIGHT
// #define OLED_FONT_HEIGHT 8 // So we can align glyphs better = 16 lines