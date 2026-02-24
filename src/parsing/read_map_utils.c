/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 19:27:29 by cmauley           #+#    #+#             */
/*   Updated: 2026/02/24 19:36:27 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

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
 * @brief lire tout le fichier dans une seule string
 */
int	read_file_to_string(int fd, char **out)
{
	char	*content;
	char	*line;

	content = ft_strdup("");
	if (!content)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		if (add_line(&content, line))
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
 * @brief split et stocke dans game->map
 *
 * @param game
 * @param content
 * @return int
 */
int	split_and_store(t_game *game, char *content)
{
	game->map = ft_split(content, '\n');
	free(content);
	if (!game->map || !game->map[0])
		return (1);
	return (0);
}
