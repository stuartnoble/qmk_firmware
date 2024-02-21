// Key mapping layers, defined in or they are indicated on the display
// (except QWERTY which interchanges with COLEMAK)
enum sofle_layers {
    QWERTY,
    COLEMAK,
    SYMBOLS,
    FUNCTIONS,
    NAVIGATION,
    SPARE
};

enum custom_keycodes {
    CK_QWRT = SAFE_RANGE,
    CK_CLMK,
    CK_PND,
    CK_BSEL
};