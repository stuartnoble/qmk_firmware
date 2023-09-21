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
enum _layers {
    _QWERTY,
    _ENGRAM,
    _CODING,
    _SYMBOLS,
    _NAV,
    _MOUSE,
    _SYSTEM,
};

enum unicode_keycodes {
    UC_GBP
};

enum coding_keycodes {
    CODE_EQUAL = SAFE_RANGE,        // ==
    CODE_NOTEQUAL,                  // !=
    CODE_LAMBDA ,                   // =>
    CODE_LAMBDAFUNC,                // () => {}
    CODE_LESSTHAN,                  // <=
    CODE_GREATERTHAN,               // >=
    CODE_PARENS,                    // ()
    CODE_BRACES,                    // {}
    CODE_INDEX,                     // []
    CODE_GENERIC                    // <>
};

enum tap_dance_keycodes {
    TD_LAMBDAFUNC                 // =>, () => {}
};