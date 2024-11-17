#include "../includes/fdf.h"
#include <stdio.h>


t_2d_point isometric_projection(t_point point, int zoom, int x_offset, int y_offset)
{
    t_2d_point iso_point;
    double angle = (30 + 180) * (4 * atan(1) / 180);  // Convert degrees to radians (30°)

    iso_point.iso_x = (point.x - point.y) * cos(angle)* zoom + x_offset;
    iso_point.iso_y = ((point.x + point.y) * sin(angle) - point.z) * zoom + y_offset;

    return iso_point;
}

void draw_pixel(t_data *data, int x, int y, int color)
{
	for (int i = 0; i < PIXEL_SIZE; i++){
		for (int j = 0; j < PIXEL_SIZE; j++){
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, x + i, y + j, color);
		}
	}
    // mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, color);
}

void draw_line(t_data *data, t_2d_point p1, t_2d_point p2, int color)
{
    int delta_x = abs(p2.iso_x - p1.iso_x);
    int delta_y = abs(p2.iso_y - p1.iso_y);
    int sign_x = p1.iso_x < p2.iso_x ? 1 : -1;
    int sign_y = p1.iso_y < p2.iso_y ? 1 : -1;
    int error = delta_x - delta_y;

    while (p1.iso_x != p2.iso_x || p1.iso_y != p2.iso_y)
    {
        draw_pixel(data, p1.iso_x, p1.iso_y, color);
        int error2 = error * 2;

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

int get_color(int z, t_data *data)
{
	double ratio;
	int red, green, blue;
    // Simple gradient from blue (low) to red (high)
    int min_z = min_map(data->map, data->n_rows, data->n_cols);
    int max_z = max_map(data->map, data->n_rows, data->n_cols);
    
    // Normalize the height z between 0 and 255 for the red gradient
    // int red = (int)(255 * (z - min_z)) / (max_z - min_z);
    // if (red < 0) 
	// 	red = 0;
    // if (red > 255) 
	// 	red = 255;
	// if (red == 0)
	// 	return (BLUE);
    // return (red << 16);  // Shift red to its RGB position
	    // Calculate the ratio of the current height (z) within the range
    ratio = (double)(z - min_z) / (max_z - min_z);

    // Interpolate between blue and red
    red = (int)(255 * ratio);      // Red increases as z increases
    green = 0;                     // No green in the gradient
    blue = (int)(255 * (1 - ratio)); // Blue decreases as z increases

    // Combine red, green, and blue into an RGB value (0xRRGGBB)
    return (red << 16) | (green << 8) | blue;
}

void render_map(t_data *data)
{
	t_2d_point p1;
	t_2d_point p2;
	int color = WHITE;
	// printf("PIXEL_SIZE: %d\n", PIXEL_SIZE);
	for (size_t i = 0; i < data->n_rows; i++)
	{
		for (size_t j = 0; j < data->n_cols; j++)
		{
			// if ((i == 0 && j == 0) || 
			// 	(i == data->n_rows - 1 && j == data->n_cols - 1))
			// 	color = WHITE;
			// else
			// 	color = get_color(data->map[i][j].z, data);
			color = get_color(data->map[i][j].z, data);
			printf("color for z: %d is: %x\n", data->map[i][j].z, color);
			p1 = isometric_projection(data->map[i][j], data->zoom, data->x_offset, data->y_offset);
			// printf("p1.iso_x: %d, p1.iso_y: %d\n", p1.iso_x, p1.iso_y);
			draw_pixel(data, (int)p1.iso_x, (int)p1.iso_y, color);
			if (j + 1 < data->n_cols)
			{
				p2 = isometric_projection(data->map[i][j + 1], data->zoom, data->x_offset, data->y_offset);
				draw_line(data, p1, p2, color);
				// draw_pixel(data, p1.iso_x, p1.iso_y, WHITE);
			}
			if (i + 1 < data->n_rows)
			{
				p2 = isometric_projection(data->map[i + 1][j], data->zoom, data->x_offset, data->y_offset);
				draw_line(data, p1, p2, color);
				// draw_pixel(data, p2.iso_x, p2.iso_y, WHITE);
			}
		}
	}
}