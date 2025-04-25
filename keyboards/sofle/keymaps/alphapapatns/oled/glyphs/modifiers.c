#include "modifiers.h"

// Renders glyphs to indicate when modifier keys are currently active
void render_modifier_glyphs(void) {
    bool is_shift_on = get_mods() & MOD_MASK_SHIFT;
    bool is_ctrl_on = get_mods() & MOD_MASK_CTRL;
    bool is_command_on = get_mods() & MOD_MASK_GUI;
    bool is_alt_on = get_mods() & MOD_MASK_ALT;

    // Provides the number of rows of modifier glyphs
    // Used by render_modifier_glyphs() to calculate glyph rendering
    const int MODIFIER_GLYPH_ROWS = 2;

    // Provides the number of bytes in a modifier glyph's row
    // Used by render_modifier_glyphs() to calculate glyph rendering
    const int MODIFIER_GLYPH_SIZE = 16;

    char glyph_buffer[128];
    
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

// Renders the caps word indicator
void render_capsword_glyph(void) {
    oled_write_raw_P(
        capsword_glyph[is_capsword_on],
        sizeof(capsword_glyph[is_capsword_on])
    );
}

// Callback functon when caps word is toggled
void caps_word_set_user(bool active) {
    is_capsword_on = active;
}