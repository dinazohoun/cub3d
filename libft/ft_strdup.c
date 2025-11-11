/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinados- <dinados-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:39:03 by dinados-          #+#    #+#             */
/*   Updated: 2024/12/05 11:38:50 by dinados-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*cpy;
	size_t	len;
	size_t	i;

	len = ft_strlen(str);
	cpy = malloc((len + 1) * sizeof(char));
	i = 0;
	if (cpy == 0)
		return (0);
	while (i < len)
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
/*
#include <stdio.h>

int	main(void)
{
	const char	str[] = " merci Seigneur!";
	char		*strcpy;

	strcpy = ft_strdup(str);
	printf("%s\n", strcpy);
	free(strcpy);
	return (0);
}*/
