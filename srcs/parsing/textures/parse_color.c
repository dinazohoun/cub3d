/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zohoun <zohoun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 10:28:03 by zohoun            #+#    #+#             */
/*   Updated: 2025/11/22 22:09:52 by zohoun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*extrait un seul nombre(0-255), pour la creation de la couleur
et verifie si c'est valide
char **str - un pointeur sur pointeur pour modifier la position du
pointeur pour avancer dans la chaîne pour la construition de la couleur*/
static int	extract_rgb(char **str)
{
	char	*start;
	int		value;

	*str = skip_whitespaces(*str);
	start = *str;
	while (**str && ft_isdigit(**str))
		(*str)++;
	if (*str == start)
		return (-1);
	value = ft_atoi(start);
	if (value < 0 || value > 255)
		return (-1);
	*str = skip_whitespaces(*str);
	return (value);
}

/*extraire les 3 composants de la couleur et les stocke dans une structure.
*/
int	parse_rgb_values(char *line, t_color *color)
{
	char	*ptr;

	ptr = line;
	color->r = extract_rgb(&ptr);
	if (color->r == -1)
		return (err_msg("Invalid R value"), -1);
	if (*ptr != ',')
		return (err_msg("missing comma after R"), -1);
	ptr++;
	color->g = extract_rgb(&ptr);
	if (color->g == -1)
		return (err_msg("Invalid G value"), -1);
	if (*ptr != ',')
		return (err_msg("missing comma after G"), -1);
	ptr++;
	color->b = extract_rgb(&ptr);
	if (color->b == -1)
		return (err_msg("Invalid B value"), -1);
	ptr = skip_whitespaces(ptr);
	if (*ptr != '\0' && *ptr != '\n')
		return (err_msg("extra characteres after B"), -1);
	color->rgb = (color->r << 16) | (color->g << 8) | color->b;
	return (1);
}

/*identifie la color ciblé pour etre stocke dans la structure et
returne l'info necessaire*/
static int	id_type_color(char *line, t_text_data *data,
		t_color **target, int *flag_bit)
{
	char	*id;

	id = line;
	while (*line && *line != ' ' && *line != '\t')
		line ++;
	if (line - id != 1)
		return (0);
	if (*id == 'F')
	{
		*target = &data->floor_color;
		*flag_bit = FLAG_F;
	}
	else if (*id == 'C')
	{
		*target = &data->ceiling_color;
		*flag_bit = FLAG_C;
	}
	else
		return (0);
	if (data->parsed_flags & *flag_bit)
		return (err_msg("Duplicate color"), -1);
	return (1);
}

/*identification de la ligne si c'est le F(floor) ou C(ceiling) 
puis on appel parse_rgb_values pour mettre a jour les
flags(la bonne coleur) */
int	parsed_colors(char *line, t_text_data *data)
{
	char	*color_str;
	t_color	*target;
	int		flag_bit;
	int		res;

	res = id_type_color(line, data, &target, &flag_bit);
	if (res != 1)
		return (res);
	color_str = skip_whitespaces(line);
	while (*color_str && *color_str != ' ' && *color_str != '\t')
		color_str++;
	color_str = skip_whitespaces(color_str);
	if (parse_rgb_values(color_str, target) == -1)
		return (-1);
	data->parsed_flags |= flag_bit;
	return (1);
}
