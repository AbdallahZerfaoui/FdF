#include "../includes/libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
    char	*ptr;

    ptr = dst;
    while (*src)
    {
        *dst = *src;
        dst++;
        src++;
    }
    *dst = '\0';
    return (ptr);
}