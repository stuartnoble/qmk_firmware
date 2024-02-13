/* LEFT SIDE */
                            /* ╭────────┬────────┬────────┬────────┬────────┬────────╮          */
                            /* │        │        │        │        │        │        │          */
#define SYMBOLS_LH_TOP          _______, _______, _______, _______, _______, _______
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┤          */
                            /* │        │   !    │   @    │   #    │   $    │   %    │          */
#define SYMBOLS_LH_UPPER        _______, KC_EXLM, KC_AT ,  KC_HASH, KC_DLR,  KC_PERC       
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┤          */
                            /* │        │   <    │   >    │   [    │   ]    │   \    │          */
#define SYMBOLS_LH_HOME         _______, KC_LABK, KC_RABK, KC_LBRC, KC_RBRC, KC_BSLS       
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤ */ // Ends with encoder click
                            /* │        │   |    │   `    │   ~    │   £    │        │        │ */
#define SYMBOLS_LH_LOWER        _______, KC_PIPE, KC_GRV,  KC_TILD, CK_PND,  XXXXXXX, _______
                            /* ╰────────┴────────├────────┼────────┼────────┼────────┼────────┤ */ // Ends with thumb key
                            /*                   │        │        │        │        │        │ */
#define SYMBOLS_LH_BOTTOM                         _______, _______, _______, _______, _______
                            /*                   ╰────────┴────────┴────────┴────────┴────────╯ */

/* RIGHT SIDE */

                            /*          ╭────────┬────────┬────────┬────────┬────────┬────────╮ */
                            /*          │        │        │        │        │        │        │ */ 
#define SYMBOLS_RH_TOP                   _______, _______, _______, _______, _______, _______  
                            /*          ├────────┼────────┼────────┼────────┼────────┼────────┤ */
                            /*          │   ^    │   &    │   *    │   +    │   =    │        │ */
#define SYMBOLS_RH_UPPER                 KC_CIRC, KC_AMPR, KC_ASTR, KC_PLUS, KC_EQL,  _______
                            /*          ├────────┼────────┼────────┼────────┼────────┼────────┤ */
                            /*          │   /    │   {    │   }    │   (    │   )    │        │ */
#define SYMBOLS_RH_HOME                  KC_SLSH, KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, _______
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤ */ // Starts with encoder click
                            /* │        │        │   '    │   ""   │   -    │   ?    │        │ */
#define SYMBOLS_RH_LOWER        _______, XXXXXXX, KC_QUOT, KC_DQUO, KC_MINS, KC_QUES, _______
                            /* ├────────┼────────┼────────┼────────┼────────┤────────┴────────╯ */         
                            /* │        │        │        │        │        │                   */
#define SYMBOLS_RH_BOTTOM       _______, _______, _______, _______, _______
                            /* ╰────────┴────────┴────────┴────────┴────────╯                   */

#define SYMBOLS_TOP         SYMBOLS_LH_TOP,    SYMBOLS_RH_TOP
#define SYMBOLS_UPPER       SYMBOLS_LH_UPPER,  SYMBOLS_RH_UPPER
#define SYMBOLS_HOME        SYMBOLS_LH_HOME,   SYMBOLS_RH_HOME
#define SYMBOLS_LOWER       SYMBOLS_LH_LOWER,  SYMBOLS_RH_LOWER
#define SYMBOLS_BOTTOM      SYMBOLS_LH_BOTTOM, SYMBOLS_RH_BOTTOM

#define SYMBOLS_LAYOUT      SYMBOLS_TOP,\
                            SYMBOLS_UPPER, \
                            SYMBOLS_HOME, \
                            SYMBOLS_LOWER, \
                            SYMBOLS_BOTTOM
// New line otherwise multiline macro produce compile error