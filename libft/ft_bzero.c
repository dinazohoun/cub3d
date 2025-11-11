/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinados- <dinados-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:37:23 by dinados-          #+#    #+#             */
/*   Updated: 2024/12/03 13:43:58 by dinados-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	str[14] = "hello, world!";
	int	i;
	
	i = 0;
	printf("avant bzero:\n %s\n", str);
	ft_bzero(str, 4);
	printf("apres bzero:\n");
	while (i < 14)
	{
		if (str[i] == 0)
			printf("\\*");
		else
			printf("%c", str[i]);
		i++;
	}
	return (0);
}*/
