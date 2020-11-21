# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: wmartens <wmartens@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/11/14 22:13:59 by wmartens      #+#    #+#                  #
#    Updated: 2020/11/20 15:04:45 by y4k_wm        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = utils.a
HEAD = utils.h

OBJ =	ft_atoi.o\
		ft_strcmp.o\
		ft_split.o\
		ft_strdup.o\
		ft_strlen.o\
		ft_substr.o\
		get_next_line_utils.o\
		get_next_line.o\
		ft_strnljoin.o\

FLAGS = -Wall -Wextra -Werror -g
# -D BUFFER_SIZE=1000

all: $(NAME)

$(NAME): $(OBJ)
		ar rcs $@ $^ 
		ranlib $(NAME)
		# $(FLAGS) 

%.o: %.c
		$(CC) -c -o $@ $< -I.

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all