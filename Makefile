# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/16 12:18:47 by tkleynts          #+#    #+#              #
#    Updated: 2021/06/16 12:23:41 by tkleynts         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME = philo

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I. -I./inc -pthread

INCLUDES = inc/philo.h

SRC_PATH = srcs

SRC_NAME =	philo.c \
			lst.c \
			utils.c \
			life.c 

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(INCLUDES) $(OBJS)
			@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
			@printf "\r\033[48;5;15;30m✅ $(NAME)\033[0m\033[K\n"
			
clean :
			@rm -f $(OBJS)

fclean :	clean
			@rm -f $(NAME)

re: fclean all