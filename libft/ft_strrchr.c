/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinados- <dinados-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:40:13 by dinados-          #+#    #+#             */
/*   Updated: 2024/12/03 16:19:11 by dinados-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}
/*
#include <unistd.h>

int	main(void)
{
	char s[] = "cent un et quuarenta et tres";
	char *res;
	
	res = ft_strrchr(s, 'i');
	if (res)
	printf("res: %s\n", res);
	else
		printf("occurrence non trouve\n");
	return (0);
}*/
