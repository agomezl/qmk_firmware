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
  E_SAVE,
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
  ML_CMNT,
  GUI_LY,
  DYNAMIC_MACRO_RANGE
};

// Macros
#include "dynamic_macro.h"

#define RUN_M1 DYN_MACRO_PLAY1
#define RUN_M2 DYN_MACRO_PLAY2
#define REC_M1 DYN_REC_START1
#define REC_M2 DYN_REC_START2
#define STOP_M DYN_REC_STOP

#define MO_MOVE MO(MOVE)
#define MO_MOUS MO(MOUS)
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
        RUN_M1,  KC_GRV,  KC_QUOT, OSM_M,   MO_MOVE, KC_SPC,  KC_SPC,  OSL_NUM, OSM_G,   KC_LOCK, MO(SYM), RUN_M2
),

/* MOVEMENT
 */
[MOVE] = LAYOUT_planck_grid(
        L_R_BRC, KC_VOLD, KC_VOLU, KC_END,  _______, _______, HOL_Y,   KC_PGUP, KC_UP,   KC_PGDN, HOL_P,   HOL_THN,
        _______, KC_HOME, KC_SPC,  KC_DEL,  HOL_F  , _______, HOL_H,   KC_LEFT, KC_DOWN, KC_RGHT, KC_INS,  _______,
        _______, _______, HOL_X,   E_LAST,  MO_MOUS, _______, _______, _______, KC_LPRN, KC_RPRN, _______, L_R_PAR,
        _______, _______, E_MAGIT, _______, _______, HOL_R,   HOL_R,   GUI_LY,  _______, _______, _______, HOL_TRM
),

/* MUM
 */
[NUM] = LAYOUT_planck_grid(
        // left hand
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,
        _______, DUAL_QU, HOL_QTE, ML_CMNT, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_BSLS, _______,
        _______, _______, _______, _______, GUI_LY,  _______, _______, _______, _______, _______, _______, _______
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
        REC_M1,  _______, MU_TOG,  _______, _______, _______, _______, _______, _______, MU_TOG,  _______, REC_M2
),

/* GAMES

*/
[GAME] = LAYOUT_planck_grid(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        KC_TAB,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        KC_LCTL, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_record_dynamic_macro(keycode, record)) {
        return false;
    }

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
    case E_SAVE:
      SEND_STRING(SS_LCTRL("x")SS_LCTRL("s"));
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
      SEND_STRING("` ` ` ` "SS_TAP(X_LEFT)SS_TAP(X_LEFT));
      break;
    case HOL_QTE:
      SEND_STRING("` ` "SS_TAP(X_LEFT));
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
    case HOL_FND:
      SEND_STRING(// open hol window
                  SS_LCTRL("x")"1"SS_LALT("h")"3"
                  // move to hol window
                  SS_LCTRL("x")SS_TAP(X_RIGHT)
                  // write in it
                  "print_find \" \" ;"SS_TAP(X_LEFT)SS_TAP(X_LEFT));
      break;
    case HOL_MCH:
      SEND_STRING(// open hol window
                  SS_LCTRL("x")"1"SS_LALT("h")"3"
                  // move to hol window
                  SS_LCTRL("x")SS_TAP(X_RIGHT)
                  // write in it
                  "print_match [] \" \" ;"SS_TAP(X_LEFT)SS_TAP(X_LEFT));
      break;
    case GUI_LY:
      reset_oneshot_layer();
      clear_keyboard_but_mods();
      set_oneshot_mods(MOD_LGUI);
      break;
    }
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(MOVE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
}

void dip_update(uint8_t index, bool active) {
  switch (index) {
    case 0:
      if (active) {
        layer_on(MOVE);
      } else {
        layer_off(MOVE);
      }
      break;
    case 1:
      if (active) {
        muse_mode = true;
      } else {
        muse_mode = false;
        #ifdef AUDIO_ENABLE
          stop_all_notes();
        #endif
      }
   }
}

uint32_t layer_state_set_user(uint32_t state) {
    palClearPad(GPIOB, 8);
    palClearPad(GPIOB, 9);
    uint8_t layer = biton32(state);
    switch (layer) {
        case MOVE:
            palSetPad(GPIOB, 9);
            break;
        case NUM:
            palSetPad(GPIOB, 8);
            break;
        case MOUS:
            palSetPad(GPIOB, 9);
            palSetPad(GPIOB, 8);
            break;
        default:
            break;
    }
    return state;
}

void matrix_scan_user(void) {
  #ifdef AUDIO_ENABLE
    if (muse_mode) {
      if (muse_counter == 0) {
        uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
        if (muse_note != last_muse_note) {
          stop_note(compute_freq_for_midi_note(last_muse_note));
          play_note(compute_freq_for_midi_note(muse_note), 0xF);
          last_muse_note = muse_note;
        }
      }
      muse_counter = (muse_counter + 1) % muse_tempo;
    }
  #endif
}
