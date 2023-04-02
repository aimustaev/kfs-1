#include "../../headers/io.h"
#include "../../headers/kernel.h"

uint16_t get_cursor_position(void)
{
    uint16_t pos = 0;
    outb(0x3D4, 0x0F);
    pos |= inb(0x3D5);
    outb(0x3D4, 0x0E);
    pos |= ((uint16_t)inb(0x3D5)) << 8;
    return pos;
}

void set_cursor_position(uint16_t position)
{
    outb(0x3D4, 0x0E);
    outb(0x3D5, (position >> 8));
    outb(0x3D4, 0x0F);
    outb(0x3D5, position);
}
