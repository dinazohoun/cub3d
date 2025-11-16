#include "../../includes/cub3d.h"

/// @brief free le contenu d'un fichier
/// @param file_info 
void    free_file_info(char **file_info)
{
    int i;

    if (!file_info)
        return ;
    i = 0;
    while (file_info[i])
        free(file_info[i++]);
    free(file_info);
}

/// @brief detruire les images, les textures
/// @param map 
void    free_images(t_map *map)
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
void    free_and_exit(t_map *map, int status)
{
    if (map)
    {
        free_file_info(map->file_info);
        if (map->mlx)
        {
            free_images(map);
            if (map->win)
                mlx_destroy_window(map->mlx, map->win);
            mlx_destroy_display(map->mlx);
            free(map->mlx);
        }
    }
    exit(status);
}