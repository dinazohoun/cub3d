/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinados- <dinados-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 07:58:30 by dinados-          #+#    #+#             */
/*   Updated: 2025/12/12 14:54:08 by dinados-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*initialise les vitesses de deplacement et de rotation*/
void	set_player_speeds(t_player *player)
{
	player->move_speed = 0.05;
	player->rot_speed = 0.05;
}

/*gestion des fleches(rotation) et direction(WASD)*/
int	handle_keypress(int keycode, t_map *map)
{
	if (keycode == KEY_ESC)
		free_and_exit(map, 0);
	if (keycode == KEY_W || keycode == KEY_UP)
		move_forward(map);
	if (keycode == KEY_A)
		move_left(map);
	if (keycode == KEY_S || keycode == KEY_DOWN)
		move_backward(map);
	if (keycode == KEY_D)
		move_right(map);
	if (keycode == KEY_LEFT)
		rotate_left(map);
	if (keycode == KEY_RIGHT)
		rotate_right(map);
	// printf("POSITION: (%.2f, %.2f) | DIR: (%.2f, %.2f) | PLANE: (%.2f, %.2f)\n",
	// 	map->player.pos_x, map->player.pos_y, map->player.dir_x,
	// 	map->player.dir_y, map->player.plane_x, map->player.plane_y);
	//game_loop(map);
	return (0);
}
