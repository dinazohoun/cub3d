/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zohoun <zohoun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:57:58 by dinados-          #+#    #+#             */
/*   Updated: 2025/12/15 10:08:01 by zohoun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

/*
-initialisation des variables, pour le calcul des coordonnes de la texture
-on calcule l'inversion des textures EST/OUEST et puis NORD/SUD
*/
void	init_tex_calc(t_tex_cal *tex, t_wall *wall, t_image *texture,
	double angle)
{
	double	ray_dir_x;
	double	ray_dir_y;

	tex->tex_x = (int)(wall->wall_x * texture->width);
	ray_dir_x = cos(angle);
	ray_dir_y = sin(angle);
	if ((wall->side == 2 || wall->side == 3) && ray_dir_x < 0)
		tex->tex_x = texture->width - tex->tex_x - 1;
	if ((wall->side == 0 || wall->side == 1) && ray_dir_y > 0)
		tex->tex_x = texture->width - tex->tex_x - 1;
	tex->step = (double)texture->height / wall->line_height;
	tex->tex_pos = (wall->draw_start - wall->wall_start) * tex->step;
}

/*
-fonction que vas remplir la couleur px par px
-remplis colonne par colonne, px par px
*/
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
		calc->tex_pos += calc->step;
		color = get_pixel_from_texture(tex, calc->tex_x, tex_y);
		put_pixel_to_buffer(&map->buffer, wall->x, i, color);
		i++;
	}
}

/*
-cette fonction vas dessiner la texture
*/
void	draw_textured_wall(t_map *map, t_wall *wall)
{
	t_image		*texture;
	t_tex_cal	calc;

	texture = select_texture(map, wall->side);
	init_tex_calc(&calc, wall, texture, wall->angle);
	draw_tex_column(map, wall, texture, &calc);
}
