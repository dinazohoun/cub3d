/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_dda.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zohoun <zohoun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 19:38:31 by dinados-          #+#    #+#             */
/*   Updated: 2025/12/14 01:13:44 by zohoun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
-initialise le premier deplacement
-Calcule la distance constante pour traverser une case que sera ajoute a
	chaque deplacement
-recupere le calcul precis des directions de(draw_one_ray(dir[2]))
*/
static void	init_diff_dist(t_dda *dda, double dir[2])
{
	if (dir[0] == 0)
		dda->diff_dist_x = 1e30;
	else
		dda->diff_dist_x = fabs(1 / dir[0]);
	if (dir[1] == 0)
		dda->diff_dist_y = 1e30;
	else
		dda->diff_dist_y = fabs(1 / dir[1]);
}

/*
-initialise le deplacement(horizontal), apartir de la dir actionné
-saute directement a la case suivante selon la direction
*/
static void	init_step_x(t_dda *dda, double pos_x)
{
	if (dda->dir_x < 0)
	{
		dda->step_x = -1;
		dda->side_dist_x = (pos_x - dda->map_x) * dda->diff_dist_x;
	}
	else
	{
		dda->step_x = 1;
		dda->side_dist_x = (dda->map_x + 1.0 - pos_x) * dda->diff_dist_x;
	}
}

/*
-initialise le deplacement (dans la vertical), a partir de la dir actionne
-saute directement a la ligne suivante
*/
static void	init_step_y(t_dda *dda, double pos_y)
{
	if (dda->dir_y < 0)
	{
		dda->step_y = -1;
		dda->side_dist_y = (pos_y - dda->map_y) * dda->diff_dist_y;
	}
	else
	{
		dda->step_y = 1;
		dda->side_dist_y = (dda->map_y + 1.0 - pos_y) * dda->diff_dist_y;
	}
}

static void	init_dda(t_dda *dda, double pos[2], double dir[2])
{
	dda->map_x = (int)pos[0];
	dda->map_y = (int)pos[1];
	dda->dir_x = dir[0];
	dda->dir_y = dir[1];
	init_diff_dist(dda, dir);
	init_step_x(dda, pos[0]);
	init_step_y(dda, pos[1]);
}

/*
- Cast un rayon avec l'algorithme DDA
- Saute de case en case(x) et de ligne en ligne(y)
- s'arrete sur les limites
*/
void	cast_ray_dda(t_map *map, double pos[2], double angle, t_dda *dda)
{
	double	dir[2];

	dir[0] = cos(angle);
	dir[1] = sin(angle);
	init_dda(dda, pos, dir);
	perform_dda(map, dda);
}
