#include "../../headers/kernel.h"

size_t	kfs_intlen(int n)
{
	int		i;

	i = 1;
    if (n < 0) {
        n = -n;
        i++;
    }
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}
