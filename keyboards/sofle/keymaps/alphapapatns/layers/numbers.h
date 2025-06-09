/* LEFT SIDE */
/* MIRYOKU, CYAN */
                            /* ╭────────┬────────┬────────┬────────┬────────┬────────╮          */
                            /* │        │        │        │        │        │        │          */
#define NUMBERS_LH_TOP          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┤          */
                            /* │        │PageUp  │  Home  │   ↑    │  End   │        │          */
#define NUMBERS_LH_UPPER        XXXXXXX, KC_PGUP, KC_HOME, KC_UP,   KC_END,  XXXXXXX
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┤          */
                            /* │        │PageDn  │   ←    │   ↓    │   →    │        │          */
#define NUMBERS_LH_HOME         XXXXXXX, KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT,XXXXXXX
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤ */ // Ends with encoder click
                            /* │        │  Undo  │  Cut   │  Copy  │ Paste  │  Redo  │  Base  │ */
#define NUMBERS_LH_LOWER        XXXXXXX, KC_UNDO, KC_CUT,  KC_COPY, KC_PSTE, C(KC_Y), CK_BASE
                            /* ╰────────┴────────├────────┼────────┼────────┼────────┼────────┤ */ // Ends with thumb key
                            /*                   │        │        │        │        │        │ */
#define NUMBERS_LH_BOTTOM                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
                            /*                   ╰────────┴────────┴────────┴────────┴────────╯ */

/* RIGHT SIDE */
/* MIRYOKU, BLUE */
                            /*          ╭────────┬────────┬────────┬────────┬────────┬────────╮ */
                            /*          │        │        │        │        │        │        │ */
#define NUMBERS_RH_TOP                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
                            /*          ├────────┼────────┼────────┼────────┼────────┼────────┤ */
                            /*          │   +    │   7    │   8    │   9    │   *    │        │ */
#define NUMBERS_RH_UPPER                 KC_PPLS, KC_7,    KC_8,    KC_9,    KC_PAST, XXXXXXX
                            /*          ├────────┼────────┼────────┼────────┼────────┼────────┤ */
                            /*          │   -    │   4    │   5    │   6    │   /    │        │ */
#define NUMBERS_RH_HOME                  KC_PMNS, KC_4,    KC_5,    KC_6,    KC_PSLS, XXXXXXX
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤ */ // Starts with encoder click
                            /* │        │   0    │   1    │   2    │   3    │   .    │        │ */
#define NUMBERS_RH_LOWER        XXXXXXX, KC_0,    KC_1,    KC_2,    KC_3,    KC_PDOT, XXXXXXX
                            /* ├────────┼────────┼────────┼────────┼────────┤────────┴────────╯ */
                            /* │        │        │        │        │        │                   */
#define NUMBERS_RH_BOTTOM       XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX
                            /* ╰────────┴────────┴────────┴────────┴────────╯                   */

#define NUMBERS_TOP      NUMBERS_LH_TOP,    NUMBERS_RH_TOP
#define NUMBERS_UPPER    NUMBERS_LH_UPPER,  NUMBERS_RH_UPPER
#define NUMBERS_HOME     NUMBERS_LH_HOME,   NUMBERS_RH_HOME
#define NUMBERS_LOWER    NUMBERS_LH_LOWER,  NUMBERS_RH_LOWER
#define NUMBERS_BOTTOM   NUMBERS_LH_BOTTOM, NUMBERS_RH_BOTTOM

#define NUMBERS_LAYOUT   NUMBERS_TOP,   \
                         NUMBERS_UPPER, \
                         NUMBERS_HOME,  \
                         NUMBERS_LOWER, \
                         NUMBERS_BOTTOM
// New line otherwise multiline macros produce compile error
