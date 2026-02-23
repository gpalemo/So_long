/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 22:07:13 by cmauley           #+#    #+#             */
/*   Updated: 2026/02/24 00:15:51 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef TILE
# define TILE 64
# endif

# include "../libft/include/libft.h"
# include "../get_next_line/get_next_line.h"
# include "../ft_printf/include/ft_printf.h"
# include <fcntl.h>

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		map_width;
	int		map_height;
	int		player_x;
	int		player_y;
	int		moves;
	int		collectibles_total;
	int		collectibles_left;
}			t_game;

// ====== PARSING ======
int	write_error(char *msg);
int	verify_ber(char *path);
int	open_map(char *path, int *fd);
int	read_map(int fd, t_game *g);

#endif