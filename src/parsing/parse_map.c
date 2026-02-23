/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 22:41:47 by cmauley           #+#    #+#             */
/*   Updated: 2026/02/24 00:04:38 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

// read (GNL)
// stocker
// transformer en char **

int	verify_ber(char *path)
{
	int len;

	if (!path)
		return (write_error("Invalid file path"));
	len = ft_strlen(path);
	if (len < 5)
		return (write_error("Map must end with .ber"));
	if (path[len - 4] != '.' 
		|| path[len - 3] != 'b'
		|| path[len - 2] != 'e'
		|| path[len - 1] != 'r')
		return (write_error("Map must have .ber extension"));
	return (0);
}

int	open_map(char *path, int *fd)
{
	*fd = open(path, O_RDONLY);
	if (*fd < 0)
		return (write_error("Cannot open file"));
	return (0);
}

int	read_map(int fd, t_game *game)
{
	t_line	*head;
	
}