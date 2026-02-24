/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 19:02:43 by cmauley           #+#    #+#             */
/*   Updated: 2026/02/24 19:36:45 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	read_map(int fd, t_game *game)
{
	char	*content;

	game->map = NULL;
	if (read_file_to_string(fd, &content))
		return (write_error("Empty map or read failed"));
	if (split_and_store(game, content))
		return (write_error("Split failed"));
	if (validate_shape(game))
		return (free_tab(game->map), write_error("Invalid map shape"));
	return (0);
}




