# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 16:38:24 by tkleynts          #+#    #+#              #
#    Updated: 2019/11/23 13:30:40 by tkleynts         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libft/libft.a
NAME = libftprintf.a
SRC =	ft_printf.c					
OBJS = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT) ft_printf.h
			ar -rc $(NAME) $(OBJS) $(LIBFT)

$(LIBFT)	: 
			make -C libft all

clean 	:
			rm -f $(OBJS)
			make -C libft clean

fclean 	:	clean
			rm -f $(NAME)
			rm -f $(LIBFT)
			
re: fclean all
