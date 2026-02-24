/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_shape.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 19:03:54 by cmauley           #+#    #+#             */
/*   Updated: 2026/02/24 19:35:53 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static int	count_height(char **map);
static int	check_no_empty_lines(char **map);
static int	check_rectangular(char **map, int *width);

int	validate_shape(t_game *game)
{
	if (check_no_empty_lines(game->map))
		return (1);
	if (check_rectangular(game->map, &game->map_width))
		return (1);
	game->map_height = count_height(game->map);
	return (0);
}

static int	count_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

static int	check_no_empty_lines(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i][0] == '\0')
			return (1);
		i++;
	}
	return (0);
}

static int	check_rectangular(char **map, int *width)
{
	int	i;
	int	w;

	w = ft_strlen(map[0]);
	i = 0;
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) != w)
			return (1);
		i++;
	}
	*width = w;
	return (0);
}
