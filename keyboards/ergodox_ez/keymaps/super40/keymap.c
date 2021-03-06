#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define LY0 0 // default layer
#define LY1 1 // media keys
#define LY2 2 // symbols
#define LY3 3 // symbols
#define LY4 4 // symbols

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
  HOL_FS,
  HOL_RFS,
  HOL_MET,
  HOL_RW,
  HOL_CSE,
  HOL_IND,
  HOL_FND,
  HOL_MCH,
  HOL_TRM,
  HOL_QTE,
  HOL_THN,
  HOL_APP,
  ML_CMNT
};

// One-shot modifiers definitions
#define OSM_S OSM(MOD_LSFT)
#define OSM_C OSM(MOD_LCTL)
#define OSM_W OSM(MOD_LGUI)
#define OSM_G OSM(MOD_LALT)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[LY0] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    XXXXXXX,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                     XXXXXXX, XXXXXXX,
                                                              XXXXXXX,
                                            XXXXXXX, MO(LY1), XXXXXXX,
        // right hand
        XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC,
        XXXXXXX, KC_Y,    KC_U,        KC_I,    KC_O,    KC_P,    KC_BSLS,
                 KC_H,    KC_J,        KC_K,    KC_L,    KC_SCLN, KC_ENT,
        XXXXXXX, KC_N,    GUI_T(KC_M), OSM_G,   OSM_M,   OSM_C,   MO(LY2),
                          XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,
        XXXXXXX,
        XXXXXXX, XXXXXXX, KC_SPC
),

// KC_COMM, KC_DOT,  KC_SLSH


// MOVEMENT
[LY1] = LAYOUT_ergodox(
        // left hand
        _______ , _______, _______, _______, _______, _______, _______,
        _______,  KC_VOLD, KC_VOLU, KC_END,  _______, _______, _______,
        KC_QUOTE, KC_HOME, _______, KC_DEL,  KC_BSPC, _______,
        _______,  ML_CMNT, HOL_X,   E_LAST,  _______, _______, _______,
        _______,  _______, _______, _______, _______,
                                                       _______, _______,
                                                                _______,
                                              _______, _______, _______,
        // right hand
        _______,  _______, _______, _______,  _______,   _______, HOL_APP,
        _______,  KC_PGUP, KC_HOME, KC_UP,    KC_END,    _______, HOL_THN,
                  KC_PGDN, KC_LEFT, KC_DOWN,  KC_RIGHT,  KC_INS,  _______,
        _______,  _______, _______, _______,  _______,   _______, LPAR_RPAR,
                           DUAL_QU, HOL_QTE,  _______,   _______, _______,
        _______, _______,
        _______,
        _______, KC_RCTL, HOL_R
    ),



// SYMBOLS
[LY2] = LAYOUT_ergodox(
        // left hand
        _______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6,
        _______,  _______, _______, _______, _______, _______,  _______,
        KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    KC_6,
        _______,  _______, _______, _______, _______, _______,  _______,
        _______,  _______, _______, _______, _______,
                                                      _______,  _______,
                                                                _______,
                                             KC_LALT, KC_RSFT,  _______,
        // right hand
        KC_F7,    KC_F8,   KC_F9,   KC_F10,   KC_F11, KC_F12,   _______,
        _______,  _______, _______, _______, _______, _______,  _______,
                   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINUS, KC_EQL,
        _______,  _______, _______, _______, _______, _______,  _______,
                           _______, _______, _______, _______,  _______,
        _______,  _______,
        _______,
        _______,  _______, _______
    ),


// Games layout
[LY3] = LAYOUT_ergodox(
       _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,
       KC_H,    _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, KC_LGUI, KC_LALT,
                                           _______, _______,
                                                    _______,
                                  KC_SPC,  _______, _______,
    // right hand
       KC_7,     KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  _______,
       _______,  _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______, _______,
       _______,  _______, _______, _______, _______, _______, _______,
                          _______, _______, _______, _______, _______,
       _______, _______,
       _______,
       _______, _______, _______
),

// Mouse layout
[LY4] = LAYOUT_ergodox(
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______,
                                           _______, _______,
                                                    _______,
                                  _______, _______, _______,
    // right hand
       _______, _______, _______, _______, _______, _______,  _______,
       _______, KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2, _______, _______,
                KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,
       _______, KC_WH_L, KC_WH_R, KC_BTN3, _______, _______, _______,
                         _______, _______, _______, _______, _______,
       KC_ACL2, _______,
       KC_ACL1,
       KC_ACL0, _______, _______
),
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
    case ML_CMNT:
      SEND_STRING("(*  *)"SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT));
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
      SEND_STRING("\\\\\\\\ ");
      return false;
      break;
    case HOL_APP:
      SEND_STRING(" |> ");
      return false;
      break;
    case HOL_FS:
      SEND_STRING("fs []"SS_TAP(X_LEFT));
      return false;
      break;
    case HOL_RFS:
      SEND_STRING("rfs []"SS_TAP(X_LEFT));
      return false;
      break;
    case HOL_RW:
      SEND_STRING("rw []"SS_TAP(X_LEFT));
      return false;
      break;
    case HOL_CSE:
      SEND_STRING("Cases_on ` ` "SS_TAP(X_LEFT));
      return false;
      break;
    case HOL_IND:
      SEND_STRING("Induct_on ` ` "SS_TAP(X_LEFT));
      return false;
      break;
    case HOL_MET:
      SEND_STRING("METIS_TAC []"SS_TAP(X_LEFT));
      return false;
      break;
    case HOL_FND:
      SEND_STRING(// open hol window
                  SS_LCTRL("x")"1"SS_LALT("h")"3"
                  // move to hol window
                  SS_LCTRL("x")SS_TAP(X_RIGHT)
                  // write in it
                  "print_find \" \" ;"SS_TAP(X_LEFT)SS_TAP(X_LEFT));
      return false;
      break;
    case HOL_MCH:
      SEND_STRING(// open hol window
                  SS_LCTRL("x")"1"SS_LALT("h")"3"
                  // move to hol window
                  SS_LCTRL("x")SS_TAP(X_RIGHT)
                  // write in it
                  "print_match [] \" \" ;"SS_TAP(X_LEFT)SS_TAP(X_LEFT));
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
