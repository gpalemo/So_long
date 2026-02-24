/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_ber.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 19:06:40 by cmauley           #+#    #+#             */
/*   Updated: 2026/02/24 19:23:57 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

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
