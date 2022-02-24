/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>
   Copyright 2022 Aidan Fitzpatrick

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
#include "rgb_matrix_map.h"

// True horror: why you can't use a proper Mac fn key, and we need to 
// play around to get an emoji picker instead, even though your MBP just
// has an emoji/globe key: https://github.com/qmk/qmk_firmware/issues/2179
#define KC_EMOJI LCTL(LCMD(KC_SPC))
#define KC_ZOOM LCMD(LSFT(KC_A))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Prt           Rotary(Mute)
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Del
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]                          PgUp
//      Caps     A        S        D        F        G        H        J        K        L        ;        "        #`        Enter             PgDn
//      Sh_L     /        Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right


    // The FN key by default maps to a momentary toggle to layer 1 to provide access to the RESET key (to put the board into bootloader mode). Without
    // this mapping, you have to open the case to hit the button on the bottom of the PCB (near the USB cable attachment) while plugging in the USB
    // cable to get the board into bootloader mode - definitely not fun when you're working on your QMK builds. Remove this and put it back to KC_RGUI
    // if that's your preference.
    //
    // To put the keyboard in bootloader mode, use FN+backspace. If you accidentally put it into bootloader, you can just unplug the USB cable and
    // it'll be back to normal when you plug it back in.
    [0] = LAYOUT(
        KC_ESC,  KC_BRMD, KC_BRMU, KC_F3,   KC_F4,   RGB_VAD, RGB_VAI, KC_MPRV, KC_MEDIA_PLAY_PAUSE,   KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, KC_DEL,           KC_ZOOM,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,                  KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,                  KC_O,    KC_P,    KC_LBRC, KC_RBRC,                   KC_PGUP,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,                  KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,           KC_PGDN,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,                  KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LOPT, KC_LCMD,                            KC_SPC,                                  KC_RCMD, KC_RCTL, MO(1),   KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [1] = LAYOUT(
        RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,                 KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,          KC_MEDIA_PLAY_PAUSE,
        RGB_TOG, _______, _______, _______, _______, _______, _______, _______, _______,               _______, _______, _______, _______, KC_DEL,           KC_INS,
        RGB_MOD, _______, _______, _______, _______, _______, _______, _______, _______,               _______, _______, _______, _______,                   KC_VOLU,
        RGB_HUI, _______, _______, _______, _______, _______, _______, _______, _______,               _______, _______, _______, _______, _______,          KC_VOLD,
        RGB_SAI, _______, _______, _______, _______, _______, _______, _______, _______,               _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                                 _______, _______, _______, _______, _______, _______
    ),


};


bool encoder_update_user(uint8_t index, bool clockwise) {
    uint8_t temp_mod = get_mods();
    uint8_t temp_osm = get_oneshot_mods();
    //bool    is_ctrl  = (temp_mod | temp_osm) & MOD_MASK_CTRL;
    //bool    is_shift = (temp_mod | temp_osm) & MOD_MASK_SHIFT;
    bool    is_cmd   = (temp_mod | temp_osm) & MOD_MASK_GUI;

    switch( get_highest_layer(layer_state) ) {
      case 1:
        if (clockwise) {
          //rgblight_step();
          tap_code(KC_DOWN);
          wait_ms(20);
          tap_code(KC_DOWN);
          wait_ms(20);
          tap_code(KC_DOWN);
          wait_ms(20);
          tap_code(KC_DOWN);
          tap_code(KC_MS_WH_UP);
        } else {
          //rgblight_step_reverse();
          tap_code(KC_UP);
          wait_ms(20);
          tap_code(KC_UP);
          wait_ms(20);
          tap_code(KC_UP);
          wait_ms(20);
          tap_code(KC_UP);
          tap_code(KC_MS_WH_DOWN);
        }
        break;
      default:
        if (is_cmd) {
          if (clockwise) {
            register_code(KC_LSFT);
            register_code(KC_Z);
            unregister_code(KC_LSFT);
            unregister_code(KC_Z);
          } else {
            register_code(KC_Z);
            unregister_code(KC_Z);
          }
        } else {
          if (clockwise) {
            tap_code(KC_VOLU);
          } else {
            tap_code(KC_VOLD);
          }
        }
    }
    return true;
}

#ifdef RGB_MATRIX_ENABLE
    // Caps lock, scroll lock and numlock indicator
    void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
        if (IS_HOST_LED_ON(USB_LED_CAPS_LOCK)) {
            rgb_matrix_set_color(LED_CAPS, RGB_GOLD);
        }

        // Non-alpha keys
        rgb_matrix_set_color(LED_HASH, RGB_GOLD);
        rgb_matrix_set_color(LED_SLSH, RGB_GOLD);
        rgb_matrix_set_color(LED_DOT, RGB_GOLD);
        rgb_matrix_set_color(LED_COMM, RGB_GOLD);

        rgb_matrix_set_color(LED_GRV, RGB_GOLD);
        rgb_matrix_set_color(LED_SCLN, RGB_GOLD);
        rgb_matrix_set_color(LED_RBRC, RGB_GOLD);
        rgb_matrix_set_color(LED_LBRC, RGB_GOLD);
        rgb_matrix_set_color(LED_QUOT, RGB_GOLD);
        rgb_matrix_set_color(LED_COMM, RGB_GOLD);
        rgb_matrix_set_color(LED_BSLS, RGB_GOLD);
                
        // LED_TAB
        //LED_CAPS

        uint8_t temp_mod = get_mods();
        uint8_t temp_osm = get_oneshot_mods();

        bool    is_ctrl  = (temp_mod | temp_osm) & MOD_MASK_CTRL;
        bool    is_shift = (temp_mod | temp_osm) & MOD_MASK_SHIFT;
        bool    is_cmd   = (temp_mod | temp_osm) & MOD_MASK_GUI;

        if ( is_cmd && is_shift ) {
          // Superhuman and palette apps
          rgb_matrix_set_color(LED_H, RGB_BLUE);

          // Selection-area screenshot
          rgb_matrix_set_color(LED_4, RGB_BLUE);
        } else if ( is_cmd || is_ctrl ) { // Common Mac/PC shortcuts
          // Palettes
          rgb_matrix_set_color(LED_K, RGB_BLUE);
          // Clipboard
          rgb_matrix_set_color(LED_U, RGB_BLUE);
          rgb_matrix_set_color(LED_B, RGB_BLUE);
          rgb_matrix_set_color(LED_C, RGB_BLUE);
          rgb_matrix_set_color(LED_V, RGB_BLUE);
          // Save and undo
          rgb_matrix_set_color(LED_S, RGB_BLUE);
          rgb_matrix_set_color(LED_Z, RGB_BLUE);
          // Superhuman
          rgb_matrix_set_color(LED_ENT, RGB_BLUE);
        }

        // Let's highlight faceless number keys.
        rgb_matrix_set_color(LED_1, RGB_GOLD);
        rgb_matrix_set_color(LED_3, RGB_GOLD);

        // Middle pair
        rgb_matrix_set_color(LED_5, RGB_GOLD);
        rgb_matrix_set_color(LED_6, RGB_GOLD);

        rgb_matrix_set_color(LED_8, RGB_GOLD);
        rgb_matrix_set_color(LED_0, RGB_GOLD);
    }
  /* 
  Functions to suspend RGB when computer is off or sleeping
  See: https://beta.docs.qmk.fm/using-qmk/hardware-features/lighting/feature_rgb_matrix#suspended-state-id-suspended-state
  */
  void suspend_power_down_kb(void) {
      rgb_matrix_set_suspend_state(true);
      suspend_power_down_user();
  }

  void suspend_wakeup_init_kb(void) {
      rgb_matrix_set_suspend_state(false);
      suspend_wakeup_init_user();
  }
#endif
