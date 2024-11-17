#include "../includes/libft.h"

//memset() is used to fill a block of memory with a particular value.

void *ft_memset(void *s, int c, size_t n)
{
    unsigned char *ptr;

    ptr = s;
    while (n--)
    {
        *ptr = c;
        ptr++;
    }
    return (s);
}