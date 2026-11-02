/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinados- <dinados-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 18:44:49 by dinados-          #+#    #+#             */
/*   Updated: 2025/12/04 15:14:22 by dinados-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
parse_cub_file(ressambler parse_bef_map et parse_map)
*/
int	parse_file(t_map *map)
{
	t_text_data	data;
	int			map_start;

	ft_bzero(&data, sizeof(t_text_data));
	map_start = -1;
	if (parse_bef_map(map->file_info, &data, &map_start) == -1)
		return (free_textures(&data), -1);
	if (parse_map(map, map_start) == -1)
		return (free_textures(&data), -1);
	cpy_texcol_to_map(map, &data);
	return (0);
}

int	main(int ac, char **av)
{
	t_map	map;

	ft_memset(&map, 0, sizeof(t_map));
	if (ac != 2)
		return (err_msg("wrong number of args"), -1);
	if (is_cub_file(av[1]) == 0)
		return (err_msg("bad file name"), -1);
	if (init_file_info(&map, av[1]) == -1)
		return (-1);
	if (parse_file(&map) == -1)
		free_and_exit(&map, 1);
	if (init_player(&map) == -1)
		free_and_exit(&map, 1);
	if (setup_graphic(&map) == -1)
		free_and_exit(&map, 1);
	if (load_all_textures(&map) == -1)
		free_and_exit(&map, 1);
	handle_events(&map);
	return (0);
}
