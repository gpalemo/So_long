/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 22:05:31 by cmauley           #+#    #+#             */
/*   Updated: 2026/03/04 00:18:43 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	apply_move(t_game *game, int nx, int ny);
static void	update_dir(t_game *game, int dx, int dy);

/**
 * @brief Vérifie si le déplacement est possible puis l'applique et
 * gère la collecte des objets et la condition de victoire.
 */
void	move_player(t_game *game, int dx, int dy)
{
	int		nx;
	int		ny;
	char	tile;
	int		win;

	win = 0;
	nx = game->px + dx;
	ny = game->py + dy;
	tile = game->map[ny][nx];
	if (tile == '1')
		return ;
	if (tile == 'E' && game->collectibles_left != 0)
		return ;
	if (tile == 'E' && game->collectibles_left == 0)
		win = 1;
	if (tile == 'C')
		game->collectibles_left--;
	update_dir(game, dx, dy);
	apply_move(game, nx, ny);
	if (win == 1)
	{
		ft_printf("Congrats ! You won in %d moves !\n", game->moves);
		clean_exit(game, 0);
	}
}

/**
 * @brief Met à jour la map et les coordonnées du joueur,
 * incrémente le compteur de mouvements et redessine.
 */
static void	apply_move(t_game *game, int nx, int ny)
{
	game->map[game->py][game->px] = '0';
	game->map[ny][nx] = 'P';
	game->px = nx;
	game->py = ny;
	game->moves++;
	render_map(game);
}

/**
 * @brief Met à jour la direction du joueur
 */
static void	update_dir(t_game *game, int dx, int dy)
{
	if (dx == 1)
		game->dir = DIR_RIGHT;
	else if (dx == -1)
		game->dir = DIR_LEFT;
	else if (dy == 1)
		game->dir = DIR_DOWN;
	else if (dy == -1)
		game->dir = DIR_UP;
}
