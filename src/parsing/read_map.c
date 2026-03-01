/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 19:02:43 by cmauley           #+#    #+#             */
/*   Updated: 2026/03/01 21:40:43 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static int	add_line(char **content, char *line);
static int	read_file_to_string(int fd, char **out);
static int	split_and_store(t_game *game, char *content);

/**
 * @brief lit le fd, découpe en tableau de lignes et valide la forme
 */
int	read_map(int fd, t_game *game)
{
	char	*content;

	game->map = NULL;
	if (read_file_to_string(fd, &content) == 1)
		return (write_error("Empty map or read failed"));
	if (split_and_store(game, content) == 1)
		return (write_error("Split failed"));
	if (validate_shape(game) == 1)
	{
		free_tab(game->map);
		game->map = NULL;
		return (write_error("Invalid map shape"));
	}
	return (0);
}

/**
 * @brief lire tout le fichier dans une seule string
 */
static int	read_file_to_string(int fd, char **out)
{
	char	*content;
	char	*line;

	content = ft_strdup("");
	if (!content)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		if (add_line(&content, line) == 1)
			return (free(content), close(fd), 1);
		line = get_next_line(fd);
	}
	close(fd);
	if (content[0] == '\0')
		return (free(content), 1);
	*out = content;
	return (0);
}

/**
 * @brief prend la ligne lue, l’ajoute et nettoie la
 * mémoire (juste pour gagner de la place dans read_file_to_string)
 */
static int	add_line(char **content, char *line)
{
	char	*tmp;

	tmp = ft_strjoin(*content, line);
	free(*content);
	free(line);
	if (!tmp)
		return (1);
	*content = tmp;
	return (0);
}

/**
 * @brief split et stocke dans game->map
 */
static int	split_and_store(t_game *game, char *content)
{
	game->map = ft_split(content, '\n');
	free(content);
	if (!game->map || !game->map[0])
		return (1);
	return (0);
}
