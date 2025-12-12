/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zohoun <zohoun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 10:28:24 by zohoun            #+#    #+#             */
/*   Updated: 2025/11/24 16:06:52 by zohoun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*parser une ligne et extraire une texture si c'est une ligne de textute
(NO/SO/EA/WE)
	* 1 si la texture est deja parsee
	* 0 si ce n'est pas une texture
	* -1 erreur 
*/
static int	parse_tex_north(char *line, t_text_data *data)
{
	char	*trimmed;
	char	*path;

	trimmed = skip_whitespaces(line);
	if (ft_strncmp(trimmed, "NO ", 3) == 0)
	{
		if (data->parsed_flags & FLAG_NORTH)
			return (err_msg("Duplicate NO texture"), -1);
		path = extract_file_path(trimmed + 3);
		if (!path)
			return (err_msg("allocation failed"), -1);
		if (!file_exists(path))
			return (free(path), err_msg("Invalid NO path"), -1);
		data->north = path;
		data->parsed_flags |= FLAG_NORTH;
		return (1);
	}
	return (0);
}

static int	parse_tex_south(char *line, t_text_data *data)
{
	char	*trimmed;
	char	*path;

	trimmed = skip_whitespaces(line);
	if (ft_strncmp(trimmed, "SO ", 3) == 0)
	{
		if (data->parsed_flags & FLAG_SOUTH)
			return (err_msg("Duplicate SO texture"), -1);
		path = extract_file_path(trimmed + 3);
		if (!path)
			return (err_msg("allocation failed"), -1);
		if (!file_exists(path))
			return (free(path), err_msg("Invalid SO path"), -1);
		data->south = path;
		data->parsed_flags |= FLAG_SOUTH;
		return (1);
	}
	return (0);
}

static int	parse_tex_east(char *line, t_text_data *data)
{
	char	*trimmed;
	char	*path;

	trimmed = skip_whitespaces(line);
	if (ft_strncmp(trimmed, "EA ", 3) == 0)
	{
		if (data->parsed_flags & FLAG_EAST)
			return (err_msg("Duplicata EA texture"), -1);
		path = extract_file_path(trimmed + 3);
		if (!path)
			return (err_msg("allocation failed"), -1);
		if (!file_exists(path))
			return (free(path), err_msg("Invalid EA texture"), -1);
		data->east = path;
		data->parsed_flags |= FLAG_EAST;
		return (1);
	}
	return (0);
}

static int	parse_tex_west(char *line, t_text_data *data)
{
	char	*trimmed;
	char	*path;

	trimmed = skip_whitespaces(line);
	if (ft_strncmp(trimmed, "WE ", 3) == 0)
	{
		if (data->parsed_flags & FLAG_WEST)
			return (err_msg("Duplicate WE texture"), -1);
		path = extract_file_path(trimmed + 3);
		if (!path)
			return (err_msg("alocation failled"), -1);
		if (!file_exists(path))
			return (free(path), err_msg("Invalid WE texture"), -1);
		data->west = path;
		data->parsed_flags |= FLAG_WEST;
		return (1);
	}
	return (0);
}

/*returne si la texture est trouve et parsee, le dernier pas de verif,
on return dans tt les cas*/
int	parsed_text_files(char *line, t_text_data *data)
{
	int	res;

	res = parse_tex_north(line, data);
	if (res != 0)
		return (res);
	res = parse_tex_south(line, data);
	if (res != 0)
		return (res);
	res = parse_tex_east(line, data);
	if (res != 0)
		return (res);
	res = parse_tex_west(line, data);
	return (res);
}
