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

#include "sofle-logo.c"
#include "decompress.c"
#include "glyphs/glyphs.h"

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

void patch_layers_glyph(int glyph_byte_index, int layer, char* output) {
    if (!active_layers[layer]) {
        return;
    }

    layer_glyph_patch_t glyph_patch = layers[layer];
    int patch_start_index = glyph_patch.patch_start_index;
    int patch_end_index = patch_start_index + glyph_patch.patch_size - 1;

    if (glyph_byte_index >= patch_start_index && glyph_byte_index <= patch_end_index) {
        output[glyph_byte_index] |= pgm_read_byte(glyph_patch.patch_bytes + (glyph_byte_index - patch_start_index));
    }
}

void render_layers_glyph(void){
    char output[128];
    
    for (int i = 0; i < 128; i++) {
        output[i] = pgm_read_byte(base_layer_glyph + i);

        patch_layers_glyph(i, SPARE, output);
        patch_layers_glyph(i, NAVIGATION, output);
        patch_layers_glyph(i, FUNCTIONS, output);
        patch_layers_glyph(i, SYMBOLS, output);
    }

    oled_write_raw(output, sizeof(output));
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

void render_status_primary(void) {
    bool isShifted = get_mods() & MOD_MASK_SHIFT;
    bool isCtrl = get_mods() & MOD_MASK_CTRL;
    bool isCommand = get_mods() & MOD_MASK_GUI;
    bool isAlt = get_mods() & MOD_MASK_ALT;

    int base_layer = get_highest_layer(default_layer_state);
    
    oled_set_cursor(0, 0);
    // oled_write_P(PSTR("13Feb"), false);

    // oled_set_cursor(0, 1);
    // oled_write_P(PSTR("16:07"), false);

    oled_set_cursor(0, 3);
    render_layers_glyph();

    oled_set_cursor(0, 7);
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

    oled_set_cursor(0, 10);
    render_modifier_glyphs(isShifted, isCtrl, isCommand, isAlt);

    oled_set_cursor(0, 14);
    render_capsword_glyph(is_capsword_on);
}

void render_status_secondary(void) {
    oled_write_compressed_P(logo);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status_primary();  
    } else {
        render_status_secondary();
    }

    return false;
}

#endif