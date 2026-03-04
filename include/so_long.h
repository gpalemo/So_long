/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 22:07:13 by cmauley           #+#    #+#             */
/*   Updated: 2026/03/04 01:27:48 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TILE 64

# define DIR_DOWN 0
# define DIR_UP 1
# define DIR_LEFT 2
# define DIR_RIGHT 3

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "../ft_printf/include/ft_printf.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>

typedef struct s_img
{
	void	*img;
	int		w;
	int		h;
}			t_img;

typedef struct s_textures
{
	t_img	floor;
	t_img	wall;
	t_img	player_d;
	t_img	player_u;
	t_img	player_l;
	t_img	player_r;
	t_img	exit;
	t_img	collec;
}			t_textures;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	int			map_width;
	int			map_height;
	int			px;
	int			py;
	int			moves;
	int			collectibles_total;
	int			collectibles_left;
	int			dir;
	t_textures	tex;
}				t_game;

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
int		clean_exit(t_game *game, int status);
int		handle_close(t_game *game);

// ====== MLX ======
int		init_mlx(t_game *game);
int		load_textures(t_game *game);
void	render_map(t_game *game);
int		handle_key(int keycode, t_game *game);
void	move_player(t_game *game, int dx, int dy);

#endif
