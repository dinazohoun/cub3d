/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinados- <dinados-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:01:05 by dinados-          #+#    #+#             */
/*   Updated: 2024/12/16 21:17:08 by dinados-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_int(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	else
	{
		if (n < 0)
		{
			count = 1;
			n = -n;
		}
		while (n)
		{
			n /= 10;
			count++;
		}
	}
	return (count);
}

char	*ft_itoa(int n)
{
	unsigned int	nb;
	int				len;
	char			*str;

	if (n < 0)
		nb = -n;
	else
		nb = n;
	len = ft_count_int(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
		str[0] = '-';
	if (n == 0)
		str[0] = '0';
	while (nb > 0)
	{
		len--;
		str[len] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (str);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int			a;
	int			b;
	int			c;
	long int	d;

	a = 123;
	b = -1-+25;
	c = -2147483648;
	d = 2147483648;
	printf("%s\n", ft_itoa(a));
	printf("%s\n", ft_itoa(b));
	printf("%s\n", ft_itoa(c));
	printf("%s\n", ft_itoa(d));
	return (0);
}
*/