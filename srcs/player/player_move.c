/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zohoun <zohoun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 11:54:25 by dinados-          #+#    #+#             */
/*   Updated: 2025/12/13 22:15:28 by zohoun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*fait avancer le joeur en avant a sa nouvelle position*/
void	move_forward(t_map *map)
{
	double	new_x;
	double	new_y;

	new_x = map->player.pos_x + map->player.dir_x * map->player.move_speed;
	new_y = map->player.pos_y + map->player.dir_y * map->player.move_speed;
	if (is_valid_position(map, new_x, new_y))
	{
		map->player.pos_x = new_x;
		map->player.pos_y = new_y;
		return ;
	}
	if (is_valid_position(map, new_x, map->player.pos_y))
	{
		map->player.pos_x = new_x;
		return ;
	}
	if (is_valid_position(map, map->player.pos_x, new_y))
	{
		map->player.pos_y = new_y;
	}
}

/*fait avancer le joeur en arriere a sa nouvelle position*/
void	move_backward(t_map *map)
{
	double	new_x;
	double	new_y;

	new_x = map->player.pos_x - map->player.dir_x * map->player.move_speed;
	new_y = map->player.pos_y - map->player.dir_y * map->player.move_speed;
	if (is_valid_position(map, new_x, new_y))
	{
		map->player.pos_x = new_x;
		map->player.pos_y = new_y;
		return ;
	}
	if (is_valid_position(map, new_x, map->player.pos_y))
	{
		map->player.pos_x = new_x;
		return ;
	}
	if (is_valid_position(map, map->player.pos_x, new_y))
	{
		map->player.pos_y = new_y;
	}
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
	if (is_valid_position(map, new_x, new_y))
	{
		map->player.pos_x = new_x;
		map->player.pos_y = new_y;
		return ;
	}
	if (is_valid_position(map, new_x, map->player.pos_y))
	{
		map->player.pos_x = new_x;
		return ;
	}
	if (is_valid_position(map, map->player.pos_x, new_y))
	{
		map->player.pos_y = new_y;
	}
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
	if (is_valid_position(map, new_x, new_y))
	{
		map->player.pos_x = new_x;
		map->player.pos_y = new_y;
		return ;
	}
	if (is_valid_position(map, new_x, map->player.pos_y))
	{
		map->player.pos_x = new_x;
		return ;
	}
	if (is_valid_position(map, map->player.pos_x, new_y))
	{
		map->player.pos_y = new_y;
	}
}
