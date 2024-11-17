#include "../includes/libft.h"

void ft_putunbr_fd(unsigned int n, int fd)
{
    if (n >= 10)
        ft_putunbr_fd(n / 10, fd);
    write(fd, &"0123456789"[n % 10], 1);
}