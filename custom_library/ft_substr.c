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

// char	*ft_strdup(const char *s)
// {
//     char	*ptr;
//     size_t	size;

//     size = 0;
//     while (s[size])
//         size++;
//     ptr = (char *)malloc(size + 1);
//     if (!ptr)
//         return (NULL);
//     size = 0;
//     while (s[size])
//     {
//         ptr[size] = s[size];
//         size++;
//     }
//     ptr[size] = '\0';
//     return (ptr);
// }

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *str_result;
    size_t i;

    if (!s || start > ft_strlen(s) || len == 0)
        return (NULL);
    // if (start > ft_strlen(s))
    //     return (ft_strdup(""));
    str_result = (char *)malloc(sizeof(char) * (len + 1));
    if (!str_result)
        return (NULL);
    i = 0;
    while (i < len && s[start + i])
    {
        str_result[i] = s[start + i];
        i++;
    }
    str_result[i] = '\0';
    return (str_result);
}