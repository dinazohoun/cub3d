/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinados- <dinados-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:38:29 by dinados-          #+#    #+#             */
/*   Updated: 2024/11/15 18:00:36 by dinados-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *b1, const void *b2, size_t n)
{
	const unsigned char	*strb1;
	const unsigned char	*strb2;
	size_t				len_o;

	strb1 = (const unsigned char *)b1;
	strb2 = (const unsigned char *)b2;
	len_o = 0;
	while (len_o < n)
	{
		if (strb1[len_o] != strb2[len_o])
			return (strb1[len_o] - strb2[len_o]);
		len_o++;
	}
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	const unsigned char strb1[] = "bonjour";
	const unsigned char strb2[] = "bonjoer";
	size_t len;

	len = 8;
	printf("%d\n", ft_memcmp(strb1, strb2, len));
	return (0);
}*/