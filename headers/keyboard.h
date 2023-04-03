/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimustaev <aimustaev@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 01:13:13 by aimustaev         #+#    #+#             */
/*   Updated: 2023/04/04 01:41:56 by aimustaev        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYBOARD_H
#define KEYBOARD_H

extern char keystatus;

char get_pressed_char(void);

#define KEYBOARD_DATA_PORT 0x60
#define KEYBOARD_CTRL_PORT 0x64

/*
 *  Internal keycodes
 */
#define SHIFT_KEY -1
#define CTRL_KEY -2
#define CAPSLOCK_KEY -3
#define LEFT_ARROW_KEY -10
#define RIGHT_ARROW_KEY -11

/*
 *  Keys bits for the keystatus
 */
#define SHIFT_BIT 1
#define CTRL_BIT 2
#define CAPSLOCK_BIT 3

/*
 *  Macros to update/get the status of a key
 */
#define SET_KEY_STATUS(status, key) status ^= (-1 ^ status) & (1 << key)
#define UNSET_KEY_STATUS(status, key) status ^= (0 ^ status) & (1 << key)
#define GET_KEY_STATUS(status, key) (status >> key) & 1

/*
 *  Macros for informations about the keycodes from the keyboard
 */
#define IS_RELEASED(keycode) keycode & 0x80
#define GET_KEYCODE_FROM_RELEASED(keycode) keycode ^ 0x80

//  * https://www.win.tue.nl/~aeb/linux/kbd/scancodes-1.html#ss1.1
//  * http://www.osdever.net/bkerndev/Docs/keyboard.htm
//  * https://wiki.osdev.org/PS2_Keyboard
static char qwerty_keyboard_table[128] = {
	0,
	0,
	'1',
	'2',
	'3',
	'4',
	'5',
	'6',
	'7',
	'8',
	'9',
	'0',
	'-',
	'=',
	'\b', /* backspace */
	'\t', /* tabulation */
	'q',
	'w',
	'e',
	'r',
	't',
	'y',
	'u',
	'i',
	'o',
	'p',
	'[',
	']',
	'\n',	  /* enter */
	CTRL_KEY, /* control */
	'a',
	's',
	'd',
	'f',
	'g',
	'h',
	'j',
	'k',
	'l',
	';',
	'\'',
	'`',
	SHIFT_KEY, /* left shift */
	'\\',
	'z',
	'x',
	'c',
	'v',
	'b',
	'n',
	'm',
	',',
	'.',
	'/',
	SHIFT_KEY, /* right shift */
	'*',
	0,			  /* alt */
	' ',		  /* space */
	CAPSLOCK_KEY, /* caps lock */
	0,			  /* F1 */
	0,			  /* F2 */
	0,			  /* F3 */
	0,			  /* F4 */
	0,			  /* F5 */
	0,			  /* F6 */
	0,			  /* F7 */
	0,			  /* F8 */
	0,			  /* F9 */
	0,			  /* F10 */
	0,			  /* num lock */
	0,			  /* scroll lock */
	0,			  /* HOME */
	0,			  /* up arrow */
	0,			  /* PAGEUP */
	'-',
	LEFT_ARROW_KEY, /* left arrow */
	0,
	RIGHT_ARROW_KEY, /* right arrow */
	'+',
	0, /* END */
	0, /* down arrow */
	0, /* PAGEDOWN */
	0, /* INSERT */
	0, /* DEL */
	0,
	0,
	0,
	0, /* F11 */
	0, /* F12 */
	0  /* undefined keys */
};

static char qwerty_shift_keyboard_table[] = {
	0, 0, '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '+', '\b', 0,
	'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '{', '}', '\n', 0, 'A',
	'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ':', '\"', '~', 0, '|', 'Z', 'X',
	'C', 'V', 'B', 'N', 'M', '<', '>', '?', 0, '*', 0, ' ', 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, '7', '8', '9', '-', '4', '5', '6', '+', '1', '2', '3',
	'0', '.', '6', 0, 0, 0, 0, 0};

#endif
