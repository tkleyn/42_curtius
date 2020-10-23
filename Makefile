# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 16:38:24 by tkleynts          #+#    #+#              #
#    Updated: 2020/10/23 14:43:50 by tkleynts         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I. -I./includes
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
			events.c \
			bmp_export.c \
			draw.c	\
			sprites.c \
			cub_exit.c \
			cub_split.c

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(INCLUDES) $(OBJS) $(LIBFT) $(MLX)
			@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLGS) -o $(NAME)
			@printf "\r\033[48;5;15;30m✅ $(NAME)\033[0m\033[K\n"

$(LIBFT) : 
			@make -C libft all

$(MLX) : 
			@make -C minilibx all

clean :
			@rm -f src/$(OBJS)
			@printf "\r\033[48;5;15;30m✅ clean\033[0m\033[K\n"

fclean :	clean
			@rm -f $(NAME)

re: fclean all
