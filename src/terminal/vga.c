#include "../../headers/kernel.h"

// void terminal_write(const char *data, size_t size)
// {
//     for (size_t i = 0; i < size; i++)
//         terminal_putchar(data[i]);
// }

uint8_t vga_entry_color(enum vga_color fg, enum vga_color bg)
{
	return fg | bg << 4;
}

uint16_t vga_entry(unsigned char uc, uint8_t color)
{
	return (uint16_t) uc | (uint16_t) color << 8;
}
