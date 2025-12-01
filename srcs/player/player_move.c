/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinados- <dinados-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 11:54:25 by dinados-          #+#    #+#             */
/*   Updated: 2025/11/30 07:52:04 by dinados-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*verifie si la position du joeur est valide dans la map, 0 si cest ok et
 1 s'il y a une erreur*/
int	is_valid_position(t_map *map, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (map_x < 0 || map_x >= map->map_w || map_y < 0 || map_y >= map->map_h)
		return (0);
	if (map->map_arr[map_y][map_x] == '1' || map->map_arr[map_y][map_x] == ' ')
		return (0);
	return (1);
}

/*fait avancer le joeur en avant a sa nouvelle position*/
void	move_forward(t_map *map)
{
	double	new_x;
	double	new_y;

	new_x = map->player.pos_x + map->player.dir_x * map->player.move_speed;
	new_y = map->player.pos_y + map->player.dir_y * map->player.move_speed;
	if (is_valid_position(map, new_x, map->player.pos_y))
		map->player.pos_x = new_x;
	if (is_valid_position(map, map->player.pos_x, new_y))
		map->player.pos_y = new_y;
}

/*fait avancer le joeur en arriere a sa nouvelle position*/
void	move_backward(t_map *map)
{
	double	new_x;
	double	new_y;

	new_x = map->player.pos_x - map->player.dir_x * map->player.move_speed;
	new_y = map->player.pos_y - map->player.dir_y * map->player.move_speed;
	if (is_valid_position(map, new_x, map->player.pos_y))
		map->player.pos_x = new_x;
	if (is_valid_position(map, map->player.pos_x, new_y))
		map->player.pos_y = new_y;
}

/*fait avancer le joeur vers la gauche
deplacement perpendiculaire a gauche
(dir_y, -dir_x)*/
void	move_left(t_map *map)
{
	double	new_x;
	double	new_y;

	new_x = map->player.pos_x + map->player.dir_y * map->player.move_speed;
	new_y = map->player.pos_y - map->player.dir_x * map->player.move_speed;
	if (is_valid_position(map, new_x, map->player.pos_y))
		map->player.pos_x = new_x;
	if (is_valid_position(map, map->player.pos_x, new_y))
		map->player.pos_y = new_y;
}

/*fait avancer le joeur vers la droite
deplacement perpendiculaire a droite
(-dir_y, dir_x)*/
void	move_right(t_map *map)
{
	double	new_x;
	double	new_y;

	new_x = map->player.pos_x - map->player.dir_y * map->player.move_speed;
	new_y = map->player.pos_y + map->player.dir_x * map->player.move_speed;
	if (is_valid_position(map, new_x, map->player.pos_y))
		map->player.pos_x = new_x;
	if (is_valid_position(map, map->player.pos_x, new_y))
		map->player.pos_y = new_y;
}
