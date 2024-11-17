#include "../includes/libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
    while (*s1 && *s2 && *s1 == *s2)
    {
        s1++;
        s2++;
    }
    return (*s1 - *s2);
}

//Test main
// #include <stdio.h>
// #include <string.h>
// int main()
// {
//     char *s1 = "Hello";
//     char *s2 = "Hello Abdallah";
//     printf("%d\n", ft_strcmp(s1, s2));
//     return (0);
// }