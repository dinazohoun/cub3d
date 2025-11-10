/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinados- <dinados-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:48:52 by dinados-          #+#    #+#             */
/*   Updated: 2025/05/15 17:33:26 by dinados-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"
#include "../printf/includes/ft_printf.h"
#include "../gnl/get_next_line.h"

void	display_moves(t_game *game)
{
	char	*moves_str;
	char	*display_str;

	put_tile(game, '1', 0, 0);
	moves_str = ft_itoa(game->moves);
	if (!moves_str)
		handle_error(NULL, "Impossible de convertir en chaîne");
	display_str = ft_strjoin("Moves: ", moves_str);
	free(moves_str);
	if (!display_str)
		handle_error(game, "Impossible de construire la chaîne de mouvements");
	mlx_string_put(game->mlx, game->win, 10, 30, 0xFFFFFF, display_str);
	free(display_str);
}
