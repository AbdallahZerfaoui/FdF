/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azerfaou <azerfaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:43:23 by azerfaou          #+#    #+#             */
/*   Updated: 2024/11/23 17:27:29 by azerfaou         ###   ########.fr       */
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

/**
 * @brief return a nuance of color depending on the z value
 * @param z the z value
 * @param data the data structure
 * @return the color
 */
int	get_color(int z, t_data *data)
{
	double	ratio;
	int		min_z;
	int		max_z;
	t_rgb	rgb;

	min_z = min_map(data->map, data->n_rows, data->n_cols);
	max_z = max_map(data->map, data->n_rows, data->n_cols);
	ratio = (double)(z - min_z) / (max_z - min_z);
	rgb.red = (int)(255 * ratio);
	rgb.green = 0;
	rgb.blue = (int)(255 * (1 - ratio));
	return ((rgb.red << 16) | (rgb.green << 8) | rgb.blue);
}

t_2d_point	draw_elem_from_data(t_data *data, int i, int j, int color)
{
	t_2d_point	p;

	p = isometric_projection(data->map[i][j], data->zoom, data->x_offset,
			data->y_offset);
	draw_pixel(data, (int)p.iso_x, (int)p.iso_y, color);
	return (p);
}

void	draw_line_from_p1_H(t_data *data, int i, int j, int color)
{
	t_2d_point	p1;
	t_2d_point	p2;

	p1 = isometric_projection(data->map[i][j], data->zoom,
			data->x_offset, data->y_offset);
	p2 = isometric_projection(data->map[i][j + 1], data->zoom,
			data->x_offset, data->y_offset);
	draw_line(data, p1, p2, color);
}

void	draw_line_from_p1_V(t_data *data, t_2d_point p1, int color)
{
	t_2d_point	p2;

	p2 = isometric_projection(data->map[p1.iso_x + 1][p1.iso_y], data->zoom,
			data->x_offset, data->y_offset);
	draw_line(data, p1, p2, color);
}


void	render_map(t_data *data)
{
	t_2d_point	p1;
	t_2d_point	p2;
	int			color;
	size_t		i;
	size_t		j;

	color = WHITE;
	i = 0;
	while (i < data->n_rows)
	{
		j = 0;
		while (j < data->n_cols)
		{
			color = get_color(data->map[i][j].z, data);
			printf("color for z: %d is: %x\n", data->map[i][j].z, color);
			p1 = draw_elem_from_data(data, i, j, color);
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
			j++;
		}
		i++;
	}
}
