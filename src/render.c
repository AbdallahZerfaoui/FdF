/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azerfaou <azerfaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:43:23 by azerfaou          #+#    #+#             */
/*   Updated: 2024/11/17 19:55:41 by azerfaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

/**
 * @note the +180 in the angle is to rotate the map 180 degrees
 */
t_2d_point	isometric_projection(t_point point, int zoom, int x_offset,
		int y_offset)
{
	t_2d_point	iso_point;
	double		angle;

	angle = (30 + 180) * (4 * atan(1) / 180);
	iso_point.iso_x = (point.x - point.y) * cos(angle) * zoom + x_offset;
	iso_point.iso_y = ((point.x + point.y) * sin(angle) - point.z) * zoom
		+ y_offset;
	return (iso_point);
}

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

void	draw_line(t_data *data, t_2d_point p1, t_2d_point p2, int color)
{
	int	delta_x;
	int	delta_y;
	int	sign_x;
	int	sign_y;
	int	error;
	int	error2;

	delta_x = abs(p2.iso_x - p1.iso_x);
	delta_y = abs(p2.iso_y - p1.iso_y);
	sign_x = p1.iso_x < p2.iso_x ? 1 : -1;
	sign_y = p1.iso_y < p2.iso_y ? 1 : -1;
	error = delta_x - delta_y;
	while (p1.iso_x != p2.iso_x || p1.iso_y != p2.iso_y)
	{
		draw_pixel(data, p1.iso_x, p1.iso_y, color);
		error2 = error * 2;
		if (error2 > -delta_y)
		{
			error -= delta_y;
			p1.iso_x += sign_x;
		}
		if (error2 < delta_x)
		{
			error += delta_x;
			p1.iso_y += sign_y;
		}
	}
}

int	get_color(int z, t_data *data)
{
	double	ratio;
	int		min_z;
	int		max_z;

	int red, green, blue;
	// Simple gradient from blue (low) to red (high)
	min_z = min_map(data->map, data->n_rows, data->n_cols);
	max_z = max_map(data->map, data->n_rows, data->n_cols);
	ratio = (double)(z - min_z) / (max_z - min_z);
	// Interpolate between blue and red
	red = (int)(255 * ratio);        // Red increases as z increases
	green = 0;                       // No green in the gradient
	blue = (int)(255 * (1 - ratio)); // Blue decreases as z increases
	// Combine red, green, and blue into an RGB value (0xRRGGBB)
	return ((red << 16) | (green << 8) | blue);
}

void	render_map(t_data *data)
{
	t_2d_point	p1;
	t_2d_point	p2;
	int			color;

	color = WHITE;
	for (size_t i = 0; i < data->n_rows; i++)
	{
		for (size_t j = 0; j < data->n_cols; j++)
		{
			color = get_color(data->map[i][j].z, data);
			printf("color for z: %d is: %x\n", data->map[i][j].z, color);
			p1 = isometric_projection(data->map[i][j], data->zoom,
					data->x_offset, data->y_offset);
			draw_pixel(data, (int)p1.iso_x, (int)p1.iso_y, color);
			if (j + 1 < data->n_cols)
			{
				p2 = isometric_projection(data->map[i][j + 1], data->zoom,
						data->x_offset, data->y_offset);
				draw_line(data, p1, p2, color);
			}
			if (i + 1 < data->n_rows)
			{
				p2 = isometric_projection(data->map[i + 1][j], data->zoom,
						data->x_offset, data->y_offset);
				draw_line(data, p1, p2, color);
			}
		}
	}
}
