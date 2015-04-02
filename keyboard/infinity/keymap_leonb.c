#include "keymap_common.h"

/*
 ****************************************************************************************************
 *
 * HOW TO COMPILE:
 *
 * make KEYMAP=leonb
 * sudo make program KEYMAP=leonb
 *
 ****************************************************************************************************
 *
 * PULL FROM UPSTREAM
 *
 * git remote add upstream https://github.com/tmk/tmk_keyboard
 * git fetch
 * git branch -u upstream/master master
 * git fetch upstream
 * git rebase upstream/master
 *
 ****************************************************************************************************
 */

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer 0: Default Layer
     * ,-----------------------------------------------------------.
     * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  \|Del|
     * |-----------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  Bsp|
     * |-----------------------------------------------------------|
     * |Fn0   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|   Enter|
     * |-----------------------------------------------------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift |Fn1|
     * |-----------------------------------------------------------'
     * |     |Gui|Alt  |         Space         |Alt  |Fn2|   |     |
     * `-----------------------------------------------------------'
     */
    [0] =
    KEYMAP(GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSLS, DEL, \
           TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSPC,      \
           FN0, A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,ENT,            \
           LSFT,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,RSFT,FN1,            \
           LCTL,LGUI,LALT,          SPC,                RALT,FN2, NO,  NO),

    /* Layer 1: HHKB mode (HHKB Fn)
     * ,-----------------------------------------------------------.
     * |Pwr| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|Ins|Del|
     * |-----------------------------------------------------------|
     * |Caps |   |   |   |   |   |   |   |Psc|Slk|Pus|Up |   |Backs|
     * |-----------------------------------------------------------|
     * |      |VoD|VoU|Mut|   |   |  *|  /|Hom|PgU|Lef|Rig|Enter   |
     * |-----------------------------------------------------------|
     * |        |   |   |   |   |   |  +|  -|End|PgD|Dow|      |   |
     * `-----------------------------------------------------------'
     * |     |Gui|Alt  |         Space         |Alt  |Gui|   |     |
     * `-----------------------------------------------------------'
     */
    [1] =
    KEYMAP(PWR, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, INS, TRNS, \
           CAPS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,PSCR,SLCK,PAUS,UP  ,TRNS,BSPC,      \
           TRNS,VOLD,VOLU,MUTE,TRNS,TRNS,PAST,PSLS,HOME,PGUP,LEFT,RGHT,PENT,           \
           TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,PPLS,PMNS,END, PGDN,DOWN,TRNS,TRNS,           \
           TRNS,TRNS,TRNS,          TRNS,               TRNS,TRNS,TRNS,TRNS),

    /* Layer 2: Poker mode (Poker Fn)
     * ,-----------------------------------------------------------.
     * |   | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|   |   |
     * |-----------------------------------------------------------|
     * |     |   | Up|   |   |   |   |   |   |   |Psc|Slk|Pus|  Del|
     * |-----------------------------------------------------------|
     * |      |Lef|Dow|Rig|   |   |   |   |   |   |Hom|PgU|        |
     * |-----------------------------------------------------------|
     * |        |   |App|   |   |   |VoD|VoU|Mut|End|PgD|      |   |
     * `-----------------------------------------------------------'
     * |     |   |     |                       |     |   |   |     |
     * `-----------------------------------------------------------'
     */
    [2] =
    KEYMAP(TRNS,F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12 ,TRNS,TRNS, \
           TRNS,TRNS,UP,  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,PSCR,SLCK,PAUS,DEL,       \
           TRNS,LEFT,DOWN,RGHT,TRNS,TRNS,TRNS,TRNS,TRNS,HOME,PGUP,TRNS,TRNS,           \
           TRNS,TRNS,APP, TRNS,TRNS,TRNS,VOLD,VOLU,MUTE,END, PGDN,TRNS,TRNS,           \
           TRNS,TRNS,TRNS,          TRNS,               TRNS,TRNS,TRNS,TRNS),
};

/*
 * Fn action definition
 */
const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_ESC), // FN1 = LCtrl with tap Escape
    [1] = ACTION_LAYER_MOMENTARY(1),
    [2] = ACTION_LAYER_MOMENTARY(2),
};
