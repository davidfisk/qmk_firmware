/*
Copyright 2019 @foostan
Copyright 2023 David Fisk

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LCTL_T(KC_D)
#define HOME_F LSFT_T(KC_F)

// Right-hand home row mods
#define HOME_J RSFT_T(KC_J)
#define HOME_K RCTL_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCLN RGUI_T(KC_SCLN)

// TODO right hand shift when hold, ENTER when tapped
#define SHFT_ENTR RSFT_T(KC_ENT)

// thumb cluster
#define LT2_SPC LT(2, KC_SPC)
#define LT3_SPC LT(3, KC_SPC)
#define LCTL_ESC LCTL_T(KC_ESC)
#define MO5 MO(5)
#define MO4 MO(4)

// random keys
#define LSFT_CAPS LSFT_T(KC_CAPS)

#define L_BASE 0
#define L_HMR_OFF 1
#define L_LOWER 2
#define L_RAISE 3
#define L_ADJUST 4
#define L_MISC 5

enum custom_keycodes { DFC_LALT, DFC_LGUI, TOG_DFLT };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {[L_BASE] = LAYOUT_split_3x6_3(
                                                                  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                                                                  KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                  LCTL_ESC, HOME_A, HOME_S, HOME_D, HOME_F, KC_G, KC_H, HOME_J, HOME_K, HOME_L, HOME_SCLN, KC_QUOT,
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                  LSFT_CAPS, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, SHFT_ENTR,
                                                                  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                                  KC_LGUI, KC_LALT, LT2_SPC, LT3_SPC, MO4, MO5
                                                                  //`--------------------------'  `--------------------------'

                                                                  ),

                                                              [L_HMR_OFF] = LAYOUT_split_3x6_3(
                                                                  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                                                                  KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                  LCTL_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                  LSFT_CAPS, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, SHFT_ENTR,
                                                                  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                                  KC_LGUI, KC_LALT, LT2_SPC, LT3_SPC, MO4, MO5
                                                                  //`--------------------------'  `--------------------------'
                                                                  ),

                                                              [L_LOWER] = LAYOUT_split_3x6_3(
                                                                  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                                                                  KC_TAB, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, TOG_DFLT,
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                  LCTL_ESC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PAST, KC_4, KC_5, KC_6, KC_PPLS, KC_PEQL,
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                  LSFT_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSLS, KC_1, KC_2, KC_3, KC_PMNS, SHFT_ENTR,
                                                                  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                                  KC_LGUI, KC_LALT, LT2_SPC, LT3_SPC, KC_DOT, KC_0
                                                                  //`--------------------------'  `--------------------------'
                                                                  ),

                                                              [L_RAISE] = LAYOUT_split_3x6_3(
                                                                  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                                                                  KC_GRV, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                  LCTL_ESC, KC_TILD, KC_HASH, KC_SLASH, KC_LCBR, KC_LBRC, KC_RBRC, KC_RCBR, KC_BSLS, KC_MINS, KC_PLUS, KC_PIPE,
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                  LSFT_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_UNDS, KC_EQL, SHFT_ENTR,
                                                                  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                                  KC_LGUI, KC_LALT, LT2_SPC, LT3_SPC, MO4, MO5
                                                                  //`--------------------------'  `--------------------------'
                                                                  ),

                                                              [L_ADJUST] = LAYOUT_split_3x6_3(
                                                                  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                                                                  XXXXXXX, KC_F1, KC_F2, KC_F3, KC_F4, XXXXXXX, XXXXXXX, KC_PGUP, XXXXXXX, XXXXXXX, KC_HOME, KC_DEL,
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                  XXXXXXX, KC_F5, KC_F6, KC_F7, KC_F8, XXXXXXX, KC_HOME, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_END,
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                  XXXXXXX, KC_F9, KC_F10, KC_F11, KC_F12, XXXXXXX, XXXXXXX, KC_PGDN, XXXXXXX, XXXXXXX, KC_END, SHFT_ENTR,
                                                                  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                                  KC_LGUI, KC_LALT, LT2_SPC, LT3_SPC, MO4, MO5
                                                                  //`--------------------------'  `--------------------------'
                                                                  ),

                                                              // TODO: fix formatting
                                                              [L_MISC] = LAYOUT_split_3x6_3(
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                  QK_BOOT, DB_TOGG, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MUTE, KC_NO, KC_NO, KC_NO, KC_NO,
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                  RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, KC_NO, KC_PAUSE, KC_VOLU, KC_NO, KC_NO, KC_NO, KC_NO,
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                  RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, KC_NO, KC_SCRL, KC_VOLD, KC_NO, KC_NO, KC_NO, RGB_RMOD,
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                  KC_LGUI, KC_LALT, LT2_SPC, LT3_SPC, MO4, MO5
                                                                  //`--------------------------'  `--------------------------'
                                                                  )};

#ifdef OLED_ENABLE

void printBits(unsigned int num) {
    unsigned int size   = sizeof(unsigned int);
    unsigned int maxPow = 1 << (size * 8 - 1);
    // printf("MAX POW : %u\n",maxPow);
    int i = 0;
    for (; i < size * 8; ++i) {
        // print last bit and shift left.
        oled_write_P(PSTR(num & maxPow ? "1" : "0"), false);
        num = num << 1;
    }
}
void oled_render_layer_state(void) {
    // oled_write_P(PSTR("Layer: "), false);
    //  switch (layer_state) {
    switch (get_highest_layer(layer_state)) {
        case L_LOWER:
            // case L_LOWER|L_HMR_OFF:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            // case L_RAISE|L_HMR_OFF:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_MISC:
            // case L_MISC|L_HMR_OFF:
            oled_write_ln_P(PSTR("System/RGB"), false);
            break;
        case L_ADJUST:
            // case L_ADJUST|L_HMR_OFF:
            // case L_ADJUST|L_LOWER:
            // case L_ADJUST|L_RAISE:
            // case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Fn/Nav"), false);
            break;
        default:
            if (default_layer_state == 2) {
                oled_write_ln_P(PSTR("QWERTY - No HRM"), false);
            } else {
                oled_write_ln_P(PSTR("QWERTY - HRM"), false);
            }
            break;
    }
    // printBits(layer_state);
    // printBits(default_layer_state);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180; // flips the display 180 degrees if offhand
    }
    return rotation;
}
char keylog_str[24] = {};

const char code_to_name[60] = {' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\', '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
    char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
        keycode = keycode & 0xFF;
    }
    if (keycode < 60) {
        name = code_to_name[keycode];
    }

    // update keylog
    snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c", record->event.key.row, record->event.key.col, keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    // static const char PROGMEM crkbd_logo[] = {
    //     0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
    //     0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
    //     0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
    //     0};
    // oled_write_P(crkbd_logo, false);

    // 'fisk-monochrome-japanese', 128x32px
    static const char fisk_monochrome_japanese[] PROGMEM = {0x00, 0xf0, 0xf8, 0xf8, 0xf8, 0xf8, 0xf0, 0xf0, 0xf0, 0xf0, 0xe0, 0xe0, 0xe0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xf0, 0xf8, 0xfc, 0x78, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xe0, 0xe0, 0xc0, 0xc0, 0xc0, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                            0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x07, 0x0f, 0x1f, 0x3f, 0xfe, 0xfc, 0xf8, 0xf0, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x0f, 0x1f, 0x3f, 0x7e, 0xfc, 0xf0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xff, 0xff, 0xff, 0x1f, 0x3e, 0x3e, 0x7c, 0xf8, 0xf8, 0xf0, 0xf0, 0xfc, 0xfe, 0x7f, 0x3f, 0x1f, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0x03, 0x07, 0x07, 0x07, 0x0f, 0x0f, 0x1f, 0x1f, 0x3e, 0x7e, 0xfc, 0xf8, 0xf0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                            0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x0f, 0x7f, 0xff, 0xff, 0x7c, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x1f, 0x7f, 0xff, 0xfd, 0xf1, 0xc1, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0f, 0x3f, 0x7e, 0xfe, 0xf8, 0xf0, 0xe0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x1f, 0x1f, 0x1e, 0x3e, 0x3f, 0x7f, 0x7f, 0xff, 0xf8, 0xf0, 0xe0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x0f, 0x3f, 0xff, 0xfe, 0xfc, 0x70, 0x00, 0x00, 0x00,
                                                            0x00, 0x07, 0x07, 0x07, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x0f, 0x3f, 0x1f, 0x0e, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x07, 0x0f, 0x0f, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00};
    oled_write_raw_P(fisk_monochrome_japanese, sizeof(fisk_monochrome_japanese));
}
// void oled_print_layer_state_bits(void)
// {
//     unsigned int num = layer_state;
//    for(int bit=0;bit<(sizeof(unsigned int) * 8); bit++)
//    {
//       oled_write_P(PSTR(num & 0x01), false);
//       num = num >> 1;
//    }
// }
// void oled_render_debug_layer_info(void) {
//     oled_write_P(PSTR("debug: "), false);
//     oled_print_layer_state_bits();
//     oled_write_ln_P(PSTR(""), false);
// }
// void oled_render_wpm(void) {
//     char buf[30]; // Where to store the formatted text
//     uint8_t wpm = get_current_wpm();
//     sprintf(buf, "WPM: %u", wpm); // %u format speed as unsigned decimal
//     oled_write_ln_P(buf, false);
// }

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        // oled_render_wpm();
        // oled_render_keylog();

        // oled_render_debug_layer_info();
    } else {
        oled_render_logo();
    }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint16_t my_layer_toggle_timer;

    if (record->event.pressed) {
        set_keylog(keycode, record);
    }
    switch (keycode) {
        case RGB_TOG:
            // taken from the massdrop ctrl firmware
            // with each keypress it cycles through the statements in this switch by getting/setting
            // the RGB flags: https://github.com/qmk/qmk_firmware/blob/master/docs/feature_rgb_matrix.md
            if (record->event.pressed) {
                switch (rgb_matrix_get_flags()) {
                    case LED_FLAG_ALL:
                        rgb_matrix_set_flags(LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER | LED_FLAG_INDICATOR);
                        rgb_matrix_set_color_all(0, 0, 0);
                        break;
                    case (LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER | LED_FLAG_INDICATOR):
                        rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
                        rgb_matrix_set_color_all(0, 0, 0);
                        break;
                    case LED_FLAG_UNDERGLOW:
                        rgb_matrix_set_flags(LED_FLAG_NONE);
                        rgb_matrix_disable_noeeprom();
                        break;
                    default:
                        rgb_matrix_set_flags(LED_FLAG_ALL);
                        rgb_matrix_enable_noeeprom();
                        break;
                }
            }
            return false;
            break;
        case DFC_LALT:
            // method of differing between tap+hold was found here:
            // https://thomasbaart.nl/2018/12/09/qmk-basics-tap-and-hold-actions/#a-workaround-for-mod-tap
            if (record->event.pressed) {
                my_layer_toggle_timer = timer_read();
                register_code(KC_LALT);
            } else {
                unregister_code(KC_LALT);
                if (timer_elapsed(my_layer_toggle_timer) < TAPPING_TERM) {
                    // cycle through default layers
                    if (default_layer_state == 2) {
                        default_layer_set(1);
                    } else {
                        default_layer_set(2);
                    }
                }
            }
            return false;
            break;
        case DFC_LGUI:
            // method of differing between tap+hold was found here:
            // https://thomasbaart.nl/2018/12/09/qmk-basics-tap-and-hold-actions/#a-workaround-for-mod-tap
            if (record->event.pressed) {
                my_layer_toggle_timer = timer_read();
                register_code(KC_LGUI);
            } else {
                unregister_code(KC_LGUI);
                if (timer_elapsed(my_layer_toggle_timer) < TAPPING_TERM) {
                    // cycle through default layers
                    if (default_layer_state == 2) {
                        default_layer_set(1);
                    } else {
                        default_layer_set(2);
                    }
                }
            }
            return false;
            break;
        case TOG_DFLT:
            // toggles default layers
            if (default_layer_state == 2) {
                default_layer_set(1);
            } else {
                default_layer_set(2);
            }
            return false;
            break;
    }
    return true;
}
