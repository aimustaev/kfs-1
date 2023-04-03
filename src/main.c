/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimustaev <aimustaev@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 01:13:41 by aimustaev         #+#    #+#             */
/*   Updated: 2023/04/04 01:47:21 by aimustaev        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/kernel.h"
#include "../headers/keyboard.h"

void test(t_terminal *term, char *s1, char *s2)
{
	char str[10];
	kfs_putstr(term, s1);
	kfs_putstr(term, " ? ");
	kfs_putstr(term, s2);
	kfs_putstr(term, " = ");
	kfs_putstr(term, kfs_itoa(kfs_strcmp(s1, s2), &str));
	kfs_putstr(term, ";\n");
}

void test_key(t_terminal *term)
{
	char str[10];

	while (1)
	{
		char keycode = get_pressed_char();
		if (keycode <= 0)
		{
			if (keycode == LEFT_ARROW_KEY)
			{
				term->cursor->move(term->cursor, CURSOR_MOVE_LEFT);
			}
			else if (keycode == RIGHT_ARROW_KEY)
			{
				term->cursor->move(term->cursor, CURSOR_MOVE_RIGHT);
			}
			else
			{
				kfs_putstr(term, kfs_itoa(keycode, &str));
			}
		}
		else
		{
			kfs_putchar(term, keycode);
		}
	}
}

int main(void)
{
	t_terminal term;

	term = terminal_initialize();

	terminal_setcolor(&term, VGA_COLOR_BROWN);
	kfs_putstr(&term, "12\n");
	test(&term, "001", "002");
	test(&term, "000", "000");
	test(&term, "001", "000");

	test_key(&term);
	return 0;
}
