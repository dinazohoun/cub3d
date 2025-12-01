/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:40:52 by dinados-          #+#    #+#             */
/*   Updated: 2025/12/01 13:53:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// @brief free data parsing structure
/// @param data 
void	free_textures(t_text_data *data)
{
	free(data->north);
	free(data->south);
	free(data->east);
	free(data->west);
}

void	cpy_texcol_to_map(t_map *map, t_text_data *data)
{
	map->path_no = data->north;
	map->path_ea = data->east;
	map->path_so = data->south;
	map->path_we = data->west;
	map->floor_color = data->floor_color.rgb;
	map->ceiling_color = data->ceiling_color.rgb;
}
