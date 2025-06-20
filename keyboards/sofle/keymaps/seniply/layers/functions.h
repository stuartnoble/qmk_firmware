/* LEFT SIDE */

#define CM_COPY C(S(KC_C))
#define CM_PSTE C(S(KC_C))


                            /* ╭────────┬────────┬────────┬────────┬────────┬────────╮          */
                            /* │        │        │        │        │        │        │          */
#define FUNCTIONS_LH_TOP        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┤          */
                            /* │        │        │        │        │        │        │          */
#define FUNCTIONS_LH_UPPER      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┤          */
                            /* │        │  Alt   │  Cmd   │ Shift  │  Ctrl  │        │          */
#define FUNCTIONS_LH_HOME       XXXXXXX, KC_LALT, KC_LCMD, KC_LSFT, KC_LCTL, XXXXXXX
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤ */ // Ends with encoder click
                            /* │        │        │        │ShftCopy│ShftPste│        │  Base  │ */
#define FUNCTIONS_LH_LOWER      XXXXXXX, XXXXXXX, XXXXXXX, CM_COPY, CM_PSTE, XXXXXXX, CK_BASE
                            /* ╰────────┴────────├────────┼────────┼────────┼────────┼────────┤ */ // Ends with thumb key
                            /*                   │        │        │        │        │ LftClk │ */
#define FUNCTIONS_LH_BOTTOM                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
                            /*                   ╰────────┴────────┴────────┴────────┴────────╯ */

/* RIGHT SIDE */
                            /*          ╭────────┬────────┬────────┬────────┬────────┬────────╮ */
                            /*          │        │        │        │        │        │        │ */
#define FUNCTIONS_RH_TOP                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
                            /*          ├────────┼────────┼────────┼────────┼────────┼────────┤ */
                            /*          │   F12  │   F7   │   F8   │   F9   │        │        │ */
#define FUNCTIONS_RH_UPPER               KC_F12,  KC_F7,   KC_F9,   KC_F9,    XXXXXXX, XXXXXXX
                            /*          ├────────┼────────┼────────┼────────┼────────┼────────┤ */
                            /*          │   F11  │   F4   │   F5   │   F6   │        │        │ */
#define FUNCTIONS_RH_HOME                KC_F11,  KC_F4,   KC_F6,   KC_F6,    XXXXXXX, XXXXXXX
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤ */ // Starts with encoder click
                            /* │        │   F10  │   F1   │   F2   │  F3    │        │        │ */
#define FUNCTIONS_RH_LOWER      XXXXXXX, KC_F10,  KC_F1,   KC_F2,   KC_F3,     XXXXXXX, XXXXXXX
                            /* ├────────┼────────┼────────┼────────┼────────┤────────┴────────╯ */
                            /* │        │        │        │        │        │                   */
#define FUNCTIONS_RH_BOTTOM     KC_ENT,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
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
