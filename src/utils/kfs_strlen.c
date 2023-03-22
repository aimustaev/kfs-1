#include "../../headers/types.h"

size_t kfs_strlen(const char *str)
{
    size_t len = 0;
    while (str[len])
        len++;
    return len;
}
