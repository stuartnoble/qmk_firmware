
// LAYER TOGGLES
#define LT_FUNC LT(FUNCTIONS, KC_DEL)
#define LT_NUM  LT(NUMBERS, KC_TAB)
#define LT_LSYM  LT(SYMBOLS, KC_BSPC)
#define LT_RSYM  LT(SYMBOLS, KC_ENT)
#define LT_NAV  LT(NUMBERS, KC_SPC)
#define LT_MOUS LT(FUNCTIONS, KC_ESC)

// TAPDANCE
//#define TD_ENT ACTION_TAP_DANCE_FN(td_enter)

// // SHORTCUTS
// #define SC_CUT  LCTL(KC_X)
// #define SC_COPY LCTL(KC_C)
// #define SC_PSTE LCTL(KC_V)
// #define SC_SAVE LCTL(KC_S)

// DESKTOPS
// #define DT_SWTC LGUI(KC_TAB)
// #define DT_LEFT LCTL(LGUI(KC_LEFT))
// #define DT_RGHT LCTL(LGUI(KC_RIGHT))
// #define DT_APPS LALT(KC_SPC)

// FANCYZONES
#define FZ_LEFT MEH(KC_LEFT)
#define FZ_RIGT MEH(KC_RIGHT)

/* LEFT SIDE */

                            /* ╭────────┬────────┬────────┬────────┬────────┬────────╮          */
                            /* │        │   1    │   2    │   3    │   4    │   5    │          */
#define BASE_LH_TOP             XXXXXXX,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5
                            /* ├────────┼────────├────────┼────────┼────────┼────────┼────────┤ */ // Ends with thumb key
                            /*                   │        │        │  Del   │  Tab   │ BkSpc  │ */
#define BASE_LH_BOTTOM                            XXXXXXX, XXXXXXX, LT_FUNC, LT_NUM,  LT_LSYM
                            /*                   ╰────────┴────────┴────────┴────────┴────────╯ */

/* RIGHT SIDE */

                            /*          ╭────────┬────────┬────────┬────────┬────────┬────────╮ */
                            /*          │   6    │   7    │   8    │   9    │   0    │        │ */
#define BASE_RH_TOP                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX
                            /* ├────────┼────────┼────────┼────────┼────────┤────────┴────────╯ */ // Starts with thumb key
                            /* │ Space   Enter  ││ Esc    │        │        │                   */
#define BASE_RH_BOTTOM          LT_NAV,  LT_RSYM, LT_MOUS, XXXXXXX, XXXXXXX
                            /* ╰────────┴────────┴────────┴────────┴────────╯                   */

#define BASE_TOP            BASE_LH_TOP, BASE_RH_TOP
#define BASE_BOTTOM         BASE_LH_BOTTOM, BASE_RH_BOTTOM
