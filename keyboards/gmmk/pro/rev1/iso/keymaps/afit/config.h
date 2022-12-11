/* Copyright 2022 Aidan Fitzpatrick
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

#pragma once

#ifdef RGB_MATRIX_ENABLE
    #define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_SOLID_COLOR
    #define RGB_DISABLE_WHEN_USB_SUSPENDED  true

    // AMF FIXME: be better if this faded down rather than just shut off!
    #define RGB_DISABLE_TIMEOUT 240000

    #define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_SOLID_COLOR

    // Regular key hue
    #define RGB_MATRIX_STARTUP_HUE 0
    // Sets the default saturation value, if none has been set
    #define RGB_MATRIX_STARTUP_SAT 255
    // Used as speed, but also the alt key hue
    #define RGB_MATRIX_STARTUP_SPD 36 // HSV_GOLD

    #define RGB_MATRIX_KEYPRESSES
    #define RGB_MATRIX_LED_PROCESS_LIMIT 15
    #define RGB_MATRIX_LED_FLUSH_LIMIT 10
    #define RGB_MATRIX_FRAMEBUFFER_EFFECTS

    /*  The less gaudy ones are:
        RGB_MATRIX_TYPING_HEATMAP
        RGB_MATRIX_SOLID_REACTIVE
        RGB_MATRIX_SOLID_SPLASH
        RGB_MATRIX_SOLID_MULTISPLASH
        RGB_MATRIX_RAINDROPS

        These are helpful:
        https://github.com/qmk/qmk_firmware/blob/master/docs/feature_rgb_matrix.md#rgb-matrix-effects-idrgb-matrix-effects
        https://thomasbaart.nl/category/mechanical-keyboards/firmware/qmk/qmk-basics/
        https://www.reddit.com/r/olkb/comments/coz5wa/help_me_start_a_collection_of_qmk_macro_and/
        https://www.reddit.com/r/olkb/comments/hxtuf7/custom_qmk_effect_i_made_3_led_effects_that_cycle/
        https://www.reddit.com/r/olkb/comments/bqx62k/qmk_flash_key_led_on_keypress/
        https://github.com/qmk/qmk_firmware/blob/master/users/drashna/rgb_stuff.c#L136-L245
        https://beta.docs.qmk.fm/using-qmk/advanced-keycodes/feature_macros
    */
    #define DISABLE_RGB_MATRIX_GRADIENT_UP_DOWN
    #define DISABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
    #define DISABLE_RGB_MATRIX_BREATHING
    #define DISABLE_RGB_MATRIX_BAND_SAT
    #define DISABLE_RGB_MATRIX_BAND_VAL
    #define DISABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
    #define DISABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
    #define DISABLE_RGB_MATRIX_BAND_SPIRAL_SAT
    #define DISABLE_RGB_MATRIX_BAND_SPIRAL_VAL
    #define DISABLE_RGB_MATRIX_CYCLE_ALL
    #define DISABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
    #define DISABLE_RGB_MATRIX_CYCLE_UP_DOWN
    #define DISABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
    #define DISABLE_RGB_MATRIX_CYCLE_OUT_IN
    #define DISABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
    #define DISABLE_RGB_MATRIX_CYCLE_PINWHEEL
    #define DISABLE_RGB_MATRIX_CYCLE_SPIRAL
    #define DISABLE_RGB_MATRIX_DUAL_BEACON
    #define DISABLE_RGB_MATRIX_RAINBOW_BEACON
    #define DISABLE_RGB_MATRIX_RAINBOW_PINWHEELS
    #define DISABLE_RGB_MATRIX_RAINDROPS
    #define DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
    #define DISABLE_RGB_MATRIX_HUE_BREATHING
    #define DISABLE_RGB_MATRIX_HUE_PENDULUM
    #define DISABLE_RGB_MATRIX_HUE_WAVE
    #define DISABLE_RGB_MATRIX_TYPING_HEATMAP
    #define DISABLE_RGB_MATRIX_DIGITAL_RAIN
    #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
    #define DISABLE_RGB_MATRIX_SOLID_REACTIVE
    #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
    #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
    #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
    #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
    #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
    #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
    #define DISABLE_RGB_MATRIX_SPLASH
    #define DISABLE_RGB_MATRIX_MULTISPLASH
    #define DISABLE_RGB_MATRIX_SOLID_SPLASH
    #define DISABLE_RGB_MATRIX_SOLID_MULTISPLASH
#endif