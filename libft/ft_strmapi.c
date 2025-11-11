/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinados- <dinados-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:15:30 by dinados-          #+#    #+#             */
/*   Updated: 2024/11/20 12:15:21 by dinados-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*n_str;

	if (!s || !f)
		return (NULL);
	n_str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!n_str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		n_str[i] = f(i, s[i]);
		i++;
	}
	n_str[i] = '\0';
	return (n_str);
}
/*
char	my_fonction(unsigned int i, char c)
{
	return (c + i);
}

int	main(void)
{
	char	str[] = "12345";
	char	*res;

	res = ft_strmapi(str, my_fonction);
	if (res != NULL)
		printf("RES: %s\n", res);
	free(res);
	return (0);
}
*/