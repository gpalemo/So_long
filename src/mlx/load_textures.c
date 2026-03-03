/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 18:18:16 by cmauley           #+#    #+#             */
/*   Updated: 2026/03/03 23:06:30 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	*load_xpm(t_game *game, char *path, int *w, int *h)
{
	return (mlx_xpm_file_to_image(game->mlx, path, w, h));
}

/**
 * @brief Charge tous les sprites XPM depuis le dossier sprites.
 * Retourne 1 si un fichier est introuvable ou invalide.
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
	game->tex.player.img = load_xpm(game, "./sprites/player.xpm",
			&game->tex.player.w, &game->tex.player.h);
	if (!game->tex.player.img)
		return (1);
	game->tex.exit.img = load_xpm(game, "./sprites/exit.xpm",
			&game->tex.exit.w, &game->tex.exit.h);
	if (!game->tex.exit.img)
		return (1);
	game->tex.collec.img = load_xpm(game, "./sprites/collec.xpm",
			&game->tex.collec.w, &game->tex.collec.h);
	if (!game->tex.collec.img)
		return (1);
	return (0);
}
