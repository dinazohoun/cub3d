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

/*
- Applique le clipping aux limites de dessin
- Evite que on sorte des limites definis(pas de bug , pas de crash)
*/
static void	apply_clipping(int wall_start, int wall_end, t_wall *wall)
{
	wall->draw_start = wall_start;
	wall->draw_end = wall_end;
	if (wall->draw_start < 0)
		wall->draw_start = 0;
	if (wall->draw_end >= SIZE_Y)
		wall->draw_end = SIZE_Y - 1;
}

/*
-Cette fonction transforme les données brutes du DDA en
	informations utilisables pour dessiner le mur
*/
static void	setup_wall(t_wall *wall, t_dda *dda, double angle, int col)
{
	double	dir[2];
	double ray_dist;
	double	perp_dist;

	dir[0] = cos(angle);
	dir[1] = sin(angle);
	ray_dist = calcul_perpen_distance_dda(dda, wall->ray_start, dir);
	perp_dist = ray_dist * cos(angle - wall->player_angle);
	wall->line_height = calcul_wall_project(perp_dist,
			&wall->wall_start, &wall->wall_end);
	wall->x = col;
	wall->side = get_wall_side_dda(dda, dir);
	wall->dda_side = dda->side;
	wall->wall_x = calculate_wall_x_dda(dda, wall->ray_start, ray_dist, dir);
	wall->angle = angle;
	apply_clipping(wall->wall_start, wall->wall_end, wall);
}

/*
-Lance un rayon avec DDA et dessine le mur texturé correspondant
-Pour chaque colonne d'écran :
-1. Calcule la direction du rayon
-2. Utilise DDA pour trouver le mur touché
-3. Dessine le mur avec la texture appropriée
*/
void	draw_one_ray(t_map *map, double ray_st[2], double angle, int col)
{
	t_dda	dda;
	t_wall	wall;

	wall.ray_start[0] = ray_st[0];
	wall.ray_start[1] = ray_st[1];
	wall.player_angle = map->player.angle;
	cast_ray_dda(map, ray_st, angle, &dda);
	setup_wall(&wall, &dda, angle, col);
	draw_textured_wall(map, &wall);
}

/*
Boucle principale de rendu du jeu (raycasting)
Pour chaque frame :
	1. dessine le sol et le plafond (fond)
	2. lance SIZE_X rayons (un par colonne d'écran) du FOV gauche au FOV droit
	3. Chaque rayon trouve un mur et le dessine avec sa texture
	4. affiche le buffer final à l'écran
*/
int	game_loop(t_map *map)
{
	double	ray[2];
	double	angle;
	double	angle_step;
	int		i;

	draw_background(map);
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
