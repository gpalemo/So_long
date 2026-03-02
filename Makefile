# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/23 22:04:08 by cmauley           #+#    #+#              #
#    Updated: 2026/03/02 23:02:10 by cmauley          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

# ----- Includes -----
INC			= -I include -I libft -I ft_printf/include \
			  -I get_next_line -I minilibx-linux

# ----- Libraries -----
LIBFT		= libft/libft.a
LIBPRINTF	= ft_printf/libftprintf.a
LIBMLX		= minilibx-linux/libmlx_Linux.a

# ----- Sources -----
SRC			=	src/main.c \
				src/parsing/check_path.c \
				src/parsing/find_player.c \
				src/parsing/open_map.c \
				src/parsing/parse.c \
				src/parsing/read_map.c \
				src/parsing/validate_elements.c \
				src/parsing/validate_shape.c \
					src/utils/destroy.c \
				src/utils/free_utils.c \
				src/utils/write_error.c \
					src/mlx/keys.c \
				src/mlx/load_textures.c \
				src/mlx/mlx_init.c \
				src/mlx/moves.c \
				src/mlx/render.c \
				get_next_line/get_next_line.c \
				get_next_line/get_next_line_utils.c

OBJ_DIR		= obj
OBJ			= $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

# ----- Link flags -----
LDFLAGS		= -L ft_printf -lftprintf -L libft -lft \
			  -L minilibx-linux -lmlx_Linux -lX11 -lXext

# ==================== Rules ====================

all: $(NAME)

$(NAME): $(LIBFT) $(LIBPRINTF) $(LIBMLX) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@


$(LIBFT):
	$(MAKE) -C libft

$(LIBPRINTF):
	$(MAKE) -C ft_printf

$(LIBMLX):
	$(MAKE) -C minilibx-linux


clean:
	$(RM) -r $(OBJ_DIR)
	$(MAKE) -C libft clean
	$(MAKE) -C ft_printf clean
	$(MAKE) -C minilibx-linux clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C libft fclean
	$(MAKE) -C ft_printf fclean

re: fclean all

.PHONY: all clean fclean re

