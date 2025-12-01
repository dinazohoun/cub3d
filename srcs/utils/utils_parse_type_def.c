/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse_type_def.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinados- <dinados-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:32:22 by dinados-          #+#    #+#             */
/*   Updated: 2025/11/25 10:32:22 by dinados-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_empty_line(char *str)
{
	while (*str)
	{
		if (*str != '\n' && \
			*str != ' ' && *str != '\t')
			return (0);
		str++;
	}
	return (1);
}

int	is_player(char c)
{
	if (c == 'N' || c == 'S'
		|| c == 'W' || c == 'E')
		return (1);
	return (0);
}

int	is_map_char(char c)
{
	if (c == '0' || c == '1'
		|| is_player(c) == 1
		|| c == ' ' || c == '\t')
		return (1);
	return (0);
}

/* return 1, si le premier char de la ligne 
d'une map est 1(donc commence avec la mur)*/
int	is_map_line(char *line)
{
	int	i;
	int	is_wall;
	int	found_content;

	i = 0;
	is_wall = 0;
	found_content = 0;
	while (line[i])
	{
		if (!found_content && (line[i] == ' ' || line[i] == '\t'))
		{
			i++;
			continue ;
		}
		found_content = 1;
		if (is_map_char(line[i]) == 0)
			return (0);
		if (line[i] == '1')
			is_wall = 1;
		i++;
	}
	if (is_wall == 1 && found_content == 1)
		return (1);
	return (0);
}

/// @brief definir le type de la ligne
/// @param line 
/// @return 
t_line	find_line_type(char *line)
{
	char	*trimmed;

	if (is_empty_line(line) == 1)
		return (LINE_EMPTY);
	trimmed = skip_whitespaces(line);
	if (ft_strncmp(trimmed, "NO ", 3) == 0)
		return (LINE_TEX_NO);
	if (ft_strncmp(trimmed, "SO ", 3) == 0)
		return (LINE_TEX_SO);
	if (ft_strncmp(trimmed, "WE ", 3) == 0)
		return (LINE_TEX_WE);
	if (ft_strncmp(trimmed, "EA ", 3) == 0)
		return (LINE_TEX_EA);
	if (ft_strncmp(trimmed, "F ", 2) == 0)
		return (LINE_COL_F);
	if (ft_strncmp(trimmed, "C ", 2) == 0)
		return (LINE_COL_C);
	if (is_map_line(line) == 1)
		return (LINE_MAP);
	return (LINE_INVALID);
}
