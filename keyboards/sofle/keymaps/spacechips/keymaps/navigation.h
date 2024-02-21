/* LEFT SIDE */
                            /* ╭────────┬────────┬────────┬────────┬────────┬────────╮          */
                            /* │        │        │        │        │        │        │          */
#define NAVIGATION_LH_TOP       _______, _______, _______, _______, _______, _______
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┤          */
                            /* │        │  Esc   │   7    │   8    │   9    │        │          */
#define NAVIGATION_LH_UPPER     _______, KC_ESC,  KC_7,    KC_8,    KC_9,    XXXXXXX       
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┤          */
                            /* │        │  Tab   │   4    │   5    │   6    │        │          */
#define NAVIGATION_LH_HOME      _______, KC_TAB,  KC_4,    KC_5,    KC_6,    XXXXXXX      
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤ */ // Ends with encoder click
                            /* │        │   0    │   1    │   2    │   3    │        │        │ */
#define NAVIGATION_LH_LOWER     _______, KC_0,    KC_1,    KC_2,    KC_3,    XXXXXXX, _______
                            /* ╰────────┴────────├────────┼────────┼────────┼────────┼────────┤ */ // Ends with thumb key
                            /*                   │        │        │        │        │        │ */
#define NAVIGATION_LH_BOTTOM                      _______, _______, _______, _______, KC_LSFT
                            /*                   ╰────────┴────────┴────────┴────────┴────────╯ */

/* RIGHT SIDE */

                            /*          ╭────────┬────────┬────────┬────────┬────────┬────────╮ */
                            /*          │        │        │        │        │        │  Del   │ */ 
#define NAVIGATION_RH_TOP                _______, _______, _______, _______, _______, KC_DEL  
                            /*          ├────────┼────────┼────────┼────────┼────────┼────────┤ */
                            /*          │        │  Home  │   ↑    │  End   │  PgUp  │        │ */
#define NAVIGATION_RH_UPPER              XXXXXXX, KC_HOME, KC_UP,   KC_END,  KC_PGUP, _______
                            /*          ├────────┼────────┼────────┼────────┼────────┼────────┤ */
                            /*          │        │   ←    │   ↓    │   →    │  PgDn  │        │ */
#define NAVIGATION_RH_HOME               XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤ */ // Starts with encoder click
                            /* │        │        │ Bkspc  │ Enter  │  Del   │        │        │ */
#define NAVIGATION_RH_LOWER     _______, XXXXXXX, KC_BSPC, KC_ENT,  KC_DEL,  XXXXXXX, _______
                            /* ├────────┼────────┼────────┼────────┼────────┤────────┴────────╯ */         
                            /* │        │        │        │        │        │                   */
#define NAVIGATION_RH_BOTTOM    _______, _______, _______, _______, _______
                            /* ╰────────┴────────┴────────┴────────┴────────╯                   */

#define NAVIGATION_TOP      NAVIGATION_LH_TOP,    NAVIGATION_RH_TOP
#define NAVIGATION_UPPER    NAVIGATION_LH_UPPER,  NAVIGATION_RH_UPPER
#define NAVIGATION_HOME     NAVIGATION_LH_HOME,   NAVIGATION_RH_HOME
#define NAVIGATION_LOWER    NAVIGATION_LH_LOWER,  NAVIGATION_RH_LOWER
#define NAVIGATION_BOTTOM   NAVIGATION_LH_BOTTOM, NAVIGATION_RH_BOTTOM

#define NAVIGATION_LAYOUT   NAVIGATION_TOP,\
                            NAVIGATION_UPPER, \
                            NAVIGATION_HOME, \
                            NAVIGATION_LOWER, \
                            NAVIGATION_BOTTOM
// New line otherwise multiline macro produce compile error