/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinados- <dinados-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:26:29 by dinados-          #+#    #+#             */
/*   Updated: 2025/11/30 07:48:47 by dinados-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*rotation vers la gauche(anti-horaire)
 vers la gauche c'est toujours negatif*/
void	rotate_left(t_map *map)
{
	map->player.angle -= map->player.rot_speed;
	map->player.dir_x = cos(map->player.angle);
	map->player.dir_y = sin(map->player.angle);
}

/*rotation vers la droite(comme les aiguilles d'une montre)
 vers la gauche c'est toujours positif*/
void	rotate_right(t_map *map)
{
	map->player.angle += map->player.rot_speed;
	map->player.dir_x = cos(map->player.angle);
	map->player.dir_y = sin(map->player.angle);
}
