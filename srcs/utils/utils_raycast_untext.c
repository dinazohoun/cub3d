#include "cub3d.h"

//simple Euclidian calculation
int	touch_wall(t_map *map, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (map_x < 0 || map_x >= map->map_w || map_y < 0 || \
		map_y >= map->map_h)
		return (1);
	if (map->map_arr[map_y][map_x] == '1')
		return (1);
	return (0);
}

double	distance_form(double diffx, double diffy)
{
	return (sqrt(diffx * diffx + diffy * diffy));
}

double	calcul_distance(double	ray_st[2], double ray_hit[2])
{
	double	diffx;
	double	diffy;

	diffx = ray_hit[0] - ray_st[0];
	diffy = ray_hit[1] - ray_st[1];
	return (distance_form(diffx, diffy));
}