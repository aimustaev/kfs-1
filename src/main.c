#include "../headers/kernel.h"

int main(void)
{
	t_terminal term;

	term = terminal_initialize();

	terminal_setcolor(&term, VGA_COLOR_GREEN);
	kfs_putstr(term, "42");
	return 0;
}
