/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinados- <dinados-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:38:35 by dinados-          #+#    #+#             */
/*   Updated: 2024/11/14 18:38:36 by dinados-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = dest;
	s = src;
	if (dest == src)
		return (0);
	while (n--)
		*d++ = *s++;
	return (dest);
}
/*
#include <stdio.h>

int	main(void)
{
	char s[] = "bonjour";
	char *d;

	ft_memcpy(s, d, 8);
	printf("%s\n", d);
	return (0);
}*/