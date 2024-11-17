#include "../includes/fdf.h"

t_point **create_map(size_t n_rows, size_t n_cols)
{
    t_point **map = (t_point **) malloc(n_rows * sizeof(t_point *));
    if (!map)
        return NULL;
    
    for (size_t i = 0; i < n_rows; i++)
    {
        map[i] = (t_point *) malloc(n_cols * sizeof(t_point));
        if (!map[i])
        {
            //Handle the fail
            while(i-- > 0)
                free(map[i]);
            free(map);
            return NULL;
        }
    }
    return map;
}

void free_map(t_point **map, size_t n_rows)
{  
    for(size_t i = 0; i < n_rows; i++)
    {
        free(map[i]);
    }
    free(map);
}

size_t count_lines(int fd)
{
    char *line = get_next_line(fd);
    int nbr_lines = 0;
    
    while (ft_strcmp(line, "") != 0)
    {
        if (line)
        {
            nbr_lines++;
        }
        free(line);
        line = get_next_line(fd);
    }
	if (line)
    	free(line);
	line = NULL;
    return nbr_lines;
}

void get_grid_size(int fd, size_t *ptr_rows, size_t *ptr_cols)
{
    char *line = get_next_line(fd);
    *ptr_cols = count_char_occurrences(line, ' ') + 1;
    *ptr_rows = count_lines(fd) + 1; // +1 for the the first line that we read above
	free(line); //checked
}

void free_ft_split(char **str)
{
	size_t i = 0;
	
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int min_map(t_point **map, size_t n_rows, size_t n_cols)
{
	int min = INT_MAX;
	for (size_t i = 0; i < n_rows; i++)
	{
		for (size_t j = 0; j < n_cols; j++)
		{
			if (map[i][j].z < min)
				min = map[i][j].z;
		}
	}
	return min;
}

int max_map(t_point **map, size_t n_rows, size_t n_cols)
{
	int max = INT_MIN;
	for (size_t i = 0; i < n_rows; i++)
	{
		for (size_t j = 0; j < n_cols; j++)
		{
			if (map[i][j].z > max)
				max = map[i][j].z;
		}
	}
	return max;
}

