#include "../includes/libft.h"

// static size_t	ft_strlen(const char *s)
// {
//     size_t	size;

//     size = 0;
//     while (*s)
//     {
//         size++;
//         s++;
//     }
//     return (size);
// }

char *ft_strjoin(char const *s1, char const *s2)
{
    char *str_result;
    size_t i;
    size_t j;

    if (!s1 || !s2)
        return (NULL);
    str_result = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if (!str_result)
        return (NULL);
    i = 0;
    j = 0;
    while (s1[i])
    {
        str_result[i] = s1[i];
        i++;
    }
    while (s2[j])
    {
        str_result[i + j] = s2[j];
        j++;
    }
    str_result[i + j] = '\0';
    return (str_result);
}