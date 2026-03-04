/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 17:56:53 by cmauley           #+#    #+#             */
/*   Updated: 2026/03/04 01:39:54 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static char	**copy_map(t_game *game);
static void	flood_fill(t_game *game, char **copy, int y, int x);

/**
 * @brief vérifie qu'un chemin valide relie le joueur à toutes 
 * les collec. et à la sortie
 */
int	check_path(t_game *game)
{
	char	**copy;
	int		i;
	int		y;

	y = 0;
	copy = copy_map(game);
	if (!copy)
		return (1);
	flood_fill(game, copy, game->py, game->px);
	while (copy[y])
	{
		i = 0;
		while (copy[y][i])
		{
			if (copy[y][i] == 'C' || copy[y][i] == 'E')
			{
				free_tab(copy);
				return (1);
			}
			i++;
		}
		y++;
	}
	free_tab(copy);
	return (0);
}

/**
 * @brief alloue et retourne une copie de la map pour flood fill
 */
static char	**copy_map(t_game *game)
{
	char	**cpy;
	int		y;

	y = 0;
	cpy = malloc(sizeof(char *) * (game->map_height + 1));
	if (!cpy)
		return (NULL);
	while (y < game->map_height)
	{
		cpy[y] = ft_strdup(game->map[y]);
		if (!cpy[y])
		{
			while (y > 0)
			{
				free(cpy[y]);
				--y;
			}
			free(cpy);
			return (NULL);
		}
		y++;
	}
	cpy[y] = NULL;
	return (cpy);
}

/**
 * @brief remplit récursivement les cases accessibles depuis (y,x) avec '.'
 */
static void	flood_fill(t_game *game, char **copy, int y, int x)
{
	if (x < 0 || y < 0 || x >= game->map_width || y >= game->map_height)
		return ;
	if (copy[y][x] == 'E')
		copy[y][x] = '1';
	if (copy[y][x] == '1')
		return ;
	if (copy[y][x] == '.')
		return ;
	else
	{
		copy[y][x] = '.';
		flood_fill(game, copy, y + 1, x);
		flood_fill(game, copy, y - 1, x);
		flood_fill(game, copy, y, x + 1);
		flood_fill(game, copy, y, x - 1);
	}
}
