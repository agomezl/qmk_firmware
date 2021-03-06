#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define LY0 0 // Default
#define LY1 1 // Games
#define LY2 2 // Movement
#define LY3 3 // Mouse
#define LY4 4 // symbols

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
  L_R_BRC,
  L_R_PAR,
  DUAL_QU,
  DUAL_GR,
  E_GO_L,
  E_GO_R,
  E_LAST,
  E_MAGIT,
  E_SAVE,
  HOL_X,
  HOL_P,
  HOL_F,
  HOL_H,
  HOL_Y,
  HOL_R,
  HOL_FS,
  HOL_RFS,
  HOL_MET,
  HOL_RW,
  HOL_CSE,
  HOL_IND,
  HOL_TRM,
  HOL_QTE,
  HOL_THN,
  HOL_ENT,
  HOL_APP,
  ML_CMNT,
  NV_OVER,
  NV_REC,
  NV_SAVE,
  NV_TOGL,
  NV_STRM,
  NV_STOP,
  NV_CAM,
  NV_MIC
};

#define RUN_M1 DYN_MACRO_PLAY1
#define RUN_M2 DYN_MACRO_PLAY2
#define REC_M1 DYN_REC_START1
#define REC_M2 DYN_REC_START2
#define STOP_M DYN_REC_STOP

// One-shot modifiers definitions
#define C_TAB LCTL_T(KC_TAB)
#define C_ENT RCTL_T(KC_ENT)
#define S_LPAR RSFT_T(KC_LPRN)
#define S_RPAR LSFT_T(KC_RPRN)
#define M_BSPC LALT_T(KC_BSPC)
#define G_ENT LGUI_T(KC_ENT)

#define OSM_S OSM(MOD_LSFT)
#define OSM_C OSM(MOD_LCTL)
#define OSM_M OSM(MOD_LALT)
#define OSM_G OSM(MOD_LGUI)
#define OSL_LY3 OSL(LY3)
#define OSL_LY2 OSL(LY2)
#define OSL_LY4 OSL(LY4)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[LY0] = LAYOUT_ergodox(  // layer 0 : default
        //  left hand
        KC_ESC,  HOL_MET, HOL_CSE, HOL_IND, HOL_FS,  HOL_RW,  KC_MINUS,
        KC_QUOT, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    XXXXXXX,
        C_TAB,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LPRN,
        KC_GRV,  XXXXXXX, E_MAGIT, XXXXXXX, KC_LGUI,
                                                     RUN_M1,  STOP_M,
                                                              XXXXXXX,
                                            M_BSPC,  MO(LY2), HOL_QTE,
        // right hand
        KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        HOL_THN, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    HOL_APP,
                 KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, C_ENT,
        KC_RPRN, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                 OSL_LY4, KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC,
        STOP_M,  RUN_M2,
        XXXXXXX,
        TO(LY1), G_ENT, KC_SPC
    ),

// Movement
[LY2] = LAYOUT_ergodox(
        // left hand
        L_R_BRC, _______, _______, _______, _______, _______, _______,
        _______, KC_VOLD, KC_VOLU, KC_END,  HOL_THN, HOL_TRM, _______,
        KC_QUOT, KC_HOME, KC_SPC,  KC_DEL,  HOL_F  , _______,
        _______, ML_CMNT, HOL_X,   E_LAST,  MO(LY3), _______, _______,
        _______, _______, _______, _______, _______,
                                                     REC_M1,  _______,
                                                              _______,
                                            _______, _______, _______,
        // right hand
        _______, _______, _______, _______, _______, _______, _______,
        HOL_ENT, HOL_Y,   KC_PGUP, KC_UP,   KC_PGDN, HOL_P,   _______,
                 HOL_H,   KC_LEFT, KC_DOWN, KC_RGHT, KC_INS,  _______,
        _______, _______, _______, _______, _______, _______, L_R_PAR,
                          KC_LCTL, DUAL_QU, DUAL_GR, _______, _______,
        _______, REC_M2,
        _______,
        _______, KC_LCTL, HOL_R
    ),

// Symbols
[LY4] = LAYOUT_ergodox(
        // left hand
        KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,    _______,
        _______,  _______, _______, _______, _______, _______,  _______,
        KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    KC_6,
        _______,  _______, _______, ML_CMNT, _______, _______,  _______,
        _______,  _______, _______, _______, _______,
                                                      _______,  _______,
                                                                _______,
                                             _______, MO(LY2),  _______,
        // right hand
        RESET,    KC_F7,    KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        _______,  _______, _______, _______, _______, _______,  _______,
                  KC_7,    KC_8,    KC_9,    KC_0,    KC_MINUS, KC_EQL,
        _______,  _______, _______, _______, _______, KC_BSLS,  _______,
                           _______, KC_LBRC, KC_RBRC, _______,  _______,
        _______,  _______,
        _______,
        _______,  _______, _______
    ),

// Games layout
[LY1] = LAYOUT_ergodox(
       _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,
       _______, _______, _______, _______, _______, _______, KC_Y,
       KC_TAB,  _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, KC_H,
       KC_LCTL, _______, KC_LGUI, KC_LALT, KC_LCTL,
                                           _______, MO(LY2),
                                                    _______,
                                  KC_SPC,  KC_M,    KC_N,

       NV_SAVE, NV_TOGL, _______, _______, _______, _______, _______,
       NV_REC,  _______, _______, _______, _______, _______, _______,
                _______, _______, _______, _______, _______, _______,
       NV_OVER, _______, _______, _______, _______, _______, _______,
                _______, _______, _______, _______, TO(LY0),
       NV_CAM,  NV_MIC,
       NV_STOP,
       NV_STRM, _______, _______
),

// Mouse layout
[LY3] = LAYOUT_ergodox(
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______,
                                           _______, _______,
                                                    _______,
                                  _______, _______, _______,
    // right hand
       _______, _______, _______, _______, _______, _______, _______,
       _______, KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2, _______, _______,
                KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,
       _______, KC_WH_L, KC_WH_R, KC_BTN3, _______, _______, _______,
                         _______, _______, _______, _______, _______,
       KC_ACL1, KC_ACL0,
       KC_ACL2,
       _______, _______, _______
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(LY4)                // FN1 - Momentary Layer 1 (Symbols)
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
    case L_R_PAR:
      SEND_STRING("()"SS_TAP(X_LEFT));
      return false;
      break;
    case L_R_BRC:
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
    case E_MAGIT:
      SEND_STRING(SS_LCTRL(SS_LSFT(SS_LALT("g"))));
      return false;
      break;
    case E_SAVE:
      SEND_STRING(SS_LCTRL("x")SS_LCTRL("s"));
      return false;
      break;
    case ML_CMNT:
      SEND_STRING("(*  *)"SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT));
      return true;
      break;
    case HOL_X:
      SEND_STRING(// Full screen
                  SS_LCTRL("x")"1"
                  // Split vertically
                  SS_LCTRL("x")"3"
                  // Move to the right
                  SS_LCTRL("x")SS_TAP(X_RIGHT)
                  // Find hol
                  SS_LCTRL("x")"bhol"
                  );
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
    case HOL_Y:
      SEND_STRING(SS_LCTRL(" ")SS_LALT("<")
                  SS_LCTRL("x")SS_LCTRL("x")
                  SS_LALT("h")"H"
                  "new" SS_DELAY(100) SS_TAP(X_ENTER));
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
      SEND_STRING("` ` ");
      return false;
      break;
    case HOL_QTE:
      SEND_STRING("` ");
      return true;
      break;
    case DUAL_QU:
      SEND_STRING("' ' "SS_TAP(X_LEFT));
      return true;
      break;
    case DUAL_GR:
      SEND_STRING("` ` "SS_TAP(X_LEFT));
      return true;
      break;
    case HOL_THN:
      SEND_STRING("\\\\ ");
      return false;
      break;
    case HOL_ENT:
      SEND_STRING(SS_TAP(X_ENTER)"\\\\ "SS_TAP(X_TAB));
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
      SEND_STRING("Cases_on ` ");
      return false;
      break;
    case HOL_IND:
      SEND_STRING("ho_match_mp_tac");
      return false;
      break;
    case HOL_MET:
      SEND_STRING("metis_tac []"SS_TAP(X_LEFT));
      return false;
      break;
    case NV_OVER:
      SEND_STRING(SS_LALT("z"));
      return false;
      break;
    case NV_REC:
      SEND_STRING(SS_LALT(SS_TAP(X_F9)));
      return false;
      break;
    case NV_SAVE:
      SEND_STRING(SS_LALT(SS_TAP(X_F10)));
      return false;
      break;
    case NV_TOGL:
      SEND_STRING(SS_LALT(SS_LSFT(SS_TAP(X_F10))));
      return false;
      break;
    case NV_STRM:
      SEND_STRING(SS_LALT(SS_TAP(X_F8)));
      return false;
      break;
    case NV_STOP:
      SEND_STRING(SS_LALT(SS_TAP(X_F7)));
      return false;
      break;
    case NV_CAM:
      SEND_STRING(SS_LALT(SS_TAP(X_F6)));
      return false;
      break;
    case NV_MIC:
      SEND_STRING(SS_LCTRL(SS_LALT("m")));
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
