/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimustaev <aimustaev@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 01:13:35 by aimustaev         #+#    #+#             */
/*   Updated: 2023/04/04 01:21:51 by aimustaev        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/kernel.h"

t_terminal terminal_initialize(void)
{
    t_terminal term;

    term.cursor = cursor_initialize();

    term.color = vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
    term.buffer = (uint16_t *)0xB8000;
    for (size_t y = 0; y < VGA_HEIGHT; y++)
    {
        for (size_t x = 0; x < VGA_WIDTH; x++)
        {
            const size_t index = y * VGA_WIDTH + x;
            term.buffer[index] = vga_entry(' ', term.color);
        }
    }
    return term;
}
