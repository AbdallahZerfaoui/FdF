#include "../includes/libft.h"

void ft_puthex_fd(unsigned int n, int fd)
{
    char *base = "0123456789abcdef";
    if (n >= 16)
        ft_puthex_fd(n / 16, fd);
    write(fd, base + n % 16, 1);
}