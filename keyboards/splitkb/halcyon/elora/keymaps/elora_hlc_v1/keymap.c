// Copyright 2024 splitkb.com (support@splitkb.com)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    _COLEMAK = 0,
    _NAV,
    _THE_RIZ,
    _SYM,
    _NUMPAD,
    _QWERTY,
    _ADJUST,
};

enum keycodes {

    EP_SENT = SAFE_RANGE, // For cmd + enter
    LGUI_SPC, // For cmd + space
    LGUIT,   // For cmd + t

    // Screenshot
    SSFULL,
    SSSELEC,

    // The Riz Code
    EP_DOSP_FAKE,
    EP_PLUS_FAKE,

    EP_SY_C_FAKE,
    EP_SY_A_FAKE,
    EP_SY_G_FAKE,
    EP_SY_S_FAKE,

    EP_OS_C,
    EP_OS_A,
    EP_OS_G,
    EP_OS_S,

    // SHORTCUTS
    EP_PIPB, // <|
    EP_PIPF, // |>
    EP_ARR1, // ->
    EP_ARR2, // =>
    EP_CURD, // ./
    EP_PARD, // ../
    EP_HOMD, // ~/

    EP_MENU,

    REPEAT,
};

// Aliases for readability
#define QWERTY   DF(_QWERTY)
#define COLEMAK  DF(_COLEMAK)

#define SYM      MO(_SYM)
#define NAV      MO(_NAV)
#define ADJUST   MO(_ADJUST)

#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
#define CTL_MINS MT(MOD_RCTL, KC_MINUS)
#define ALT_ENT  MT(MOD_LALT, KC_ENT)
#define SHT_ENT  MT(MOD_LSFT, KC_ENT)


#define EP_SENT LGUI(KC_ENT) // Comman + Enter
#define LGUI_SPC LGUI(KC_SPC) // Command + Space
#define LGUIT    LGUI(KC_T)    // Command + T
#define SSFULL LGUI(S(KC_3)) // ScreenShot Full Screen
#define SSSELEC LGUI(S(KC_4)) // ScreenShot Selection

// TY: thumb keys
#define EP_DOSP LT(_NAV, KC_SPC)
#define EP_NUMP MO(_NUMPAD)
#define EP_SFEN SFT_T(KC_ENT)
#define EP_FNBS LT(EP_FN, KC_BSPC)
#define EP_LBRC LT(_NAV, KC_LBRC)
#define EP_RBRC SFT_T(KC_RBRC)

// FN: one-shot keys
#define EP_FN_G OSM(MOD_LGUI)
#define EP_FN_A OSM(MOD_LALT)
#define EP_FN_C OSM(MOD_LCTL)
#define EP_FN_S OSM(MOD_LSFT)

// SY: mod tap
#define EP_SY_G GUI_T(EP_SY_G_FAKE)
#define EP_SY_A ALT_T(EP_SY_A_FAKE)
#define EP_SY_C CTL_T(EP_SY_C_FAKE)
#define EP_SY_S SFT_T(EP_SY_S_FAKE)

// DO: shortcuts
#define EP_UNDO LGUI(KC_Z)
#define EP_REDO LGUI(S(KC_Z))
#define EP_COPY LGUI(KC_C)
#define EP_PSTE LGUI(KC_V)
#define EP_CUT LGUI(KC_X)
#define EP_BACK LGUI(KC_LEFT_BRACKET)
#define EP_FRWD LGUI(KC_RIGHT_BRACKET)
#define EP_STAB S(KC_TAB)
#define EP_WDL LALT(KC_LEFT)
#define EP_WDR LALT(KC_RIGHT)
#define EP_FLUP LGUI(KC_UP)
#define EP_FLDW LGUI(KC_DOWN)
#define EP_LNLF LGUI(KC_LEFT)
#define EP_LNRT LGUI(KC_RIGHT)

// International keys (linux)
//   #define EP_CEDL RALT(KC_COMM)
//   #define EP_GBP A(KC_3)
//   #define EP_EUR S(A(KC_2))

// International keys (macos)
/* #define EP_CEDL A(KC_C) */

// Dead accent keys (linux)
//   #define EP_DTIL RALT(S(KC_GRV))
//   #define EP_ACUT RALT(KC_QUOT)
//   #define EP_DCIR RALT(KC_6)
//   #define EP_DGRV RALT(KC_GRV)

// Dead accent keys (macos)
#define EP_DTIL A(KC_N)
#define EP_ACUT A(KC_E)
#define EP_DCIR A(KC_I)
#define EP_DGRV A(KC_GRV)

// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 * Colemak
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Esc   |   1  |   2  |   3  |   4  |   5  |                              |   6  |   7  |   8  |   9  |   0  | Delete |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  Tab   |   Q  |   W  |   F  |   P  |   G  |                              |   J  |   L  |   U  |   Y  | ;  : |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   R  |   S  |   T  |   D  |                              |   H  |   N  |   E  |   I  |   O  |Ctrl/' "|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   D  |   B  | [ {  |CapsLk|  | -  _ |  ] } |   K  |   M  | ,  < | . >  | /  ? | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |Adjust| LGUI | LShi/| Nav/ |NUMPAD|  |      | Sym  | Space| LGUI+| LGUI+|
 *                        |      |      | Enter| Space|      |  |      |      |      | Space| Enter|
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * | MUTE | ____ | _____ | ____ | ____ |                                              | MUTE | ____ | _____ | ____ | ____ |
 * `-----------------------------------'                                              `-----------------------------------'
 */
 [_COLEMAK] = LAYOUT_elora_hlc(
    KC_ESC  , KC_1 ,  KC_2   ,  KC_3  ,   KC_4 ,   KC_5 ,                                        KC_6 ,  KC_7 ,  KC_8 ,   KC_9 ,  KC_0 , KC_DEL ,
    KC_TAB  , KC_Q ,  KC_W   ,  KC_F  ,   KC_P ,   KC_G ,                                        KC_J,   KC_L ,  KC_U ,   KC_Y ,KC_SCLN, KC_BSPC,
    CTL_ESC , KC_A ,  KC_R   ,  KC_S  ,   KC_T ,   KC_D ,                                        KC_H,   KC_N ,  KC_E ,   KC_I ,  KC_O , CTL_QUOT,
    KC_LSFT , KC_Z ,  KC_X   ,  KC_C  ,   KC_V ,   KC_B , KC_LBRC,KC_CAPS,     KC_MINS, KC_RBRC, KC_K,   KC_M ,KC_COMM, KC_DOT ,KC_SLSH, KC_RSFT,
                                  ADJUST, KC_LGUI, SHT_ENT, EP_DOSP, EP_NUMP,     _______,   SYM  , KC_SPC, LGUI_SPC, EP_SENT,
    KC_MUTE, KC_NO,  KC_NO, KC_NO, KC_NO,                                                                KC_MUTE, KC_NO, KC_NO, KC_NO, KC_NO
   ),

/*
 * Colemak, duplicate layout of the base <> to EP_MD
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Esc   |   1  |   2  |   3  |   4  |   5  |                              |   6  |   7  |   8  |   9  |   0  | Delete |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  Tab   |   Q  |   W  |   F  |   P  |   G  |                              |   J  |   L  |   U  |   Y  | ;  : |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   R  |   S  |   T  |   D  |                              |   H  |   N  |   E  |   I  |   O  |Ctrl/' "|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   D  |   B  | [ {  |CapsLk|  | -  _ |  ] } |   K  |   M  | ,  < | . >  | /  ? | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |Adjust| LGUI | LShi/| Nav/ |NUMPAD|  |      | Sym  | Space| LGUI+| LGUI+|
 *                        |      |      | Enter| Space|      |  |      |      |      | Space| Enter|
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * | MUTE | ____ | _____ | ____ | ____ |                                              | MUTE | ____ | _____ | ____ | ____ |
 * `-----------------------------------'                                              `-----------------------------------'
 */
 [_THE_RIZ] = LAYOUT_elora_hlc(
    KC_ESC  , KC_1 ,  KC_2   ,  KC_3  ,   KC_4 ,   KC_5 ,                                        KC_6 ,  KC_7 ,  KC_8 ,   KC_9 ,  KC_0 , KC_DEL ,
    KC_TAB  , KC_Q ,  KC_W   ,  KC_F  ,   KC_P ,   KC_G ,                                        KC_J,   KC_L ,  KC_U ,   KC_Y ,KC_SCLN, KC_BSPC,
    CTL_ESC , KC_A ,  KC_R   ,  KC_S  ,   KC_T ,   KC_D ,                                        KC_H,   KC_N ,  KC_E ,   KC_I ,  KC_O , CTL_QUOT,
    KC_LSFT , KC_Z ,  KC_X   ,  KC_C  ,   KC_V ,   KC_B , KC_LBRC,KC_CAPS,     KC_MINS, KC_RBRC, KC_K,   KC_M ,KC_COMM, KC_DOT ,KC_SLSH, KC_RSFT,
                                  ADJUST, KC_LGUI, SHT_ENT, EP_DOSP, EP_NUMP,     _______,   SYM  , KC_SPC, LGUI_SPC, EP_SENT,
    KC_MUTE, KC_NO,  KC_NO, KC_NO, KC_NO,                                                                KC_MUTE, KC_NO, KC_NO, KC_NO, KC_NO
   ),

/*
 * Nav Layer: Navigation / Action
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |CaptFu|CaptSe|      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |   tab  |Repeat|  esc |Brow B|Brow F| MW Up|                              | pgUp |ctrl ←|ctrl →| home |ctrhom| delete |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |   esc  |  gui |  alt | ctrl | shift| MW Dn|                              |  ←   |   ↓  |   ↑  |   →  | end  | insert |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | lshift | Undo |  Cut | Copy | Paste| Redo |      | volup|  |Bri Dn|      | pgDn | UnTab|  esc |  tab |ctrend|        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |8Po voldn|  |Bri Up| Enter| Bksp |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * |      |      |       |      |      |                                              |      |      |       |      |      |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [_NAV] = LAYOUT_elora_hlc(
      _______, _______, _______, _______, _______, _______,                                      SSFULL, SSSELEC, _______, _______, _______, _______,
      KC_TAB , REPEAT , KC_ESC , EP_BACK, EP_FRWD, KC_WH_U,                                     KC_PGUP,  EP_WDL,  KC_UP ,  EP_WDR, EP_FLUP, KC_DEL ,
      KC_ESC , EP_OS_G, EP_OS_A, EP_OS_C, EP_OS_S, KC_WH_D,                                     EP_LNLF, KC_LEFT, KC_DOWN, KC_RGHT, EP_LNRT, KC_INS ,
      KC_LSFT, EP_UNDO, EP_CUT , EP_COPY, EP_PSTE, EP_REDO, _______, KC_VOLU, KC_BRIU, _______, KC_PGDN, EP_STAB,  KC_ESC,  KC_TAB, EP_FLDW, _______,
                                 _______, _______, _______, _______, KC_VOLD, KC_BRID,  KC_ENT, KC_BSPC, _______, _______,
     _______, _______,  _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),

/*
 * NumPad
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |   F1   |  F2  |  F3  |  F4  |  F5  |  F6  |                              |  F7  |  F8  |  F9  |  F10 |  F11 |   F12  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |   -  |   1  |   2  |  3   |   +  |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |   esc  |  gui |  alt | ctrl | shift|      |                              |   *  |   4  |   5  |  6   |  0   | Delete |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      | LLock|  |      |      |   /  |   7  |  8   |  9   |  =   |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * |      |      |       |      |      |                                              |      |      |       |      |      |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [_NUMPAD] = LAYOUT_elora_hlc(
       KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 ,  KC_F5 ,  KC_F6 ,                                      KC_F7 ,  KC_F8 ,  KC_F9 , KC_F10 , KC_F11 , KC_F12 ,
      _______, _______, _______, _______, _______, _______,                                     KC_MINS,   KC_1 ,  KC_2  ,  KC_3  , KC_PLUS, KC_BSPC,
      _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                                     KC_ASTR,   KC_4 ,  KC_5  ,  KC_6  ,   KC_0 , KC_DEL ,
      _______, _______, _______, _______, _______, _______, _______, QK_LLCK, _______, _______, KC_SLSH,   KC_7 ,  KC_8  ,  KC_9  ,  KC_EQL, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
     _______, _______,  _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),

/*
 * Sym Layer: Numbers and symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  1   |  2   |  3   |  4   |  5   |                              |   6  |  7   |  8   |  9   |  0   |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  ~   |   <  |   >  |   #  |  @   |                              |   &  |  :   |   [  |  ]   |  \   |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  !   |   -  |   +  |   =  |  `   |                              |   $  |  _   |  (   |  )   |   %  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  ^   |  /   |   *  |  0   |  ?   |      | LLock|  |      |      |   |  |  1   |  {   |  }   |  ;   |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * |      |      |       |      |      |                                              |      |      |       |      |      |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [_SYM] = LAYOUT_elora_hlc(
      _______,   KC_1 ,   KC_2 ,   KC_3 ,   KC_4 ,  KC_5 ,                                        KC_6 ,   KC_7 ,   KC_8 ,   KC_9 ,   KC_0 , _______,
      _______, KC_TILD,  KC_LT ,  KC_GT , KC_HASH, KC_AT ,                                      KC_AMPR, KC_COLN, KC_LBRC, KC_RBRC, KC_BSLS, _______,
      _______, KC_EXLM, KC_MINS, KC_PLUS,  KC_EQL, KC_GRV,                                      KC_DLR , KC_UNDS, KC_LPRN, KC_RPRN, KC_PERC, _______,
      _______, KC_CIRC, KC_SLSH, KC_ASTR,   KC_0 , KC_QUES, _______, QK_LLCK, _______, _______, KC_PIPE,   KC_1 , KC_LCBR, KC_RCBR, KC_SCLN, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
     _______, _______,  _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),

/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Esc   |   1  |   2  |   3  |   4  |   5  |                              |   6  |   7  |   8  |   9  |   0  |  Esc   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |Ctrl/' "|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  | [ {  |CapsLk|  | NumP |  ] } |   N  |   M  | ,  < | . >  | /  ? | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |Adjust| LGUI | LAlt/| Space| Nav  |  | Sym  | Space| AltGr| RGUI | Menu |
 *                        |      |      | Enter|      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * | MUTE | ____ | _____ | ____ | ____ |                                              | MUTE | ____ | _____ | ____ | ____ |
 * `-----------------------------------'                                              `-----------------------------------'
 */
 [_QWERTY] = LAYOUT_elora_hlc(
    KC_ESC  , KC_1 ,  KC_2   ,  KC_3  ,   KC_4 ,   KC_5 ,                                        KC_6 ,  KC_7 ,  KC_8 ,   KC_9 ,  KC_0 , KC_ESC ,
    KC_TAB  , KC_Q ,  KC_W   ,  KC_E  ,   KC_R ,   KC_T ,                                        KC_Y,   KC_U ,  KC_I ,   KC_O ,  KC_P , KC_BSPC,
    CTL_ESC , KC_A ,  KC_S   ,  KC_D  ,   KC_F ,   KC_G ,                                        KC_H,   KC_J ,  KC_K ,   KC_L ,KC_SCLN,CTL_QUOT,
    KC_LSFT , KC_Z ,  KC_X   ,  KC_C  ,   KC_V ,   KC_B , KC_LBRC,KC_CAPS,     _NUMPAD  , KC_RBRC, KC_N,   KC_M ,KC_COMM, KC_DOT ,KC_SLSH, KC_RSFT,
                               ADJUST , KC_LGUI, ALT_ENT, KC_SPC , NAV   ,     SYM    , KC_SPC ,KC_RALT, KC_RGUI, KC_APP,
    KC_MUTE, KC_NO,  KC_NO, KC_NO, KC_NO,                                                                KC_MUTE, KC_NO, KC_NO, KC_NO, KC_NO
   ),

/*
 * Adjust Layer: Default layer settings, RGB, Media
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              | TOG  | SAI  | HUI  | VAI  | MOD  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |QWERTY|      |      |                              | SAD  | HUD  | VAD  | RMOD |      |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |Colmak|      |Vol Up|                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |Vol Dn|      |      |  |      |      |VolMut|M Prev|M Play|M Next|Bri Dn|  Bri Up|
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * |      |      |       |      |      |                                              |      |      |       |      |      |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [_ADJUST] = LAYOUT_elora_hlc(
      _______, _______, _______, _______, _______, _______,                                    RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI,  RGB_MOD, _______,
      _______, _______, _______, QWERTY , _______, _______,                                    _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD, _______,
      _______, _______, _______, COLEMAK, _______, KC_VOLU,                                    _______, _______, _______, _______,  _______, _______,
      _______, _______, _______, _______, _______, KC_VOLD,_______, _______, _______, _______, KC_MUTE, KC_MPRV, KC_MPLY, KC_MNXT, KC_BRID, KC_BRIU,
                                 _______, _______, _______,_______, _______, _______, _______, _______, _______, _______,
     _______, _______,  _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),

// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  * ,-----------------------------------.                                              ,-----------------------------------.
//  * |      |      |       |      |      |                                              |      |      |       |      |      |
//  * `-----------------------------------'                                              `-----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT_elora_hlc(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//      _______, _______,  _______, _______, _______,                                                       _______, _______, _______, _______, _______
//     ),
//
};

typedef struct {
    uint16_t trigger;
    uint16_t mod;
    uint16_t timer;
  } oslm_state_t;

  oslm_state_t oslm_c = {
    .trigger = EP_OS_C,
    .mod = MOD_BIT(KC_LCTL),
    .timer = 0,
  };
  oslm_state_t oslm_a = {
    .trigger = EP_OS_A,
    .mod = MOD_BIT(KC_LALT),
    .timer = 0,
  };
  oslm_state_t oslm_g = {
    .trigger = EP_OS_G,
    .mod = MOD_BIT(KC_LGUI),
    .timer = 0,
  };
  oslm_state_t oslm_s = {
    .trigger = EP_OS_S,
    .mod = MOD_BIT(KC_LSFT),
    .timer = 0,
  };


/*
// KEY OVERRIDES
// S(EP_DOSP) -> KC_UNDS
const key_override_t unds_ko = ko_make_basic(MOD_BIT(KC_LSFT), EP_DOSP, KC_UNDS);

// S(EP_NUMP) -> KC_AT
const key_override_t at_ko = ko_make_basic(MOD_BIT(KC_LSFT), EP_NUMP, KC_AT);

// S(KC_COMMA) -> KC_SCLN
const key_override_t scln_ko = ko_make_basic(MOD_BIT(KC_LSFT), KC_COMMA, KC_SCLN);

// S(KC_DOT) -> KC_COLN
const key_override_t coln_ko = ko_make_basic(MOD_BIT(KC_LSFT), KC_DOT, KC_COLN);

// S(KC_EXLM) -> KC_QUES
const key_override_t ques_ko = ko_make_basic(MOD_BIT(KC_LSFT), KC_EXLM, KC_QUES);

// S(KC_BSPC) -> KC_DEL
const key_override_t sbsp_ko = ko_make_with_layers_and_negmods(MOD_BIT(KC_RSFT), KC_BSPC, KC_DEL, ~0, MOD_BIT(KC_LGUI));

// A(KC_DEL) -> C(KC_K)
const key_override_t c_k_ko = ko_make_with_layers_and_negmods(MOD_BIT(KC_LALT), KC_DEL, C(KC_K), ~0, 0);

const key_override_t *key_overrides[] = {
    &unds_ko,
    &at_ko,
    &scln_ko,
    &coln_ko,
    &ques_ko,
    &c_k_ko,
    &sbsp_ko
};
*/

// REPEAT

// Used to extract the basic tapping keycode from a dual-role key.
// Example: GET_TAP_KC(MT(MOD_RSFT, KC_E)) == KC_E
#define GET_TAP_KC(dual_role_key) dual_role_key & 0xFF

uint16_t last_tap = KC_NO;
uint8_t last_modifier = 0;
uint8_t mods_state = 0;
uint8_t oneshot_mods_state = 0;

void processrepeat_key(uint16_t keycode, const keyrecord_t *record) {
  if (keycode != REPEAT) {
    // Early return when holding down a pure layer key
    // to retain modifiers
    switch (keycode) {
    case QK_DEF_LAYER ... QK_DEF_LAYER_MAX:
    case QK_MOMENTARY ... QK_MOMENTARY_MAX:
    case QK_LAYER_MOD ... QK_LAYER_MOD_MAX:
    case QK_ONE_SHOT_LAYER ... QK_ONE_SHOT_LAYER_MAX:
    case QK_TOGGLE_LAYER ... QK_TOGGLE_LAYER_MAX:
    case QK_TO ... QK_TO_MAX:
    case QK_LAYER_TAP_TOGGLE ... QK_LAYER_TAP_TOGGLE_MAX:
      return;
    }

    switch (keycode) {
    case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
    case QK_MOD_TAP ... QK_MOD_TAP_MAX:
      if (record->event.pressed && record->tap.count > 0) {
        last_modifier = oneshot_mods_state > mods_state ? oneshot_mods_state : mods_state;
        last_tap = GET_TAP_KC(keycode);
      }
      break;
    default:
      if (record->event.pressed) {
        last_modifier = oneshot_mods_state > mods_state ? oneshot_mods_state : mods_state;
        last_tap = keycode;
      }
      break;
    }
  } else { // keycode == REPEAT
    if (record->event.pressed) {
      register_mods(last_modifier);
      register_code16(last_tap);
    } else {
      unregister_code16(last_tap);
      unregister_mods(last_modifier);
    }
  }
}

// OSLM: process a OSLM key
void process_osml(oslm_state_t *oslm_state, uint16_t keycode, keyrecord_t *record) {
  static uint16_t mods = 0;
  if (record->event.pressed) {
    // init: init timer, register trigger mod
    oslm_state->timer = timer_read();
    register_mods(oslm_state->mod);
    // get mods at the time of pressed event.
    mods = get_mods();
  } else {
    // clear held mod
    unregister_mods(oslm_state->mod);

    // released: check if it's a tap
    if (timer_elapsed(oslm_state->timer) < TAPPING_TERM) {
      // tap: keep all current mods and set oneshot layer
      set_oneshot_mods(mods);
      set_oneshot_layer( _THE_RIZ, ONESHOT_START);
    }
  }
}


// PROCESS KEYS
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    #ifdef CONSOLE_ENABLE
      uprintf("%u, %u: k=0x%04X #%u l=%u p=%b m=0x%02X M=0x%02X\n",
        record->event.key.row,
        record->event.key.col,
        keycode,
        record->tap.count,
        get_highest_layer(layer_state),
        record->event.pressed,
        get_mods(),
        get_oneshot_mods()
      );
    #endif
        bool ret = false;

      mods_state = get_mods();
      oneshot_mods_state = get_oneshot_mods();

      switch (keycode) {

        case EP_DOSP:
          // Intercept hold release to clear OSM/OSLM state.
          if (!record->event.pressed && record->tap.count == 0) {
            layer_clear();
            clear_oneshot_mods();
            unregister_mods(mods_state);
          }
          ret = true;
          break;

        // DO: OS_C
        case EP_OS_C:
          process_osml(&oslm_c, keycode, record);
          break;

        // DO: OS_A
        case EP_OS_A:
          process_osml(&oslm_a, keycode, record);
          break;

        // DO: OS_G
        case EP_OS_G:
          process_osml(&oslm_g, keycode, record);
          break;

        // DO: OS_S
        case EP_OS_S:
          process_osml(&oslm_s, keycode, record);
          break;

        // BEGIN SY MT
        case EP_SY_S:
          if (record->event.pressed && record->tap.count > 0) {
            tap_code16(KC_RPRN);
          } else {
            ret = true;
          }
          break;

        case EP_SY_C:
          if (record->event.pressed && record->tap.count > 0) {
            tap_code16(KC_LPRN);
          } else {
            ret = true;
          }
          break;

        case EP_SY_A:
          if (record->event.pressed && record->tap.count > 0) {
            tap_code16(KC_DLR);
          } else {
            ret = true;
          }
          break;

        case EP_SY_G:
          if (record->event.pressed && record->tap.count > 0) {
            tap_code16(KC_TILD);
          } else {
            ret = true;
          }
          break;
        // END SY MT

        // BEGIN FN MT
        case EP_FN_S:
          if (record->event.pressed && record->tap.count > 0) {
            tap_code16(EP_DTIL);
            layer_clear();
          } else {
            ret = true;
          }
          break;

        case EP_FN_C:
          if (record->event.pressed && record->tap.count > 0) {
            tap_code16(EP_ACUT);
            layer_clear();
          } else {
            ret = true;
          }
          break;

        case EP_FN_A:
          if (record->event.pressed && record->tap.count > 0) {
            tap_code16(EP_DCIR);
            layer_clear();
          } else {
            ret = true;
          }
          break;

        case EP_FN_G:
          if (record->event.pressed && record->tap.count > 0) {
            tap_code16(EP_DGRV);
            layer_clear();
          } else {
            ret = true;
          }
          break;
        // END FN MT

        // BEGIN SYMBOL SHORTCUTS
        case EP_PIPB:
          if (record->event.pressed) {
            SEND_STRING("<|");
          }
          break;

        case EP_PIPF:
          if (record->event.pressed) {
            SEND_STRING("|>");
          }
          break;

        case EP_ARR1:
          if (record->event.pressed) {
            SEND_STRING("->");
          }
          break;

        case EP_ARR2:
          if (record->event.pressed) {
            SEND_STRING("=>");
          }
          break;

        case EP_CURD:
          if (record->event.pressed) {
            SEND_STRING("./");
          }
          break;

        case EP_PARD:
          if (record->event.pressed) {
            SEND_STRING("../");
          }
          break;

        case EP_HOMD:
          if (record->event.pressed) {
            SEND_STRING("~/");
          }
          break;
        // END SYMBOL SHORTCUTS

        // S(KC_EQL): ../
        // case KC_EQL:
        //   if (record->event.pressed && (mods_state == MOD_BIT(KC_LSFT))) {
        //     del_mods(MOD_BIT(KC_LSFT));
        //     SEND_STRING("../");
        //     add_mods(MOD_BIT(KC_LSFT));
        //   } else {
        //     ret = true;
        //   }
        //   break;

        // S(KC_MINS): ./
        // case KC_MINS:
        //   if (record->event.pressed && (mods_state == MOD_BIT(KC_LSFT))) {
        //     del_mods(MOD_BIT(KC_LSFT));
        //     SEND_STRING("./");
        //     add_mods(MOD_BIT(KC_LSFT));
        //   } else {
        //     ret = true;
        //   }
        //   break;

        // S(KC_SLSH): ~/
        // case KC_SLSH:
        //   if (record->event.pressed && (mods_state == MOD_BIT(KC_LSFT))) {
        //     del_mods(MOD_BIT(KC_LSFT));
        //     SEND_STRING("~/");
        //     add_mods(MOD_BIT(KC_LSFT));
        //   } else {
        //     ret = true;
        //   }
        //   break;

        default:
          // Clear current OSLM layer state.
          if (IS_LAYER_ON(_THE_RIZ) && record->event.pressed) {
            clear_oneshot_layer_state(ONESHOT_PRESSED);
          }
          ret = true;
      }

      processrepeat_key(keycode, record);
      return ret;
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    default:
      return true;
  }
}


// Prevent tap key repeat on second quick tap.
// https://docs.qmk.fm/#/tap_hold?id=quick-tap-term
uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // case EP_SYSP: return 200;
    default: return 0;
  }
}
