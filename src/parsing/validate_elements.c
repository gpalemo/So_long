/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_elements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 16:50:49 by cmauley           #+#    #+#             */
/*   Updated: 2026/03/01 21:41:51 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static int	count_nb_char(char **map, char c);
static int	map_wall_check(char *line);

/**
 * @brief vérifie que la map ne contient que les caractères autorisés (0,1,C,E,P)
 */
int	check_char(char **map)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] != '0' && map[j][i] != '1'
				&& map[j][i] != 'C' && map[j][i] != 'E'
				&& map[j][i] != 'P')
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

/**
 * @brief vérifie qu'il y a exactement 1P, 1E et au moins 1C et stocke le compte
 */
int	check_nb_char_and_stock_coll(t_game *game)
{
	int	c_count;

	if (count_nb_char(game->map, 'P') != 1)
		return (1);
	if (count_nb_char(game->map, 'E') != 1)
		return (1);
	c_count = count_nb_char(game->map, 'C');
	if (c_count < 1)
		return (1);
	game->collectibles_total = c_count;
	game->collectibles_left = c_count;
	return (0);
}

/**
 * @brief compte le nombre de caractères c dans la map
 */
static int	count_nb_char(char **map, char c)
{
	int	i;
	int	j;
	int	nb;

	nb = 0;
	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == c)
				nb++;
			i++;
		}
		j++;
	}
	return (nb);
}

/**
 * @brief vérifie que la map est entourée de murs
 */
int	wall_check(char **map)
{
	int	j;
	int	len;

	len = ft_strlen(map[0]) - 1;
	j = 1;
	if (map_wall_check(map[0]) == 1)
		return (1);
	while (map[j + 1])
	{
		if (map[j][0] != '1' || map[j][len] != '1')
			return (1);
		j++;
	}
	if (map_wall_check(map[j]) == 1)
		return (1);
	return (0);
}

/**
 * @brief vérifie qu'une ligne entière ne contient que des '1'
 */
static int	map_wall_check(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			return (1);
		i++;
	}
	return (0);
}
