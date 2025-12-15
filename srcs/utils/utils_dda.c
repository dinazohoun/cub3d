/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_dda.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zohoun <zohoun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 17:39:36 by zohoun            #+#    #+#             */
/*   Updated: 2025/12/13 23:53:56 by zohoun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
-determine le côté du mur est touche avec DDA
*/
int	get_wall_side_dda(t_dda *dda, double dir[2])
{
	if (dda->side == 0)
	{
		if (dir[0] > 0)
			return (2);
		else
			return (3);
	}
	else
	{
		if (dir[1] > 0)
			return (1);
		else
			return (0);
	}
}

/*
** Calcule wallX avec DDA
*/
double	calculate_wall_x_dda(t_dda *dda, double pos[2], double perp_dist,
		double dir[2])
{
	double	wall_x;

	if (dda->side == 0)
		wall_x = pos[1] + perp_dist * dir[1];
	else
		wall_x = pos[0] + perp_dist * dir[0];
	wall_x = wall_x - floor(wall_x);
	return (wall_x);
}

/*
-Calcule la distance perpendiculaire((reelle)) avec DDA jusqu'au mur
-ce calcul evite l effet tirée des textures (fish-eye)
*/
double	calcul_perpen_distance_dda(t_dda *dda, double pos[2], double dir[2])
{
	double	perp_dist;

	if (dda->side == 0)
		perp_dist = (dda->map_x - pos[0] + (1 - dda->step_x) / 2) / dir[0];
	else
		perp_dist = (dda->map_y - pos[1] + (1 - dda->step_y) / 2) / dir[1];
	return (perp_dist);
}

/*
-Effectue l'algorithme DDA pour trouver le mur
-boucle(tant que n'as pas de mur),on avance a la case suivante
*/
void	perform_dda(t_map *map, t_dda *dda)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (dda->side_dist_x < dda->side_dist_y)
		{
			dda->side_dist_x += dda->diff_dist_x;
			dda->map_x += dda->step_x;
			dda->side = 0;
		}
		else
		{
			dda->side_dist_y += dda->diff_dist_y;
			dda->map_y += dda->step_y;
			dda->side = 1;
		}
		if (touch_wall(map, dda->map_x, dda->map_y))
			hit = 1;
	}
}
