/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd_pf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azerfaou <azerfaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 20:46:44 by azerfaou          #+#    #+#             */
/*   Updated: 2024/10/25 13:04:19 by azerfaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/**
 * @brief Print a string to a file descriptor and add a newline at the end
 */
int	ft_putendl_fd_pf(char *s, int fd)
{
	ssize_t	result;

	ft_putstr_fd_pf(s, fd);
	result = ft_putchar_fd_pf('\n', fd);
	if (result == -1)
		return (-1);
	return (ft_strlen(s) + 1);
}
