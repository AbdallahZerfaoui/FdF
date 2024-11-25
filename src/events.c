/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azerfaou <azerfaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:14:53 by azerfaou          #+#    #+#             */
/*   Updated: 2024/11/24 21:04:53 by azerfaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == ESC_KEY)
	{
		clean_exit(data);
	}
	return (0);
}

int	handle_destroy(t_data *data)
{
	clean_exit(data);
	return (0);
}

void	clean_exit(t_data *data)
{
	if (data->mlx_ptr && data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free_map((void **)data->map, data->n_rows);
	exit(0);
}
