#include "../includes/libft.h"

size_t	ft_strlen(const char *s)
{
    size_t	size;

    size = 0;
    if (!s)
        return (size);
    while (*s)
    {
        size++;
        s++;
    }
    return (size);
}