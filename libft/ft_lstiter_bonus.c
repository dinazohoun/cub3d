/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinados- <dinados-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:40:48 by dinados-          #+#    #+#             */
/*   Updated: 2024/12/02 15:53:18 by dinados-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
void	print_content(void *content)
{
	printf("%s\n", (char *)content);
}

int	main(void)
{
	t_list	*node1 = ft_lstnew(strdup("node1"));
	t_list	*node2 = ft_lstnew(strdup("node2"));
	t_list	*node3 = ft_lstnew(strdup("node3"));
	
	node1->next = node2;
	node2->next = node3;
	printf("liste de contenus:\n");
	ft_lstiter(node1, print_content);
	ft_lstclear(&node1, free);
	return (0);
}*/
