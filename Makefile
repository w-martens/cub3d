# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: y4k_wm <y4k_wm@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/11 15:47:01 by y4k_wm        #+#    #+#                  #
#    Updated: 2020/11/21 15:06:12 by y4k_wm        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = gcc
MLX_DIR = ./mlx
UTILS = ./utils


SRC =	map_parse.c\
		test.c\

OBJ = $(SRC:%.c=%.o)

# FLAGS = -Wall -Wextra -Werror -O3 #-fsanitize=address -g -fno-omit-frame-pointer

all: $(NAME)

ifeq ($(shell uname), Linux)
	$(NAME): $(OBJ)
		make -C $(MLX_DIR)
		make -C $(UTILS)
		$(CC) $^ ./utils/utils.a -lbsd -lmlx -lXext -lX11 -o $(NAME)
else	
	$(NAME): $(OBJ)
		make -C $(MLX_DIR)
		make -C $(UTILS)
		$(CC) $^ ./utils/utils.a -lbsd -lmlx -lXext -lX11 -o $(NAME)
endif
%.o: %.c
	$(CC) -c $< -o $@

debug: $(NAME)

$(NAME): $(OBJ)
	make -C $(UTILS)
	$(CC) -g $^ ./utils/utils.a -o $(NAME)
	
clean:
	# make clean -C $(MLX_DIR)
	make clean -C $(UTILS)
	rm -f $(OBJ)
	# rm -f screenshot.bmp

fclean: clean
	rm -f $(NAME)

re: fclean all
