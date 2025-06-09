#ifndef ENUMS_H
#define ENUMS_H

// Key mapping layers, defined in order they are indicated on the display
// (except QWERTY which interchanges with COLEMAK)
enum sofle_layers {
    QWERTY,
    COLEMAK,
    FUNCTIONS,
    NUMBERS,
    SYMBOLS,
    SPARE
};

// Keycodes for custom key actions
enum custom_keycodes {
    CK_QWRT = SAFE_RANGE,
    CK_CLMK,
    CK_BASE,
    CK_BSEL
};

// Keycodes for combos
enum combo_events {
    COMBO_EOL
};

// Keycodes for tapdance actions
enum tapdance_keycodes {
    TD_DLR,
    TD_PRN,
    TD_CBR,
    TD_BRC,
    TD_QUOT
};

#endif
