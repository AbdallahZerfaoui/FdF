/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azerfaou <azerfaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:20:12 by azerfaou          #+#    #+#             */
/*   Updated: 2024/11/25 19:20:56 by azerfaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_pixel(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < PIXEL_SIZE)
	{
		while (j < PIXEL_SIZE)
		{
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

/**
 * @brief draw a pixel from a t_data elem on the screen
 * @note this function project the point in isometric projection
 * then draw the pixel on the screen
 */
t_2d_point	draw_elem_from_data(t_data *data, int i, int j, int color)
{
	t_2d_point	p;

	p = isometric_projection(data->map[i][j], data->zoom, data->x_offset,
			data->y_offset);
	p.i = i;
	p.j = j;
	draw_pixel(data, (int)p.iso_x, (int)p.iso_y, color);
	return (p);
}
