/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:23:43 by dinados-          #+#    #+#             */
/*   Updated: 2025/01/26 23:39:21 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countword(char const *s, char c)
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

static char	**ft_free(char **lst, int i)
{
	while (i > 0)
	{
		i--;
		free(lst[i]);
	}
	free(lst);
	return (NULL);
}

static char	**ft_freelst(char **lst, int i, size_t word_len, const char *s)
{
	lst[i] = (char *)malloc((word_len + 1) * sizeof(char));
	if (!lst[i])
		return (ft_free(lst, i));
	ft_strlcpy(lst[i], s, word_len + 1);
	return (lst);
}

char	**ft_split(char const *s, char c)
{
	char	**lst;
	size_t	word_len;
	int		i;

	lst = (char **)malloc((ft_countword(s, c) + 1) * sizeof(char *));
	if (!s || !lst)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			word_len = 0;
			while (s[word_len] && s[word_len] != c)
				word_len++;
			if (!ft_freelst(lst, i++, word_len, s))
				return (NULL);
			s += word_len;
		}
	}
	lst[i] = NULL;
	return (lst);
}
/*
int	main(void)
{
	char	str[] = " bonjour 42! bienvenue a l'ecole, aujourd'hui";
	char	delimiteur;
	char	**words;
	int		i;

	delimiteur = ' ';
	words = ft_split(str, delimiteur);
	if (!words)
		return (0);
	printf("resultat de la division\n");
	i = 0;
	while (words[i])
	{
		printf("mot %d: %s\n", i + 1, words[i]);
		free(words[i]);
		i++;
	}
	free(words);
	return (0);
}*/
