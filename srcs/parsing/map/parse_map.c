/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinados- <dinados-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:24:05 by dinados-          #+#    #+#             */
/*   Updated: 2025/11/25 10:36:07 by dinados-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_map_size(char **file_info, int map_start, int *h, int *w)
{
	int	i;
	int	last_h;
	int	last_w;
	int	cur_w;

	i = map_start;
	last_h = 0;
	last_w = 0;
	while (file_info[i] != NULL)
	{
		if (find_line_type(file_info[i]) != LINE_MAP)
			return (err_msg("Invalid line after start of map"), -1);
		last_h++;
		cur_w = ft_strlen(file_info[i]);
		if (cur_w > last_w)
			last_w = cur_w;
		i++;
	}
	if (last_h == 0)
		return (err_msg("No map"), -1);
	*h = last_h;
	*w = last_w;
	return (0);
}

int	alloc_map_arr(t_map *map, int h, int w)
{
	int	y;

	y = 0;
	map->map_h = h;
	map->map_w = w;
	map->map_arr = safe_malloc(sizeof(char *) * (h + 1));
	while (y < h)
	{
		map->map_arr[y] = safe_malloc(w + 1);
		map->map_arr[y][0] = '\0';
		y++;
	}
	map->map_arr[h] = NULL;
	return (0);
}

int	fill_map_arr(t_map *map, char **file_info, int map_start)
{
	int	y;
	int	i;
	int	len;

	y = 0;
	i = map_start;
	while (y < map->map_h)
	{
		len = ft_strlen(file_info[i]);
		ft_memcpy(map->map_arr[y], file_info[i], len);
		while (len < map->map_w)
		{
			map->map_arr[y][len] = ' ';
			len++;
		}
		map->map_arr[y][map->map_w] = '\0';
		y++;
		i++;
	}
	return (0);
}

int	verif_map(t_map *map)
{
	if (verif_elems_of_map(map) == -1)
		return (-1);
	if (verif_closed_map(map) == -1)
		return (-1);
	return (0);
}

int	parse_map(t_map *map, int map_start)
{
	if (get_map_size(map->file_info, map_start, \
		&map->map_h, &map->map_w) == -1)
		return (-1);
	if (alloc_map_arr(map, \
		map->map_h, map->map_w) == -1)
		return (-1);
	if (fill_map_arr(map, map->file_info, map_start) == -1)
		return (-1);
	if (verif_map(map) == -1)
		return (-1);
	return (0);
}
