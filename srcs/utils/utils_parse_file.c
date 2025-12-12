/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinados- <dinados-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:40:52 by dinados-          #+#    #+#             */
/*   Updated: 2025/12/09 15:59:48 by dinados-         ###   ########.fr       */
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

char	*append_and_free(char *fcontent, char *read_buf)
{
	char	*new_fcontent;

	if (!fcontent)
		return (ft_strdup(read_buf));
	new_fcontent = ft_strjoin(fcontent, read_buf);
	if (!new_fcontent)
		return (free(fcontent), NULL);
	free(fcontent);
	return (new_fcontent);
}

/// @brief copier tout le contenu d'un fichier dans
/// seule chaine
/// @param file 
/// @return une chaine avec le contenu d'un fichier
char	*read_and_copy_file_content(const char *file)
{
	int		fd;
	char	read_buf[4096 + 1];
	size_t	already_read;
	char	*fcontent;

	fcontent = NULL;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (err_msg("cannot open file"), NULL);
	already_read = read(fd, read_buf, 4096);
	while (already_read > 0)
	{
		read_buf[already_read] = '\0';
		fcontent = append_and_free(fcontent, read_buf);
		if (!fcontent)
			return (close(fd), NULL);
		already_read = read(fd, read_buf, 4096);
	}
	close (fd);
	return (fcontent);
}
