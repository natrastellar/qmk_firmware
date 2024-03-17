/*
Copyright 2024 Mori
https://github.com/remorae

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

#pragma once

#define MY_HSV_A_Z HSV_WHITE
#define MY_HSV_0_9 HSV_YELLOW
#define MY_HSV_SCARY HSV_RED
#define MY_HSV_MOD HSV_ORANGE
#define MY_HSV_LAYER HSV_MAGENTA
#define MY_HSV_NAV HSV_CYAN
#define MY_HSV_PUNCT HSV_PURPLE
#define MY_HSV_OK HSV_GREEN
#define MY_HSV_SUPER HSV_BLUE

// LEDS snake along one half of keyboard starting from top left
// 0-27
// 34-61
const rgblight_segment_t PROGMEM my_rgb_layer_qwerty[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 5, MY_HSV_0_9}, // 12345
    {35, 5, MY_HSV_0_9}, // 67890
    {6, 5, MY_HSV_A_Z}, // QWERT
    {40, 5, MY_HSV_A_Z}, // YUIOP
    {13, 5, MY_HSV_A_Z}, // ASDFG
    {48, 4, MY_HSV_A_Z}, // HJKL
    {18, 5, MY_HSV_A_Z}, // ZXCVB
    {52, 2, MY_HSV_A_Z}, // NM
    {0, 1, MY_HSV_SCARY}, // Esc
    {11, 1, MY_HSV_NAV}, // Tab
    {12, 1, MY_HSV_MOD}, // LCTL
    {23, 1, MY_HSV_MOD}, // LShft
    {34, 1, MY_HSV_SCARY}, // Bksp
    {45, 1, MY_HSV_SCARY}, // Del
    {57, 1, MY_HSV_MOD}, // RShft
    {24, 1, MY_HSV_SUPER}, // LWin
    {25, 1, MY_HSV_LAYER}, // L1(L3)
    {26, 1, MY_HSV_OK}, // Enter
    {27, 1, MY_HSV_NAV}, // Home
    {46, 2, MY_HSV_PUNCT}, // ;'
    {54, 3, MY_HSV_PUNCT}, // ,./
    //{61, 1, MY_HSV_NAV}, // End (Knob)
    {60, 1, MY_HSV_OK}, // Space
    {59, 1, MY_HSV_LAYER}, // L2(L3)
    {58, 1, MY_HSV_MOD} // RAlt
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_rgb_layer_qwerty
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _QWERTY));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return state;
}
