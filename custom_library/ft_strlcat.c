#include "../includes/libft.h"

// strlcat() appends string src to the end of dst. 
// It will append at most dst_size – strlen(dst) – 1 characters. 
// It will then NUL-terminate, unless dstsize is 0 or 
// the original dst string was longer than dstsize 
// (in practice this should not happen as it means that either dstsize is incorrect 
// or that dst is not a proper string).

size_t ft_strlcat(char *dst, const char *src, size_t dst_size)
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