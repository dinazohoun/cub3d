#include "cub3d.h"

// for the tests
void	print_arr(t_map *map)
{
    for (int i = 0; i < map->file_lines; i++)
		printf("line[%d] : %s\n", i, map->file_info[i]);
}

int main(int ac, char **av)
{
    t_map   map;
   
    (void) av;
    ft_memset(&map, 0, sizeof(t_map));
    if (ac != 2)
        return (err_msg("wrong number of args"), -1);
    if (is_cub_file(av[1]) == 0)
        return (err_msg("bad file name"), -1);
    if (init_file_info(&map, av[1]) == -1)
        return (err_msg("file_info init"), -1);
    print_arr(&map);
    // PARSE MAP part (map, fd)
    map.floor_color = create_color(128, 0, 128);
	map.ceiling_color = create_color(135, 206, 235); 
    setup_graphic(&map);
    if (load_all_textures(&map) == -1)
		return (err_msg("Error to load textures"), -1);
    test_display_textures(&map);
    handle_events(&map);
    return (0);
}