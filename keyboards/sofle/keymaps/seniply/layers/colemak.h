
/* LEFT SIDE */

                            /* ╭────────┬────────┬────────┬────────┬────────┬────────╮          */
                            /* │        │   1    │   2    │   3    │   4    │   5    │          */
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┤          */
                            /* │        │   Q    │   W    │   F    │   P    │   G    │          */
#define COLEMAK_LH_UPPER        XXXXXXX, KC_Q,    KC_W,    KC_F,    KC_P,    KC_G
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┤          */
                            /* │        │   A    │   R    │   S    │   T    │   D    │          */
#define COLEMAK_LH_HOME         XXXXXXX, KC_A,    KC_R,    KC_S,    KC_T,    KC_D
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤ */ // Ends with encoder click
                            /* │ Shift  │   Z    │    X   │   C    │   V    │   B    │ QWERTY │ */
#define COLEMAK_LH_LOWER        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    CK_QWRT
                            /* ╰────────┴────────├────────┼────────┼────────┼────────┼────────┤ */ // Ends with thumb key
                            /*                   │        │        │        │ BkSpc  │ Tab    │ */
                            /*                   ╰────────┴────────┴────────┴────────┴────────╯ */

/* RIGHT SIDE */
#define CM_QUOT TD(TD_QUOT)

                            /*          ╭────────┬────────┬────────┬────────┬────────┬────────╮ */
                            /*          │   6    │   7    │   8    │   9    │   0    │        │ */
                            /*          ├────────┼────────┼────────┼────────┼────────┼────────┤ */
                            /*          │   J    │   L    │   U    │   Y    │   '    │ Del    │ */
#define COLEMAK_RH_UPPER                 KC_J,    KC_L,    KC_U,    KC_Y,    CM_QUOT, KC_DEL
                            /*          ├────────┼────────┼────────┼────────┼────────┼────────┤ */
                            /*          │   H    │   N    │   E    │   I    │   O    │ Bkspc  │ */
#define COLEMAK_RH_HOME                  KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_BSPC
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤ */ // Starts with encoder click
                            /* │        │   K    │   M    │   ,    │   .    │   /    │        │ */
#define COLEMAK_RH_LOWER        XXXXXXX, KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX
                            /* ├────────┼────────┼────────┼────────┼────────┤────────┴────────╯ */
                            /* │ Enter  │ Space  │ Esc    │        │        │                   */
                            /* ╰────────┴────────┴────────┴────────┴────────╯                   */

#define COLEMAK_UPPER       COLEMAK_LH_UPPER, COLEMAK_RH_UPPER
#define COLEMAK_HOME        COLEMAK_LH_HOME,  COLEMAK_RH_HOME
#define COLEMAK_LOWER       COLEMAK_LH_LOWER, COLEMAK_RH_LOWER

#define COLEMAK_LAYOUT      BASE_TOP,      \
                            COLEMAK_UPPER, \
                            COLEMAK_HOME,  \
                            COLEMAK_LOWER, \
                            BASE_BOTTOM
// New line otherwise multiline macros produce compile error
