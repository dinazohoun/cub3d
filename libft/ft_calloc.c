/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinados- <dinados-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 09:06:23 by dinados-          #+#    #+#             */
/*   Updated: 2024/12/09 11:53:15 by dinados-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*str;

	if (nmemb != 0 && size > SIZE_MAX / nmemb)
		return (NULL);
	str = (char *)malloc(nmemb * size);
	if (str == NULL)
		return (NULL);
	ft_memset(str, 0, nmemb * size);
	return ((void *)str);
}
/*
#include <stdio.h>
#include <stdlib.h>
int	main(void)
{
	printf("%ld", sizeof(size_t));
	return (0);
}*/
