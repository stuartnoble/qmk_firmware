/* LEFT SIDE */
                            /* ╭────────┬────────┬────────┬────────┬────────┬────────╮          */
                            /* │        │        │        │        │        │        │          */
#define FUNCTIONS_LH_TOP        _______, _______, _______, _______, _______, _______
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┤          */
                            /* │        │ Insert │ PrtScr │        │        │        │          */
#define FUNCTIONS_LH_UPPER      _______, KC_INS,  KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX       
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┤          */
                            /* │        │MediaPrv│MediaPly│MediaNxt│        │        │          */
#define FUNCTIONS_LH_HOME       _______, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX       
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤ */ // Ends with encoder click
                            /* │        │ VolDn  │VolMute │ VolUp  │        │        │        │ */
#define FUNCTIONS_LH_LOWER      _______, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX, _______
                            /* ╰────────┴────────├────────┼────────┼────────┼────────┼────────┤ */ // Ends with thumb key
                            /*                   │        │        │        │        │        │ */
#define FUNCTIONS_LH_BOTTOM                       _______, _______, _______, _______, _______
                            /*                   ╰────────┴────────┴────────┴────────┴────────╯ */

/* RIGHT SIDE */

                            /*          ╭────────┬────────┬────────┬────────┬────────┬────────╮ */
                            /*          │        │        │        │        │        │Colemak │ */ 
#define FUNCTIONS_RH_TOP                 _______, _______, _______, _______, _______, CK_CLMK  
                            /*          ├────────┼────────┼────────┼────────┼────────┼────────┤ */
                            /*          │        │   F1   │   F2   │   F3   │   F4   │ QWERTY │ */
#define FUNCTIONS_RH_UPPER               XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   CK_QWRT
                            /*          ├────────┼────────┼────────┼────────┼────────┼────────┤ */
                            /*          │        │   F5   │   F6   │   F7   │   F8   │        │ */
#define FUNCTIONS_RH_HOME                XXXXXXX, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤ */ // Starts with encoder click
                            /* │        │        │   F9   │  F10   │   F11  │   F12  │        │ */
#define FUNCTIONS_RH_LOWER      _______, XXXXXXX, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______
                            /* ├────────┼────────┼────────┼────────┼────────┤────────┴────────╯ */         
                            /* │        │        │        │        │        │                   */
#define FUNCTIONS_RH_BOTTOM     _______, _______, _______, _______, _______
                            /* ╰────────┴────────┴────────┴────────┴────────╯                   */

#define FUNCTIONS_TOP       FUNCTIONS_LH_TOP,    FUNCTIONS_RH_TOP
#define FUNCTIONS_UPPER     FUNCTIONS_LH_UPPER,  FUNCTIONS_RH_UPPER
#define FUNCTIONS_HOME      FUNCTIONS_LH_HOME,   FUNCTIONS_RH_HOME
#define FUNCTIONS_LOWER     FUNCTIONS_LH_LOWER,  FUNCTIONS_RH_LOWER
#define FUNCTIONS_BOTTOM    FUNCTIONS_LH_BOTTOM, FUNCTIONS_RH_BOTTOM

#define FUNCTIONS_LAYOUT    FUNCTIONS_TOP,\
                            FUNCTIONS_UPPER, \
                            FUNCTIONS_HOME, \
                            FUNCTIONS_LOWER, \
                            FUNCTIONS_BOTTOM
// New line otherwise multiline macro produce compile error