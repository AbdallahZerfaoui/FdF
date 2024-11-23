/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azerfaou <azerfaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 20:46:11 by azerfaou          #+#    #+#             */
/*   Updated: 2024/10/25 13:02:28 by azerfaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// This function returns a pointer to the matching byte or NULL
// if the character does not occur in the given memory area.

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*mem_block;
	unsigned char	ch;

	mem_block = (unsigned char *)str;
	ch = (unsigned char)c;
	while (n--)
	{
		if (*mem_block == ch)
			return (mem_block);
		mem_block++;
	}
	return (NULL);
}
