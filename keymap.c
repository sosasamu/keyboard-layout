#include QMK_KEYBOARD_H

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _LOWER,
    _RAISE,
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_LOWER,
    KC_RAISE,
    KC_SPOTL,
    KC_VIM,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Supr |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  MUTE |    |SLEEP  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |   -  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LOWER| LAlt |LCtrl | LGUI | /Space  /       \Enter \  | RAISE| SPOT |   [  |   ]  |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_QWERTY] = LAYOUT(
  QK_GESC,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_EQL,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC,
  KC_DEL,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,   KC_SLEP ,KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_MINS,
               KC_LOWER, KC_LALT,KC_LCPO, KC_LGUI, KC_SPC,       KC_ENT, KC_RAISE, KC_SPOTL, KC_LBRC, KC_RBRC
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   `  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   ^  |   &  |   *  |   !  |   @  |                    |   7  |   8  |   9  |   (  |   )  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Supr |   #  |   =  |   -  |   $  |   %  |-------.    ,-------|   4  |   5  |   6  |   +  |   ~  |   |  |
 * |------+------+------+------+------+------|  MUTE |    |SLEEP  |------+------+------+------+------+------|
 * | Shift|   [  |   ]  |   ;  |   {  |   }  |-------|    |-------|   1  |   2  |   3  |   :  |   \  |   -  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |   0  | LCTR | LAlt | LGUI | /Space  /       \Enter \  |RAISE |  0   |   (  |   )  |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_LOWER] = LAYOUT(
  KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_EXLM,  KC_AT,                        KC_7, KC_8, KC_9, KC_LPRN, KC_RPRN,  KC_F12,
  _______, KC_HASH, KC_EQL, KC_MINS,  KC_DLR, KC_PERC,                        KC_4, KC_5, KC_6, KC_PLUS, KC_TILD, KC_BSLS,
  _______, KC_LBRC, KC_RBRC, KC_SCLN, KC_LCBR, KC_RCBR, _______,       _______, KC_1, KC_2, KC_3, KC_COLN, KC_BSLS, _______,
                       KC_0, _______, _______, _______, _______,       _______, _______, KC_0, KC_LPRN, KC_RPRN
),
/* RAISE
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |  `   |Breath|Swirl |Snake |Knight| Xmas |                    |Static| RGB  |Static|RAINBOW|     |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |QK_BOOT| Ins |  Up  | Menu |QWERTY|      |                    |BLTOGG|BLSTEP|BLBRTG|      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | PGDW | VOLDO| PLAY |VOLUP |      |-------.    ,-------| LEFT | DOWN |  UP  | RIGHT|      | Bspc |
 * |------+------+------+------+------+------|  MUTE |    |RGB_TOG|------+------+------+------+------+------|
 * |Shift |RGBMOD|RGBHUI|RGBVAI|      | PREV |-------|    |-------| NEXT |      |      |      |      | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LOWER| LCTR | LAlt | LGUI | /Space  /       \Enter \  | RAISE| SPOT |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_RAISE] = LAYOUT(
  _______, RGB_M_B, RGB_M_SW, RGB_M_SN, RGB_M_K, RGB_M_X,                  RGB_M_G, RGB_M_T, RGB_M_P, RGB_M_R, XXXXXXX, XXXXXXX,
  QK_BOOT,  KC_INS,  XXXXXXX, KC_APP, KC_QWERTY, XXXXXXX,                   BL_TOGG, BL_STEP, BL_BRTG, KC_LPRN, KC_RPRN, KC_BSPC,
  _______, KC_PGDN, KC_VOLD, KC_MPLY, KC_VOLU, XXXXXXX,                     KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_BSLS, KC_BSLS,
  _______, RGB_MOD, RGB_HUI, RGB_VAI, XXXXXXX, KC_MPRV,  _______,       RGB_TOG,  KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                         _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
)
};

#ifdef OLED_ENABLE

static void print_status_narrow(void) {
    // Print current mode
    oled_write_ln_P(PSTR("MODE"), false);
    oled_write_ln_P(PSTR(""), false);
    if (keymap_config.swap_lctl_lgui) {
        oled_write_ln_P(PSTR("WIN"), false);
    } else {
        oled_write_ln_P(PSTR("MAC"), false);
    }
    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Qwrt"), false);
            break;
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower"), false);
            break;
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return rotation;
    }
    return OLED_ROTATION_270;
}

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };

    oled_write_P(qmk_logo, false);
}

bool should_process_keypress(void) { return true; }

bool oled_task_user(void) {
    if (!is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
            } else {
                layer_off(_LOWER);
            }
            return false;
        case KC_RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
            } else {
                layer_off(_RAISE);
            }
            return false;
        case KC_SPOTL:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LGUI));
                register_code(KC_SPC);
            } else {
                unregister_mods(mod_config(MOD_LGUI));
                unregister_code(KC_SPC);
            }
            return false;
        case KC_VIM:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LGUI));
                register_mods(mod_config(MOD_LGUI));
            } else {
                unregister_mods(mod_config(MOD_LGUI));
                unregister_mods(mod_config(MOD_LGUI));
            }
    }
    return true;
}

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_BRID);
        } else {
            tap_code(KC_BRIU);
        }
    }
    return true;
}
#endif
