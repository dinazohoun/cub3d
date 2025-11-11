/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinados- <dinados-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:16:16 by dinados-          #+#    #+#             */
/*   Updated: 2024/12/04 13:26:19 by dinados-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	if (lst != NULL && del != NULL)
	{
		del(lst->content);
		free(lst);
	}
}
/*
int	main(void)
{
	int		*element;
	t_list	*node;

	element = (int *)malloc(sizeof(int));
	if (!element)
	{
		printf("memory allocation failled\n");
		return (1);
	}
	*element = 123456;
	node = ft_lstnew(element);
	if (!node)
	{
		free(element);
		printf("memory allocation failled\n");
		return (1);
	}
		printf("node content: %d\n", *((int *)node->content));
		free(node->content);
		free(node);
		return (0);
}
*/