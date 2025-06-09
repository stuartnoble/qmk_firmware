
// LAYER TOGGLES
#define LT_LSYM LT(SYMBOLS, KC_SPC)
#define LT_NAV  LT(NUMBERS, KC_SPC)

#define CM_CAD	LALT(LCTL(KC_DEL))

/* LEFT SIDE */

                            /* ╭────────┬────────┬────────┬────────┬────────┬────────╮          */
                            /* │ Esc    │   1    │   2    │   3    │   4    │   5    │          */
#define BASE_LH_TOP             KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5
                            /* ├────────┼────────├────────┼────────┼────────┼────────┼────────┤ */ // Ends with thumb key
                            /*                   │  Cut   │  Copy    Paste  │  Tab   │ Space  │ */
#define BASE_LH_BOTTOM                            C(KC_V), C(KC_C), C(KC_V), KC_TAB,  LT_LSYM
                            /*                   ╰────────┴────────┴────────┴────────┴────────╯ */

/* RIGHT SIDE */

                            /*          ╭────────┬────────┬────────┬────────┬────────┬────────╮ */
                            /*          │   6    │   7    │   8    │   9    │   0    │CtlAltDl│ */
#define BASE_RH_TOP                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    CM_CAD
                            /* ├────────┼────────┼────────┼────────┼────────┤────────┴────────╯ */ // Starts with thumb key
                            /* │ Space    Enter  │        │        │        │                   */
#define BASE_RH_BOTTOM          LT_NAV,  KC_ENT,  XXXXXXX, XXXXXXX, XXXXXXX
                            /* ╰────────┴────────┴────────┴────────┴────────╯                   */

#define BASE_TOP            BASE_LH_TOP, BASE_RH_TOP
#define BASE_BOTTOM         BASE_LH_BOTTOM, BASE_RH_BOTTOM
