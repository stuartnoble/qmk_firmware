// MOD_TAP  
#define CM_HR_A KC_A
#define CM_HR_R LALT_T(KC_R)
#define CM_HR_S LSFT_T(KC_S)
#define CM_HR_T LCTL_T(KC_T)
#define CM_HR_G LGUI_T(KC_G)

/* LEFT SIDE */
                            /* ╭────────┬────────┬────────┬────────┬────────┬────────╮          */
                            /* │  ESC   │   1    │   2    │   3    │   4    │   5    │          */
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┤          */
                            /* │  Cut   │   Q    │   W    │   F    │   P    │   B    │          */
#define COLEMAK_LH_UPPER        SC_CUT,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B         
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┤          */
                            /* │  Copy  │   A    │ R/Alt  │ S/Shft │ T/Ctrl │ G/Cmd  │          */
#define COLEMAK_LH_HOME         SC_COPY, CM_HR_A, CM_HR_R, CM_HR_S, CM_HR_T, CM_HR_G         
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤ */ // Ends with encoder click
                            /* │ Paste  │   Z    │   X    │   C    │   D    │   V    │ QWERTY │ */
#define COLEMAK_LH_LOWER        SC_PSTE, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    CK_QWRT
                            /* ╰────────┴────────├────────┼────────┼────────┼────────┼────────┤ */ // Ends with thumb key
                            /*                   │  Save  │SYMBOLS │BlockSel│  NAV   │ Space  │ */
                            /*                   ╰────────┴────────┴────────┴────────┴────────╯ */

/* RIGHT SIDE */

#define CM_HR_M RGUI_T(KC_M)
#define CM_HR_N RCTL_T(KC_N)
#define CM_HR_E RSFT_T(KC_E)
#define CM_HR_I RALT_T(KC_I)
#define CM_HR_O KC_O

                            /*          ╭────────┬────────┬────────┬────────┬────────┬────────╮ */
                            /*          │   6    │   7    │   8    │   9    │   0    │ Bkspc  │ */   
                            /*          ├────────┼────────┼────────┼────────┼────────┼────────┤ */
                            /*          │   J    │   L    │   U    │   Y    │  : ;   │  _ -   │ */
#define COLEMAK_RH_UPPER                 KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_MINUS
                            /*          ├────────┼────────┼────────┼────────┼────────┼────────┤ */
                            /*          │ M/Cmd  │ N/Ctrl │ E/Shft │ I/Alt  │   O    │  ' "   │ */
#define COLEMAK_RH_HOME                  CM_HR_M, CM_HR_N, CM_HR_E, CM_HR_I, CM_HR_O, KC_QUOT
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤ */ // Starts with encoder click
                            /* │ Play   │   K    │   H    │  , <   │  . >   │  / ?   │ Apps   │ */
#define COLEMAK_RH_LOWER        KC_MPLY, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, DT_APPS   
                            /* ├────────┼────────┼────────┼────────┼────────┤────────┴────────╯ */         
                            /* │ Space  │SYMBOLS │PrevDesk│NextDesk│Desktops│                   */
                            /* ╰────────┴────────┴────────┴────────┴────────╯                   */

#define COLEMAK_UPPER       COLEMAK_LH_UPPER, COLEMAK_RH_UPPER
#define COLEMAK_HOME        COLEMAK_LH_HOME,  COLEMAK_RH_HOME
#define COLEMAK_LOWER       COLEMAK_LH_LOWER, COLEMAK_RH_LOWER

#define COLEMAK_LAYOUT      BASE_TOP,\
                            COLEMAK_UPPER, \
                            COLEMAK_HOME, \
                            COLEMAK_LOWER, \
                            BASE_BOTTOM
// New line otherwise multiline macro produce compile error