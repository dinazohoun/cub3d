/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinados- <dinados-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:16:44 by dinados-          #+#    #+#             */
/*   Updated: 2024/11/28 15:47:41 by dinados-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (dest[i] != '\0' && i < dstsize)
		i++;
	if (i >= dstsize)
	{
		return (dstsize + ft_strlen(src));
	}
	j = 0;
	while (src[j] != '\0' && i + j + 1 < dstsize)
	{
		dest[i + j] = src[j];
		j++;
	}
	if (i + j < dstsize)
	{
		dest[i + j] = '\0';
	}
	return (i + ft_strlen(src));
}
/*
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	char	src[] = " there is no stars in the sky";
	char	dest[30] = "there is no stars !n the sky";
	int		res;

	res = ft_strlcat(dest, src, 30);
	printf("res: %s\n", dest);
	printf("len: %d\n", res);
	return (0);
}
*/