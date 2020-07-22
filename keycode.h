/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 11:13:39 by tkleynts          #+#    #+#             */
/*   Updated: 2020/07/22 11:24:53 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYCODE_H
# define KEYCODE_H




/*
 *  Summary:
 *    Virtual keycodes
 *  
 *  Discussion:
 *    These constants are the virtual keycodes defined originally in
 *    Inside Mac Volume V, pg. V-191. They identify physical keys on a
 *    keyboard. Those constants with "ANSI" in the name are labeled
 *    according to the key position on an ANSI-standard US keyboard.
 *    For example, k_ANSI_A indicates the virtual keycode for the key
 *    with the letter 'A' in the US keyboard layout. Other keyboard
 *    layouts may have the 'A' key label on a different physical key;
 *    in this case, pressing 'A' will generate a different virtual
 *    keycode.
 */
enum {
  k_ANSI_A                    = 0x00,
  k_ANSI_S                    = 0x01,
  k_ANSI_D                    = 0x02,
  k_ANSI_F                    = 0x03,
  k_ANSI_H                    = 0x04,
  k_ANSI_G                    = 0x05,
  k_ANSI_Z                    = 0x06,
  k_ANSI_X                    = 0x07,
  k_ANSI_C                    = 0x08,
  k_ANSI_V                    = 0x09,
  k_ANSI_B                    = 0x0B,
  k_ANSI_Q                    = 0x0C,
  k_ANSI_W                    = 0x0D,
  k_ANSI_E                    = 0x0E,
  k_ANSI_R                    = 0x0F,
  k_ANSI_Y                    = 0x10,
  k_ANSI_T                    = 0x11,
  k_ANSI_1                    = 0x12,
  k_ANSI_2                    = 0x13,
  k_ANSI_3                    = 0x14,
  k_ANSI_4                    = 0x15,
  k_ANSI_6                    = 0x16,
  k_ANSI_5                    = 0x17,
  k_ANSI_Equal                = 0x18,
  k_ANSI_9                    = 0x19,
  k_ANSI_7                    = 0x1A,
  k_ANSI_Minus                = 0x1B,
  k_ANSI_8                    = 0x1C,
  k_ANSI_0                    = 0x1D,
  k_ANSI_RightBracket         = 0x1E,
  k_ANSI_O                    = 0x1F,
  k_ANSI_U                    = 0x20,
  k_ANSI_LeftBracket          = 0x21,
  k_ANSI_I                    = 0x22,
  k_ANSI_P                    = 0x23,
  k_ANSI_L                    = 0x25,
  k_ANSI_J                    = 0x26,
  k_ANSI_Quote                = 0x27,
  k_ANSI_K                    = 0x28,
  k_ANSI_Semicolon            = 0x29,
  k_ANSI_Backslash            = 0x2A,
  k_ANSI_Comma                = 0x2B,
  k_ANSI_Slash                = 0x2C,
  k_ANSI_N                    = 0x2D,
  k_ANSI_M                    = 0x2E,
  k_ANSI_Period               = 0x2F,
  k_ANSI_Grave                = 0x32,
  k_ANSI_KeypadDecimal        = 0x41,
  k_ANSI_KeypadMultiply       = 0x43,
  k_ANSI_KeypadPlus           = 0x45,
  k_ANSI_KeypadClear          = 0x47,
  k_ANSI_KeypadDivide         = 0x4B,
  k_ANSI_KeypadEnter          = 0x4C,
  k_ANSI_KeypadMinus          = 0x4E,
  k_ANSI_KeypadEquals         = 0x51,
  k_ANSI_Keypad0              = 0x52,
  k_ANSI_Keypad1              = 0x53,
  k_ANSI_Keypad2              = 0x54,
  k_ANSI_Keypad3              = 0x55,
  k_ANSI_Keypad4              = 0x56,
  k_ANSI_Keypad5              = 0x57,
  k_ANSI_Keypad6              = 0x58,
  k_ANSI_Keypad7              = 0x59,
  k_ANSI_Keypad8              = 0x5B,
  k_ANSI_Keypad9              = 0x5C
};

/* keycodes for keys that are independent of keyboard layout*/
enum {
  k_Return                    = 0x24,
  k_Tab                       = 0x30,
  k_Space                     = 0x31,
  k_Delete                    = 0x33,
  k_Escape                    = 0x35,
  k_Command                   = 0x37,
  k_Shift                     = 0x38,
  k_CapsLock                  = 0x39,
  k_Option                    = 0x3A,
  k_Control                   = 0x3B,
  k_RightCommand              = 0x36,
  k_RightShift                = 0x3C,
  k_RightOption               = 0x3D,
  k_RightControl              = 0x3E,
  k_Function                  = 0x3F,
  k_F17                       = 0x40,
  k_VolumeUp                  = 0x48,
  k_VolumeDown                = 0x49,
  k_Mute                      = 0x4A,
  k_F18                       = 0x4F,
  k_F19                       = 0x50,
  k_F20                       = 0x5A,
  k_F5                        = 0x60,
  k_F6                        = 0x61,
  k_F7                        = 0x62,
  k_F3                        = 0x63,
  k_F8                        = 0x64,
  k_F9                        = 0x65,
  k_F11                       = 0x67,
  k_F13                       = 0x69,
  k_F16                       = 0x6A,
  k_F14                       = 0x6B,
  k_F10                       = 0x6D,
  k_F12                       = 0x6F,
  k_F15                       = 0x71,
  k_Help                      = 0x72,
  k_Home                      = 0x73,
  k_PageUp                    = 0x74,
  k_ForwardDelete             = 0x75,
  k_F4                        = 0x76,
  k_End                       = 0x77,
  k_F2                        = 0x78,
  k_PageDown                  = 0x79,
  k_F1                        = 0x7A,
  k_LeftArrow                 = 0x7B,
  k_RightArrow                = 0x7C,
  k_DownArrow                 = 0x7D,
  k_UpArrow                   = 0x7E
};

#endif
