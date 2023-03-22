#include "../../headers/kernel.h"

void terminal_setcolor(t_terminal *term, uint8_t color)
{
    term->color = color;
}