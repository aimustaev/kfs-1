/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimustaev <aimustaev@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 01:30:14 by aimustaev         #+#    #+#             */
/*   Updated: 2023/04/04 01:42:35 by aimustaev        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/kernel.h"

char keystatus = 0;

uint16_t keyboard_handler(void)
{
	uint16_t keycode = 0;

	while (1)
	{
		keycode = inb(KEYBOARD_DATA_PORT);

		if (IS_RELEASED(keycode))
		{
			switch (qwerty_keyboard_table[GET_KEYCODE_FROM_RELEASED(keycode)])
			{
			case SHIFT_KEY:
				UNSET_KEY_STATUS(keystatus, SHIFT_BIT);
			case CTRL_KEY:
				UNSET_KEY_STATUS(keystatus, CTRL_BIT);
			}
		}
		else
		{
			outb(KEYBOARD_DATA_PORT, 0);
			if (keycode < 0 || keycode > 128)
				continue;
			switch (qwerty_keyboard_table[keycode])
			{
			case SHIFT_KEY:
				SET_KEY_STATUS(keystatus, SHIFT_BIT);
				break;
			case CTRL_KEY:
				SET_KEY_STATUS(keystatus, CTRL_BIT);
				break;
			case CAPSLOCK_KEY:
				if (GET_KEY_STATUS(keystatus, CAPSLOCK_BIT))
					UNSET_KEY_STATUS(keystatus, CAPSLOCK_BIT);
				else
					SET_KEY_STATUS(keystatus, CAPSLOCK_BIT);
				break;
			}
			break;
		}
	}
	return keycode;
}

char get_pressed_char(void)
{
	uint16_t keycode = 0;

	keycode = keyboard_handler();
	if (GET_KEY_STATUS(keystatus, SHIFT_BIT) || GET_KEY_STATUS(keystatus, CAPSLOCK_BIT))
	{
		return qwerty_shift_keyboard_table[keycode];
	}
	return qwerty_keyboard_table[keycode];
}
