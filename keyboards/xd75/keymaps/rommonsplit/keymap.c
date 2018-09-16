/* Copyright 2017 Wunder
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "xd75.h"

// Layer shorthand
#define _QW 0
#define _FN 1

//Tap Dance Declarations
enum {
  TD_LSQBRACKET_LBRACKET = 0,
  TD_RSQBRACKET_RBRACKET,
  TD_EQL_PLUS,
  TD_MINS_UNDERS,
  TD_SLSH_QUES,
  TD_BSLASH_PIPE,
  TD_SQUOT_DQUOT,
  TD_SCLN_DPOI,
  TD_COMM_LARR,
  TD_DOT_RARR,
  TD_GRV_TLD
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_LSQBRACKET_LBRACKET]  = ACTION_TAP_DANCE_DOUBLE(KC_LBRACKET, LSFT(KC_9)),
  [TD_RSQBRACKET_RBRACKET]  = ACTION_TAP_DANCE_DOUBLE(KC_RBRACKET, LSFT(KC_0)),
  [TD_EQL_PLUS] = ACTION_TAP_DANCE_DOUBLE(KC_EQL, LSFT(KC_EQL)),
  [TD_MINS_UNDERS] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, LSFT(KC_MINS)),
  [TD_BSLASH_PIPE] = ACTION_TAP_DANCE_DOUBLE(KC_BSLASH, LSFT(KC_BSLASH)),
  [TD_SLSH_QUES] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, LSFT(KC_SLSH)),
  [TD_SQUOT_DQUOT] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT,LSFT(KC_QUOT)),
  [TD_SCLN_DPOI] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN,LSFT(KC_SCLN)),
  [TD_COMM_LARR] = ACTION_TAP_DANCE_DOUBLE(KC_COMM,LSFT(KC_COMM)),
  [TD_DOT_RARR] = ACTION_TAP_DANCE_DOUBLE(KC_DOT,LSFT(KC_DOT)),
  [TD_GRV_TLD] = ACTION_TAP_DANCE_DOUBLE(KC_GRV,LSFT(KC_GRV))
// Other declarations would go here, separated by commas, if you have them
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | ESC    | 1      | 2      | 3      | 4      | 5      | -      | `      | =      | 6      | 7      | 8      | 9      | 0      | BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | E      | R      | T      | [      | \      | ]      | Y      | U      | I      | O      | P      | '      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | F12    | A      | S      | D      | F      | G      | HOME   | END    | PG UP  | H      | J      | K      | L      | ;      | ENTER  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | LSHIFT | Z      | X      | C      | V      | B      | DEL    | UP     | PG DN  | N      | M      | ,      | .      | /      | RSHIFT |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | LCTRL  | LGUI   | LALT   | FN     | SPACE  | SPACE  | LEFT   | DOWN   | RIGHT  | SPACE  | SPACE  | FN     | RALT   | INS    | RCTRL  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_QW] = { /* QWERTY */
  { KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    TD(TD_MINS_UNDERS), TD(TD_GRV_TLD),  TD(TD_EQL_PLUS),  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC  },
  { KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    TD(TD_LSQBRACKET_LBRACKET), TD(TD_BSLASH_PIPE), TD(TD_RSQBRACKET_RBRACKET), KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    TD(TD_SQUOT_DQUOT)  },
  { KC_F12,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_HOME, KC_END,  KC_PGUP, KC_H,    KC_J,    KC_K,    KC_L,    TD(TD_SCLN_DPOI), KC_ENT   },
  { KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_DEL,  KC_UP,   KC_PGDN, KC_N,    KC_M,    TD(TD_COMM_LARR), TD(TD_DOT_RARR),  TD(TD_SLSH_QUES), KC_RSFT  },
  { KC_LCTL, KC_LGUI, KC_LALT, MO(_FN), KC_SPC,  KC_SPC,  KC_LEFT, KC_DOWN, KC_RGHT, KC_SPC,  KC_SPC,  MO(_FN), KC_RALT, KC_INS, KC_RCTL  },
 },

/* FUNCTION
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | F1     | F2     | F3     | F4     | F5     | F6     | NUM LK | P/     | P*     | F7     | F8     | F9     | F10    | F11    | F12    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | SELECT | CALC   | MYCOMP | MAIL   | RGB HD | RGB HI | P7     | P8     | P9     | -      |        |        | PR SCR | SCR LK | PAUSE  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | PREV   | PLAY   | NEXT   | STOP   | RGB SD | RGB SI | P4     | P5     | P6     | +      |        | RESET  |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | VOL-   | MUTE   | VOL+   | APP    | RGB VD | RGB VI | P1     | P2     | P3     | PENT   |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        | RGB TG | FN     | RGB RMD| RGB MD | P0     |        | P.     | PENT   | PENT   | FN     |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_FN] = { /* FUNCTION */
  { KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_NLCK, KC_SLSH, KC_ASTR, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12   },
  { KC_MSEL, KC_CALC, KC_MYCM, KC_MAIL, RGB_HUD, RGB_HUI, KC_P7,   KC_P8,   KC_P9,   KC_MINS, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS  },
  { KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, RGB_SAD, RGB_SAI, KC_P4,   KC_P5,   KC_P6,   KC_PLUS, _______, RESET,   _______, _______, _______  },
  { KC_VOLD, KC_MUTE, KC_VOLU, KC_APP,  RGB_VAD, RGB_VAI, KC_P1,   KC_P2,   KC_P3,   KC_PENT, _______, _______, _______, _______, _______  },
  { _______, _______, RGB_TOG, MO(_FN), RGB_RMOD,RGB_MOD, KC_P0,   _______, KC_PDOT, KC_PENT, KC_PENT, MO(_FN), _______, _______, _______  },
 }
};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};
