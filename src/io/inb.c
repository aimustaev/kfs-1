#include "../../headers/io.h"

uint8_t inb(uint16_t port)
{
  uint8_t ret;
  asm volatile("inb %1, %0" : "=a"(ret) : "dN"(port));
  return ret;
}
