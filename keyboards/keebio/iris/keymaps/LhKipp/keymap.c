/* First, you have to find the device ID of the keyboard to change: */

/*   $ xinput -list | grep -i key */
/*   ⎣ Virtual core keyboard                     id=3    [master keyboard (2)] */
/*   ↳ Virtual core XTEST keyboard               id=5    [slave  keyboard (3)] */
/*   ↳ Power Button                              id=6    [slave  keyboard (3)] */
/*   ↳ Power Button                              id=7    [slave  keyboard (3)] */
/*   ↳ LITEON Technology USB Keyboard            id=9    [slave  keyboard (3)] */
/*   ↳ LITEON Technology USB Keyboard            id=10   [slave  keyboard (3)] */

/*   Then change the layout using setxkbmap: */

/*   $ setxkbmap -device 9 dvorak */

/*   Some versions of setxkbmap need a '-layout' argument: */

/*   $ setxkbmap -device 9 -layout dvorak */
#include QMK_KEYBOARD_H
extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _SC 1
#define _DVORAK 2
#define _SPEC1 3
#define _SPEC2 4

#define SFT_ESC LSFT_T(KC_ESC) //Shift on press, Escape on tap
#define SFT_ENT LSFT_T(KC_ENT) //Shift on press, Escape on tap
#define LCTRL_SPC LCTL_T(KC_SPC) //Ctrl on press, Space on tap

#define OS_LGUI OSM(MOD_LGUI) //LGUI as one shot key
#define OS_LALT OSM(MOD_LALT) //LGUI as one shot key
#define OS_SPEC1 OSL(_SPEC1) //LGUI as one shot key
#define OS_SPEC2 OSL(_SPEC2) //LGUI as one shot key

#define SC DF(_SC)
#define QWERT DF(_QWERTY)
#define DVORAK DF(_DVORAK)

enum custom_keycodes {
  QWERTY = SAFE_RANGE,

  GER_COM,
  GER_DOT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_INS,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Z,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     SFT_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SLSH, SFT_ENT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     OS_LGUI, KC_Y,    KC_X,    KC_C,    KC_V,    KC_B,    SC,               DVORAK,  KC_N,    KC_M,    GER_COM, GER_DOT, KC_MINS ,KC_RALT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                   KC_LALT, LCTRL_SPC, KC_LBRC,                  KC_RBRC, OS_SPEC1, OS_SPEC2
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘

  ),

  [_SC] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_F1,            KC_F10,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                     KC_LALT, KC_SPC, KC_ESC,                KC_ENT,  KC_LCTL,   QWERT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_DVORAK] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_INS,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_SCLN, KC_COMM, KC_DOT,  KC_P,    KC_Y,                               KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     SFT_ESC, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                               KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    SFT_ENT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     OS_LGUI, KC_QUOT, KC_Q,    KC_J,    KC_K,    KC_X,    KC_RALT,           QWERT,  KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    OS_LALT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LALT , LCTRL_SPC,KC_RALT,                  KC_RALT,OS_SPEC1,OS_SPEC2
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_SPEC1] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_ASTR, KC_DQUO, KC_LEFT, KC_RGHT, KC_GRV,                             KC_1,    KC_DOWN, KC_UP,   KC_QUOT, KC_PIPE, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_LBRC, KC_LT,   KC_LCBR, KC_LPRN, KC_AMPR,                            KC_EQL,  KC_RPRN, KC_RCBR, KC_GT,   KC_RBRC, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_TILD, KC_PLUS, KC_0,    KC_DLR,  KC_BSLS, _______,          _______, KC_CIRC, KC_EXLM, KC_HASH, KC_AT,   KC_PERC, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                     _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_SPEC2] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_PSCR, _______, KC_BRIU, KC_BRID, _______,                            _______, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_F11,  KC_F12,  KC_HOME, KC_END,  _______,                            _______, KC_PGDN, KC_PGUP, KC_F13,  KC_F14,  _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  _______,          _______, KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,  _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case GER_COM:
            if(record->event.pressed){
                if(keyboard_report->mods & (MOD_BIT(KC_LSFT))){ //If shift is on
                        SEND_STRING(SS_UP(X_LSHIFT)SS_TAP(X_SCOLON)SS_DOWN(X_LSHIFT));
                }else{
                        SEND_STRING(SS_TAP(X_COMMA));
                }
            }
            break;
    case GER_DOT:
            if(record->event.pressed){
                if(keyboard_report->mods & (MOD_BIT(KC_LSFT))){ //If shift is on
                        SEND_STRING(SS_TAP(X_SCOLON));
                }else{
                        SEND_STRING(SS_TAP(X_DOT));
                }
            }
            break;
  }
  return true;
}
