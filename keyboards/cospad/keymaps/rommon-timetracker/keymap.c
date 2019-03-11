#include QMK_KEYBOARD_H
#include "led.h"

#ifdef RGBLIGHT_ENABLE
#include "rgblight.h"
#endif

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BL 0
#define _FL 1

#define _______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap _BL: (Base Layer) Default Layer
 * ,-------------------.
 * |Esc |TAB | FN | BS |
 * |----|----|----|----|
 * | NL | /  | *  | -  |
 * |----|----|----|----|
 * | 7  | 8  | 9  | +  |
 * |----|----|----|----|
 * | 4  | 5  | 6  |    |
 * |----|----|----|----|
 * | 1  | 2  | 3  | En |
 * |----|----|----|----|
 * | 0  | 0  | .  | En |
 * `-------------------'
 */

[_BL] = LAYOUT_ortho_6x4(
        HYPR(KC_F15),   _______,   MO(_FL),   BL_ON, \
  _______,  _______,  _______,   BL_OFF, \
  _______,    _______,    _______,    _______,          \
  KC_F21,    KC_F22,    KC_F23,     KC_F24, \
  HYPR(KC_F17),    HYPR(KC_F18),    HYPR(KC_F19),    HYPR( KC_F20),         \
  HYPR(KC_F21),  HYPR(KC_F22),      HYPR(KC_F23),   HYPR(KC_F24)),

/* Keymap _FL: Function Layer
 * ,-------------------.
 * |RGBT|TAB | FN | BS |
 * |----|----|----|----|
 * |RGBM|RGBP|BTOG| -  |
 * |----|----|----|----|
 * |HUD |HUI |BON |    |
 * |----|----|----| +  |
 * |SAD |SAI |BOFF|    |
 * |----|----|----|----|
 * |VAD |VAS | 3  |    |
 * |----|----|----| En |
 * |   0     |RST |    |
 * `-------------------'
 */
[_FL] = LAYOUT_ortho_6x4(
        RGB_TOG,  KC_TAB,   KC_TRNS,   KC_BSPC, \
  RGB_MOD,  RGB_M_P,  BL_TOGG,   KC_PMNS, \
  RGB_HUD,  RGB_HUI,  BL_ON,     KC_PPLS,         \
  RGB_SAD,  RGB_SAI,  BL_OFF,    KC_PPLS, \
  RGB_VAD,  RGB_VAI,  KC_P3,       KC_PENT,       \
  KC_P0, KC_P0,             RESET,     KC_PENT),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_F13:
            if (record->event.pressed) {
                cospad_bl_led_togg();
            }
            return false;
        case BL_ON:
            if (record->event.pressed) {
                cospad_bl_led_on();
            }
            return false;
        case BL_OFF:
            if(record->event.pressed) {
                cospad_bl_led_off();
            }
            return false;
        default:
            return true;
    }
}
