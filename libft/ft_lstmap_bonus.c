/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinados- <dinados-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:49:06 by dinados-          #+#    #+#             */
/*   Updated: 2024/12/05 15:15:21 by dinados-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (new_node == NULL)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		lst = lst->next;
		ft_lstadd_back(&new_list, new_node);
	}
	return (new_list);
}

/*
#include <stdio.h>
#include <stdlib.h>

void	*add_suffix(void *content)
{
	char	*str;
	char	*new_str;

	str = (char *) content;
	new_str = (char *)malloc(strlen(str) + 8);
	if (!new_str)
		return (NULL);
	strcpy(new_str, str);
	strcat(new_str, "mapped");
	return (new_str);
}
void	del(void *content)
{
	free(content);
}
void	print_content(void *content)
{
	printf(" %s\n", (char *)content);
}

int	main(void)
{
	t_list	*new_list;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	node1 = ft_lstnew(strdup("node1 "));
	node2 = ft_lstnew(strdup("node2 "));
	node3 = ft_lstnew(strdup("node3 "));
	node1->next = node2;
	node2->next = node3;
	printf("liste de contenus:\n");
	ft_lstiter(node1, print_content);
	new_list = ft_lstmap(node1, add_suffix, del);
	if (!new_list)
	{
		printf("erreur lors de la creation\n");
		ft_lstclear(&node1, del);
		return (1);
	}
	else
		printf(" \nNouvelle liste\n");
		ft_lstiter(new_list, print_content);
		ft_lstclear(&node1, del);
		ft_lstclear(&new_list, del);
		return (0);
}
*/