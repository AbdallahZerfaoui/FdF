/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azerfaou <azerfaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 20:56:11 by azerfaou          #+#    #+#             */
/*   Updated: 2024/10/07 21:24:16 by azerfaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The value of c must be between -128 and 127
// The function ft_toupper() converts a lower-case letter to
// the corresponding upper-case letter.

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	if (c < -1)
		return (c + 256);
	return (c);
}
