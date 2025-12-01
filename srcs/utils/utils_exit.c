#include "cub3d.h"

void	*safe_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	return (ptr);
}

/// @brief free le contenu d'un fichier
/// @param arr
void	free_arr(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

/// @brief detruire les images, les textures
/// @param map 
void	free_images(t_map *map)
{
	if (!map || !map->mlx)
		return ;
	if (map->buffer.img)
		mlx_destroy_image(map->mlx, map->buffer.img);
	if (map->img)
		mlx_destroy_image(map->mlx, map->img);
	if (map->tex_north.img)
		mlx_destroy_image(map->mlx, map->tex_north.img);
	if (map->tex_south.img)
		mlx_destroy_image(map->mlx, map->tex_south.img);
	if (map->tex_east.img)
		mlx_destroy_image(map->mlx, map->tex_east.img);
	if (map->tex_west.img)
		mlx_destroy_image(map->mlx, map->tex_west.img);
}

/// @brief effacer tout avant exit quand on 
/// une fenetre
/// @param map 
/// @param status 
void	free_all(t_map *map)
{
	if (map)
	{
		if (map->file_info)
			free_arr(map->file_info);
		if (map->map_arr)
			free_arr(map->map_arr);
		free(map->path_no);
		free(map->path_so);
		free(map->path_ea);
		free(map->path_we);
		if (map->mlx)
		{
			free_images(map);
			if (map->win)
				mlx_destroy_window(map->mlx, map->win);
			mlx_destroy_display(map->mlx);
			free(map->mlx);
		}
	}
}

/*vide et quitte la map*/
void	free_and_exit(t_map *map, int status)
{
	free_all(map);
	exit(status);
}