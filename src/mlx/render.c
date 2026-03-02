/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 18:18:23 by cmauley           #+#    #+#             */
/*   Updated: 2026/03/02 23:32:23 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	draw_tile(t_game *game, int x, int y);

/**
 * @brief Parcourt toute la map et dessine chaque case dans la fenêtre.
 */
void	render_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			draw_tile(game, x, y);
			x++;
		}
		y++;
	}
}

/**
 * @brief Dessine le sprite correspondant à la case (x, y) de la map.
 */
static void	draw_tile(t_game *game, int x, int y)
{
	char	tile;
	int		px;
	int		py;
	
	tile = game->map[y][x];
	px = x * TILE;
	py = y * TILE;
	mlx_put_image_to_window(game->mlx, game->win, game->tex.floor.img, px, py);
	if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->tex.wall.img, px, py);
	else if (tile == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->tex.collectible.img, px, py);
	else if (tile == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->tex.exit.img, px, py);
	else if (tile == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->tex.player.img, px, py);
}