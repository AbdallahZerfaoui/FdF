#include "../includes/libft.h"

char *ft_strncpy (char * destination, const char * source, size_t n)
{
    size_t i;

    i = 0;
    while (source[i] && i < n)
    {
        destination[i] = source[i];
        i++;
    }
    while (i < n)
    {
        destination[i] = '\0';
        i++;
    }
    return (destination);
}