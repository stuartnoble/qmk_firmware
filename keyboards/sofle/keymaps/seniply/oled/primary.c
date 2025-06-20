#include QMK_KEYBOARD_H

#include "glyphs/layers.h"
#include "glyphs/keymaps.h"
#include "glyphs/modifiers.h"

// Main function to render the content to the primary OLED
// Returns false by default for use in oled_task_user
bool render_primary_oled(void) {
    oled_set_cursor(0, 3);
    render_layers_glyph();

    oled_set_cursor(0, 7);
    render_base_keymap_glyph();

    oled_set_cursor(0, 10);
    render_modifier_glyphs();

    oled_set_cursor(0, 14);
    render_capsword_glyph();

    return false;
}