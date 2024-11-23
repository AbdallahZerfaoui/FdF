/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azerfaou <azerfaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:44:05 by azerfaou          #+#    #+#             */
/*   Updated: 2024/10/25 20:43:21 by azerfaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
/***
 * @brief This function will print a format string to the standard output
 * @param format The format string
 * @param ... The arguments to replace the format string
 * @return The number of characters printed
 */
int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		result;

	va_start(args, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format != '%')
		{
			if (ft_putchar_fd_pf(*format, 1) == -1)
				return (va_end(args), -1);
			count++;
		}
		else
		{
			format++;
			result = print_format(*format, args);
			if (result == -1)
				return (va_end(args), -1);
			count += result;
		}
		format++;
	}
	return (va_end(args), count);
}
