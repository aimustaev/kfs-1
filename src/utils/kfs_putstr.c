#include "../../headers/kernel.h"

void kfs_putstr(t_terminal *term, const char *data)
{
	kfs_write(term, data, kfs_strlen(data));
}