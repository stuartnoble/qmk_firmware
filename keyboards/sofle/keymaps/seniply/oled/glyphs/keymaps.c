#include "keymaps.h"

// Renders the base layer indicator glyph
void render_base_keymap_glyph(void) {
    int base_layer = get_highest_layer(default_layer_state);

    oled_write_raw_P(
        base_glyphs[base_layer],
        sizeof(base_glyphs[base_layer])
    );
}