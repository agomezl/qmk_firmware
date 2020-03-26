/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"

extern keymap_config_t keymap_config;

enum planck_layers {
                    BASE,  // BASE
                    GAME,  // GAMES
                    MOVE,  // MOVE
                    NUM,   // NUM
                    MOUS,  // MOUSE
                    SYM    // SYM
};

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
  L_R_BRC,
  L_R_PAR,
  DUAL_QU,
  E_GO_L,
  E_GO_R,
  E_LAST,
  E_MAGIT,
  SONG1,
  HOL_X,
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
  HOL_TRM,
  HOL_QTE,
  HOL_THN,
  HOL_APP,
  ML_CMNT,
  DYNAMIC_MACRO_RANGE
};

#define RUN_M1 DYN_MACRO_PLAY1
#define RUN_M2 DYN_MACRO_PLAY2
#define REC_M1 DYN_REC_START1
#define REC_M2 DYN_REC_START2
#define STOP_M DYN_REC_STOP

#define MO_MOVE MO(MOVE)
#define MO_MOUS MO(MOUS)
#define MO_NUM  MO(NUM)
#define TG_GAME TG(GAME)


#define C_TAB LCTL_T(KC_TAB)
#define C_ENT LCTL_T(KC_ENT)
#define M_SPC LALT_T(KC_SPC)
#define OSM_S OSM(MOD_LSFT)
#define OSM_C OSM(MOD_LCTL)
#define OSM_M OSM(MOD_LALT)
#define OSM_G OSM(MOD_LGUI)
#define OSL_NUM OSL(NUM)
#define OSL_SYM OSL(SYM)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* BASE
 */
[BASE] = LAYOUT_planck_grid(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        C_TAB,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, C_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_GRV,  E_MAGIT, KC_LGUI, KC_LALT, MO_MOVE, KC_SPC,  KC_SPC,  OSL_NUM, KC_LPRN, KC_RPRN, MO(SYM), RUN_M1
),

/* MOVEMENT
 */
[MOVE] = LAYOUT_planck_grid(
        L_R_BRC, KC_VOLD, KC_VOLU, KC_END,  _______, HOL_TRM, _______, KC_PGUP, KC_UP,   KC_PGDN, HOL_P,   HOL_THN,
        KC_QUOT, KC_HOME, KC_SPC,  KC_DEL,  HOL_F  , _______, HOL_H,   KC_LEFT, KC_DOWN, KC_RGHT, KC_INS,  _______,
        _______, ML_CMNT, HOL_X,   E_LAST,  MO_MOUS, _______, _______, _______, _______, _______, _______, L_R_PAR,
        KC_LOCK, SONG1,   _______, _______, _______, HOL_R,   HOL_R,   KC_LCTL, DUAL_QU, HOL_QTE, _______, _______
),

/* MUM
 */
[NUM] = LAYOUT_planck_grid(
        // left hand
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSLS, _______,
        _______, _______, _______, _______, KC_RCTL, _______, _______, _______, KC_LBRC, KC_RBRC, _______, _______
),

[MOUS] = LAYOUT_planck_grid(
        _______, _______, _______, _______, _______, _______, KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_WH_L, KC_WH_R, KC_BTN3, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
[SYM] = LAYOUT_planck_grid(
        TG_GAME, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, STOP_M,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        MU_MOD,  AU_TOG,  MU_TOG,  _______, _______, _______, _______, _______, AU_TOG,  MU_TOG,  _______, REC_M1
),

/* GAMES

*/
[GAME] = LAYOUT_planck_grid(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        KC_TAB,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        KC_LCTL, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, TG_GAME
),
};

#undef MARIO_GAMEOVER
#define MARIO_GAMEOVER \
    HD_NOTE(_C5 ), \
    HD_NOTE(_G4 ), \
    H__NOTE(_E4 ), \
    H__NOTE(_A4 ), \
    H__NOTE(_B4 ), \
    H__NOTE(_A4 ), \
    H__NOTE(_AF4), \
    H__NOTE(_BF4), \
    H__NOTE(_AF4), \
    WD_NOTE(_G4 ),

#define E1M1  \
    Q__NOTE(_E3 ), \
    Q__NOTE(_E3 ), \
    Q__NOTE(_E4 ), \
    Q__NOTE(_E3 ), \
    Q__NOTE(_E3 ), \
    Q__NOTE(_D4 ), \
    Q__NOTE(_E3 ), \
    Q__NOTE(_E3 ), \
    Q__NOTE(_C4 ), \
    Q__NOTE(_E3 ), \
    Q__NOTE(_E3 ), \
    Q__NOTE(_BF3), \
    Q__NOTE(_E3 ), \
    Q__NOTE(_E3 ), \
    Q__NOTE(_B3 ), \
    Q__NOTE(_C4 ), \
    Q__NOTE(_E3 ), \
    Q__NOTE(_E3 ), \
    Q__NOTE(_E4 ), \
    Q__NOTE(_E3 ), \
    Q__NOTE(_E3 ), \
    Q__NOTE(_D4 ), \
    Q__NOTE(_E3 ), \
    Q__NOTE(_E3 ), \
    Q__NOTE(_C4 ), \
    Q__NOTE(_E3 ), \
    Q__NOTE(_E3 ), \
    H__NOTE(_BF3),

float mysong [][2] = SONG(E1M1);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  if (record->event.pressed) {
    switch (keycode) {
    // dynamically generate these.
    case L_R_PAR:
      SEND_STRING("()"SS_TAP(X_LEFT));
      break;
    case L_R_BRC:
      SEND_STRING("[]"SS_TAP(X_LEFT));
      break;
    case E_GO_L:
      SEND_STRING(SS_LCTRL("x")SS_TAP(X_LEFT));
      break;
    case E_GO_R:
      SEND_STRING(SS_LCTRL("x")SS_TAP(X_RIGHT));
      break;
    case E_LAST:
      SEND_STRING(SS_LCTRL("c "));
      break;
    case E_MAGIT:
      SEND_STRING(SS_LCTRL(SS_LSFT(SS_LALT("g"))));
      break;
    case ML_CMNT:
      SEND_STRING("(*  *)"SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT));
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
      break;
    case HOL_P:
      SEND_STRING(SS_LALT("h")"p");
      break;
    case HOL_F:
      SEND_STRING(SS_LALT("h")"e");
      break;
    case HOL_R:
      SEND_STRING(SS_LALT("hr"));
      break;
    case HOL_H:
      SEND_STRING(SS_LALT("h"));
      break;
    case HOL_TRM:
      SEND_STRING("` ` ` ` ");
      break;
    case HOL_QTE:
      SEND_STRING("` ` ");
      break;
    case DUAL_QU:
      SEND_STRING("' ' "SS_TAP(X_LEFT));
      break;
    case HOL_THN:
      SEND_STRING("\\\\\\\\ ");
      break;
       case HOL_APP:
      SEND_STRING(" |> ");
      break;
    case HOL_FS:
      SEND_STRING("fs []"SS_TAP(X_LEFT));
      break;
    case HOL_RFS:
      SEND_STRING("rfs []"SS_TAP(X_LEFT));
      break;
    case HOL_RW:
      SEND_STRING("rw []"SS_TAP(X_LEFT));
      break;
    case HOL_CSE:
      SEND_STRING("Cases_on ` ` "SS_TAP(X_LEFT));
      break;
    case HOL_IND:
      SEND_STRING("ho_match_mp_tac");
      break;
    case HOL_MET:
      SEND_STRING("metis_tac []"SS_TAP(X_LEFT));
      break;
    case SONG1:
      if (is_audio_on()) {
        PLAY_SONG(mysong);
      } else {
        audio_on();
        PLAY_SONG(mysong);
        audio_off();
      }
      break;
    }
  }
  return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    planck_ez_left_led_off();
    planck_ez_right_led_off();
    uint8_t layer = biton32(state);
    switch (layer) {
        case MOVE:
            planck_ez_left_led_on();
            break;
        case NUM:
            planck_ez_right_led_on();
            break;
        case MOUS:
            planck_ez_right_led_on();
            planck_ez_left_led_on();
            break;
        default:
            break;
    }
    return state;
}
