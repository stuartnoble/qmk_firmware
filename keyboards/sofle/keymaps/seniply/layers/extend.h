/* LEFT SIDE */

#define OM_ALT  OSM(MOD_LALT)
#define OM_CMD  OSM(MOD_LGUI)
#define OM_SHFT OSM(MOD_LSFT)
#define OM_CTRL OSM(MOD_LCTL)
#define MO_FUNC MO(FUNCTIONS)
#define CM_EOL TD(TD_EOL)

                            /* ╭────────┬────────┬────────┬────────┬────────┬────────╮          */
                            /* │        │        │        │        │        │        │          */
#define EXTEND_LH_TOP            _______, _______, _______, _______, _______, _______
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┤          */
                            /* │        │        │        │        │        │        │          */
#define EXTEND_LH_UPPER          _______, KC_ESC, _______, KC_FIND, _______, KC_INS
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┤          */
                            /* │        │        │        │        │        │        │          */
#define EXTEND_LH_HOME           _______, OM_ALT, OM_CMD, OM_SHFT, OM_CTRL, KC_LCMD
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤ */ // Ends with encoder click
                            /* │        │  Undo  │  Cut   │  Copy    Paste  │  Redo  │  Base  │ */
#define EXTEND_LH_LOWER         _______, C(KC_Z), C(KC_V), C(KC_C), C(KC_V), C(KC_Y), CK_BASE
                            /* ╰────────┴────────├────────┼────────┼────────┼────────┼────────┤ */ // Ends with thumb key
                            /*                   │        │        │        │        │        │ */
#define EXTEND_LH_BOTTOM                           _______, _______, _______, _______, _______
                            /*                   ╰────────┴────────┴────────┴────────┴────────╯ */

/* RIGHT SIDE */
                            /*          ╭────────┬────────┬────────┬────────┬────────┬────────╮ */
                            /*          │        │        │        │        │        │        │ */
#define EXTEND_RH_TOP                     _______, _______, _______, _______, _______, _______
                            /*          ├────────┼────────┼────────┼────────┼────────┼────────┤ */
                            /*          │        │        │        │        │        │        │ */
#define EXTEND_RH_UPPER                   KC_PGUP, KC_HOME, KC_UP,  KC_END,   KC_LCAP, _______
                            /*          ├────────┼────────┼────────┼────────┼────────┼────────┤ */
                            /*          │        │        │        │        │        │        │ */
#define EXTEND_RH_HOME                    KC_PGDN, KC_LEFT, KC_DOWN,KC_RIGHT, KC_DEL, _______
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤ */ // Starts with encoder click
                            /* │        │        │        │        │        │        │        │ */
#define EXTEND_RH_LOWER          _______, CM_EOL, KC_BSPC, KC_TAB,  _______, _______, _______
                            /* ├────────┼────────┼────────┼────────┼────────┤────────┴────────╯ */
                            /* │        │        │        │        │        │                   */
#define EXTEND_RH_BOTTOM         KC_ENT, MO_FUNC, _______, _______, _______
                            /* ╰────────┴────────┴────────┴────────┴────────╯                   */

#define EXTEND_TOP      EXTEND_LH_TOP,    EXTEND_RH_TOP
#define EXTEND_UPPER    EXTEND_LH_UPPER,  EXTEND_RH_UPPER
#define EXTEND_HOME     EXTEND_LH_HOME,   EXTEND_RH_HOME
#define EXTEND_LOWER    EXTEND_LH_LOWER,  EXTEND_RH_LOWER
#define EXTEND_BOTTOM   EXTEND_LH_BOTTOM, EXTEND_RH_BOTTOM

#define EXTEND_LAYOUT   EXTEND_TOP,   \
                        EXTEND_UPPER, \
                        EXTEND_HOME,  \
                        EXTEND_LOWER, \
                        EXTEND_BOTTOM
// New line otherwise multiline macros produce compile error
