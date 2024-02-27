#ifndef ENUMS_H
#define ENUMS_H

// Key mapping layers, defined in order they are indicated on the display
// (except QWERTY which interchanges with COLEMAK)
enum sofle_layers {
    QWERTY,
    COLEMAK,
    SYMBOLS,
    FUNCTIONS,
    NAVIGATION,
    SPARE
};

// Keycodes for custom key actions
enum custom_keycodes {
    CK_QWRT = SAFE_RANGE,
    CK_CLMK,
    CK_PND,
    CK_BSEL
};

#endif