/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azerfaou <azerfaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 20:52:36 by azerfaou          #+#    #+#             */
/*   Updated: 2024/10/31 12:05:21 by azerfaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// This function returns a pointer to a null-terminated byte string,
// which is a duplicate of the string pointed to by s.
// The memory obtained is done dynamically using malloc

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	size;

	size = 0;
	while (s[size])
		size++;
	ptr = (char *)malloc(size + 1);
	if (!ptr)
		return (NULL);
	size = 0;
	while (s[size])
	{
		ptr[size] = s[size];
		size++;
	}
	ptr[size] = '\0';
	return (ptr);
}

// /**
//  * @note version get next line
//  */
// char	*ft_strdup(const char *s)
// {
// 	char	*ptr;
// 	size_t	size;

// 	size = ft_strlen(s);
// 	ptr = (char *)ft_calloc(size + 1, sizeof(char));
// 	if (!ptr)
// 		return (NULL);
// 	ptr = ft_strncpy(ptr, s, size);
// 	return (ptr);
// }
