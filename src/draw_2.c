/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azerfaou <azerfaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:35:21 by azerfaou          #+#    #+#             */
/*   Updated: 2024/11/25 19:21:32 by azerfaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
