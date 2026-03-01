/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 19:25:24 by cmauley           #+#    #+#             */
/*   Updated: 2026/03/01 21:42:34 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

/**
 * @brief parcourt la map et stocke la position 
 * du joueur 'P' dans game->px/py
 */
int	find_player(t_game *game)
{
	int		x;
	int		y;
	char	**map;

	y = 0;
	if (!game)
		return (1);
	map = game->map;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				game->px = x;
				game->py = y;
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}
