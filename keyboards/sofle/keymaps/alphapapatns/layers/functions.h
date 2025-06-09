/* LEFT SIDE */
/* MIRYOKU, YELLOW*/
                            /* ╭────────┬────────┬────────┬────────┬────────┬────────╮          */
                            /* │        │        │        │        │        │        │          */
#define FUNCTIONS_LH_TOP        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┤          */
                            /* │        │WheelUp │        │MouseUp │        │        │          */
#define FUNCTIONS_LH_UPPER      XXXXXXX, MS_WHLU, XXXXXXX, MS_UP,   XXXXXXX, XXXXXXX
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┤          */
                            /* │        │WheelDn │MouseLft│MouseDn │MouseRgt│        │          */
#define FUNCTIONS_LH_HOME       XXXXXXX, MS_WHLD, MS_LEFT, MS_DOWN, MS_RGHT, XXXXXXX
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤ */ // Ends with encoder click
                            /* │        │  Undo  │  Cut   │  Copy  │ Paste  │  Redo  │  Base  │ */
#define FUNCTIONS_LH_LOWER      XXXXXXX, KC_UNDO, KC_CUT,  KC_COPY, KC_PSTE, C(KC_Y), CK_BASE
                            /* ╰────────┴────────├────────┼────────┼────────┼────────┼────────┤ */ // Ends with thumb key
                            /*                   │        │        │MidlClk │RghtClk │ LftClk │ */
#define FUNCTIONS_LH_BOTTOM                       XXXXXXX, XXXXXXX, MS_BTN3, MS_BTN2, MS_BTN1
                            /*                   ╰────────┴────────┴────────┴────────┴────────╯ */

/* RIGHT SIDE */
/* MIRYOKU, RED*/
                            /*          ╭────────┬────────┬────────┬────────┬────────┬────────╮ */
                            /*          │        │        │        │        │        │        │ */
#define FUNCTIONS_RH_TOP                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
                            /*          ├────────┼────────┼────────┼────────┼────────┼────────┤ */
                            /*          │PrtScrn │   F7   │   F8   │   F9   │   F12  │        │ */
#define FUNCTIONS_RH_UPPER               KC_PSCR, KC_F7,   KC_F9,   KC_F9,   KC_F12,  XXXXXXX
                            /*          ├────────┼────────┼────────┼────────┼────────┼────────┤ */
                            /*          │ScrlLck │   F4   │   F5   │   F6   │   F11  │        │ */
#define FUNCTIONS_RH_HOME                KC_SCRL, KC_F4,   KC_F6,   KC_F6,   KC_F11,  XXXXXXX
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤ */ // Starts with encoder click
                            /* │        │PausBrk │   F1   │   F2   │  F3    │   F10  │        │ */
#define FUNCTIONS_RH_LOWER      XXXXXXX, KC_PAUS, KC_F1,   KC_F2,  KC_F3,    KC_F10,  XXXXXXX
                            /* ├────────┼────────┼────────┼────────┼────────┤────────┴────────╯ */
                            /* │        │        │        │        │        │                   */
#define FUNCTIONS_RH_BOTTOM     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
                            /* ╰────────┴────────┴────────┴────────┴────────╯                   */

#define FUNCTIONS_TOP       FUNCTIONS_LH_TOP,    FUNCTIONS_RH_TOP
#define FUNCTIONS_UPPER     FUNCTIONS_LH_UPPER,  FUNCTIONS_RH_UPPER
#define FUNCTIONS_HOME      FUNCTIONS_LH_HOME,   FUNCTIONS_RH_HOME
#define FUNCTIONS_LOWER     FUNCTIONS_LH_LOWER,  FUNCTIONS_RH_LOWER
#define FUNCTIONS_BOTTOM    FUNCTIONS_LH_BOTTOM, FUNCTIONS_RH_BOTTOM

#define FUNCTIONS_LAYOUT    FUNCTIONS_TOP,   \
                            FUNCTIONS_UPPER, \
                            FUNCTIONS_HOME,  \
                            FUNCTIONS_LOWER, \
                            FUNCTIONS_BOTTOM
// New line otherwise multiline macros produce compile error
