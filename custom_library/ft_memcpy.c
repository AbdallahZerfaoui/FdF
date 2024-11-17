#include "../includes/libft.h"

// The memcpy function assumes that the source and destination do not overlap. 
// If there's any overlap, you should use memmove instead. 

void *ft_memcpy(void *dst, const void *src, size_t n_bytes)
{
    unsigned char *dst_ptr;
    const unsigned char *src_ptr;

    if (!dst || !src)
        return (NULL);

    dst_ptr = (unsigned char *)dst;
    src_ptr = (const unsigned char *)src;
    while (n_bytes--)
        *dst_ptr++ = *src_ptr++;
    return (dst);
}