#include "../includes/get_next_line.h"


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


