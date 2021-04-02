# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 16:38:24 by tkleynts          #+#    #+#              #
#    Updated: 2021/04/02 15:16:16 by tkleynts         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME = checker

LIBFT_PATH = ../libft/
LIBFT = $(LIBFT_PATH)libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I. -I./inc -I$(LIBFT_PATH)

INCLUDES = inc/checker.h

SRC_PATH = src
SRC_NAME =	checker.c instr_push.c instr_rotate.c instr_rrotate.c instr_swap.c lst.c offset.c utils.c

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(INCLUDES) $(OBJS) $(LIBFT)
			@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
			@printf "\r\033[48;5;15;30m✅ $(NAME)\033[0m\033[K\n"

$(LIBFT) : 
			@make -C libft all
			
clean :
			@rm -f src/$(OBJS)

fclean :	clean
			@rm -f $(NAME)

re: fclean all