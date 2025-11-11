/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinados- <dinados-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:43:21 by dinados-          #+#    #+#             */
/*   Updated: 2024/11/25 12:07:20 by dinados-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*ptr_last;

	if (!lst)
		return (NULL);
	while (lst)
	{
		ptr_last = lst;
		lst = lst->next;
	}
	return (ptr_last);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*node4;
	t_list	*last;

	node1 = ft_lstnew("oi");
	node2 = ft_lstnew("tudo");
	node3 = ft_lstnew("bem");
	node4 = ft_lstnew("contigo");
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	last = ft_lstlast(node1);
	if (last)
		printf("last node: %s\n", (char *)last->content);
	return (0);
}*/
