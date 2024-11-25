/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azerfaou <azerfaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:35:21 by azerfaou          #+#    #+#             */
/*   Updated: 2024/11/24 21:36:21 by azerfaou         ###   ########.fr       */
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
 * @brief initialize the line structure
 */
void	init_line_struct(t_line *line, t_2d_point p1, t_2d_point p2)
{
	line->delta_x = abs(p2.iso_x - p1.iso_x);
	line->delta_y = abs(p2.iso_y - p1.iso_y);
	line->error = line->delta_x - line->delta_y;
	line->sign_x = 1;
	line->sign_y = 1;
	if (p1.iso_x >= p2.iso_x)
		line->sign_x = -1;
	if (p1.iso_y >= p2.iso_y)
		line->sign_y = -1;
}

void	draw_line(t_data *data, t_2d_point p1, t_2d_point p2, int color)
{
	t_line	line;

	init_line_struct(&line, p1, p2);
	while (p1.iso_x != p2.iso_x || p1.iso_y != p2.iso_y)
	{
		draw_pixel(data, p1.iso_x, p1.iso_y, color);
		line.error2 = line.error * 2;
		if (line.error2 > -line.delta_y)
		{
			line.error -= line.delta_y;
			p1.iso_x += line.sign_x;
		}
		if (line.error2 < line.delta_x)
		{
			line.error += line.delta_x;
			p1.iso_y += line.sign_y;
		}
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

// void	draw_line_from_p1_h(t_data *data, int i, int j, int color)
// {
// 	t_2d_point	p1;
// 	t_2d_point	p2;

// 	p1 = isometric_projection(data->map[i][j], data->zoom,
// 			data->x_offset, data->y_offset);
// 	p2 = isometric_projection(data->map[i][j + 1], data->zoom,
// 			data->x_offset, data->y_offset);
// 	draw_line(data, p1, p2, color);
// }

// void	draw_line_from_p1_v(t_data *data, t_2d_point p1, int color)
// {
// 	t_2d_point	p2;

// 	p2 = isometric_projection(data->map[p1.iso_x + 1][p1.iso_y], data->zoom,
// 			data->x_offset, data->y_offset);
// 	draw_line(data, p1, p2, color);
// }
void	draw_horizontal_line(t_data *data, t_2d_point p1, int color)
{
	size_t		i;
	size_t		j;
	t_2d_point	p2;

	i = p1.i;
	j = p1.j;
	if (j + 1 < data->n_cols)
	{
		p2 = isometric_projection(data->map[i][j + 1],
				data->zoom, data->x_offset, data->y_offset);
		draw_line(data, p1, p2, color);
	}
}

void	draw_vertical_line(t_data *data, t_2d_point p1, int color)
{
	size_t		i;
	size_t		j;
	t_2d_point	p2;

	i = p1.i;
	j = p1.j;
	if (i + 1 < data->n_rows)
	{
		p2 = isometric_projection(data->map[i + 1][j],
				data->zoom, data->x_offset, data->y_offset);
		draw_line(data, p1, p2, color);
	}
}
