/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinados- <dinados-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:46:00 by dinados-          #+#    #+#             */
/*   Updated: 2024/11/25 17:04:23 by dinados-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dst;
	const char	*c_src;
	size_t		i;

	if (!dest && !src)
		return (NULL);
	dst = (char *)dest;
	c_src = (const char *)src;
	if (dst > c_src)
	{
		while (n-- > 0)
			dst[n] = c_src[n];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			dst[i] = c_src[i];
			i++;
		}
	}
	return (dst);
}
/*
#include <stdio.h>

int	main(void)
{
	char	src[] = "bonjour";
	char	dst[] = "aujourd'hui c'est cool";

	ft_memmove(dst, src, 3);
	printf("apres chevauchement: dst = \"%s\"\n", dst);
	return (0);
}*/
