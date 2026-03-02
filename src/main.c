/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 23:14:04 by cmauley           #+#    #+#             */
/*   Updated: 2026/03/02 23:34:52 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

/**
 * @brief Point d'entrée : parse la map, initialise MLX,
 * charge les textures, lance la boucle événementielle.
 */
int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (write_error("Usage: ./so_long map.ber"));
	if (parse(&game, av[1]) == 1)
		return (1);
	if (init_mlx(&game) == 1)
		return (free_tab(game.map), 1);
	if (load_textures(&game) == 1)
		return (free_tab(game.map), write_error("textures failed"));
	render_map(&game);
	mlx_key_hook(game.win, handle_key, &game);
	mlx_hook(game.win, 17, 0, handle_close, &game);
	mlx_loop(game.mlx);
	return (0);
}
