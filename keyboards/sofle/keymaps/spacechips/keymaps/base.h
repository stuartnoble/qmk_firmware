// LAYER TOGGLES
#define LT_FUNC LT(FUNCTIONS, KC_ENT)
#define LT_SYM  LT(SYMBOLS, KC_TAB)
#define LT_NAV  LT(NAVIGATION, KC_LSFT)

// SHORTCUTS
#define SC_CUT  LCTL(KC_X)
#define SC_COPY LCTL(KC_C)
#define SC_PSTE LCTL(KC_V)
#define SC_SAVE LCTL(KC_S)

// DESKTOPS
#define DT_SWTC LGUI(KC_TAB)
#define DT_LEFT LCTL(LGUI(KC_LEFT))
#define DT_RGHT LCTL(LGUI(KC_RIGHT))
#define DT_APPS LALT(KC_SPC)

// FANCYZONES
#define FZ_LEFT MEH(KC_LEFT)
#define FZ_RIGT MEH(KC_RIGHT)

/* LEFT SIDE */

                            /* ╭────────┬────────┬────────┬────────┬────────┬────────╮          */
                            /* │  Esc   │   1    │   2    │   3    │   4    │   5    │          */
#define BASE_LH_TOP             KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5         
                            /* ├────────┼────────├────────┼────────┼────────┼────────┼────────┤ */ // Ends with thumb key
                            /*                   │  Save  │BlockSel│  NAV   │SYMBOLS │ Space  │ */
#define BASE_LH_BOTTOM                            SC_SAVE, CK_BSEL, LT_NAV,  LT_SYM,  KC_SPC
                            /*                   ╰────────┴────────┴────────┴────────┴────────╯ */

/* RIGHT SIDE */
 
                            /*          ╭────────┬────────┬────────┬────────┬────────┬────────╮ */
                            /*          │   6    │   7    │   8    │   9    │   0    │ Bkspc  │ */   
#define BASE_RH_TOP                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC
                            /* ├────────┼────────┼────────┼────────┼────────┤────────┴────────╯ */ // Starts with thumb key
                            /* │ Space  │FUNCS   │PrevDesk│NextDesk│Desktops│                   */
#define BASE_RH_BOTTOM          KC_SPC,  LT_FUNC, DT_LEFT, DT_RGHT, DT_SWTC                  
                            /* ╰────────┴────────┴────────┴────────┴────────╯                   */

#define BASE_TOP            BASE_LH_TOP, BASE_RH_TOP
#define BASE_BOTTOM         BASE_LH_BOTTOM, BASE_RH_BOTTOM