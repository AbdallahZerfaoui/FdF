/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azerfaou <azerfaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 20:55:01 by azerfaou          #+#    #+#             */
/*   Updated: 2024/10/25 13:02:28 by azerfaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// This function returns a pointer to the last occurrence of character in str.
// If the value is not found, the function returns a null pointer.

char	*ft_strrchr(const char *str, int search_chr)
{
	char	*last;

	last = NULL;
	while (*str)
	{
		if (*str == (char) search_chr)
			last = (char *)str;
		str++;
	}
	if (*str == (char) search_chr)
		last = (char *)str;
	return (last);
}
