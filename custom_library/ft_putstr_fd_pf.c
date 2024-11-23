/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_pf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azerfaou <azerfaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 20:51:42 by azerfaou          #+#    #+#             */
/*   Updated: 2024/10/25 13:04:19 by azerfaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putstr_fd_pf(char *s, int fd)
{
	char	*s_backup;
	ssize_t	result;

	s_backup = s;
	if (!s)
		return (ft_putstr_fd_pf("(null)", fd));
	while (*s)
	{
		result = ft_putchar_fd_pf(*s, fd);
		if (result == -1)
			return (-1);
		s++;
	}
	return (ft_strlen(s_backup));
}
