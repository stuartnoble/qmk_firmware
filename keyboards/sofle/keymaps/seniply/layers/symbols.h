#include "keymap_uk.h"

#define CM_DLR TD(TD_DLR)
// #define CM_CBR TD(TD_CBR)
// #define CM_PRN TD(TD_PRN)
// #define CM_BRC TD(TD_BRC)

#define MO_NUMS MO(NUMBERS)

/* LEFT SIDE */
                            /* ╭────────┬────────┬────────┬────────┬────────┬────────╮          */
                            /* │        │        │        │        │        │        │          */
#define SYMBOLS_LH_TOP          _______, _______, _______, _______, _______, _______
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┤          */
                            /* │        │   !    │        │   #    │   $    │   %    │          */
#define SYMBOLS_LH_UPPER        _______, UK_EXLM, UK_AT,   UK_HASH, CM_DLR,  UK_PERC
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┤          */
                            /* │        │  Alt   │  Cmd   │ Shift  │  Ctrl  │   ^    │          */
#define SYMBOLS_LH_HOME         XXXXXXX, KC_LALT, KC_LCMD, KC_LSFT, KC_LCTL, UK_CIRC
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤ */ // Ends with encoder click
                            /* │        │        │        │   \    │   |    │   &    │  Base  │ */
#define SYMBOLS_LH_LOWER        _______, _______, _______, UK_BSLS,  UK_PIPE, UK_AMPR, CK_BASE
                            /* ╰────────┴────────├────────┼────────┼────────┼────────┼────────┤ */ // Ends with thumb key
                            /*                   │        │        │        │        │        │ */
#define SYMBOLS_LH_BOTTOM                         _______, _______, _______, _______, MO_NUMS
                            /*                   ╰────────┴────────┴────────┴────────┴────────╯ */

/* RIGHT SIDE */
                            /*          ╭────────┬────────┬────────┬────────┬────────┬────────╮ */
                            /*          │        │        │        │        │        │        │ */
#define SYMBOLS_RH_TOP                   _______, _______, _______ ,_______, _______, XXXXXXX
                            /*          ├────────┼────────┼────────┼────────┼────────┼────────┤ */
                            /*          │   =    │   `    │   :    │   ;    │    +   │        │ */
#define SYMBOLS_RH_UPPER                  UK_EQL,  UK_GRV, UK_COLN, KC_SCLN, UK_PLUS, XXXXXXX
                            /*          ├────────┼────────┼────────┼────────┼────────┼────────┤ */
                            /*          │  *     │   (    │   {    |   [    │  -     │        │ */
#define SYMBOLS_RH_HOME                  UK_ASTR , KC_LPRN,KC_LCBR, KC_LBRC ,UK_MINS , XXXXXXX
                            /* ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤ */ // Starts with encoder click
                            /* │        │  ~     |        │        │        │  _     │        │ */
#define SYMBOLS_RH_LOWER        _______, UK_TILD , KC_RPRN,KC_RCBR, KC_RBRC, UK_UNDS , XXXXXXX
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
