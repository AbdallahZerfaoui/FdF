/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azerfaou <azerfaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:43:11 by azerfaou          #+#    #+#             */
/*   Updated: 2024/11/24 21:25:09 by azerfaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point	**create_map(size_t n_rows, size_t n_cols)
{
	t_point	**map;
	size_t	i;

	i = 0;
	map = (t_point **)ft_calloc(n_rows, sizeof(t_point *));
	if (!map)
		return (NULL);
	while (i < n_rows)
	{
		map[i] = (t_point *)ft_calloc(n_cols, sizeof(t_point));
		if (!map[i])
		{
			while (i-- > 0)
				free(map[i]);
			free(map);
			return (NULL);
		}
		i++;
	}
	return (map);
}

int	**create_colors_map(size_t n_rows, size_t n_cols)
{
	int		**map;
	size_t	i;

	i = 0;
	map = (int **)ft_calloc(n_rows, sizeof(int *));
	if (!map)
		return (NULL);
	while (i < n_rows)
	{
		map[i] = (int *)ft_calloc(n_cols, sizeof(int));
		if (!map[i])
		{
			while (i-- > 0)
				free(map[i]);
			free(map);
			return (NULL);
		}
		i++;
	}
	return (map);
}

void	free_map(void **map, size_t n_rows)
{
	size_t	i;

	i = 0;
	while (i < n_rows)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

size_t	count_lines(int fd)
{
	char	*line;
	int		nbr_lines;

	line = get_next_line(fd);
	if (!line)
		return (0);
	nbr_lines = 0;
	while (ft_strcmp(line, "") != 0)
	{
		if (line)
		{
			nbr_lines++;
		}
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
	}
	if (line)
		free(line);
	line = NULL;
	return (nbr_lines);
}

/**
 * @note the +1 in ptr_rows is to count the first line that we read above
 */
void	get_grid_size(int fd, size_t *ptr_rows, size_t *ptr_cols)
{
	char	*line;

	line = get_next_line(fd);
	*ptr_cols = count_words(line, ' ');
	*ptr_rows = count_lines(fd) + 1;
	free(line);
}
