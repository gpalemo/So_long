/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 23:14:04 by cmauley           #+#    #+#             */
/*   Updated: 2026/02/23 23:53:33 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	main(int ac, char **av)
{
	if (ac != 2)
		return (write_error("Usage: ./so_long map.ber"));
	if (verify_ber(av[1]))
		return (1);
	if (open_map(av[1], &fd))
		return (1);
	// read_fd
	
	close(fd);
	return (0);
}