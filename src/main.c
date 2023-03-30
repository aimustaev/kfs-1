#include "../headers/kernel.h"

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

int main(void)
{
	t_terminal term;
	
	term = terminal_initialize();

	terminal_setcolor(&term, VGA_COLOR_BROWN);
	kfs_putstr(&term, "42\n");
	test(&term, "001", "002");
	test(&term, "000", "000");
	test(&term, "001", "000");
	set_cursor_position(term.row * VGA_WIDTH + term.column);
	return 0;
}
