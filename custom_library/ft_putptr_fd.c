#include "../includes/libft.h"

void display_hex(void *ptr, int fd)
{
    unsigned long long n = (unsigned long long)ptr;
    char *base = "0123456789abcdef";
    if (n >= 16)
        display_hex((void *)(n / 16), fd);
    write(fd, base + n % 16, 1);
}

void ft_putptr_fd(void *ptr, int fd)
{
    write(fd, "0x", 2);
    display_hex(ptr, fd);
}