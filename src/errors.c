/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azerfaou <azerfaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:16:54 by azerfaou          #+#    #+#             */
/*   Updated: 2024/11/25 19:17:21 by azerfaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	display_error(void)
{
	perror("Error\n");
	exit(1);
}

void	handle_inputs(int argc)
{
	if (argc != 2)
	{
		perror("Usage: ./fdf <file.fdf>\n");
		exit (1);
	}
}
