#include "../includes/libft.h"

// The memmove function copies n_bytes from src to dst. 
// The main difference between memcpy and memmove is that memmove 
//can handle overlapping memory regions.
// If dst is before src, the function copies the data from the beginning 
// to the end because even if it overwrites the data, it will not affect the
// data that has not been copied yet.
// If src is before dst, the function copies the data from the end to the beginning for the same reason.

void *ft_memmove(void *dst, const void *src, size_t n_bytes)
{
    unsigned char *dst_ptr;
    const unsigned char *src_ptr;

    if (!dst || !src)
        return (NULL);

    dst_ptr = (unsigned char *)dst;
    src_ptr = (const unsigned char *)src;
    if (dst_ptr < src_ptr) // || (src_ptr + n_bytes) <= dst_ptr)
    {
        while (n_bytes--)
            *dst_ptr++ = *src_ptr++;
    }
    else
    {
        dst_ptr += n_bytes;
        src_ptr += n_bytes;
        while (n_bytes--)
            *--dst_ptr = *--src_ptr;
    }
    return (dst);
}