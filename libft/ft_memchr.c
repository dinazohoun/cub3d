/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinados- <dinados-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:55:29 by dinados-          #+#    #+#             */
/*   Updated: 2024/12/03 16:30:35 by dinados-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return (str + i);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>

int	main(void)
{
	char	s[] = "test de ma fonction memchr";
	char	sh;
	size_t	len;
	void	*res;
	void	*std_res;

	sh = 'o';
	len = strlen(s);
	res = ft_memchr(s, (int)sh, len);
	std_res = memchr(s, (int)sh, len);
	if (res != NULL)
	{
		printf("found '%c' at position %zu (ft_memchr)\n", sh,
			(size_t)((char *)res - s));
	}
	else
	{
		printf("'%c' not found in s (ft_memchr)\n", sh);
	}
	if (std_res != NULL)
	{
		printf("found '%c' at positon %zu (memchr)\n", sh,
			(size_t)((char *)std_res - s));
	}
	else
	{
		printf("'%c' not found in s (memchr)\n", sh);
	}
	return (0);
}
*/