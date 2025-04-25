
/* LEFT SIDE */
#define CM_MODZ LGUI_T(KC_Z)
#define CM_MODX LALT_T(KC_X)
#define CM_MODC LCTL_T(KC_C)
#define CM_MODD LSFT_T(KC_D)

                            /* ╭────────┬────────┬────────┬────────┬────────┬────────╮          */
                            /* │        │   1    │   2    │   3    │   4    │   5    │          */
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┤          */
                            /* │        │   Q    │   W    │   F    │   P    │   B    │          */
#define COLEMAK_LH_UPPER        XXXXXXX, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┤          */
                            /* │        │   A    │   R    │   S    │   T    │   G    │          */
#define COLEMAK_LH_HOME         XXXXXXX, KC_A,    KC_R,    KC_S,    KC_T,    KC_G
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤ */ // Ends with encoder click
                            /* │        │ Z(Cmd) │ X(Alt) │ C(Ctlr)│ D(Shft)│   V    │ QWERTY │ */
#define COLEMAK_LH_LOWER        XXXXXXX, CM_MODZ, CM_MODX, CM_MODC, CM_MODD, KC_V,    CK_QWRT
                            /* ╰────────┴────────├────────┼────────┼────────┼────────┼────────┤ */ // Ends with thumb key
                            /*                   │        │        │ Del    │ BkSpc  │ Tab    │ */
                            /*                   ╰────────┴────────┴────────┴────────┴────────╯ */

/* RIGHT SIDE */
#define CM_MODH RSFT_T(KC_H)
#define CM_MOD1 LCTL_T(KC_COMM)
#define CM_MOD2 LALT_T(KC_DOT)
#define CM_MOD3 RGUI_T(KC_SLSH)

                            /*          ╭────────┬────────┬────────┬────────┬────────┬────────╮ */
                            /*          │   6    │   7    │   8    │   9    │   0    │        │ */
                            /*          ├────────┼────────┼────────┼────────┼────────┼────────┤ */
                            /*          │   J    │   L    │   U    │   Y    │  : ;   │        │ */
#define COLEMAK_RH_UPPER                 KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, XXXXXXX
                            /*          ├────────┼────────┼────────┼────────┼────────┼────────┤ */
                            /*          │   M    │   N    │   E    │   I    │   O    │        │ */
#define COLEMAK_RH_HOME                  KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    XXXXXXX
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤ */ // Starts with encoder click
                            /* │        │   K    │ H(Shft)│ ,(Ctrl)│ .(Alt) │ /(Cmd))│        │ */
#define COLEMAK_RH_LOWER        XXXXXXX, KC_K,    CM_MODH, CM_MOD1, CM_MOD2, CM_MOD3, XXXXXXX
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
// New line otherwise multiline macro produce compile error