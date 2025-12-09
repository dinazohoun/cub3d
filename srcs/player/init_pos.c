/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinados- <dinados-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:32:04 by dinados-          #+#    #+#             */
/*   Updated: 2025/11/30 09:21:24 by dinados-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*trouver le joeur dans la carte
-verifie si c'est un caractere joeur si oui retourne le joeur trouve*/
int	find_pos_player(t_map *map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->map_h)
	{
		j = 0;
		while (j < map->map_w)
		{
			if (map->map_arr[i][j] == 'N' || map->map_arr[i][j] == 'S'
				|| map->map_arr[i][j] == 'E' || map->map_arr[i][j] == 'W')
			{
				*y = i;
				*x = j;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

/*calcul de l'orientation au depart et la plane positionne 
perpendicularment au joeur. utilise 2 vecteurs:
- definit ou le joeur regarde (dir)
- et la largeur du champ de vision (plane)*/
static void	direction_nord_south(t_player *player, char orientation)
{
	if (orientation == 'N')
	{
		player->angle = -3.14 / 2;
	}
	else if (orientation == 'S')
	{
		player->angle = 3.14 / 2;
	}
}

static void	direction_east_west(t_player *player, char orientation)
{
	if (orientation == 'E')
	{
		player->angle = 0;
	}
	else if (orientation == 'W')
	{
		player->angle = 3.14;
	}
}

void	set_player_direction(t_player *player, char orientation)
{
	direction_nord_south(player, orientation);
	direction_east_west(player, orientation);
	player->dir_x = cos(player->angle);
	player->dir_y = sin(player->angle);
}

int	init_player(t_map *map)
{
	int		player_x;
	int		player_y;
	char	orientation;

	if (!find_pos_player(map, &player_x, &player_y))
		return (err_msg("pos player not found"), -1);
	orientation = map->map_arr[player_y][player_x];
	map->player.pos_x = (double)player_x + 0.5;
	map->player.pos_y = (double)player_y + 0.5;
	set_player_direction(&map->player, orientation);
	set_player_speeds(&map->player);
	map->player.recen_x = (SIZE_X - map->map_w * TILE) / 2;
	map->player.recen_y = (SIZE_Y - map->map_h * TILE) / 2;
	printf("Player initialized:\n");
	printf("   Position: (%.2f, %.2f)\n", map->player.pos_x, map->player.pos_y);
	printf("   Direction: (%.2f, %.2f)\n", map->player.dir_x, map->player.dir_y);
	printf("   plane: (%.2f, %.2f)\n", map->player.plane_x,
		map->player.plane_y);
	printf("   Orientation: %c\n", orientation);
	return (0);
}
