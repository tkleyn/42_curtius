# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 16:38:24 by tkleynts          #+#    #+#              #
#    Updated: 2020/07/15 11:44:25 by tkleynts         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = cub3d
LIBFT = libft/libft.a
MLX = minilibx/libmlx.a
MLX_FLGS = -L minilibx -lmlx -framework OpenGL -framework AppKit

SRC = main.c cub_load.c map.c check_file.c dda.c

OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT) $(MLX) cub3d.h
			$(CC)  $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLGS) -o $(NAME)

$(LIBFT) : 
			make -C libft all

$(MLX) : 
			make -C minilibx all

clean :
			rm -f $(OBJS)

fclean :	clean
			rm -f $(NAME)

re: fclean all
