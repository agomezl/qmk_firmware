/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Drashna Jael're  <drashna@live.com>
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



#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
    LY0,  // default layer
    LY1,  // movement
    LY2,  // symbols
    LY3,  // media keys
    LY4,
};

enum custom_keycodes {
  VRSN = ML_SAFE_RANGE,
  RGB_SLD,
  L_R_BRC,
  L_R_CRL,
  L_R_PAR,
  WEB_TAG,
  WEB_END,
  DUAL_QU,
  DUAL_Q2,
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
  NV_MIC,
  C_M_OSM,
  M_S_OSM,
  C_S_OSM,
  MEH_OSM,
  OSM_CLR
};

#define RUN_M1 DYN_MACRO_PLAY1
#define RUN_M2 DYN_MACRO_PLAY2
#define REC_M1 DYN_REC_START1
#define REC_M2 DYN_REC_START2
#define STOP_M DYN_REC_STOP

// One-shot modifiers definitions
#define C_TAB   LCTL_T(KC_TAB)
#define C_ENT   RCTL_T(KC_ENT)
#define S_LPAR  RSFT_T(KC_LPRN)
#define S_RPAR  LSFT_T(KC_RPRN)
#define M_BSPC  LALT_T(KC_BSPC)
#define G_ENT   LGUI_T(KC_ENT)
#define WIN_D_L C(G(KC_LEFT))
#define WIN_D_R C(G(KC_RIGHT))



#define OSM_S OSM(MOD_LSFT)
#define OSM_C OSM(MOD_LCTL)
#define OSM_M OSM(MOD_LALT)
#define OSM_G OSM(MOD_LGUI)
#define OSL_LY3 OSL(LY3)
#define OSL_LY2 OSL(LY2)
#define OSL_LY1 OSL(LY1)
#define OSL_LY4 OSL(LY4)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LY0] = LAYOUT_moonlander(
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    MU_MOD,  /* */ MU_TOG,  KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    HOL_TRM, /* */ DUAL_QU, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        C_TAB,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    L_R_BRC, /* */ WEB_TAG, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, C_ENT,
        KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             /* */          KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC,
        KC_GRV,  RGB_MOD, E_MAGIT, RGB_TOG, OSM_G,            RUN_M1,  /* */ RUN_M2,           OSL_LY2, KC_LEFT, KC_UP,   KC_DOWN, KC_RIGHT,
                                            OSM_M, OSL_LY1,   KC_LBRC, /* */ KC_RBRC, KC_BSPC, KC_SPC
    ),

    [LY1] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, RESET,   /* */ STOP_M,  _______, _______, _______, _______, _______, _______,
        L_R_BRC, KC_VOLD, KC_VOLU, KC_END,  HOL_APP, HOL_THN, DUAL_GR, /* */ DUAL_Q2, HOL_Y,   KC_PGUP, KC_UP,   KC_PGDN, HOL_P,   _______,
        KC_QUOT, KC_HOME, KC_BSPC,  KC_DEL,  HOL_F , KC_ESC,  L_R_CRL, /* */ WEB_END, HOL_H,   KC_LEFT, KC_DOWN, KC_RGHT, KC_INS,  _______,
        OSM_S,   ML_CMNT, HOL_X,   E_LAST,  MO(LY3), OSM_CLR,          /* */          _______, _______, _______, _______, _______, L_R_PAR,
        C_S_OSM, _______, _______, _______, _______,          REC_M1,  /* */ REC_M2,           MEH_OSM, _______, _______, _______, _______,
                                            C_M_OSM, _______, WIN_D_L, /* */ WIN_D_R, OSM_C,   HOL_R
    ),

    [LY2] = LAYOUT_moonlander(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   RGB_VAD, /* */ RGB_VAI, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        _______, _______, _______, KC_MS_U, _______, _______, RGB_HUD, /* */ RGB_HUI, _______, _______, _______, _______, _______, _______,
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    RGB_SAD, /* */ RGB_SAI, KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,
        OSM_S,   _______, _______, _______, _______, OSM_CLR,                         _______, _______, _______, _______, KC_BSLS, _______,
        M_S_OSM, _______, _______, _______, _______,          RGB_MOD,       RGB_TOG,          _______, _______, _______, _______, _______,
                                            _______, OSM_C,   _______,       _______, _______, _______
    ),

    [LY3] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,           _______, KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,           _______, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,
        _______, _______, _______, _______, _______, OSM_CLR,                             KC_WH_L, KC_WH_R, KC_BTN3, _______, _______, _______,
        _______, _______, _______, _______, _______,          _______,           _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),

};

layer_state_t layer_state_set_user(layer_state_t state) {
    ML_LED_1(false);
    ML_LED_2(false);
    ML_LED_3(false);
    ML_LED_4(false);
    ML_LED_5(false);
    ML_LED_6(false);

    switch (get_highest_layer(state)) {
        case 1:
            ML_LED_1(1);
            ML_LED_4(1);
            break;
        case 2:
            ML_LED_2(1);
            ML_LED_5(1);
            break;
        case 3:
            ML_LED_3(1);
            break;
        case 4:
            ML_LED_4(1);
            break;
        case 5:
            ML_LED_5(1);
            break;
        case 6:
            ML_LED_6(1);
            break;
        default:
            break;
    }

    return state;
}


#define LEDMAP(C) {C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C}
#define COLOR1 {32,255,255}
#define COLOR2 {127,248,237}


const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
  [1] = LEDMAP(COLOR1),
  [2] = LEDMAP(COLOR2),
};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
        case VRSN:
            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            return false;
        case L_R_PAR:
          SEND_STRING("()"SS_TAP(X_LEFT));
          return false;
          break;
        case WEB_END:
          SEND_STRING("</>"SS_TAP(X_LEFT));
          return false;
          break;
        case WEB_TAG:
          SEND_STRING("<>"SS_TAP(X_LEFT));
          return false;
          break;
        case L_R_CRL:
          SEND_STRING("{}"SS_TAP(X_LEFT));
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
                      "hor" SS_DELAY(100) SS_TAP(X_ENTER));
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
          SEND_STRING("` ` "SS_TAP(X_LEFT));
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
        case DUAL_Q2:
          SEND_STRING("\" \" "SS_TAP(X_LEFT));
          return true;
          break;
        case DUAL_GR:
          SEND_STRING("` ` ` ` "SS_TAP(X_LEFT)SS_TAP(X_LEFT));
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
        case C_M_OSM:
          set_oneshot_mods(MOD_LCTL | MOD_LALT);
          return false;
          break;
        case M_S_OSM:
          set_oneshot_mods(MOD_LALT | MOD_LSFT);
          return false;
          break;
        case C_S_OSM:
          set_oneshot_mods(MOD_LCTL | MOD_LSFT);
          return false;
          break;
        case MEH_OSM:
          set_oneshot_mods(MOD_LCTL | MOD_LALT | MOD_LSFT);
          return false;
          break;
        case OSM_CLR:
          clear_oneshot_mods();
          return false;
          break;
        }
    }
    return true;
}
