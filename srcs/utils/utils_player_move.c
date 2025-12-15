/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_player_move.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zohoun <zohoun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 22:14:39 by zohoun            #+#    #+#             */
/*   Updated: 2025/12/13 22:19:33 by zohoun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
-formule pour determiner quand on a touche un mur  */
static int	is_wall_at(t_map *map, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (map_x < 0 || map_x >= map->map_w || map_y < 0 || map_y >= map->map_h)
		return (1);
	if (map->map_arr[map_y][map_x] == '1' || map->map_arr[map_y][map_x] == ' ')
		return (1);
	return (0);
}

/*
-verifie si la position du joeur est valide dans la map, 0 si cest ok et
 1 s'il y a une erreur
- ajout de la marge de collision determine quand on a touche le mur*/
int	is_valid_position(t_map *map, double x, double y)
{
	double	margin;

	margin = 0.15;
	if (is_wall_at(map, x - margin, y - margin))
		return (0);
	if (is_wall_at(map, x + margin, y - margin))
		return (0);
	if (is_wall_at(map, x - margin, y + margin))
		return (0);
	if (is_wall_at(map, x + margin, y + margin))
		return (0);
	return (1);
}
