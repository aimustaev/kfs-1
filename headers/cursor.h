/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimustaev <aimustaev@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 01:12:46 by aimustaev         #+#    #+#             */
/*   Updated: 2023/04/04 01:23:31 by aimustaev        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURSOR_H
#define CURSOR_H

#include "types.h"

enum cursor_move
{
	CURSOR_MOVE_LEFT = 0,
	CURSOR_MOVE_RIGHT = 1,
	CURSOR_MOVE_NEXT_LINE = 2,
};

typedef struct Cursor
{
	size_t row;
	size_t column;

	size_t (*get_position)(struct Cursor *this);
	size_t (*get_cursor_position)(void);
	size_t (*set_cursor_position)(uint16_t position);
	size_t (*move)(struct Cursor *this, enum cursor_move type);
	size_t (*left)(struct Cursor *this);
	size_t (*right)(struct Cursor *this);
	size_t (*next_line)(struct Cursor *this);
} t_cursor;

size_t get_position(t_cursor *this);
t_cursor *cursor_initialize(void);
uint16_t get_cursor_position(void);
void set_cursor_position(uint16_t position);
// MOVE
void cursor_move(t_cursor *this, enum cursor_move type);
void cursor_move_left(t_cursor *this);
void cursor_move_right(t_cursor *this);
void cursor_move_next_line(t_cursor *term);
#endif
