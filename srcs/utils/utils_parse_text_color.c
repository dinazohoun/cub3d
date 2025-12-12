/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse_text_color.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinados- <dinados-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 11:51:55 by zohoun            #+#    #+#             */
/*   Updated: 2025/11/25 09:10:42 by dinados-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*saute les espaces blancs au debut de la ligne*/
char	*skip_whitespaces(char *str)
{
	while (*str && (*str == ' ' || *str == '\t'))
		str++;
	return (str);
}

/*verifier que un fichier existe vraiment
file_exists("textures/north.xpm") → 1 (existe)
file_exists("textures/absent.xpm") → 0 (n'existe pas)
*/
int	file_exists(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

/*extrait le chemin du fichier depuis une ligne(après "NO ", "SO ", etc.)*/
char	*extract_file_path(char *line)
{
	char	*start;
	char	*end;
	char	*path;
	int		len;

	start = skip_whitespaces(line);
	end = start;
	while (*end && *end != ' ' && *end != '\t' && *end != '\n')
		end++;
	len = end - start;
	path = malloc(len + 1);
	if (!path)
		return (NULL);
	ft_strlcpy(path, start, len + 1);
	return (path);
}
