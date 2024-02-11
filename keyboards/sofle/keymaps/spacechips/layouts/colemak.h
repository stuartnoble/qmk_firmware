/* LEFT SIDE */
                            /* ╭────────┬────────┬────────┬────────┬────────┬────────╮ */
                            /* │  ESC   │   1    │   2    │   3    │   4    │   5    │ */
#define _BASE_LH_TOP            KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┤ */
                            /* │  Cut   │   Q    │   W    │   F    │   P    │   B    │ */
#define _COLEMAK_LH_UPPER       SC_CUT,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┤ */
                            /* │  Copy  │ A/Shft │   R    │ S/Alt  │ T/Ctrl │ G/Cmd  │ */
#define _COLEMAK_LH_HOME        SC_COPY, MT_LS_A,  KC_R,   MT_LA_S, MT_LC_T, MT_LG_G
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤ */ // Ends with encoder click
                            /* │ Paste  │   Z    │   X    │   C    │   D    │   V    │  MUTE  │ */
#define _COLEMAK_LH_LOWER       SC_PSTE, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_MUTE
                            /*                   ├────────┼────────┼────────┼────────┼────────┤ */ // Ends with thumb key
                            /*                   │  Save  │SYMBOLS │BlockSel│  NAV   │ Space  │ */
#define _BASE_LH_BOTTOM                           SC_SAVE, LT_SYM,  CK_BSEL, LT_NAV,  KC_SPC
                            /*                   ╰────────┴────────┴────────┴────────┴────────╯ */


/* RIGHT SIDE */

                            /* ╭────────┬────────┬────────┬────────┬────────┬────────╮ */
                            /* │   6    │   7    │   8    │   9    │   0    │ Bkspc  │ */   
#define _BASE_RH_TOP            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┤ */
                            /* │   J    │   L    │   U    │   Y    │  : ;   │  _ -   │ */
#define _COLEMAK_RH_UPPER       KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_MINUS
  




# define _BASE_TOP_     _BASE_LH_TOP, _BASE_RH_TOP

 LAYOUT(
  _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
  _______, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                            KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, _______,
  _______, MT_LS_A, KC_R,    MT_LA_S, MT_LC_T, MT_LG_G,                         MT_RG_M, MT_RC_N, MT_RA_E, KC_I,    MT_RS_O, _______,
  _______, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    _______,       _______, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, _______,
                    _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
);