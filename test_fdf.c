/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azerfaou <azerfaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:39:02 by azerfaou          #+#    #+#             */
/*   Updated: 2024/11/17 18:51:13 by azerfaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "includes/mlx.h"
#include "includes/fdf.h"

int	main(void)
{
	void	*mlx;
	void	*window;

	mlx = mlx_init();
	if (!mlx)
		return (1);
	window = mlx_new_window(mlx, 800, 600, "MiniLibX Test Window");
	if (!window)
		return (1);
	mlx_loop(mlx);
	return (0);
}
