/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 22:59:44 by cmauley           #+#    #+#             */
/*   Updated: 2026/03/01 21:34:05 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

/**
 * @brief affiche "Error\n" suivi du message et retourne 1
 */
int	write_error(char *msg)
{
	ft_printf("Error\n%s\n", msg);
	return (1);
}
