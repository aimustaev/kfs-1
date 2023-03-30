#include "../../headers/io.h"

void outw(uint16_t port, uint16_t value)
{
    asm volatile ("outw %1, %0" : : "dN" (port), "a" (value));
}
