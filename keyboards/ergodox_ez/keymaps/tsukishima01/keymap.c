#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_jp.h"


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
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)

enum custom_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  JP_LSPO,
  JP_RSPC,
};

enum combos {
  ER_UP,
  DF_SPACE,
  CV_DOWN,
  SD_LEFT,
  FG_RIGHT,
  UI_F9,
  IO_F8,
  HJ_F6,
  JK_F10,
  KL_F7,
  Mc_LEFT,
  cd_RIGHT,
};

const uint16_t PROGMEM er_combo[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM cv_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM sd_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM fg_combo[] = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM ui_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM io_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM hj_combo[] = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM mc_combo[] = {KC_M, KC_COMMA, COMBO_END};
const uint16_t PROGMEM cd_combo[] = {KC_COMMA, KC_DOT, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [ER_UP] = COMBO(er_combo, KC_UP),
  [DF_SPACE] = COMBO(df_combo, KC_SPACE),
  [CV_DOWN] = COMBO(cv_combo, KC_DOWN),
  [SD_LEFT] = COMBO(sd_combo, KC_LEFT),
  [FG_RIGHT] = COMBO(fg_combo, KC_RIGHT),
  [UI_F9] = COMBO(ui_combo, KC_F9),
  [IO_F8] = COMBO(io_combo, KC_F8),
  [HJ_F6] = COMBO(hj_combo, KC_F6),
  [JK_F10] = COMBO(jk_combo, KC_F10),
  [KL_F7] = COMBO(kl_combo, KC_F7),
  [Mc_LEFT] = COMBO(mc_combo, KC_LEFT),
  [cd_RIGHT] = COMBO(cd_combo, KC_RIGHT)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ergodox_pretty(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           LGUI(KC_L),                                     KC_TRANSPARENT, KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_EQUAL,
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           LALT(LCTL(KC_TAB)),                                KC_SCOLON,      KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLASH,
    KC_LCTRL,       KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_MINUS,       KC_RCTRL,
    KC_LSHIFT,      KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           LALT(KC_TAB),                                   KC_QUOTE,       KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_RSHIFT,
    LSFT(KC_LCTRL), KC_ENTER,       KC_LGUI,        KC_LALT,        LT(1,KC_F13),                                                                                                   LT(2,KC_F14),   KC_LALT,        KC_RGUI,        KC_SPACE,       RSFT(KC_RCTRL),
                                                                                                    LGUI(LSFT(KC_S)),KC_PAUSE,       KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_SPACE,       KC_BSPACE,      TG(2),          KC_CAPSLOCK,    KC_DELETE,      KC_ENTER
  ),
  [1] = LAYOUT_ergodox_pretty(
    LALT(KC_F4),    KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RPRN,        RESET,
    LCTL(KC_W),     KC_MS_BTN2,     KC_MS_BTN1,     KC_MS_UP,       LCTL(KC_S),     KC_Y,           KC_TRANSPARENT,                                 KC_NO,          KC_NO,          KC_MS_ACCEL2,   RSFT(KC_LEFT),  RSFT(KC_RIGHT), KC_NO,          KC_NO,
    KC_TRANSPARENT, LCTL(KC_A),     KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    LCTL(KC_Y),                                                                     KC_PGUP,        KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TRANSPARENT,
    KC_TRANSPARENT, LCTL(KC_Z),     LCTL(KC_X),     LCTL(KC_C),     LCTL(KC_V),     KC_N,           KC_TRANSPARENT,                                 KC_NO,          KC_PGDOWN,      KC_HOME,        RSFT(KC_HOME),  RSFT(KC_END),   KC_END,         KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,        KC_NO,                                          KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
    KC_TRANSPARENT, KC_NO,          KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_KP_EQUAL,    KC_NO,                                          KC_NO,          KC_NO,          KC_LBRACKET,    KC_RBRACKET,    KC_COLN,        KC_SCOLON,      KC_F12,
    KC_TRANSPARENT, KC_KP_MINUS,    KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_KP_SLASH,                                                                    KC_NO,          KC_LPRN,        KC_RPRN,        KC_DQUO,        KC_QUOTE,       KC_TRANSPARENT,
    KC_TRANSPARENT, KC_KP_PLUS,     KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_KP_ASTERISK, KC_TRANSPARENT,                                 KC_NO,          KC_NO,          KC_LCBR,        KC_RCBR,        KC_GRAVE,       KC_TILD,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_KP_DOT,      KC_KP_0,                                                                                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_SCROLLLOCK,  KC_PSCREEN,     KC_INSERT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_LALT,        KC_TRANSPARENT, KC_TRANSPARENT, KC_LGUI,        KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    LGUI(LSFT(KC_4)),KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    TO(0),          KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, LGUI(KC_SPACE), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case JP_LSPO:
      perform_space_cadet(record, KC_LSFT, KC_LSFT, KC_8);
      return false;
    case JP_RSPC:
      perform_space_cadet(record, KC_LSFT, KC_LSFT, KC_9);
      return false;
  }
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
