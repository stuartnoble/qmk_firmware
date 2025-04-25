/* LEFT SIDE */
#define QW_MODZ LGUI_T(KC_Z)
#define QW_MODX LALT_T(KC_X)
#define QW_MODC LCTL_T(KC_C)
#define QW_MODV LSFT_T(KC_V)

                            /* ╭────────┬────────┬────────┬────────┬────────┬────────╮          */
                            /* │        │   1    │   2    │   3    │   4    │   5    │          */
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┤          */
                            /* │        │   Q    │   W    │   E    │   R    │   T    │          */
#define QWERTY_LH_UPPER         XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┤          */
                            /* │        │   A    │   S    │   D    │   F    │   G    │          */
#define QWERTY_LH_HOME          XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤ */ // Ends with encoder click
                            /* │        │ Z(Cmd) │  X(Alt)│ C(Ctrl)│ V(Shft)│   B    │COLEMAK │ */
#define QWERTY_LH_LOWER         XXXXXXX, QW_MODZ, QW_MODX, QW_MODC, QW_MODV, KC_B,    CK_CLMK
                            /* ╰────────┴────────├────────┼────────┼────────┼────────┼────────┤ */ // Ends with thumb key
                            /*                   │        │        │ Del    │ BkSpc  │ Tab    │ */
                            /*                   ╰────────┴────────┴────────┴────────┴────────╯ */

/* RIGHT SIDE */
#define QW_MODM RSFT_T(KC_M)
#define QW_MOD1 LCTL_T(KC_COMM)
#define QW_MOD2 LALT_T(KC_DOT)
#define QW_MOD3 RGUI_T(KC_SLASH)

                            /*          ╭────────┬────────┬────────┬────────┬────────┬────────╮ */
                            /*          │   6    │   7    │   8    │   9    │   0    │        │ */
                            /*          ├────────┼────────┼────────┼────────┼────────┼────────┤ */
                            /*          │   Y    │   U    │   I    │   O    │   P    │        │ */
#define QWERTY_RH_UPPER                  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    XXXXXXX
                            /*          ├────────┼────────┼────────┼────────┼────────┼────────┤ */
                            /*          │   H    │   J    │   K    │   L    │   ;    │        │ */
#define QWERTY_RH_HOME                   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, XXXXXXX
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤ */ // Starts with encoder click
                            /* │        │   N    │ M(Shft)│ ,(Ctrl)│ .(Alt) │ /(Cmd) │        │ */
#define QWERTY_RH_LOWER         XXXXXXX, KC_N,    QW_MODM, QW_MOD1, QW_MOD2, QW_MOD3, XXXXXXX
                            /* ├────────┼────────┼────────┼────────┼────────┤────────┴────────╯ */
                            /* │ Enter  │ Space  │ Esc    │        │        │                   */
                            /* ╰────────┴────────┴────────┴────────┴────────╯                   */

#define QWERTY_UPPER        QWERTY_LH_UPPER, QWERTY_RH_UPPER
#define QWERTY_HOME         QWERTY_LH_HOME,  QWERTY_RH_HOME
#define QWERTY_LOWER        QWERTY_LH_LOWER, QWERTY_RH_LOWER

#define QWERTY_LAYOUT       BASE_TOP,     \
                            QWERTY_UPPER, \
                            QWERTY_HOME,  \
                            QWERTY_LOWER, \
                            BASE_BOTTOM
// New line otherwise multiline macro produce compile error