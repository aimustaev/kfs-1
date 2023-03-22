#include "../../headers/kernel.h"

void kfs_write(t_terminal term, const char* data, size_t size)
{
	for (size_t i = 0; i < size; i++)
		kfs_putchar(&term, data[i]);
}