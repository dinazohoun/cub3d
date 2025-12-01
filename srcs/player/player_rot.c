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

/*
cette fonction vas faire tourner un vector autour d'un point
 -direction, le regard du joeur
 -vitesse, de la rotation*/
void	rotate_vector(double *x, double *y, double angle)
{
	double	old_x;
	double	old_y;
	double	cos_angle;
	double	sin_angle;

	old_x = *x;
	old_y = *y;
	cos_angle = cos(angle);
	sin_angle = sin(angle);
	*x = old_x * cos_angle - old_y * sin_angle;
	*y = old_x * sin_angle + old_y * cos_angle;
}

/*rotation vers la gauche(anti-horaire)
 vers la gauche c'est toujours negatif*/
void	rotate_left(t_map *map)
{
	double	rot_angle;

	rot_angle = -map->player.rot_speed;
	rotate_vector(&map->player.dir_x, &map->player.dir_y, rot_angle);
	rotate_vector(&map->player.plane_x, &map->player.plane_y, rot_angle);
}

/*rotation vers la droite(comme les aiguilles d'une montre)
 vers la gauche c'est toujours positif*/
void	rotate_right(t_map *map)
{
	double	rot_angle;

	rot_angle = map->player.rot_speed;
	rotate_vector(&map->player.dir_x, &map->player.dir_y, rot_angle);
	rotate_vector(&map->player.plane_x, &map->player.plane_y, rot_angle);
}
