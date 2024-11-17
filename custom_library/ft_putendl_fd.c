#include "../includes/libft.h"

// void ft_putstr_fd(char *s, int fd)
// {
//     while (*s)
//     {
//         write(fd, s, 1);
//         s++;
//     }
// }

void ft_putendl_fd(char *s, int fd)
{
    ft_putstr_fd(s, fd);
    write(fd, "\n", 1);
}