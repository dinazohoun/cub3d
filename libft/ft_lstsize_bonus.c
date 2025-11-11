/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinados- <dinados-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:20:47 by dinados-          #+#    #+#             */
/*   Updated: 2024/11/25 13:28:57 by dinados-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	t_list *node1 = ft_lstnew("eu quero comer");
	t_list *node2 = ft_lstnew("estou");
	t_list *node3 = ft_lstnew("com fome");
	int size;

	node1->next = node2;
	node2->next = node3;
	size = ft_lstsize(node1);

	printf("size:%d\n", size);
	return (0);
}*/
