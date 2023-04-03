#include "../../headers/terminal.h"

void kfs_putchar(t_terminal *term, char c)
{
	set_value_by_position(term, c);
	term->cursor->move(term->cursor, CURSOR_MOVE_RIGHT);
}
