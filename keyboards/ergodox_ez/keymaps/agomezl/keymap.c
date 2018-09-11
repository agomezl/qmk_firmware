#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define MOVE 1 // symbols
#define SYMB 2 // symbols
#define MDIA 3 // media keys

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
  LBRC_RBRC,
  LPAR_RPAR,
  DUAL_QU,
  E_GO_L,
  E_GO_R,
  E_LAST,
  HOL_X,
  HOL_Y,
  HOL_P,
  HOL_F,
  HOL_H,
  HOL_R,
  HOL_TRM,
  HOL_QTE,
  HOL_THN,
  HOL_APP
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_ESC,   XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,
        KC_GRAVE, KC_Q,    KC_W,    KC_E,     KC_R,     KC_T,    XXXXXXX,
        KC_TAB,   KC_A,    KC_S,    KC_D,     KC_F,     KC_G,
        KC_LSFT,  KC_Z,    KC_X,    KC_C,     KC_V,     KC_B,    XXXXXXX,
        KC_LCTRL, XXXXXXX, XXXXXXX, XXXXXXX, KC_LALT,
                                                        XXXXXXX,  XXXXXXX,
                                                                  XXXXXXX,
                                             KC_LGUI,   MO(MOVE), HOL_H,
        // right hand
        XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, KC_BSPC,
        XXXXXXX,  KC_Y,    KC_U,    KC_I,     KC_O,     KC_P,    KC_BSLS,
                  KC_H,    KC_J,    KC_K,     KC_L,     KC_SCLN, KC_ENT,
        XXXXXXX,  KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH, MO(SYMB),
                           KC_LPRN, KC_RPRN,  KC_LBRC,  KC_RBRC, KC_RCTRL,
        E_GO_L,   E_GO_R,
        XXXXXXX,
        XXXXXXX,  XXXXXXX,  KC_SPC
    ),

// MOVEMENT
[MOVE] = LAYOUT_ergodox(
        // left hand
        LBRC_RBRC, _______, _______, _______, _______, _______, _______,
        _______,   KC_VOLD, KC_VOLU, KC_END,  _______, _______, _______,
        KC_QUOTE,  KC_HOME, _______, KC_DEL,  HOL_F  , _______,
        _______,   _______, HOL_X,   E_LAST,  _______, _______, _______,
        _______,   _______, _______, _______, _______,
                                                       _______, _______,
                                                                _______,
                                              _______, _______, _______,
        // right hand
        _______,  _______, _______, _______,  _______,   _______, HOL_APP,
        _______,  HOL_Y,   KC_PGUP, KC_UP,    KC_PGDOWN, HOL_P,   _______,
                  _______, KC_LEFT, KC_DOWN,  KC_RIGHT,  KC_INS,  _______,
        _______,  _______, _______, _______,  _______,   _______, LPAR_RPAR,
                           DUAL_QU, HOL_QTE,  _______,   _______, HOL_TRM,
        _______,  _______,
        _______,
        _______,  _______, HOL_R
    ),

// SYMBOLS
[SYMB] = LAYOUT_ergodox(
        // left hand
        _______,  _______, _______, _______, _______, _______,  _______,
        _______,  _______, _______, _______, _______, _______,  _______,
        KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    KC_6,
        _______,  _______, _______, _______, _______, _______,  _______,
        _______,  _______, _______, _______, _______,
                                                      _______,  _______,
                                                                _______,
                                             _______, MO(MOVE), _______,
        // right hand
        _______,  _______, _______, _______, _______, _______,  _______,
        _______,  _______, _______, _______, _______, _______,  _______,
                   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINUS, KC_EQL,
        _______,  _______, _______, _______, _______, _______,  _______,
                           _______, _______, _______, _______,  _______,
        _______,  _______,
        _______,
        _______,  _______, _______
    ),

// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      break;
    case 1:
      if (record->event.pressed) { // For resetting EEPROM
        eeconfig_init();
      }
      break;
  }
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
    // dynamically generate these.
    case EPRM:
      eeconfig_init();
      return false;
      break;
    case VRSN:
      SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      return false;
      break;
    case LPAR_RPAR:
      SEND_STRING("()"SS_TAP(X_LEFT));
      return false;
      break;
    case LBRC_RBRC:
      SEND_STRING("[]"SS_TAP(X_LEFT));
      return false;
      break;
    case E_GO_L:
      SEND_STRING(SS_LCTRL("x")SS_TAP(X_LEFT));
      return false;
      break;
    case E_GO_R:
      SEND_STRING(SS_LCTRL("x")SS_TAP(X_RIGHT));
      return false;
      break;
    case E_LAST:
      SEND_STRING(SS_LCTRL("c "));
      return false;
      break;
    case HOL_X:
      SEND_STRING(SS_LCTRL("x")"1"SS_LALT("h")"3");
      return false;
      break;
    case HOL_Y:
      SEND_STRING(// Get hol window
                  SS_LCTRL("x")"1"SS_LALT("h")"3"
                  // Kill it
                  SS_LCTRL("x")SS_TAP(X_RIGHT)SS_LCTRL("x")"k"SS_TAP(X_ENTER)"yes"
                  // Start it again
                  SS_TAP(X_ENTER)SS_LCTRL("x")"0"SS_LALT("h")"3"
                  // Select up to point
                  SS_LCTRL(" ")SS_LALT("<")SS_LCTRL("xx")
                  // Load in HOL
                  SS_LCTRL("uu")SS_LALT("hr")SS_LCTRL(" "));
      return false;
      break;
    case HOL_P:
      SEND_STRING(SS_LALT("h")"p");
      return false;
      break;
    case HOL_F:
      SEND_STRING(SS_LALT("h")"e");
      return false;
      break;
    case HOL_R:
      SEND_STRING(SS_LALT("hr"));
      return false;
      break;
    case HOL_H:
      SEND_STRING(SS_LALT("h"));
      return false;
      break;
    case HOL_TRM:
      SEND_STRING("` ` ` ` "SS_TAP(X_LEFT)SS_TAP(X_LEFT));
      return false;
      break;
    case HOL_QTE:
      SEND_STRING("` ` "SS_TAP(X_LEFT));
      return false;
      break;
    case DUAL_QU:
      SEND_STRING("' ' "SS_TAP(X_LEFT));
      return false;
      break;
    case HOL_THN:
      SEND_STRING("\\\\");
      return false;
      break;
    case HOL_APP:
      SEND_STRING(" |> ");
      return false;
      break;
    }
  }

  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }

  return state;
};
