/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azerfaou <azerfaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:46:55 by azerfaou          #+#    #+#             */
/*   Updated: 2024/10/15 19:35:27 by azerfaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// #include "printf_includes.h"
// # include "Libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

// ft_printf Helper functions
int		ft_printf(const char *format, ...);
int		print_format(char specifier, va_list args);

// Helper functions
int		ft_putunbr_fd_pf(long long n, int fd);
int		ft_puthex_fd_pf(long long n, int fd);
int		ft_puthex_upper_fd_pf(unsigned int n, int fd);
int		ft_putptr_fd_pf(void *ptr, int fd);
int		ft_putchar_fd_pf(char c, int fd);
int		ft_putstr_fd_pf(char *s, int fd);
int		ft_putendl_fd_pf(char *s, int fd);
int		ft_putnbr_fd_pf(int n, int fd);

// Helper functions
int		ft_num_digits(long long num);
size_t	ft_ptrlen(void *ptr);
size_t	ft_strlen(const char *s);

#endif
