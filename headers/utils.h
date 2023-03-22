#ifndef UTILS_H
# define UTILS_H

size_t kfs_strlen(const char* str);
void kfs_write(t_terminal term, const char* data, size_t size);
void kfs_putchar(t_terminal *term, char c);
void kfs_putstr(t_terminal term, const char *data);

#endif