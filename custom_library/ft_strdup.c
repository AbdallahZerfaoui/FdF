#include "../includes/libft.h"

// This function returns a pointer to a null-terminated byte string, 
// which is a duplicate of the string pointed to by s. 
// The memory obtained is done dynamically using malloc

char	*ft_strdup(const char *s)
{
    char	*ptr;
    size_t	size;

    size = 0;
    while (s[size])
        size++;
    ptr = (char *)malloc(size + 1);
    if (!ptr)
        return (NULL);
    size = 0;
    while (s[size])
    {
        ptr[size] = s[size];
        size++;
    }
    ptr[size] = '\0';
    return (ptr);
}