/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinados- <dinados-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:21:22 by dinados-          #+#    #+#             */
/*   Updated: 2024/12/05 14:29:59 by dinados-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
	*lst = NULL;
}
/*
#include <stdio.h>
#include <stdlib.h>

void	del(void *content)
{
	free(content);
}
int	main(void)
{
	char	*str1;
	char	*str2;
	char	*str3;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	str1 = strdup("15");
	str2 = strdup("256");
	str3 = strdup("top");
	if (!str1 || !str2 || str3)
		return (1);
	node1 = ft_lstnew("str1");
	node2 = ft_lstnew("str2");
	node3 = ft_lstnew("str3");
	if (!node1 || !node2 || !node3)
	{
		if (node1) free(node1);
		if (node2) free(node2);
		if (node3) free(node3);
		return (1);
	}
	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;
	ft_lstclear(&node1, del);
	if (node1 == NULL)
	{
		printf("list correctement supprime\n");
	}
	else
		printf("erreur lors de la suppression\n");
	return (0);
}*/
