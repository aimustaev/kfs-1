/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vga.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimustaev <aimustaev@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 01:12:38 by aimustaev         #+#    #+#             */
/*   Updated: 2023/04/04 01:21:37 by aimustaev        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/kernel.h"

uint8_t vga_entry_color(enum vga_color fg, enum vga_color bg)
{
	return fg | bg << 4;
}

uint16_t vga_entry(unsigned char uc, uint8_t color)
{
	return (uint16_t)uc | (uint16_t)color << 8;
}

void terminal_setcolor(t_terminal *term, uint8_t color)
{
	term->color = color;
}

void set_value_by_position(t_terminal *term, char c)
{
	const size_t position = term->cursor->get_position(term->cursor);
	term->buffer[position] = vga_entry(c, term->color);
}
