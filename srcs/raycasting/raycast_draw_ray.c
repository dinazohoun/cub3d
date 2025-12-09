#include "cub3d.h"

void	cast_ray(t_map *map, double ray_st[2], double angle, \
				double ray_hit[2])
{
	ray_hit[0] = ray_st[0];
	ray_hit[1] = ray_st[1];
	while (!touch_wall(map, ray_hit[0], ray_hit[1]))
	{
		ray_hit[0] += cos(angle) * RAY_STEP;
		ray_hit[1] += sin(angle) * RAY_STEP;
	}
}

double	calcul_perpen_distance(double ray_st[2], double ray_hit[2], \
							double ray_angle, double player_angle)
{
	double	dist;
	double	perp_dist;

	dist = calcul_distance(ray_st, ray_hit);
	perp_dist = dist * cos(ray_angle - player_angle);
	return (perp_dist);
}


void	calcul_wall_project(double perp_dist, int *top_wall, int *bottom_wall)
{
	double	proj_plane;
	double	height;

	proj_plane = (SIZE_X / 2.0) / (tan(FOV / 2.0));
	height = proj_plane / perp_dist;
	*top_wall = (int)(SIZE_Y / 2.0 - height / 2.0);
	*bottom_wall = (int)(SIZE_Y / 2.0 + height / 2.0);
}
void	draw_vertical_line(t_map *map, int col, int top_wall, \
							int bottom_wall, int clr)
{
	if (top_wall < 0)
		top_wall = 0;
	if (bottom_wall >= SIZE_Y)
		bottom_wall = SIZE_Y - 1;
	while (top_wall <= bottom_wall)
	{
		put_pixel_to_buffer(&map->buffer, col, top_wall, clr);
		top_wall++;
	}
}

