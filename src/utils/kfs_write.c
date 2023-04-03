#include "../../headers/kernel.h"

void kfs_write(t_terminal *term, const char *data, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		if (data[i] == 10)
		{
			term->cursor->move(term->cursor, CURSOR_MOVE_NEXT_LINE);
		}
		else
		{
			kfs_putchar(term, data[i]);
		}
	}
}