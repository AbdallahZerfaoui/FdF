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

// char *ft_substr(char const *s, unsigned int start, size_t len)
// {
//     char *str_result;
//     size_t i;

//     if (!s || start > ft_strlen(s) || len == 0)
//         return (NULL);
//     str_result = (char *)malloc(sizeof(char) * (len + 1));
//     if (!str_result)
//         return (NULL);
//     i = 0;
//     while (i < len && s[start + i])
//     {
//         str_result[i] = s[start + i];
//         i++;
//     }
//     str_result[i] = '\0';
//     return (str_result);
// }

// use ft_substr in ft_split
char **ft_split(char const *s, char c)
{
    char **result;
    size_t i;
    size_t j;
    size_t len;

    if (!s)
        return (NULL);
    result = (char **)malloc(sizeof(char *) * (ft_strlen(s) + 1));
    if (!result)
        return (NULL);
    i = 0;
    j = 0;
    while (s[i])
    {
        while (s[i] == c)
            i++;
        len = 0;
        while (s[i + len] && s[i + len] != c)
            len++;
        if (len)
        {
            result[j] = ft_substr(s, i, len);
            if (!result[j])
                return (NULL);
            j++;
        }
        i += len;
    }
    result[j] = NULL;
    return (result);
}