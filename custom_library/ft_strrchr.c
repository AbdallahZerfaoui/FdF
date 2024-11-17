#include "../includes/libft.h"

// This function returns a pointer to the last occurrence of character in str. 
// If the value is not found, the function returns a null pointer.

char *ft_strrchr(const char *str, int search_chr)
{
    char *last = NULL;
    while (*str)
    {
        if (*str == search_chr)
            last = (char *)str;
        str++;
    }
    if (*str == search_chr)
        last = (char *)str;
    return (last);
}