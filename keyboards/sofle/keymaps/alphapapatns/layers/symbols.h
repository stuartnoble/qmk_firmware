#include "keymap_uk.h"

#define CM_DLR TD(TD_DLR)
#define CM_CBR TD(TD_CBR)
#define CM_PRN TD(TD_PRN)
#define CM_BRC TD(TD_BRC)

/* LEFT SIDE */
                            /* ╭────────┬────────┬────────┬────────┬────────┬────────╮          */
                            /* │        │        │        │        │        │        │          */
#define SYMBOLS_LH_TOP          _______, _______, _______, _______, _______, _______
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┤          */
                            /* │        │        │        │        │        │        │          */
#define SYMBOLS_LH_UPPER        _______, _______, _______, _______, _______, _______
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┤          */
                            /* │        │        │        │        │        │        │          */
#define SYMBOLS_LH_HOME         _______, _______, _______, _______, _______, _______
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤ */ // Ends with encoder click
                            /* │        │        │        │        │        │        │  Base  │ */
#define SYMBOLS_LH_LOWER        _______, _______, _______, _______, _______, _______, CK_BASE
                            /* ╰────────┴────────├────────┼────────┼────────┼────────┼────────┤ */ // Ends with thumb key
                            /*                   │        │        │        │        │        │ */
#define SYMBOLS_LH_BOTTOM                         _______, _______, _______, _______, _______
                            /*                   ╰────────┴────────┴────────┴────────┴────────╯ */

/* RIGHT SIDE */
                            /*          ╭────────┬────────┬────────┬────────┬────────┬────────╮ */
                            /*          │   ^    │   $    │   ~    │   `    │   %    │        │ */
#define SYMBOLS_RH_TOP                   UK_CIRC, CM_DLR,  UK_TILD, UK_GRV,  UK_PERC, XXXXXXX
                            /*          ├────────┼────────┼────────┼────────┼────────┼────────┤ */
                            /*          │   !    │   {    │   +    │   #    │   :    │        │ */
#define SYMBOLS_RH_UPPER                 UK_EXLM, CM_CBR,  UK_PLUS, UK_HASH, UK_COLN, XXXXXXX
                            /*          ├────────┼────────┼────────┼────────┼────────┼────────┤ */
                            /*          │   &    │   (    │   -    │   _    │   ;    │        │ */
#define SYMBOLS_RH_HOME                  UK_AMPR, CM_PRN,  UK_MINS, UK_UNDS, KC_SCLN, XXXXXXX
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤ */ // Starts with encoder click
                            /* │        │   \    │   [    │   =    │   *    │   |    │        │ */
#define SYMBOLS_RH_LOWER        _______, UK_BSLS, CM_BRC,  UK_EQL,  UK_ASTR, UK_PIPE, XXXXXXX
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
// New line otherwise multiline macros produce compile error
