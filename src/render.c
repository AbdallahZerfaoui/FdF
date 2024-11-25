/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azerfaou <azerfaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:43:23 by azerfaou          #+#    #+#             */
/*   Updated: 2024/11/25 19:10:22 by azerfaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/**
 * @note the +180 in the angle is to rotate the map 180 degrees
 */
t_2d_point	isometric_projection(t_point point, int zoom, int x_offset,
		int y_offset)
{
	t_2d_point	iso_point;
	double		angle;

	iso_point.i = 0;
	iso_point.j = 0;
	angle = (30 + 180) * (4 * atan(1) / 180);
	iso_point.iso_x = (point.x - point.y) * cos(angle) * zoom + x_offset;
	iso_point.iso_y = ((point.x + point.y) * sin(angle) - point.z) * zoom
		+ y_offset;
	return (iso_point);
}

/**
 * @brief return a nuance of color depending on the z value
 * @param z the z value
 * @param data the data structure
 * @return the color
 * @note You can call this function with a data or params structure
 */
int	get_color(int z, t_map_params *data)
{
	double	ratio;
	int		min_z;
	int		max_z;
	t_rgb	rgb;

	ratio = 0;
	min_z = min_map(data->map, data->n_rows, data->n_cols);
	max_z = max_map(data->map, data->n_rows, data->n_cols);
	if (min_z != max_z)
		ratio = (double)(z - min_z) / (max_z - min_z);
	rgb.red = (int)(255 * ratio);
	rgb.green = 0;
	rgb.blue = (int)(255 * (1 - ratio));
	return ((rgb.red << 16) | (rgb.green << 8) | rgb.blue);
}

/**
 * render_map - Renders a 2D representation of the map by projecting 3D points 
 *			into isometric coordinates and drawing lines between them.
 *
 * @data: A pointer to the data structure containing the map, colors, and other
 *		rendering parameters such as zoom and offsets.
 *
 * Description:
 * This function iterates over each point in the map grid and:
 * - Projects each 3D map point into a 2D isometric point using the 
 *   `isometric_projection` function.
 * - Draws lines horizontally and vertically between adjacent points in the grid.
 *
 * For each grid point:
 * - The color of the point is determined from `colors_map`.
 * - Lines are drawn:
 *   - Horizontally to the next point in the same row (if it exists).
 *   - Vertically to the corresponding point in the next row (if it exists).
 *
 * This effectively creates a wireframe representation of the map in an isometric
 * view, rendered on the graphical window.
 */
void	render_map(t_data *data)
{
	t_2d_point	p1;
	int			color;
	size_t		i;
	size_t		j;

	i = 0;
	while (i < data->n_rows)
	{
		j = 0;
		while (j < data->n_cols)
		{
			color = data->colors_map[i][j];
			p1 = draw_elem_from_data(data, i, j, color);
			draw_horizontal_line(data, p1, color);
			draw_vertical_line(data, p1, color);
			j++;
		}
		i++;
	}
}
