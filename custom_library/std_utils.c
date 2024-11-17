#include "../includes/get_next_line.h"


// char	*ft_strdup(const char *s)
// {
//     char	*ptr;
//     size_t	size;

//     size = 0;
//     while (s[size])
//         size++;
//     ptr = (char *)malloc(size + 1);
//     if (!ptr)
//         return (NULL);
//     size = 0;
//     while (s[size])
//     {
//         ptr[size] = s[size];
//         size++;
//     }
//     ptr[size] = '\0';
//     return (ptr);
// }

size_t ft_strlcat_gnl(char *dst, const char *src, size_t dst_size)
{
    size_t i;
    size_t dst_len;
    size_t src_len;

    dst_len = 0;
    while (dst[dst_len] && dst_len < dst_size)
        dst_len++;
    src_len = ft_strlen(src);
    i = 0;
    while (src[i] && dst_len + i + 1 < dst_size)
    {
        dst[dst_len + i] = src[i];
        i++;
    }
    if (dst_len < dst_size)
        dst[dst_len + i] = '\0';
    return (dst_len + src_len);
}

// void *ft_memset(void *s, int c, size_t n)
// {
//     unsigned char *ptr;

//     ptr = s;
//     while (n--)
//     {
//         *ptr = c;
//         ptr++;
//     }
//     return (s);
// }

// char *ft_strchr(const char *str, int search_chr)
// {
//     if (!str)
//         return (NULL);
//     while (*str)
//     {
//         if (*str == search_chr)
//             return ((char *)str);
//         str++;
//     }
//     if (*str == search_chr)
//         return ((char *)str);
//     return (NULL);
// }

// char *ft_strncpy (char *destination, const char *source, size_t n)
// {
//     size_t i;

//     i = 0;
//     while (source[i] && i < n)
//     {
//         destination[i] = source[i];
//         i++;
//     }
//     while (i < n)
//     {
//         destination[i] = '\0';
//         i++;
//     }
//     return (destination);
// }

// size_t ft_strlcpy(char *dst, const char *src, size_t dst_size)
// {
//     size_t	i;
//     size_t src_len;

//     src_len = ft_strlen(src);

//     i = 0;
//     if (dst_size == 0)
//         return (src_len);
//     while (src[i] && i < dst_size - 1)
//     {
//         dst[i] = src[i];
//         i++;
//     }
//     dst[i] = '\0';
//     return (src_len);
// }

char *ft_strjoin_gnl(char const *s1, char const *s2)
{
    char *str_result;

    if (!s1 && !s2)
        return (NULL);
    str_result = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if (!str_result)
        return (NULL);

    ft_strlcpy(str_result, s1, ft_strlen(s1)+1);
    ft_strlcat_gnl(str_result, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
    // free((char *)s1); // free remainder(s1) in get_next_line
    return (str_result);
}


