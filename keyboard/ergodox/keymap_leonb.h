static const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * Keymap: Default Layer in QWERTY
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |  `     |  1   |  2   |  3   |  4   |  5   |      |           |  -   |  6   |  7   |  8   |  9   |  0   |  =     |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * | Tab    |  Q   |  W   |  E   |  R   |  T   | L1   |           | [    |  Y   |  U   |  I   |  O   |  P   |  \     |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |ctrl/esc|  A   |  S   |  D   |  F   |  G   |------|           |------|  H   |  J   |  K   |  L   |  ;   |  '     |
     * |--------+------+------+------+------+------|      |           | ]    |------+------+------+------+------+--------|
     * | Lshift |  Z   |  X   |  C   |  V   |  B   |      |           |      |  N   |  M   |  ,   |  .   |  /   | LShift |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   | PgUp | PgDn | End  | Home | Alt  |                                       |  Lft |  Dn  |  Up  | Rght |      |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        | LGui |      |       |      |      |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      |      |       |      |      |      |
     *                                 | BkSp |  Del |------|       |------| Enter| Space|
     *                                 |      |      |      |       |      |      |      |
     *                                 `--------------------'       `--------------------'
     *
     *
     *
     ****************************************************************************************************
     *
     * HOW TO COMPILE:
     *
     * make -f Makefile.lufa clean
     * make -f Makefile.lufa leonb
     *
     ****************************************************************************************************
     *
     * HOW TO DEBUG:
     *
     * sudo ./hid-listen
     * (see: https://www.pjrc.com/teensy/hid_listen.html)
     *
     ****************************************************************************************************
     *
     * Test:
     * - Alt + F4
     * - Ctrl + Gui + Up
     * - Ctrl + Alt + Shift + Lft/Rght
     *
     ****************************************************************************************************
     *
     */

    KEYMAP(  // Layer0: default, leftled:none, rightled: none
        // left hand
        GRV, 1,   2,   3,   4,   5,   NO,
        TAB, Q,   W,   E,   R,   T,   NO,
        FN2, A,   S,   D,   F,   G,
        LSFT,Z,   X,   C,   V,   B,   NO,
        PGUP,PGDN,END, HOME,LALT,
                                      LGUI,NO,
                                           NO,
                                 BSPC,DEL, NO,
        // right hand
             MINS,6,   7,   8,   9,   0,   EQL,
             LBRC,Y,   U,   I,   O,   P,   BSLS,
                  H,   J,   K,   L,   SCLN,QUOT,
             RBRC,N,   M,   COMM,DOT, SLSH,RSFT,
                       LEFT,DOWN,UP,  RGHT,FN1,
        NO,  NO,
        NO,
        NO,  ENT, SPC
    ),

    KEYMAP(  // Layer1: default, leftled:none, rightled: 1
        // left hand
        FN0, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                       TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),
};

/* id for user defined functions & macros */
enum function_id {
    TEENSY_KEY,
    CUSTOM_LAYER_TAP_TOGGLE,
};

/*
 * Fn action definition
 */
static const uint16_t PROGMEM fn_actions[] = {
    [0] =   ACTION_FUNCTION(TEENSY_KEY),                 // FN0  - Teensy key
    [1] =   ACTION_FUNCTION_TAP(CUSTOM_LAYER_TAP_TOGGLE), // FN1  - Teensy key
    [2] =   ACTION_MODS_TAP_KEY(MOD_LCTL, KC_ESC),       // FN2  = LCtrl with tap Escape
};

/*
 * user defined action function
 */
void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    // print("action_function called\n");
    // print("id  = "); phex(id); print("\n");
    // print("opt = "); phex(opt); print("\n");

    switch (id) {
        case TEENSY_KEY:
            clear_keyboard();
            print("\n\nJump to bootloader... ");
            _delay_ms(50);
            bootloader_jump(); // should not return
            print("not supported.\n");
            break;

        case CUSTOM_LAYER_TAP_TOGGLE:
            xprintf("\n\ntap.count: %d", record->tap.count);
            xprintf("\n\nevent.pressed: %d", record->event.pressed);

            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    print("\nlayer_invert");
                    layer_invert(1);
                }
            } else {
                if (record->event.pressed) {
                    print("\nlayer_on");
                    layer_on(1);
                } else {
                    print("\nlayer_off");
                    layer_off(1);
                }
            }
            break;
    }
}

/*
 * Custom matrix logic as used in matrix.c
 */
void custom_matrix_logic()
{
    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_left_led_1_off();
    ergodox_left_led_2_off();
    ergodox_left_led_3_off();

    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        case 1:
            ergodox_right_led_1_on();
            break;
        default:
            // none
            break;
    }

    mcp23018_status = ergodox_left_leds_update();
}

/*
 * ACTION_MODS_TAP_KEY(MOD_RCTL, KC_ENT)
 * Works as a modifier key while holding, but registers a key on tap(press and
 * release quickly).
 */

/*
 * ACTION_LAYER_TAP_TOGGLE(layer)
 * Turns on layer momentary while holding and toggles it with serial taps.
 */

/* ACTION_MODS_ONESHOT(MOD_LSFT) */
