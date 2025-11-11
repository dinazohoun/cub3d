/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinados- <dinados-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:38:00 by dinados-          #+#    #+#             */
/*   Updated: 2024/12/04 15:50:35 by dinados-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	int	res;

	if (c >= 0 && c <= 127)
		res = 1;
	else
		res = 0;
	return (res);
}
/*
#include <stdio.h>

int	main(void)
{
		printf("%d\n", ft_isascii('ds'));
		return (0);
}*/