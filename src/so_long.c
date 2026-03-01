/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 23:14:04 by cmauley           #+#    #+#             */
/*   Updated: 2026/03/01 18:09:14 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (write_error("Usage: ./so_long map.ber"));
	if (parse(&game, av[1] == 1))
		return (1);
	// init mlx + game loop
	return (0);
}
