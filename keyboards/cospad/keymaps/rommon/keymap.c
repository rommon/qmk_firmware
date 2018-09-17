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
#define _FN 1
#define _L2 2
#define _L3 3
#define _L4 4

#define TAPPING_TOGGLE 2

#define _______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: (Base Layer) Default Layer
   * ,---------------------------.
   * | APP    | F7  | F1  | FN   |
   * |--------|-----|-----|------|
   * | EXPL   | F8  | F2  | PLAY |
   * |--------|-----|-----|------|
   * | FORMAT | F9  | F3  | STOP |
   * |--------|-----|-----|------|
   * |        | F10 | F4  | MUTE |
   * |--------|-----|-----|------|
   * | PREV   | F11 | F5  | V-   |
   * |--------|-----|-----|------|
   * | NEXT   | F12 | F6  | V+   |
   * `---------------------------'
   */

[_BL] = LAYOUT_ortho_6x4(
  KC_APP,           KC_F7,   KC_F1, TG(_FN), \
  LGUI(KC_E),       KC_F8,   KC_F2, KC_MPLY, \
  LALT(LSFT(KC_L)), KC_F9,   KC_F3, KC_MSTP, \
  KC_TRNS,          KC_F10,  KC_F4, KC_MUTE, \
  KC_MPRV,          KC_F11,  KC_F5, KC_VOLD, \
  KC_MNXT,          KC_F12,  KC_F6, KC_VOLU),
  /* Keymap _FL: Function Layer
   * ,----------------------------.
   * | M L   | M B 1 | TOG  | FN  |
   * |-------|-------|------|-----|
   * | M D   | M U   | MOD  | L2  |
   * |-------|-------|------|-----|
   * | M R   | M B 2 | RMOD | L3  |
   * |-------|-------|------|-----|
   * | M W U | SAI   | HUI  | L4  |
   * |-------|-------|------|-----|
   * | M W D | SAD   | HUD  |     |
   * |-------|-------|------|-----|
   * | M B 3 | VAD   | VAI  | RST |
   * `----------------------------'
   */
[_FN] = LAYOUT_ortho_6x4(
  KC_MS_L, KC_BTN1, RGB_TOG,  TG(_FN),\
  KC_MS_D, KC_MS_U, RGB_MOD,  MO(_BL),\
  KC_MS_R, KC_BTN2, RGB_RMOD, KC_TRNS,\
  KC_WH_U, RGB_SAI, RGB_HUI,  KC_TRNS, \
  KC_WH_D, RGB_SAD, RGB_HUD,  KC_TRNS, \
  KC_BTN3, RGB_VAD, RGB_VAI,  RESET)
};


const uint16_t PROGMEM fn_actions[] = {
    [0] = MO(_FN),
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
