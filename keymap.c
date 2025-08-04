#include QMK_KEYBOARD_H
#include "features/bongo_cat.h"
#include <stdio.h>

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
  _DVORAK,
  _COLEMAK
};

char wpm_str[10];

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LOWER| LALT |DELETE| /Space  /       \Enter \  |BSP   |LGUI  | RAISE|
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
  KC_LCTL,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,  KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
                       MO(_LOWER), KC_LALT, KC_DELETE,  KC_SPC, KC_ENT, KC_BSPC, KC_LGUI, MO(_RAISE)
),
/* DVORAK
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   '  |   ,  |   .  |   P  |   Y  |                    |   F  |   G  |   C  |   R  |   L  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   A  |   O  |   E  |   U  |   I  |-------.    ,-------|   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   ;  |   Q  |   J  |   K  |   X  |-------|    |-------|   B  |   M  |   W  |   V  |   Z  |   =  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LOWER| LALT |DELETE| /Space  /       \Enter \  |BSP   |LGUI  | RAISE|
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
 [_DVORAK] = LAYOUT(
	KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5,                                KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, 
	KC_TAB, KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y,                        KC_F, KC_G, KC_C, KC_R, KC_L, KC_BSLS, 
	KC_ESC, KC_A, KC_O, KC_E, KC_U, KC_I,                                KC_D, KC_H, KC_T, KC_N, KC_S, KC_SLSH, 
	KC_LSFT, KC_SCLN, KC_Q, KC_J, KC_K, KC_X,       KC_LBRC, KC_RBRC,    KC_B, KC_M, KC_W, KC_V, KC_Z, KC_EQL, 
                              TO(_LOWER), KC_LALT, KC_DELETE,  KC_SPC, KC_ENT, KC_BSPC, KC_LGUI, TO(_RAISE)
	),

/* COLEMAK
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |                    |   J  |   L  |   U  |   Y  |   ;  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   A  |   R  |   S  |   T  |   D  |-------.    ,-------|   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   K  |   M  |   ,  |   .  |   /  |   =  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LOWER| LALT |DELETE| /Space  /       \Enter \  |BSP   |LGUI  | RAISE|
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
 [_COLEMAK] = LAYOUT(
	KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5,                                KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, 
	KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_G,                                KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_BSLS, 
	KC_ESC, KC_A, KC_R, KC_S, KC_T, KC_D,                                KC_H, KC_N, KC_E, KC_I, KC_O, KC_QUOT, 
	KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,        KC_LBRC, KC_RBRC,      KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_EQL, 
                              TO(_LOWER), KC_LALT, KC_DELETE,  KC_SPC, KC_ENT, KC_BSPC, KC_LGUI, TO(_RAISE)
	),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  +   |   ?  |      |  UP  |      |      |                    |   `  |   !  |   @  |   #  |   $  |   %  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  =   |   :  | LEFT | DOWN |RIGHT |      |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   -  |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LSHIFT|   ;  |      |      |      |      |-------|    |-------|   \  |   _  |   +  |   {  |   }  |   |  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LOWER| LALT |DELETE| /Space  /       \Enter \  |BSP   |LGUI  | RAISE|
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  KC_PLUS, KC_QUES, XXXXXXX, KC_UP, XXXXXXX, XXXXXXX,                     KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,
  KC_EQL, KC_COLON, KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX,                  KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TILD,
  KC_LSFT, KC_SCLN , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC,  KC_BACKSLASH, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
                             MO(_LOWER), KC_LALT, KC_DELETE,  KC_SPC, KC_ENT, KC_BSPC, KC_LGUI, MO(_RAISE)
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | HOME | PGUP |   (  |   )  |   A  |  S   |                    |      |      |      |  UP  |      |  |   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | END  | PGDWN|   {  |   }  |   D  |  F   |-------.    ,-------|      |      | LEFT | DOWN | Right|      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LSHIFT|      |   /  |   \  |   Z  |  X   |-------|    |-------|      |      |   C  |   V  |RCTRL | RSFT |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LOWER| LALT |DELETE| /Space  /       \Enter \  |BSP   |LGUI  | RAISE|
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT(
  KC_F1,   KC_F2,   KC_F3,        KC_F4,   KC_F5,   KC_F6,                        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  KC_HOME, KC_PGUP, KC_LPRN,      KC_RPRN, KC_A,  KC_S,                           XXXXXXX, XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, KC_PIPE,
  KC_END,  KC_PGDN, KC_LCBR,      KC_RCBR, KC_D,    KC_F,                         XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX,
  KC_LSFT, XXXXXXX, KC_SLSH, KC_BACKSLASH, KC_Z,    KC_X,   _______, _______,     XXXXXXX, XXXXXXX, KC_C, KC_V, KC_RCTL, KC_RSFT,
                                   _______, _______, _______,  _______, _______,  _______, _______, _______
),
/* ADJUST
 * ,------------------------------------------.                    ,-----------------------------------------.
 * |       |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |-------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |M_MAKE |EEPRST|      |      |      |      |                    |      |      |      |COLMAK|DVORAK|QWERTY|
 * |-------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |M_VRSN |M_MALL|      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |-------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |M_FLSH |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `------------------------------------------/       /     \      \-----------------------------------------'
 *                    |      |      |      | /       /       \      \  |      |      |      |
 *                    |      |      |      |/       /         \      \ |      |      |      |
 *                    `----------------------------'           '------''--------------------'
 */
[_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, TO(_COLEMAK),  TO(_DVORAK), TO(_QWERTY), 
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
                             _______, _______, _______,  _______, _______,  _______, _______, _______ 
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

/*
  // This is my old, factory made OLED task. It has a keylogger on master and lilly logo on slave.
  static bool void oldOledTask(void) {
    if (is_keyboard_master()) {
      // If you want to change the display of OLED, you need to change here
      oled_write_ln(read_layer_state(), false);
      oled_write_ln(read_keylog(), false);
      oled_write_ln(read_keylogs(), false);
      //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
      //oled_write_ln(read_host_led_state(), false);
      //oled_write_ln(read_timelog(), false);
    } else {
      oled_write(read_logo(), false);
    }
      return false;
  }
*/

// ###################################################################### BONGOCAT FUN ################################################################################
//
// Render master OLED display
//
static void render_status(void) {
    oled_clear();
    // WPM
    oled_write_P(PSTR("      "), false);
    sprintf(wpm_str, "%03d", get_current_wpm());
    oled_write(wpm_str, false);
    oled_write_P(PSTR("   WPM"), false);
    
    // Layer indicator
    oled_write_P(PSTR("\n      LAYER "), false);

    switch (get_highest_layer(layer_state)) {
      case _RAISE:
	        oled_write_P(PSTR("RAISE"), false);
	        break;
      case _LOWER:
          oled_write_P(PSTR("LOWER"), false);
          break;
      case _ADJUST:
          oled_write_P(PSTR("ADJUST"), false);
          break;
      case _DVORAK:
          oled_write_P(PSTR("DVORAK"), false);
          break;
      case _COLEMAK:
          oled_write_P(PSTR("COLEMAK"), false);
          break;
      default:
          oled_write_P(PSTR("QWERTY"), false);
          break;
    }
}

//
// OLED display rendering
//
bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // Master
        render_status();
    } else {
        render_bongo_cat();
        oled_set_cursor(0, 6);
        oled_write_P(PSTR("WPM:  "), false);
        oled_write(get_u8_str(get_current_wpm(), ' '), false);
    }
	
	return 0;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}


