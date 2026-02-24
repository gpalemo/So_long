/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 19:08:42 by cmauley           #+#    #+#             */
/*   Updated: 2026/02/24 19:10:03 by cmauley          ###   ########.fr       */
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
		return (write_error("Cannot open file"));
	return (0);
}
