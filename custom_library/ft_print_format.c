/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azerfaou <azerfaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:33:47 by azerfaou          #+#    #+#             */
/*   Updated: 2024/10/25 13:04:19 by azerfaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
 * @brief This function will print a format string to the standard output
 * You must check if the write failed,
	by checking the return value of the write function
 * and mainly inside of all the recursive functions
 */
int	print_format(char specifier, va_list args)
{
	if (specifier == 'c')
		return (ft_putchar_fd_pf(va_arg(args, int), 1));
	else if (specifier == 's')
		return (ft_putstr_fd_pf(va_arg(args, char *), 1));
	else if (specifier == 'p')
		return (ft_putptr_fd_pf(va_arg(args, void *), 1));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_putnbr_fd_pf(va_arg(args, int), 1));
	else if (specifier == 'u')
		return (ft_putunbr_fd_pf(va_arg(args, unsigned int), 1));
	else if (specifier == 'x')
		return (ft_puthex_fd_pf(va_arg(args, unsigned int), 1));
	else if (specifier == 'X')
		return (ft_puthex_upper_fd_pf(va_arg(args, unsigned int), 1));
	else if (specifier == '%')
		return (ft_putchar_fd_pf('%', 1));
	return (0);
}
