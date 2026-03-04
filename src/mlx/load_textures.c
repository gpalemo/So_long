/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 18:18:16 by cmauley           #+#    #+#             */
/*   Updated: 2026/03/04 00:02:02 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	*load_xpm(t_game *game, char *path, int *w, int *h)
{
	return (mlx_xpm_file_to_image(game->mlx, path, w, h));
}

static int	load_player_textures(t_game *game)
{
	game->tex.player_d.img = load_xpm(game, "./sprites/player_d.xpm",
			&game->tex.player_d.w, &game->tex.player_d.h);
	if (!game->tex.player_d.img)
		return (1);
	game->tex.player_u.img = load_xpm(game, "./sprites/player_u.xpm",
			&game->tex.player_u.w, &game->tex.player_u.h);
	if (!game->tex.player_u.img)
		return (1);
	game->tex.player_l.img = load_xpm(game, "./sprites/player_l.xpm",
			&game->tex.player_l.w, &game->tex.player_l.h);
	if (!game->tex.player_l.img)
		return (1);
	game->tex.player_r.img = load_xpm(game, "./sprites/player_r.xpm",
			&game->tex.player_r.w, &game->tex.player_r.h);
	if (!game->tex.player_r.img)
		return (1);
	return (0);
}

/**
 * @brief Charge tous les sprites XPM depuis le dossier sprites.
 */
int	load_textures(t_game *game)
{
	game->tex.floor.img = load_xpm(game, "./sprites/floor.xpm",
			&game->tex.floor.w, &game->tex.floor.h);
	if (!game->tex.floor.img)
		return (1);
	game->tex.wall.img = load_xpm(game, "./sprites/wall.xpm",
			&game->tex.wall.w, &game->tex.wall.h);
	if (!game->tex.wall.img)
		return (1);
	game->tex.exit.img = load_xpm(game, "./sprites/exit.xpm",
			&game->tex.exit.w, &game->tex.exit.h);
	if (!game->tex.exit.img)
		return (1);
	game->tex.collec.img = load_xpm(game, "./sprites/collec.xpm",
			&game->tex.collec.w, &game->tex.collec.h);
	if (!game->tex.collec.img)
		return (1);
	if (load_player_textures(game))
		return (1);
	return (0);
}
