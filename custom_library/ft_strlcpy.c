#include "../includes/libft.h"

// The strlcpy() function copies up to size − 1 characters from the 
// NUL-terminated string src to dst, NUL-terminating the result.

// static size_t	ft_strlen(const char *s)
// {
//     size_t	size;

//     size = 0;
//     while (*s)
//     {
//         size++;
//         s++;
//     }
//     return (size);
// }

size_t ft_strlcpy(char *dst, const char *src, size_t dst_size)
{
    size_t	i;
    size_t src_len;

    src_len = ft_strlen(src);

    i = 0;
    if (dst_size == 0)
        return (src_len);
    while (src[i] && i < dst_size - 1)
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (src_len);
}