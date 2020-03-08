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
  _NUMKEY,
  _MOUSE,
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
  UI_PAGEUP
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

combo_t key_combos[COMBO_COUNT] = {
  [DG_SHIFTRIGHT] = COMBO(dg_combo, LSFT(KC_RIGHT)),
  [FG_RIGHT] = COMBO(fg_combo, KC_RIGHT),
  [SD_LEFT] = COMBO(sd_combo, KC_LEFT),
  [SF_SHIFTLEFT] = COMBO(sf_combo, LSFT(KC_LEFT)),
  [DF_DOWN] = COMBO(df_combo, KC_DOWN),
  [ER_UP] = COMBO(er_combo, KC_UP),
  [CV_SPACE] = COMBO(cv_combo, KC_SPACE),
  [JK_PAGEDOWN] = COMBO(jk_combo, KC_PGDOWN),
  [UI_PAGEUP] = COMBO(ui_combo, KC_PGUP)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_WIN] = LAYOUT_ergodox_pretty(
    KC_NO,          KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_TRANSPARENT,                                 KC_F6,          KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,
    KC_NO,          KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_KANA2,                                       KC_F7,          KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_EQUAL,
    KC_LCTRL,       KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCOLON,      KC_QUOTE,
    KC_LSHIFT,      KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           MO(_NUMKEY),                                    LT(_NUMKEY,KC_F10),KC_N,        KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_RSHIFT,
    KC_LGUI,        KC_CAPSLOCK,    MO(_MOUSE),     KC_LALT,        KC_F13,                                                                                                         KC_F14,         KC_NO,          TT(_MOUSE),     KC_PAUSE,       KC_NO,
                                                                                                    KC_ESCAPE,      RESET,          LGUI(LSFT(KC_S)),KC_ESCAPE,
                                                                                                                    TG(_MAC),       LCTL(KC_F7),
                                                                                    KC_TAB,         KC_BSPACE,      KC_DELETE,      LGUI(KC_S),     KC_ENTER,       KC_SPACE
  ),
  [_NICOLA] = LAYOUT_ergodox_pretty(
    LGUI(LSFT(KC_S)),KC_1,          KC_2,           KC_3,           KC_4,           KC_5,           KC_TRANSPARENT,                                 KC_F6,          KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,
    LCTL(KC_F7),    NG_Q,           NG_W,           NG_E,           NG_R,           NG_T,           KC_TRANSPARENT,                                 KC_F7,          NG_Y,           NG_U,           NG_I,           NG_O,           NG_P,           KC_EQUAL,
    KC_LCTRL,       NG_A,           NG_S,           NG_D,           NG_F,           NG_G,                                                                           NG_H,           NG_J,           NG_K,           NG_L,           NG_SCLN,        KC_QUOTE,
    KC_LSHIFT,      NG_Z,           NG_X,           NG_C,           NG_V,           NG_B,           MO(_NUMKEY),                                    MO(_NUMKEY),    NG_N,           NG_M,           NG_COMM,        NG_DOT,         NG_SLSH,        KC_RSHIFT,
    KC_TRANSPARENT, KC_TRANSPARENT,KC_TRANSPARENT,  KC_TRANSPARENT, NG_SHFTL,                                                                                                       NG_SHFTR,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_NO,          KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [_NUMKEY] = LAYOUT_ergodox_pretty(
    KC_GRAVE,       KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRANSPARENT,                                 KC_NO,          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
    KC_TILD,        KC_EXLM,        KC_AT,          KC_HASH,        KC_LCBR,        KC_RCBR,        KC_TRANSPARENT,                                 KC_TAB,         KC_TRANSPARENT, KC_7,           KC_KP_8,        KC_KP_9,        KC_KP_SLASH,    KC_F12,
    KC_PIPE,        KC_DLR,         KC_PERC,        KC_CIRC,        KC_LPRN,        KC_RPRN,                                                                        KC_S,           KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_ASTR,        KC_PLUS,
    KC_BSLASH,      KC_AMPR,        KC_ASTR,        KC_QUES,        KC_LBRACKET,    KC_RBRACKET,    KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_COMMA,       KC_MINUS,
    KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_KP_0,        KC_KP_DOT,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_NO,          KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [_MOUSE] = LAYOUT_ergodox_pretty(
    LALT(KC_F4),    KC_TRANSPARENT, KC_PC_CUT,      KC_PC_COPY,     KC_PC_PASTE,    KC_HOME,        KC_NO,                                          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_NO,          KC_NO,          LALT(LSFT(KC_TAB)),KC_MS_UP,    LALT(KC_TAB),   KC_PGUP,        KC_NO,                                       KC_TRANSPARENT,KC_TRANSPARENT,  KC_PSCREEN,     KC_INSERT,      KC_SCROLLLOCK,  KC_NO,          KC_TRANSPARENT,
    LCTL(KC_W),     KC_MS_BTN2,     KC_MS_LEFT,     KC_MS_BTN1,     KC_MS_RIGHT,    KC_PGDOWN,                                                                      KC_TRANSPARENT, KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TRANSPARENT,
    KC_TRANSPARENT, KC_NO,          LCTL(LSFT(KC_TAB)),KC_MS_DOWN,  LCTL(KC_TAB),   KC_END,         KC_NO,                                          KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_MS_ACCEL2,                                                                                                   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_NO,          KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
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
