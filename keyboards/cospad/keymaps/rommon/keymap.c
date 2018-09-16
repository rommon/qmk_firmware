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
#define _L2 2
#define _L3 3

#define _______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: (Base Layer) Default Layer
   * ,------------------------.
   * | FN   | APP  | F7  | F1 |
   * |------|------|-----|----|
   * | L2   | CALC | F8  | F2 |
   * |------|------|-----|----|
   * | L3   | PLAY | F9  | F3 |
   * |------|------|-----|----|
   * | MUTE | STOP | F10 | F4 |
   * |------|------|-----|----|
   * | V-   | PREV | F11 | F5 |
   * |------|------|-----|----|
   * | V+   | NEXT | F12 | F6 |
   * `------------------------'
   */

[_BL] = LAYOUT_ortho_6x4(
  MO(_FL), KC_APP,  KC_F7,  KC_F1, \
  MO(_L2), KC_CALC,  KC_F8,  KC_F2, \
  MO(_L3), KC_MPLY,  KC_F9,  KC_F3, \
  KC_MUTE, KC_MSTP, KC_F10, KC_F4, \
  KC_VOLD, KC_MPRV,  KC_F11, KC_F5, \
  KC_VOLU, KC_MNXT,  KC_F12, KC_F6),

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
  RGB_HUD,  RGB_HUI,  BL_ON,     KC_F1,         \
  RGB_SAD,  RGB_SAI,  BL_OFF,    KC_PPLS, \
  RGB_VAD,  RGB_VAI,  KC_P3,     KC_F1,         \
  KC_P0,    KC_F1,          RESET,     KC_PENT),
};


const uint16_t PROGMEM fn_actions[] = {
    [0] = MO(_FL),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
   switch (keycode) {
      case BL_TOGG:
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
