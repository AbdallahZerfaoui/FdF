/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azerfaou <azerfaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 20:56:01 by azerfaou          #+#    #+#             */
/*   Updated: 2024/10/08 11:46:52 by azerfaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The value of c must be between 0 and 255
// The function ft_tolower() converts an upper-case letter
// to the corresponding lower-case letter.

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	if (c < -1)
		return (c + 256);
	return (c);
}
