/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinados- <dinados-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:57:58 by dinados-          #+#    #+#             */
/*   Updated: 2025/12/12 19:10:24 by dinados-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
-determine quel cote du mur est touché
-return 0 NORTH, 1 SOUTH, 2 EAST, 3 WEST
*/
int	get_wall_side(double angle)
{
	double	dx;
	double	dy;

	dx = cos(angle);
	dy = sin(angle);
	if (fabs(dx) > fabs(dy))
	{
		if (dx > 0)
			return (3);
		else
			return (2);
	}
	else
	{
		if (dy > 0)
			return (1);
		else
			return (0);
	}
}

/*
-calcul la position exacte ou le rayon touche le mur 
-selon le coté, la position exacte sera la valeur apres la virgule
 */
double	calculate_wall_x(t_map *map, double perp_dist, double angle, int side)
{
	double	wall_x;
	double	ray_dir_x;
	double	ray_dir_y;

	ray_dir_x = cos(angle);
	ray_dir_y = sin(angle);
	if (side == 2 || side == 3)
		wall_x = map->player.pos_y + perp_dist * ray_dir_y;
	else
		wall_x = map->player.pos_x + perp_dist * ray_dir_x;
	wall_x = wall_x - floor(wall_x);
	return (wall_x);
}

/*
-associe chaque cote a une texture
*/
t_image	*select_texture(t_map *map, int side)
{
	if (side == 0)
		return (&map->tex_north);
	else if (side == 1)
		return (&map->tex_south);
	else if (side == 2)
		return (&map->tex_east);
	else
		return (&map->tex_west);
}

/*initialisation des variables, pour le calcul des coordonnes de la texture*/
void	init_tex_calc(t_tex_cal *tex, t_wall *wall, t_image *texture,
	double angle)
{
	double	ray_dir_x;
	double	ray_dir_y;

	tex->tex_x = (int)(wall->wall_x * texture->width);
	ray_dir_x = cos(angle);
	ray_dir_y = sin(angle);
	// DEBUG
    if (wall->x == 600)
    {
        printf("\n=== DEBUG Col 600 ===\n");
        printf("Side: %d (0=N, 1=S, 2=E, 3=W)\n", wall->side);
        printf("wall_x: %.4f\n", wall->wall_x);
        printf("tex_x AVANT inversion: %d\n", tex->tex_x);
        printf("ray_dir: (%.4f, %.4f)\n", ray_dir_x, ray_dir_y);
    }
	if (wall->side == 3 && ray_dir_x > 0)
		tex->tex_x = texture->width - tex->tex_x - 1;
	if (wall->side == 2 && ray_dir_x < 0)
		tex->tex_x = texture->width - tex->tex_x - 1;
	if (wall->side == 0 && ray_dir_y > 0)
		tex->tex_x = texture->width - tex->tex_x - 1;
	if (wall->side == 1 && ray_dir_y < 0)
		tex->tex_x = texture->width - tex->tex_x - 1;
	 //  DEBUG
	if (wall->x == 600)
        printf("tex_x APRÈS inversion: %d\n", tex->tex_x);
	tex->step = (double)texture->height / wall->line_height;
	tex->tex_pos = (wall->draw_start - wall->wall_start) * tex->step;
	//  DEBUG
    if (wall->x == 600)
    {
        printf("line_height: %d\n", wall->line_height);
        printf("wall_start: %d, draw_start: %d\n", wall->wall_start, wall->draw_start);
        printf("step: %.6f\n", tex->step);
        printf("tex_pos: %.2f\n", tex->tex_pos);
        printf("======================\n");
	}
}

/*fonction que vas remplir la couleur px par px*/
void	draw_tex_column(t_map *map, t_wall *wall, t_image *tex,
		t_tex_cal *calc)
{
	int	i;
	int	color;
	int	tex_y;

	i = wall->draw_start;
	while (i < wall->draw_end)
	{
		tex_y = (int)calc->tex_pos;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= tex->height)
			tex_y = tex->height - 1;
		 //  DEBUG premiers pixels
        if (wall->x == 600 && i < wall->draw_start + 3)
            printf("  y=%d: tex_y=%d, tex_pos=%.2f\n", i, tex_y, calc->tex_pos);
		calc->tex_pos += calc->step;
		color = get_pixel_from_texture(tex, calc->tex_x, tex_y);
		put_pixel_to_buffer(&map->buffer, wall->x, i, color);
		i++;
	}
}

void	draw_textured_wall(t_map *map, t_wall *wall)
{
	t_image		*texture;
	t_tex_cal	calc;

	texture = select_texture(map, wall->side);
	init_tex_calc(&calc, wall, texture, wall->angle);
	draw_tex_column(map, wall, texture, &calc);
}
