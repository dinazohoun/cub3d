/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinados- <dinados-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:01:28 by dinados-          #+#    #+#             */
/*   Updated: 2024/11/25 12:53:52 by dinados-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	t_list	*node1 = ft_lstnew("dia");
	t_list	*node2 = ft_lstnew("ou boa");
	t_list	*node3 = ft_lstnew("noite");
	t_list	*front;
	t_list	*current;
	t_list	*new_front;

	node1->next = node2;
	node2->next = node3;
	front = node1;
	current = front;
	printf("before add:\n");
	while (current)
	{
		printf("%s -> ", (char *)current->content);
		current =  current->next;
	}
	printf("NULL\n");
	new_front = ft_lstnew("bom");
	ft_lstadd_front(&front, new_front);
	printf("after add:\n");
	current = front;
	while (current)
	{
		printf("%s -> ", (char *)current->content);
		current = current->next;
	}
	printf("NULL\n");
	return (0);
}*/
