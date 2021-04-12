# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 16:38:24 by tkleynts          #+#    #+#              #
#    Updated: 2021/04/12 11:09:43 by tkleynts         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME = push_swap

LIBFT_PATH = ../libft/
LIBFT = $(LIBFT_PATH)libft.a

INCLUDES = inc/push_swap.h

COMMONS_PATH = ../commons
COMMONS_INC = $(COMMONS_PATH)/inc/
COMMONS_SRC_PATH = $(COMMONS_PATH)/src
COMMONS_NAME = instr_push.c \
			instr_rotate.c \
			instr_rrotate.c \
			instr_swap.c \
			offset.c \
			utils.c

COMMONS_SRC = $(addprefix $(COMMONS_SRC_PATH)/,$(COMMONS_NAME))
COMMONS_OBJS = $(COMMONS_SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I. -I./inc -I$(LIBFT_PATH) -I$(COMMONS_INC)

SRC_PATH = src
SRC_NAME =	push_swap.c

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(INCLUDES) $(COMMONS_OBJS) $(OBJS) $(LIBFT)
			@$(CC) $(CFLAGS) $(COMMONS_OBJS) $(OBJS) $(LIBFT) -o $(NAME)
			@printf "\r\033[48;5;15;30m✅ $(NAME)\033[0m\033[K\n"

$(LIBFT) : 
			@make -C $(LIBFT_PATH) all
			
clean :
			@rm -f $(OBJS)
			@rm -f $(COMMONS_OBJS)

fclean :	clean
			@rm -f $(NAME)

re: fclean all