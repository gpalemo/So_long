/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 18:18:23 by cmauley           #+#    #+#             */
/*   Updated: 2026/03/03 23:09:31 by cmauley          ###   ########.fr       */
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

static void	put_img(t_game *game, void *img, int px, int py)
{
	mlx_put_image_to_window(game->mlx, game->win, img, px, py);
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
	put_img(game, game->tex.floor.img, px, py);
	if (tile == '1')
		put_img(game, game->tex.wall.img, px, py);
	else if (tile == 'C')
		put_img(game, game->tex.collec.img, px, py);
	else if (tile == 'E')
		put_img(game, game->tex.exit.img, px, py);
	else if (tile == 'P')
		put_img(game, game->tex.player.img, px, py);
}
