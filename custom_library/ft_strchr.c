#include "../includes/libft.h"

// This function returns a pointer to the first occurrence of the character i.e. 
// "search_chr" in the string(str), or NULL if the character is not found.

char *ft_strchr(const char *str, int search_chr)
{
    if (!str)
        return (NULL);
    while (*str)
    {
        if (*str == search_chr)
            return ((char *)str);
        str++;
    }
    if (*str == search_chr)
        return ((char *)str);
    return (NULL);
}
