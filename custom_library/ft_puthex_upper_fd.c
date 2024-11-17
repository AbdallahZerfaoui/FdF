#include "../includes/libft.h"

void ft_puthex_upper_fd(unsigned int n, int fd)
{
    char *base = "0123456789ABCDEF";
    if (n >= 16)
        ft_puthex_upper_fd(n / 16, fd);
    write(fd, base + n % 16, 1);
}