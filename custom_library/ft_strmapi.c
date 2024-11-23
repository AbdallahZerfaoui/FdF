/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azerfaou <azerfaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 20:54:31 by azerfaou          #+#    #+#             */
/*   Updated: 2024/10/25 13:02:28 by azerfaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// ft_striteri takes a string and a function as arguments.
// The function iterates over the string and applies 
// the function to each character in the string.
// The function takes the index of the character and the character as arguments.
// It creates a new string with the results of the 
// function applied to each character.

char	*ft_strmapi(char const *s, char (*func)(unsigned int, char))
{
	char			*str_result;
	unsigned int	i;

	if (!s || !func)
		return (NULL);
	str_result = (char *)malloc(ft_strlen(s) + 1);
	if (!str_result)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str_result[i] = func(i, s[i]);
		i++;
	}
	str_result[i] = '\0';
	return (str_result);
}
