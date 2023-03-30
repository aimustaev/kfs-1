#ifndef UTILS_H
#define UTILS_H

size_t kfs_strlen(const char *str);
void kfs_write(t_terminal *term, const char *data, size_t size);
void kfs_putchar(t_terminal *term, char c);
void kfs_putstr(t_terminal *term, const char *data);
int kfs_strcmp(const char *s1, const char *s2);
size_t kfs_intlen(int n);
char *kfs_itoa(int n, char *str);
void *kfs_memset(void *b, int c, size_t len);
#endif