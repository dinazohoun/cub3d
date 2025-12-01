/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_verif_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinados- <dinados-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:36:42 by dinados-          #+#    #+#             */
/*   Updated: 2025/11/25 10:36:42 by dinados-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// @brief verifier le nombre de jouer dans le map
/// @param pl_nb 
/// @return 
int	verif_player_nb(int pl_nb)
{
	if (pl_nb == 0)
		return (err_msg("No player"), -1);
	if (pl_nb > 1)
		return (err_msg("Incorrect nb of players"), -1);
	return (0);
}

/// @brief verifier les elements de map 
/// @param map 
/// @return 
int	verif_elems_of_map(t_map *map)
{
	int	y;
	int	x;
	int	pl_nb;

	pl_nb = 0;
	y = 0;
	while (y < map->map_h)
	{
		x = 0;
		while (x < map->map_w)
		{
			if (!is_map_char(map->map_arr[y][x]))
				return (err_msg("Invalid char in map"), -1);
			if (is_player(map->map_arr[y][x]))
				pl_nb++;
			x++;
		}
		y++;
	}
	if (verif_player_nb(pl_nb) == -1)
		return (-1);
	return (0);
}

int	is_cell_inside(char c)
{
	if (c == '0' || is_player(c))
		return (1);
	return (0);
}

// le premier if pour regarder si la valeur est a l'extreme
// le deuxieme-une des voisins-> les espaces
int	is_not_enclosed(t_map *map, int y, int x)
{
	if (y == 0 || y == map->map_h - 1 || \
		x == 0 || x == map->map_w - 1)
		return (1);
	if (map->map_arr[y - 1][x] == ' ' || \
		map->map_arr[y + 1][x] == ' ' || \
		map->map_arr[y][x - 1] == ' ' || \
		map->map_arr[y][x + 1] == ' ')
		return (1);
	return (0);
}

/*si la valeur 0 ou joeur il doit pas
apparaitre no a l'extreme ni avoir les espaces 
parmi les voisins*/
int	verif_closed_map(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->map_h)
	{
		x = 0;
		while (x < map->map_w)
		{
			if (is_cell_inside(map->map_arr[y][x]) == 1)
			{
				if (is_not_enclosed(map, y, x) == 1)
					return (err_msg("Map is not closed"), -1);
			}
			x++;
		}
		y++;
	}
	return (0);
}
