#include "../../headers/terminal.h"

void move_cursor_left(t_terminal *term)
{
    if (++term->column == VGA_WIDTH)
    {
        term->column = 0;
        if (++term->row == VGA_HEIGHT)
            term->row = 0;
    }
}

void move_cursor_down(t_terminal *term)
{

    if (++term->row == VGA_HEIGHT)
        term->row = 0;
}

void move_cursor_next_line(t_terminal *term)
{
    term->column = 0;
    if (++term->row == VGA_HEIGHT)
        term->row = 0;
}