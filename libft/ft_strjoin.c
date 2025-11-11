/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinados- <dinados-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:39:15 by dinados-          #+#    #+#             */
/*   Updated: 2024/12/04 15:50:53 by dinados-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*nstr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	nstr = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!nstr)
		return (NULL);
	while (s1[i])
	{
		nstr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		nstr[i] = s2[j];
		i++;
		j++;
	}
	nstr[i] = '\0';
	return (nstr);
}
/*
int	main(int ac, char **av)
{
	char	*s1;
	char	*s2;
	char	*res;

	if (ac != 3)
	{
		printf("%s <s1> <s2>\n", av[0]);
		return (1);
	}
	s1 = av[1];
	s2 = av[2];
	res = ft_strjoin(s1, s2);
	if (res)
	{
		printf("chaine jointe: %s\n", res);
		free(res);
	}
	else
	{
		printf("erreur d'allocation memo\n");
	}
	return (0);
}*/
