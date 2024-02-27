#include "layers.h"

// Patches the layer glyph when the given layer is active
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

// Renders the glyph for active layers
void render_layers_glyph(void) {
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

// Callback function when layer states change
layer_state_t layer_state_set_user(layer_state_t state) {
  active_layers[SYMBOLS] = IS_LAYER_ON_STATE(state, SYMBOLS);
  active_layers[FUNCTIONS] = IS_LAYER_ON_STATE(state, FUNCTIONS);
  active_layers[NAVIGATION] = IS_LAYER_ON_STATE(state, NAVIGATION);
  active_layers[SPARE] = IS_LAYER_ON_STATE(state, SPARE);
  
  return state;
}