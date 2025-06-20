#include "sofle-logo.c"
#include "decompress.c"

// Main function to render the content to the secondary OLED
// Returns false by default for use in oled_task_user
bool render_secondary_oled(void) {
    oled_write_compressed_P(logo);

    return false;
}