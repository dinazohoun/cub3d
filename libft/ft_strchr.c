/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinados- <dinados-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:38:54 by dinados-          #+#    #+#             */
/*   Updated: 2024/12/02 12:36:33 by dinados-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	cc;

	i = 0;
	cc = (char)c;
	while (s[i])
	{
		if (s[i] == cc)
			return ((char *) &s[i]);
		i++;
	}
	if (cc == '\0')
	{
		return ((char *) &s[i]);
	}
	return (NULL);
}
/*
#include <unistd.h>

int	main(void)
{
	char  s[] = "cent un";
	char *prt = ft_strchr(s, 'L');

	printf("res: %s\n", prt);
	return (0);
}*/
