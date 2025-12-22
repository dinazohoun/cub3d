/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_file_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinados- <dinados-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 18:49:23 by dinados-          #+#    #+#             */
/*   Updated: 2025/12/09 15:50:31 by dinados-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
compte le nombre de lignes dans une chaine
return le nombre de lignes*/
static int	count_lines(const char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			count++;
		i++;
	}
	if (i > 0 && str[i - 1] != '\n')
		count++;
	return (count);
}

/*enleve le '\n' final d'une ligne si present*/
static void	remove_delimitateur(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}

/*
-alloue un tableau et compte les lignes
-return le nombre de lignes ou -1 si erreur
*/
static int	alloc_file_info(t_map *map, const char *file)
{
	char	*fcontent;
	int		count;

	fcontent = read_and_copy_file_content(file);
	if (!fcontent)
		return (-1);
	count = count_lines(fcontent);
	free(fcontent);
	if (count == 0)
		return (-1);
	map->file_info = malloc(sizeof(char *) * (count + 1));
	if (!map->file_info)
		return (err_msg("malloc failed"), -1);
	return (count);
}

/*rempli le tableau file_info en lisant le ficher avec gnl
return 0 si ok ou -1 si erreur
*/
static int	fill_file_info(t_map *map, const char *file)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		free(map->file_info);
		return (err_msg("cannot open file"), -1);
	}
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		remove_delimitateur(line);
		map->file_info[i] = line;
		i++;
		line = get_next_line(fd);
	}
	map->file_info[i] = NULL;
	close(fd);
	return (0);
}

/// @brief remplir le tableau avec le contenu de fichier
/// @param map 
/// @param file 
/// @return 
int	init_file_info(t_map *map, const char *file)
{
	int		line;

	line = alloc_file_info(map, file);
	if (line == -1)
		return (err_msg("empty file"), -1);
	if (fill_file_info(map, file) == -1)
		return (-1);
	map->file_lines = line;
	return (0);
}
