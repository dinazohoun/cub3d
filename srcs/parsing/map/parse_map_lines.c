/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_lines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinados- <dinados-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 10:15:44 by dinados-          #+#    #+#             */
/*   Updated: 2025/12/08 11:44:11 by dinados-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
-traite a ligne dans le calcul de la taille de la map
-met a jour les variables h,w ,ended
-return 1 pour continuer, 0 pour arreter, -1 pour l'erreur
*/
static int	process_map_line(char *line, int *h, int *w, int *ended)
{
	int		cur_w;
	t_line	type;

	type = find_line_type(line);
	if (type == LINE_EMPTY)
	{
		if (*h > 0)
			*ended = 1;
		return (1);
	}
	if (type != LINE_MAP)
	{
		if (*h > 0)
			return (0);
		return (err_msg("Invalid line after start map"), -1);
	}
	if (*ended && type == LINE_MAP)
		return (err_msg("Empty line in map"), -1);
	(*h)++;
	cur_w = ft_strlen(line);
	if (cur_w > *w)
		*w = cur_w;
	return (1);
}

/*
-calcul la taile de la map(hauteur et largeur)(boucle sur toutes les lignes)
-dectecte les lignes vides 
-return 0 si ok et -1 si erreur
*/
int	get_map_size(char **file_info, int map_start, int *h, int *w)
{
	int	i;
	int	status;
	int	map_ended;

	i = map_start;
	*h = 0;
	*w = 0;
	map_ended = 0;
	while (file_info[i] != NULL)
	{
		status = process_map_line(file_info[i], h, w, &map_ended);
		if (status == -1)
			return (-1);
		if (status == 0)
			break ;
		i++;
	}
	if (*h == 0)
		return (err_msg("No map"), -1);
	return (0);
}
