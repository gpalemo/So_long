/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 22:39:35 by cmauley           #+#    #+#             */
/*   Updated: 2026/03/04 00:06:57 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	destroy_textures(t_game *game);

/**
 * @brief Libère toutes les ressources MLX et la map,
 * puis quitte le programme.
 */
int	clean_exit(t_game *game, int status)
{
	destroy_textures(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (game->map)
		free_tab(game->map);
	exit(status);
}

static void	destroy_textures(t_game *game)
{
	if (game->tex.floor.img)
		mlx_destroy_image(game->mlx, game->tex.floor.img);
	if (game->tex.wall.img)
		mlx_destroy_image(game->mlx, game->tex.wall.img);
	if (game->tex.exit.img)
		mlx_destroy_image(game->mlx, game->tex.exit.img);
	if (game->tex.collec.img)
		mlx_destroy_image(game->mlx, game->tex.collec.img);
	if (game->tex.player_d.img)
		mlx_destroy_image(game->mlx, game->tex.player_d.img);
	if (game->tex.player_u.img)
		mlx_destroy_image(game->mlx, game->tex.player_u.img);
	if (game->tex.player_l.img)
		mlx_destroy_image(game->mlx, game->tex.player_l.img);
	if (game->tex.player_r.img)
		mlx_destroy_image(game->mlx, game->tex.player_r.img);
}

/**
 * @brief Callback appelé lors de la fermeture de la fenêtre (croix).
 * Appelle clean_exit pour quitter proprement.
 */
int	handle_close(t_game *game)
{
	clean_exit(game, 0);
	return (0);
}
