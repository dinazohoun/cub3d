/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_draw_ray.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinados- <dinados-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:03:54 by dinados-          #+#    #+#             */
/*   Updated: 2025/12/09 16:03:54 by dinados-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
-Calcule l'hauteur du mur a l'ecran
-Retourne line_height
*/
int	calcul_wall_project(double perp_dist, int *top_wall, int *bottom_wall)
{
	double	proj_plane;
	double	height;
	int		line_height;

	proj_plane = (SIZE_X / 2.0) / (tan(FOV / 2.0));
	height = proj_plane / perp_dist;
	line_height = (int)height;
	*top_wall = (int)(SIZE_Y / 2.0 - height / 2.0);
	*bottom_wall = (int)(SIZE_Y / 2.0 + height / 2.0);
	return (line_height);
}
// void	cast_ray(t_map *map, double ray_st[2], double angle, 
// 				double ray_hit[2])
// {
// 	ray_hit[0] = ray_st[0];
// 	ray_hit[1] = ray_st[1];
// 	while (!touch_wall(map, ray_hit[0], ray_hit[1]))
// 	{
// 		ray_hit[0] += cos(angle) * RAY_STEP;
// 		ray_hit[1] += sin(angle) * RAY_STEP;
// 	}
// }

// double	calcul_perpen_distance(double ray_st[2], double ray_hit[2], 
// 							double ray_angle, double player_angle)
// {
// 	double	dist;
// 	double	perp_dist;

// 	dist = calcul_distance(ray_st, ray_hit);
// 	perp_dist = dist * cos(ray_angle - player_angle);
// 	return (perp_dist);
// }

// void	draw_vertical_line(t_map *map, int col, int bottom_wall, int clr)
// {
// 	int		top_wall;

// 	top_wall = 0;
// 	if (top_wall < 0)
// 		top_wall = 0;
// 	if (bottom_wall >= SIZE_Y)
// 		bottom_wall = SIZE_Y - 1;
// 	while (top_wall <= bottom_wall)
// 	{
// 		put_pixel_to_buffer(&map->buffer, col, top_wall, clr);
// 		top_wall++;
// 	}
// }
