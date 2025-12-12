/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zohoun <zohoun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:06:28 by zohoun            #+#    #+#             */
/*   Updated: 2025/12/11 15:37:32 by zohoun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*initialisation du buffer pour le rendu
 -cree une image en memoire
 -recupere l'adresse des donnes du buffer
*/
int	init_buffer(t_map *map)
{
	map->buffer.img = mlx_new_image(map->mlx, SIZE_X, SIZE_Y);
	if (!map->buffer.img)
		return (err_msg("failed to create buffer image"), -1);
	map->buffer.addr = mlx_get_data_addr(map->buffer.img,
			&map->buffer.bits_per_pixel,
			&map->buffer.line_length, &map->buffer.endian);
	if (!map->buffer.addr)
		return (err_msg("failed to get buffer address"), -1);
	map->buffer.width = SIZE_X;
	map->buffer.height = SIZE_Y;
	printf("Render buffer initialisé à (%dx%d)\n", SIZE_X, SIZE_Y);
	return (0);
}

/*met un pixel dans le buffer
 -verifie que le pixel est dans les limites de x et y
 -calcul de l'adresse du pixel dans le buffer
 -ecrit la couleur */
void	put_pixel_to_buffer(t_image *buffer, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= SIZE_X || y < 0 || y >= SIZE_Y)
		return ;
	dst = buffer->addr + (y * buffer->line_length + x
			* (buffer->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/*affiche le buffer a l'ecran a la position du depart*/
void	display_buffer(t_map *map)
{
	mlx_put_image_to_window(map->mlx, map->win, map->buffer.img, 0, 0);
}

/*dessine le sol et le plafond, comme la vision des yeux
 -motie regard vers le haut, au-dessus de l'horizon
 -motie regard vers le bas , en-dessous de la ligne de l'horizon*/
void	draw_background(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < SIZE_Y / 2)
	{
		x = 0;
		while (x < SIZE_X)
		{
			put_pixel_to_buffer(&map->buffer, x, y, map->ceiling_color);
			x++;
		}
		y++;
	}
	while (y < SIZE_Y)
	{
		x = 0;
		while (x < SIZE_X)
		{
			put_pixel_to_buffer(&map->buffer, x, y, map->floor_color);
			x++;
		}
		y++;
	}
}

/*cree une couleur RGB*/
int	create_color(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}
