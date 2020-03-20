#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"
#include "keymap_swedish.h"
#include "keymap_br_abnt2.h"
#include "keymap_canadian_multilingual.h"
#include "keymap_german_ch.h"
#include "keymap_jp.h"
#include "keymap_bepo.h"


// NICOLA親指シフト
#include "nicola.h"
NGKEYS nicola_keys;
// NICOLA親指シフト

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL

enum keymap_layers {
  _WIN,
  _NICOLA, // NICOLA親指シフト入力レイヤー
  _NUMMOUSE,
  _SIGN,
  _MAC,
};

enum custom_keycodes {
  RGB_SLD = NG_SAFE_RANGE,
  KC_KANA2
  };

enum combos {
  DG_SHIFTRIGHT,
  FG_RIGHT,
  SD_LEFT,
  SF_SHIFTLEFT,
  DF_DOWN,
  ER_UP,
  CV_SPACE,
  JK_PAGEDOWN,
  UI_PAGEUP,
  WE_HOME,
  RT_END,
  AX_CAPS,
  Mc_KAGIL,
  cd_KAGIR
};

const uint16_t PROGMEM dg_combo[] = {KC_D, KC_G, COMBO_END};
const uint16_t PROGMEM fg_combo[] = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM sd_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM sf_combo[] = {KC_S, KC_F, COMBO_END};
const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM er_combo[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM cv_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM ui_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM rt_combo[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM ax_combo[] = {KC_A, KC_X, COMBO_END};
const uint16_t PROGMEM mc_combo[] = {KC_M, KC_COMMA, COMBO_END};
const uint16_t PROGMEM cd_combo[] = {KC_COMMA, KC_DOT, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [DG_SHIFTRIGHT] = COMBO(dg_combo, LSFT(KC_RIGHT)),
  [FG_RIGHT] = COMBO(fg_combo, KC_RIGHT),
  [SD_LEFT] = COMBO(sd_combo, KC_LEFT),
  [SF_SHIFTLEFT] = COMBO(sf_combo, LSFT(KC_LEFT)),
  [DF_DOWN] = COMBO(df_combo, KC_DOWN),
  [ER_UP] = COMBO(er_combo, KC_UP),
  [CV_SPACE] = COMBO(cv_combo, KC_SPACE),
  [JK_PAGEDOWN] = COMBO(jk_combo, KC_PGDOWN),
  [UI_PAGEUP] = COMBO(ui_combo, KC_PGUP),
  [WE_HOME] = COMBO(we_combo, KC_HOME),
  [RT_END] = COMBO(rt_combo, KC_END),
  [AX_CAPS] = COMBO(ax_combo, KC_CAPSLOCK),
  [Mc_KAGIL] = COMBO(mc_combo, KC_LBRACKET),
  [cd_KAGIR] = COMBO(cd_combo, KC_RBRACKET)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_WIN] = LAYOUT_ergodox_pretty(
    KC_GRAVE,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_ESCAPE,                                      KC_DELETE,      KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_EQUAL,
    KC_BSLASH,      KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_KANA2,                                       KC_F10,         KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_SCOLON,
    KC_LCTRL,       KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_MINUS,       KC_QUOTE,
    KC_RSHIFT,      KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           TG(_SIGN),                                      TG(_NUMMOUSE),  KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_RSHIFT,
    KC_LGUI,        KC_SPACE,       KC_ENTER,       KC_LALT,        LT(_NUMMOUSE,KC_F13),                                                                                           LT(_SIGN,KC_F14),KC_RCTRL,      KC_BSPACE,      KC_TAB,         KC_PAUSE,
                                                                                                    KC_TRANSPARENT, RESET,          LGUI(LSFT(KC_S)),KC_ESCAPE,
                                                                                                                    TO(_MAC),       LCTL(KC_F7),
                                                                                    KC_TAB,         KC_BSPACE,      KC_DELETE,      LGUI(KC_S),     KC_ENTER,       KC_SPACE
  ),
  [_NICOLA] = LAYOUT_ergodox_pretty(
    LGUI(LSFT(KC_S)),KC_1,          KC_2,           KC_3,           KC_4,           KC_5,           KC_TRANSPARENT,                                 KC_F6,          KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_EQUAL,
    LCTL(KC_F7),    NG_Q,           NG_W,           NG_E,           NG_R,           NG_T,           KC_TRANSPARENT,                                 KC_F7,          NG_Y,           NG_U,           NG_I,           NG_O,           NG_P,           KC_MINUS,
    KC_LCTRL,       NG_A,           NG_S,           NG_D,           NG_F,           NG_G,                                                                           NG_H,           NG_J,           NG_K,           NG_L,           NG_SCLN,        RCTL_T(KC_QUOTE),
    KC_LSHIFT,      NG_Z,           NG_X,           NG_C,           NG_V,           NG_B,           MO(_NUMMOUSE),                                  MO(_NUMMOUSE),  NG_N,           NG_M,           NG_COMM,        NG_DOT,         NG_SLSH,        KC_RSHIFT,
    KC_TRANSPARENT, KC_TRANSPARENT,KC_TRANSPARENT,  KC_TRANSPARENT, NG_SHFTL,                                                                                                       NG_SHFTR,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_NO,          KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [_NUMMOUSE] = LAYOUT_ergodox_pretty(
    LALT(KC_F4),    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
    LCTL(KC_W),     KC_HOME,        LALT(LSFT(KC_TAB)),KC_MS_UP,    LALT(KC_TAB),   KC_PGUP,        KC_NO,                                          KC_TRANSPARENT, KC_EQUAL,       KC_7,           KC_KP_8,        KC_KP_9,        KC_KP_COMMA,    KC_F12,
    KC_TRANSPARENT, KC_MS_BTN2,     KC_MS_LEFT,     KC_MS_BTN1,     KC_MS_RIGHT,    KC_PGDOWN,                                                                      KC_KP_PLUS,     KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_ASTR,        KC_NO,
    KC_TRANSPARENT, KC_END,         LCTL(LSFT(KC_TAB)),KC_MS_DOWN,  LCTL(KC_TAB),   KC_NO,          KC_NO,                                          KC_TRANSPARENT, KC_KP_MINUS,    KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_KP_SLASH,    KC_TRANSPARENT,
    KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_KP_0,        KC_NO,          KC_KP_DOT,      KC_TRANSPARENT, KC_NO,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_NO,          KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [_SIGN] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_NO,                                          KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,
    KC_TRANSPARENT, KC_EXLM,        KC_AT,          KC_HASH,        KC_LCBR,        KC_RCBR,        KC_NO,                                          KC_TRANSPARENT, KC_NO,          KC_AUDIO_VOL_UP,DYN_REC_START1, DYN_REC_START2, KC_INSERT,      KC_TRANSPARENT,
    KC_PIPE,        KC_DLR,         KC_PERC,        KC_CIRC,        KC_LPRN,        KC_RPRN,                                                                        KC_NO,          KC_AUDIO_VOL_DOWN,DYN_MACRO_PLAY1,DYN_MACRO_PLAY2,KC_PSCREEN,   KC_TRANSPARENT,
    KC_TILD,        KC_AMPR,        KC_ASTR,        KC_QUES,        KC_LBRACKET,    KC_RBRACKET,    KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_NO,          KC_AUDIO_MUTE,  DYN_REC_STOP,   KC_NO,          KC_SCROLLLOCK,  KC_TRANSPARENT,
    KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_NO,          KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [_MAC] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_LALT,        KC_TRANSPARENT, KC_TRANSPARENT, KC_LGUI,        LT(_NUMMOUSE,KC_LANG2),                                                                                         LT(_SIGN,KC_LANG1),KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, LGUI(LSFT(KC_4)),KC_TRANSPARENT,
                                                                                                                    TO(_WIN),       KC_NO,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LGUI(KC_SPACE), KC_TRANSPARENT, KC_TRANSPARENT
  ),
};

void matrix_init_user(void) {
  // NICOLA親指シフト
  set_nicola(_NICOLA);
  // NICOLA親指シフト
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_KANA2:
      if (record->event.pressed) {
        if (nicola_state()) {
          nicola_off();
        } else {
          nicola_on();
        }
      }
      return false;
      break;
  };
  // NICOLA親指シフト
  bool a = true;
  if (nicola_state()) {
    nicola_mode(keycode, record);
    a = process_nicola(keycode, record);
    // update_led();
  }
  if (a == false) return false;
  // NICOLA親指シフト

  return true;
  }

uint32_t layer_state_set_user(uint32_t state) {
  uint8_t layer = biton32(state);
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    case 1:
      ergodox_right_led_1_on();
      break;
    case 2:
      ergodox_right_led_2_on();
      break;
    case 3:
      ergodox_right_led_3_on();
      break;
    case 4:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      break;
    case 5:
      ergodox_right_led_1_on();
      ergodox_right_led_3_on();
      break;
    case 6:
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    case 7:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    default:
      break;
  }
  return state;
};
