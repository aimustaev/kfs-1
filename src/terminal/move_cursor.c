#include "../../headers/terminal.h"

void move_cursor(t_terminal *term)
{
    if (++term->column == VGA_WIDTH)
    {
        term->column = 0;
        if (++term->row == VGA_HEIGHT)
            term->row = 0;
    }
}