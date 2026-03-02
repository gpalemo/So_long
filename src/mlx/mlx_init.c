/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 16:56:30 by cmauley           #+#    #+#             */
/*   Updated: 2026/03/02 18:12:30 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

/**
 * @brief initialise l'environnement MLX (serveur graphique X11) 
 * et crée la fenêtre dont les dimensions 
 * sont calculées depuis la taille de la map.
 */
int	init_mlx(t_game *game)
{
	int w;
	int h;

	w = game->map_width * TILE;
	h = game->map_height * TILE;
	game->mlx = mlx_init();
	if (!game->mlx)
		return (write_error("mlx_init failed"));
	game->win = mlx_new_window(game->mlx, w, h, "so_long");
	if (!game->win)
		return (write_error("mlx_new_window failed"));
	return (0);
}