/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 18:53:54 by cmauley           #+#    #+#             */
/*   Updated: 2026/03/01 18:12:19 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	free_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
/**
 * @brief libère la map, affiche l'erreur et retourne 1
 */
int	fail_map(t_game *g, char *msg)
{
	if (g->map)
		free_tab(g->map);
	g->map = NULL;
	return (write_error(msg));
}
