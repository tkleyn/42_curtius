# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 16:38:24 by tkleynts          #+#    #+#              #
#    Updated: 2020/08/03 16:17:15 by tkleynts         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = cub3d
LIBFT = libft/libft.a
MLX = minilibx/libmlx.a
MLX_FLGS = -L minilibx -lmlx -framework OpenGL -framework AppKit
INCLUDES = includes/cub3d.h \
			includes/x_events.h \
			includes/keycode.h

SRC_PATH = src
SRC_NAME =	main.c \
			cub_pars.c \
			cub_map.c \
			cub_check.c \
			dda.c \
			move.c \
			set.c \
			events.c

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(INCLUDES) $(OBJS) $(LIBFT) $(MLX) 
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLGS) -o $(NAME)

$(LIBFT) : 
			make -C libft all

$(MLX) : 
			make -C minilibx all

clean :
			rm -f src/$(OBJS)

fclean :	clean
			rm -f $(NAME)

re: fclean all
