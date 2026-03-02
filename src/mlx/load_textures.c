/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 18:18:16 by cmauley           #+#    #+#             */
/*   Updated: 2026/03/02 23:31:21 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

/**
 * @brief Charge tous les sprites XPM depuis le dossier sprites.
 * Retourne 1 si un fichier est introuvable ou invalide.
 */
int	load_textures(t_game *game)
{
	game->tex.floor.img = mlx_xpm_file_to_image(game->mlx, "./sprites/floor.xpm", &game->tex.floor.w, &game->tex.floor.h);
	if (!game->tex.floor.img)
		return (1);
	game->tex.wall.img = mlx_xpm_file_to_image(game->mlx, "./sprites/wall.xpm", &game->tex.wall.w, &game->tex.wall.h);
	if (!game->tex.wall.img)
		return (1);
	game->tex.player.img = mlx_xpm_file_to_image(game->mlx, "./sprites/player.xpm", &game->tex.player.w, &game->tex.player.h);
	if (!game->tex.player.img)
		return (1);
	game->tex.exit.img = mlx_xpm_file_to_image(game->mlx, "./sprites/exit.xpm", &game->tex.exit.w, &game->tex.exit.h);
	if (!game->tex.exit.img)
		return (1);
	game->tex.collectible.img = mlx_xpm_file_to_image(game->mlx, "./sprites/collec.xpm", &game->tex.collectible.w, &game->tex.collectible.h);
	if (!game->tex.collectible.img)
		return (1);
	return (0);
}
