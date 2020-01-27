# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 16:38:24 by tkleynts          #+#    #+#              #
#    Updated: 2020/01/27 15:28:12 by tkleynts         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libft/libft.a
NAME = libftprintf.a
SRC =	ft_printf.c	conv_c.c conv_diux.c conv_p.c conv_s.c conv_pc.c flags.c flags_utils.c			
OBJS = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT) ft_printf.h
	cp $(LIBFT) $(NAME)
	ar rc $(NAME) $(LIBFT) $(OBJS)

%.o: %.c
	$(CC) $(CCFLAGS) -c -o $@ $<

$(LIBFT)	: 
			make -C libft all

clean 	:
			rm -f $(OBJS)
			make -C libft clean

fclean 	:	clean
			rm -f $(NAME)
			rm -f $(LIBFT)
			
re: fclean all
