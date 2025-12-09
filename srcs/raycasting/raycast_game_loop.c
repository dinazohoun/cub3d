/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_game_loop.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinados- <dinados-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:05:14 by dinados-          #+#    #+#             */
/*   Updated: 2025/12/09 16:05:14 by dinados-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// obligatiore d'avoir le x qu'on reinitialise dans le loop
// re colorer tous les pixel d'une fenetre
void	redraw_window(t_map *map, int clr)
{
	int	x;
	int	y;

	y = 0;
	while (y < SIZE_Y)
	{
		x = 0;
		while (x < SIZE_X)
		{
			put_pixel_to_buffer(&map->buffer, x, y, clr);
			x++;
		}
		y++;
	}
}

void	draw_one_ray(t_map *map, double ray_st[2], double angle, int col)
{
	double	ray_hit[2];
	double	perp_dist;
	int		top_wall;
	int		bottom_wall;

	cast_ray(map, ray_st, angle, ray_hit);
	perp_dist = calcul_perpen_distance(ray_st, ray_hit, \
										angle, map->player.angle);
	calcul_wall_project(perp_dist, &top_wall, &bottom_wall);
	draw_vertical_line(map, col, bottom_wall, 0x0000FF);
}

int	game_loop(t_map *map)
{
	double	ray[2];
	double	angle;
	double	angle_step;
	int		i;

	redraw_window(map, 0x000000);
	ray[0] = map->player.pos_x;
	ray[1] = map->player.pos_y;
	angle = map->player.angle - FOV / 2.0;
	angle_step = FOV / (double)SIZE_X;
	i = 0;
	while (i < SIZE_X)
	{
		draw_one_ray(map, ray, angle, i);
		angle += angle_step;
		i++;
	}
	display_buffer(map);
	return (0);
}
