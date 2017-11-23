# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amehmeto <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/21 02:31:22 by amehmeto          #+#    #+#              #
#    Updated: 2017/11/23 05:48:15 by amehmeto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = fdf
FILE = main.c \
	   src/draw_line.c

OBJ = $(FILE:.c=.o)
CC = gcc
FLAGS = -Weverything -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	make -C minilibx_macos
	$(CC) $(FLAGS) -o $(NAME) $(notdir $(OBJ)) libft/libft.a minilibx_macos/libmlx.a  -I src -I minilibx_macos 

%.o: %.c src/fdf.h
	$(CC) -c $< $(FLAGS)

clean:
	make -C libft clean
	rm -f $(OBJ)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all
