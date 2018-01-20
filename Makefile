# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amehmeto <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/21 02:31:22 by amehmeto          #+#    #+#              #
#    Updated: 2018/01/20 00:28:53 by amehmeto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = fdf
FILE = src/main.c \
	   src/draw_line.c \
	   src/map_parser.c \
	   src/points_adjustment.c \
	   src/is_ok.c \
	   src/free_in_mass.c

OBJ = $(FILE:.c=.o)
CC = gcc
FLAGS = -g -Weverything -lmlx -framework OpenGL -framework AppKit
#FLAGS = -g -Weverything -lmlx -framework OpenGL -framework AppKit \
 -O1 -g -fsanitize=address	\
 -fno-omit-frame-pointer		\
 -fsanitize-address-use-after-scope \


all: $(NAME)

$(NAME): $(OBJ)
	make -C ../Libft
	make -C minilibx_macos
	$(CC) $(FLAGS) -o $(NAME) $(notdir $(OBJ)) ../Libft/libft.a minilibx_macos/libmlx.a  -I src -I minilibx_macos

%.o: %.c src/fdf.h
	$(CC) -c $< $(FLAGS)

clean:
	make -C ../Libft clean
	rm -f $(OBJ)

fclean: clean
	make -C ../Libft fclean
	rm -f $(NAME)

re: fclean all
