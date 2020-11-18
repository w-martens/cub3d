# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: y4k_wm <y4k_wm@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/11 15:47:01 by y4k_wm        #+#    #+#                  #
#    Updated: 2020/11/11 17:02:38 by y4k_wm        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = gcc
# MLX_DIR = ./mlx
UTILS = ./utils


SRC =	map_parse.c\
		test.c\

OBJ = $(SRC:%.c=%.o)

# FLAGS = -Wall -Wextra -Werror -O3 #-fsanitize=address -g -fno-omit-frame-pointer

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(UTILS)
	$(CC) $^ ./utils/utils.a -o $(NAME)			

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
