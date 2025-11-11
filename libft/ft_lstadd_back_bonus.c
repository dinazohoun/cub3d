/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinados- <dinados-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:35:42 by dinados-          #+#    #+#             */
/*   Updated: 2024/12/04 13:30:14 by dinados-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*back;

	if (*lst == NULL)
		*lst = new;
	else
	{
		back = ft_lstlast(*lst);
		back->next = new;
	}
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	t_list *node1 = ft_lstnew("je");
	t_list *node2 = ft_lstnew("me sens");
	t_list *node3 = ft_lstnew("tres bien");
	t_list *new_node = ft_lstnew("merci");
	t_list *back;

	node1->next = node2;
	node2->next = node3;
	ft_lstadd_back(&node1, new_node);
	back = node1;
	while (back)
	{
		printf("%s -> ", (char *)back->content);
		back = back->next;
	}
	printf("NULL\n");
	return (0);
}*/