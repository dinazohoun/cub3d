/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinados- <dinados-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:29:53 by dinados-          #+#    #+#             */
/*   Updated: 2024/11/21 10:58:34 by dinados-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
/*
void	my_fonction(unsigned int i, char *c)
{
	*c = (char) toupper(*c);
}

int	main(void)
{
	char	s[] = "a b c d e f";

	ft_striteri(s, my_fonction);
	printf("%s\n", s);
	return (0);
}
*/