/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 22:07:13 by cmauley           #+#    #+#             */
/*   Updated: 2026/03/01 22:00:58 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef TILE
#  define TILE 64
# endif

# include "../libft/libft.h"
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
	int		px;
	int		py;
	int		moves;
	int		collectibles_total;
	int		collectibles_left;
}			t_game;

// ====== PARSING ======
int		parse(t_game *game, char *path);

// --- file ---
int		verify_ber(char *path);
int		open_map(char *path, int *fd);

// --- read ---
int		read_map(int fd, t_game *game);

// --- validate ---
int		validate_shape(t_game *game);
int		check_char(char **map);
int		wall_check(char **map);
int		check_nb_char_and_stock_coll(t_game *game);
int		find_player(t_game *game);
int		check_path(t_game *game);

// ====== UTILS ======
void	free_tab(char **tab);
int		write_error(char *msg);
int		fail_map(t_game *g, char *msg);

#endif
