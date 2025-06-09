
/* LEFT SIDE */
#define CM_MODA LGUI_T(KC_A)
#define CM_MODR LALT_T(KC_R)
#define CM_MODS LCTL_T(KC_S)
#define CM_MODT LSFT_T(KC_T)

                            /* ╭────────┬────────┬────────┬────────┬────────┬────────╮          */
                            /* │        │   1    │   2    │   3    │   4    │   5    │          */
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┤          */
                            /* │        │   Q    │   W    │   F    │   P    │   G    │          */
#define COLEMAK_LH_UPPER        XXXXXXX, KC_Q,    KC_W,    KC_F,    KC_P,    KC_G
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┤          */
                            /* │        │ A(Cmd) │ R(Alt) │S(Ctrl) │T(Shft) │   D    │          */
#define COLEMAK_LH_HOME         XXXXXXX, CM_MODA, CM_MODR, CM_MODS, CM_MODT, KC_D
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤ */ // Ends with encoder click
                            /* │ Shift  │   Z    │    X   │   C    │   V    │   B    │ QWERTY │ */
#define COLEMAK_LH_LOWER        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    CK_QWRT
                            /* ╰────────┴────────├────────┼────────┼────────┼────────┼────────┤ */ // Ends with thumb key
                            /*                   │        │        │        │ BkSpc  │ Tab    │ */
                            /*                   ╰────────┴────────┴────────┴────────┴────────╯ */

/* RIGHT SIDE */
#define CM_MODN RSFT_T(KC_N)
#define CM_MODE RCTL_T(KC_E)
#define CM_MODI RALT_T(KC_I)
#define CM_MODO RGUI_T(KC_O)
#define CM_QUOT TD(TD_QUOT)

                            /*          ╭────────┬────────┬────────┬────────┬────────┬────────╮ */
                            /*          │   6    │   7    │   8    │   9    │   0    │        │ */
                            /*          ├────────┼────────┼────────┼────────┼────────┼────────┤ */
                            /*          │   J    │   L    │   U    │   Y    │   '    │ Del    │ */
#define COLEMAK_RH_UPPER                 KC_J,    KC_L,    KC_U,    KC_Y,    CM_QUOT, KC_DEL
                            /*          ├────────┼────────┼────────┼────────┼────────┼────────┤ */
                            /*          │   H    │N(Shft) │E(Ctrl) │ I(Alt) │ O(Cmd) │ Bkspc  │ */
#define COLEMAK_RH_HOME                  KC_H,    CM_MODN, CM_MODE, CM_MODI, CM_MODO, KC_BSPC
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
