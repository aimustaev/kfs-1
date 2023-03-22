#include "../../headers/terminal.h"

void set_value_by_position(t_terminal *term, char c)
{
    const size_t index = term->row * VGA_WIDTH + term->column;
    term->buffer[index] = vga_entry(c, term->color);
}