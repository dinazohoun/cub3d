/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_graphic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinados- <dinados-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 18:44:06 by dinados-          #+#    #+#             */
/*   Updated: 2025/12/01 18:44:28 by dinados-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_cross_win(t_map *map)
{
	free_and_exit(map, 0);
	return (0);
}

int	setup_graphic(t_map *map)
{
	map->mlx = mlx_init();
	if (!map->mlx)
		return (-1);
	map->win = mlx_new_window(map->mlx, SIZE_X, SIZE_Y, "cub3d");
	if (!map->win)
		return (-1);
	if (init_buffer(map) == -1)
		return (-1);
	map->img = mlx_new_image(map->mlx, SIZE_X, SIZE_Y);
	if (!map->img)
		return (-1);
	return (0);
}

// handle key press a la place de close key win
void	handle_events(t_map *map)
{
	mlx_hook(map->win, 2, 1L << 0, handle_keypress, map);
	mlx_hook(map->win, 17, 0, close_cross_win, map);
	mlx_loop(map->mlx);
}
