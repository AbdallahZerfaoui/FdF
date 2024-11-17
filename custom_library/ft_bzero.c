#include "../includes/libft.h"

//The ft_bzero() function shall place n zero-valued bytes 
//in the area pointed to by s

void ft_bzero(void *s, size_t n)
{
    char *ptr;

    ptr = s;
    while (n--)
    {
        *ptr = 0;
        ptr++;
    }
}