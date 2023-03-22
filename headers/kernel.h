#ifndef KERNEL_H
# define KERNEL_H

#include "types.h"
#include "terminal.h"
#include "utils.h"

static t_terminal g_term;

// static struct kfs_terminal g_terminal;

void terminal_write(t_terminal term, const char *data, size_t size);
void terminal_putchar(t_terminal *term, char c);

#endif