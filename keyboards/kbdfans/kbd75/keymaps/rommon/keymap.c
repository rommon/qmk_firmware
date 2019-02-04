#include QMK_KEYBOARD_H

#define _______ KC_TRNS

//Tap Dance Declarations
enum {
  TD_LSQBRACKET_LBRACKET = 0,
  TD_RSQBRACKET_RBRACKET,
  TD_LCTL_L2,
  TD_WIN_EXPLORER
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_LSQBRACKET_LBRACKET]  = ACTION_TAP_DANCE_DOUBLE(KC_LBRACKET, LSFT(KC_9)),
  [TD_RSQBRACKET_RBRACKET]  = ACTION_TAP_DANCE_DOUBLE(KC_RBRACKET, LSFT(KC_0)),
  [TD_LCTL_L2] = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, MO(2)),
  [TD_WIN_EXPLORER] = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, KC_MY_COMPUTER)
// Other declarations would go here, separated by commas, if you have them
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* 0: Qwerty layer
   * +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+--------+-------+
   * | ESC   | F1    | F2    | F3    | F4    | F5    | F6    | F7    | F8    | F9    | F10   | F11   | F12   | HOME  | END    | DEL   |
   * +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+----------------+-------+
   * | `     | 1     | 2     | 3     | 4     | 5     | 6     | 7     | 8     | 9     | 0     | -     | =     | BKSPC          | PG UP |
   * +-------+-+-----+-+-----+-+-----+-+-----+-+-----+-+-----+-+-----+-+-----+-+-----+-+-----+-+-----+-+-----+-+--------------+-------+
   * | H_TAB   | Q     | W     | E     | R     | T     | Y     | U     | I     | O     | P     | [     | ]     | \            | PG DN |
   * +---------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+--------------+-------+
   * | MO(2)     | A    | S     | D     | F     | G     | H     | J     | K     | L     | ;     | '     | ENTER               | F13  |
   * +-----------+------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+---------------------+-------+
   * | L_SHIFT     | Z     | X     | C     | V     | B     | N     | N     | M     | ,     | .     | /     | R_SHIFT  | UP    | F14  |
   * +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+----------------+-------+
   * | L_CTRL | LGUI | LALT |       SPACE                                                | RALT | MO(1) | RCRTL | LEFT | DOWN | RIGHT |
   * +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+----------------+-------+
   */
  [0] = LAYOUT(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_HOME,  KC_END,    KC_DEL,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_DEL,   KC_BSPC,  KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRACKET,  KC_RBRACKET,  KC_BSLS,            KC_PGDN,
        MO(2),  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,                      KC_ENT,   KC_F13,
        KC_LSFT,  MO(1),    KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,            KC_UP,    KC_F14,
        KC_LCTL,  TD(TD_WIN_EXPLORER),  KC_LALT,                      KC_SPC,   KC_SPC,   KC_SPC,                       KC_RALT,  MO(1),    KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT
  ),

/* 1: Fn
   * +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+--------+-------+
   * |       |       |       |       |       |       |       |       |       |       |       |       |       |       |        | INS   |
   * +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+----------------+-------+
   * |       |       |       |       |       |       |       |       |       |       |       |       |       |          RESET |       |
   * +-------+-+-----+-+-----+-+-----+-+-----+-+-----+-+-----+-+-----+-+-----+-+-----+-+-----+-+-----+-+-----+-+--------------+-------+
   * |         | RGB_TOG | RGB_MOD | RGB_HUI | RGB_HUD | RGB_SAI | RGB_SAD | RGB_VAI | RGB_VAD |       |       |       |       |              |       |
   * +---------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+--------------+-------+
   * |           |      |       |       |       |       |       |       |       |       |       |       |                     | PLAY  |
   * +-----------+------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+---------------------+-------+
   * |             |       |       | BL_DEC| BL_TOGG | BL_TOGG | BL_STEP |       |       |       |       |       |          | UP    | STOP  |
   * +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+----------------+-------+
   * |        |      |      |       APP                                                  |      |       |       | PREV | DOWN | NEXT  |
   * +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+----------------+-------+
   */
  [1] = LAYOUT(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_INS,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RESET,    _______,
    _______,  RGB_TOG,  RGB_MOD,  RGB_HUI,  RGB_HUD,  RGB_SAI,  RGB_SAD,  RGB_VAI,  RGB_VAD,  _______,  _______,  _______,  _______,  _______,            _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                      _______,  KC_MPLY,
    _______,  _______,  _______,  _______,  BL_DEC,   BL_TOGG,  BL_TOGG,   BL_STEP,  _______,  _______,  _______,  _______,  _______,           KC_VOLU,  KC_MSTP,
    _______,  _______,  _______,                      KC_APP,   KC_APP,    KC_APP,                      _______,  _______,  _______,  KC_MPRV,  KC_VOLD,  KC_MNXT
  ),
  [2] = LAYOUT(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RESET,    _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                      _______,  _______,
    _______,  _______,  _______,  _______,  _______,   _______,  _______,   _______,  _______,  _______,  _______,  _______,  KC_WWW_BACK,           KC_PGUP,  KC_WWW_FORWARD,
    _______,  _______,  _______,                      KC_APP,   KC_APP,    KC_APP,                      _______,  _______,  _______,  KC_HOME,  KC_PGDN,  KC_END
  ),
};

void led_set_user(uint8_t usb_led) {
    if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
        DDRB |= (1 << 2); PORTB &= ~(1 << 2);
    } else {
        DDRB &= ~(1 << 2); PORTB &= ~(1 << 2);
    }
}

