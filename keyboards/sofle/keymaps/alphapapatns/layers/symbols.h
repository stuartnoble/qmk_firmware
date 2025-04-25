#include "keymap_uk.h"

// ` ~ # & |    ^ { } [ ]
// ! " : = $    @ ( ) _ ;
// % £ * + \    / - < > ?

/* LEFT SIDE */
                            /* ╭────────┬────────┬────────┬────────┬────────┬────────╮          */
                            /* │        │        │        │        │        │        │          */
#define SYMBOLS_LH_TOP          _______, _______, _______, _______, _______, _______
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┤          */
                            /* │        │   `    │   ~    │   #    │   &    │   |    │          */
#define SYMBOLS_LH_UPPER        _______, UK_GRV,  UK_TILD, UK_HASH, UK_AMPR, UK_PIPE
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┤          */
                            /* │        │   !    │   "    │   :    │   =    │   $    │          */
#define SYMBOLS_LH_HOME         _______, UK_EXLM, UK_DQUO, UK_COLN, UK_EQL,  UK_DLR
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤ */ // Ends with encoder click
                            /* │        │   %    │   £    │   *    │   +    │   \    │  Base  │ */
#define SYMBOLS_LH_LOWER        _______, UK_PERC, UK_PND,  UK_ASTR, UK_PLUS, UK_BSLS, CK_BASE
                            /* ╰────────┴────────├────────┼────────┼────────┼────────┼────────┤ */ // Ends with thumb key
                            /*                   │        │        │        │        │        │ */
#define SYMBOLS_LH_BOTTOM                         _______, _______, _______, _______, _______
                            /*                   ╰────────┴────────┴────────┴────────┴────────╯ */

/* RIGHT SIDE */
                            /*          ╭────────┬────────┬────────┬────────┬────────┬────────╮ */
                            /*          │        │        │        │        │        │        │ */
#define SYMBOLS_RH_TOP                   _______, _______, _______, _______, _______, _______
                            /*          ├────────┼────────┼────────┼────────┼────────┼────────┤ */
                            /*          │   ^    │   {    │   }    │   [    │   ]    │        │ */
#define SYMBOLS_RH_UPPER                 UK_CIRC, UK_LCBR, UK_RCBR, UK_LBRC, UK_RBRC, _______
                            /*          ├────────┼────────┼────────┼────────┼────────┼────────┤ */
                            /*          │   @    │   (    │   )    │   _    │   ;    │        │ */
#define SYMBOLS_RH_HOME                  UK_AT,   UK_LPRN, UK_RPRN, UK_UNDS, UK_SCLN, _______
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤ */ // Starts with encoder click
                            /* │        │   /    │   -    │   <    │   >    │   ?    │        │ */
#define SYMBOLS_RH_LOWER        _______, UK_SLSH, UK_MINS, UK_LABK, UK_RABK, UK_QUES, _______
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
