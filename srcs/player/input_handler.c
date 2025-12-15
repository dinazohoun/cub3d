/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zohoun <zohoun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 07:58:30 by dinados-          #+#    #+#             */
/*   Updated: 2025/12/13 16:46:56 by zohoun           ###   ########.fr       */
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
	return (0);
}
