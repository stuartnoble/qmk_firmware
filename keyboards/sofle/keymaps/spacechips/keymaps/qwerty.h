// MOD_TAP  
#define QW_HR_A KC_A
#define QW_HR_S LALT_T(KC_S)
#define QW_HR_D LSFT_T(KC_D)
#define QW_HR_F LCTL_T(KC_F)
#define QW_HR_G LGUI_T(KC_G)

/* LEFT SIDE */
                            /* ╭────────┬────────┬────────┬────────┬────────┬────────╮          */
                            /* │  ESC   │   1    │   2    │   3    │   4    │   5    │          */
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┤          */
                            /* │  Cut   │   Q    │   W    │   E    │   R    │   T    │          */
#define QWERTY_LH_UPPER         SC_CUT,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T         
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┤          */
                            /* │  Copy  │   A    │ S/Alt  │ D/Shft │ F/Ctrl │ G/Cmd  │          */
#define QWERTY_LH_HOME          SC_COPY, QW_HR_A, QW_HR_S, QW_HR_D, QW_HR_F, QW_HR_G         
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤ */ // Ends with encoder click
                            /* │ Paste  │   Z    │   X    │   C    │   V    │   B    │COLEMAK │ */
#define QWERTY_LH_LOWER         SC_PSTE, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    CK_CLMK
                            /* ╰────────┴────────├────────┼────────┼────────┼────────┼────────┤ */ // Ends with thumb key
                            /*                   │  Save  │SYMBOLS │BlockSel│  NAV   │ Space  │ */
                            /*                   ╰────────┴────────┴────────┴────────┴────────╯ */

/* RIGHT SIDE */

#define QW_HR_H  LGUI_T(KC_H)
#define QW_HR_J  RCTL_T(KC_J)
#define QW_HR_K  RSFT_T(KC_K)
#define QW_HR_L  LALT_T(KC_L)
#define QW_HR_SC KC_SCLN

                            /*          ╭────────┬────────┬────────┬────────┬────────┬────────╮ */
                            /*          │   6    │   7    │   8    │   9    │   0    │ Bkspc  │ */   
                            /*          ├────────┼────────┼────────┼────────┼────────┼────────┤ */
                            /*          │   Y    │   U    │   I    │   O    │   P    │  _ -   │ */
#define QWERTY_RH_UPPER                  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINUS
                            /*          ├────────┼────────┼────────┼────────┼────────┼────────┤ */
                            /*          │ H/Cmd  │ J/Ctrl │ K/Shft │ L/Alt  │  : ;   │  ' "   │ */
#define QWERTY_RH_HOME                   QW_HR_H, QW_HR_J, QW_HR_K, QW_HR_L, QW_HR_SC,KC_QUOT
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤ */ // Starts with encoder click
                            /* │ Play   │   K    │   H    │  , <   │  . >   │  / ?   │ Apps   │ */
#define QWERTY_RH_LOWER         KC_MPLY, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, DT_APPS   
                            /* ├────────┼────────┼────────┼────────┼────────┤────────┴────────╯ */         
                            /* │ Space  │SYMBOLS │PrevDesk│NextDesk│Desktops│                   */
                            /* ╰────────┴────────┴────────┴────────┴────────╯                   */

#define QWERTY_UPPER        QWERTY_LH_UPPER, QWERTY_RH_UPPER
#define QWERTY_HOME         QWERTY_LH_HOME,  QWERTY_RH_HOME
#define QWERTY_LOWER        QWERTY_LH_LOWER, QWERTY_RH_LOWER

#define QWERTY_LAYOUT       BASE_TOP,\
                            QWERTY_UPPER, \
                            QWERTY_HOME, \
                            QWERTY_LOWER, \
                            BASE_BOTTOM
// New line otherwise multiline macro produce compile error