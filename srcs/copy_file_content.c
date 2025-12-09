/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_file_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinados- <dinados-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 18:49:23 by dinados-          #+#    #+#             */
/*   Updated: 2025/12/01 18:50:17 by dinados-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	ft_countlines(char const *s, char c)
{
	int	count;

	if (!*s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
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

/// @brief remplir le tableau avec le contenu de fichier
/// @param map 
/// @param file 
/// @return 
int	init_file_info(t_map *map, const char *file)
{
	char	*fcontent;

	fcontent = read_and_copy_file_content(file);
	if (!fcontent)
		return (-1);
	map->file_info = ft_split(fcontent, '\n');
	map->file_lines = ft_countlines(fcontent, '\n');
	free(fcontent);
	if (!map->file_info)
		return (-1);
	return (0);
}
