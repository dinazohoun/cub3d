/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinados- <dinados-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 20:16:35 by dinados-          #+#    #+#             */
/*   Updated: 2025/12/06 16:50:48 by dinados-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*-ajoute un caractere a la ligne en construition
-si on depasse la capaccite on double pour ne pas segfault
-return le pointeur vers la ligne ou null si malloc echoue*/
static char	*append_to_line(char *line, char c, int *len, int *capacity)
{
	char	*new_line;
	int		k;

	if (*len >= *capacity - 1)
	{
		*capacity *= 2;
		new_line = malloc(*capacity);
		if (!new_line)
			return (NULL);
		k = 0;
		while (k < *len)
		{
			new_line[k] = line[k];
			k++;
		}
		free(line);
		line = new_line;
	}
	line[*len] = c;
	(*len)++;
	return (line);
}

/*
-lit les donnes dans le buffer si besoin
-gere la fin de fichier et les erreurs de lecture
- return 1 si ok, -1 si erreur, 0 sil ny a rien*/
static int	gnl_read_and_check(int fd, char *buf, int *i, int *bytes)
{
	if (*i >= *bytes)
	{
		*bytes = read(fd, buf, BUFFER_SIZE);
		if (*bytes < 0)
			return (-1);
		*i = 0;
		if (*bytes == 0)
			return (0);
	}
	return (1);
}

/*traite chaque caractere du buffer et l ajoute a la ligne
verifie si c'est un '\n
return 1 pour continuer, 0 si on trouve '\n', -1 si erreur*/
static int	gnl_process_buffer(char *buf, char **line, t_gnl_data *v)
{
	*line = append_to_line(*line, buf[v->i], &v->len, &v->capacity);
	if (!*line)
		return (-1);
	if (buf[v->i] == '\n')
	{
		v->i++;
		return (0);
	}
	v->i++;
	return (1);
}

/*initialise les variables de la struture pour gnl et verifie le malloc*/
static int	gnl_init(int fd, t_gnl_data *v)
{
	v->len = 0;
	v->capacity = BUFFER_SIZE;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	v->line = malloc(v->capacity);
	if (!v->line)
		return (0);
	return (1);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE];
	static int	i = 0;
	static int	bytes = 0;
	t_gnl_data	v;
	int			status;

	if (!gnl_init(fd, &v))
		return (NULL);
	while (1)
	{
		status = gnl_read_and_check(fd, buf, &i, &bytes);
		if (status == -1)
			return (free(v.line), NULL);
		if (status == 0 && v.len == 0)
			return (free(v.line), NULL);
		if (status == 0)
			break ;
		v.i = i;
		status = gnl_process_buffer(buf, &v.line, &v);
		i = v.i;
		if (status <= 0)
			break ;
	}
	v.line[v.len] = '\0';
	return (v.line);
}
