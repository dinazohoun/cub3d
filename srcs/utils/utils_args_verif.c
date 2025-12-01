/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_args_verif.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinados- <dinados-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 18:42:28 by dinados-          #+#    #+#             */
/*   Updated: 2025/12/01 18:42:35 by dinados-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	err_msg(char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
}

int	is_cub_file(const char *file)
{
	size_t	ext_len;
	char	*first_char_ptr;

	if (!file)
		return (0);
	ext_len = ft_strlen(file);
	first_char_ptr = ft_strnstr(file, ".cub", ext_len);
	if (!first_char_ptr)
		return (0);
	if (*(first_char_ptr + 4) == '\0')
		return (1);
	else
		return (0);
}
