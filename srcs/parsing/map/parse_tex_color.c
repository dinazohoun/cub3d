/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tex_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinados- <dinados-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:28:33 by dinados-          #+#    #+#             */
/*   Updated: 2025/11/25 10:28:33 by dinados-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	save_pos_bef_map(t_text_data *data, int *map_start, int i)
{
	*map_start = i;
	if (data->parsed_flags != ALL_FLAGS)
	{
		err_msg("Missing element in file");
		return (-1);
	}
	return (0);
}

int	verif_tex_color(char *line, t_line type, t_text_data *data)
{
	if (type == LINE_TEX_NO || type == LINE_TEX_SO
		|| type == LINE_TEX_WE || type == LINE_TEX_EA)
	{
		if (parsed_text_files(line, data) == -1)
			return (-1);
	}
	if (type == LINE_COL_F || type == LINE_COL_C)
	{
		if (parsed_colors(line, data) == -1)
			return (-1);
	}
	return (0);
}

int	parse_bef_map(char **file_info, t_text_data *data, int *map_start)
{
	int		i;
	t_line	type;

	*map_start = -1;
	i = 0;
	while (file_info[i])
	{
		type = find_line_type(file_info[i]);
		if (type == LINE_EMPTY)
		{
			i++;
			continue ;
		}
		if (type == LINE_MAP)
			return (save_pos_bef_map(data, map_start, i));
		if (type == LINE_INVALID)
			return (err_msg("Invalid element in file"), -1);
		if (verif_tex_color(file_info[i], type, data) == -1)
			return (-1);
		i++;
	}
	return (err_msg("No map in file"), -1);
}
