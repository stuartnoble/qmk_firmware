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

// Matches the ordering of code_symbols
enum coding_keycodes {
    CL_EQUAL = SAFE_RANGE,   // ==
    CL_NOTEQ,                // !=
    CL_LMBDA,                // =>
    CL_EQLT,                 // <=
    CL_EQGT,                 // >=
    CL_BRACE,                // {}
    CL_PAREN,                // ()
    CL_INDEX,                // []
    CL_GNRIC                 // <>
};

static const char code_equal[] = "==";
static const char code_notequal[] = "!=";
static const char code_lambda[] = "=>";
static const char code_lessthan[] = "<=";
static const char code_greaterthan[] = ">=";
static const char code_braces[] = "{}";
static const char code_parens[] = "()";
static const char code_index[] = "[]";
static const char code_generic[] = "<>";

// Matches the ordering of coding_keycodes
static const char* const code_symbols[9] = {
    code_equal,
    code_notequal,
    code_lambda,
    code_lessthan,
    code_greaterthan,
    code_braces,
    code_parens,
    code_index,
    code_generic
};

// Get the keycode index by subtracting the base index value
static uint16_t get_code_index(uint16_t keycode) {
    return keycode - CL_EQUAL;
}