/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 17:30:35 by cmauley           #+#    #+#             */
/*   Updated: 2026/03/01 21:45:27 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	init_game(t_game *g);

/**
 * @brief orchestre toute la phase de parsing de la map
 */
int	parse(t_game *game, char *path)
{
	int	fd;

	init_game(game);
	if (verify_ber(path) == 1)
		return (1);
	if (open_map(path, &fd) == 1)
		return (write_error("Could not open file"));
	if (read_map(fd, game) == 1)
		return (1);
	if (check_char(game->map) == 1)
		return (fail_map(game, "Invalid character in map"));
	if (wall_check(game->map) == 1)
		return (fail_map(game, "Map must be surrounded by walls"));
	if (check_nb_char_and_stock_coll(game) == 1)
		return (fail_map(game, "Map must have 1P, 1E and at least 1C"));
	if (find_player(game) == 1)
		return (fail_map(game, "Player position not found"));
	if (check_path(game) == 1)
		return (fail_map(game, "Invalid path"));
	return (0);
}

/**
 * @brief initialise toutes les valeurs de la structure game à zéro/NULL
 */
static void	init_game(t_game *g)
{
	g->mlx = NULL;
	g->win = NULL;
	g->map = NULL;
	g->moves = 0;
	g->collectibles_total = 0;
	g->collectibles_left = 0;
	g->px = 0;
	g->py = 0;
	g->map_width = 0;
	g->map_height = 0;
}
