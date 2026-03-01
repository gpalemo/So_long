/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 19:08:42 by cmauley           #+#    #+#             */
/*   Updated: 2026/03/01 17:46:44 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

/**
 * @brief ouvre le fichier et recup le fd
 */
int	open_map(char *path, int *fd)
{
	*fd = open(path, O_RDONLY);
	if (*fd < 0)
		return (1);
	return (0);
}

/**
 * @brief verifie que le fichier est bien un .ber
 */
int	verify_ber(char *path)
{
	int	len;

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