
#include "cub3d.h"

/*chargement de une texture depuis un fichier .xpm
returne 0 si erreur -1*/
int	load_texture(t_map *map, char *path, t_image *texture)
{
    texture->img = mlx_xpm_file_to_image(map->mlx, path, &texture->width,
        &texture->height);
    if (!texture->img)
    {
        printf("Error\nFailed to load texture: %s\n", path);
        return (-1);
    }
    texture->addr = mlx_get_data_addr(texture->img, &texture->bits_per_pixel,
        &texture->line_length,
        &texture->endian);
    if (!texture->addr)
    {
        printf("Error\nFailed to get texture addr: %s\n", path);
        mlx_destroy_image(map->mlx, texture->img);
        return (-1);
    }
    printf("texture chargé: %s (%dx%d)\n", path, texture->width, texture->height);
    return(0);
}

//charge les 4 murs
int	load_all_textures(t_map *map)
{
    if (load_texture(map, "srcs/textures/NORTH.xpm", &map->tex_north) == -1)
        return (-1);
    if (load_texture(map, "srcs/textures/SOUTH.xpm", &map->tex_south) == -1)
        return (-1);
    if (load_texture(map, "srcs/textures/EAST.xpm", &map->tex_east) == -1)
        return (-1);
    if (load_texture(map, "srcs/textures/WEST.xpm", &map->tex_west) == -1)
        return (-1);
    return(0);
}

//recupere la couleur d'un pixel dans une texture
int get_pixel_from_texture(t_image *texture, int x, int y)
{
    char    *pixel;
    
    if (x < 0 || x >= texture->width || y < 0 || y >= texture->height)
        return (0x000000);
    pixel = texture->addr + (y * texture->line_length + x * (texture->bits_per_pixel / 8));
    return (*(unsigned int *)pixel);
}