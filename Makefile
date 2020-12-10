# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: y4k_wm <y4k_wm@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/11 15:47:01 by y4k_wm        #+#    #+#                  #
#    Updated: 2020/12/03 22:16:40 by wmartens      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = gcc
MLX_LIN = ./mlx_linux
MLX_OSX = ./mlx
UTILS = ./utils


SRC =	map_parse.c\
		test.c\

OBJ = $(SRC:%.c=%.o)

FLAGS = -Wall -Wextra -Werror -fsanitize=address -g #-fno-omit-frame-pointer

all: $(NAME)
$(NAME): $(OBJ)
	make -C $(MLX_OSX)
	make -C $(UTILS)
	# $(CC) $^ ./utils/utils.a -o $(NAME) $(FLAGS)
	$(CC) $^ ./utils/utils.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(FLAGS)	
# ifeq ($(shell uname), Linux)
# 	$(NAME): $(OBJ)
# 		make -C $(MLX_LIN)
# 		make -C $(UTILS)
# 		$(CC) $^ ./utils/utils.a -lbsd -lmlx -lXext -lX11 -o $(NAME) $(FLAGS)
# else	
	# $(NAME): $(OBJ)
	# 	make -C $(MLX_OSX)
	# 	make -C $(UTILS)
	# 	$(CC) $^ ./utils/utils.a -lbsd -lmlx_osx -lXext -lX11 -o $(NAME) $(FLAGS)
# endif

# %.o: %.c
# 	$(CC) -c $< -o $@

# debug: $(NAME)

# $(NAME): $(OBJ)
# 	make -C $(UTILS)
# 	$(CC) -g $^ ./utils/utils.a -o $(NAME) $(FLAGS)

clean:
	# make clean -C $(MLX_DIR)
	make clean -C $(UTILS)
	rm -f $(OBJ)
	# rm -f screenshot.bmp

fclean: clean
	rm -f $(NAME)

re: fclean all
