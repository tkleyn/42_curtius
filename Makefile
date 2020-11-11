# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/04 15:08:29 by tkleynts          #+#    #+#              #
#    Updated: 2020/11/11 13:17:29 by tkleynts         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ASM			=	nasm
ASMFLAGS	=	-f macho64
NAME		=	libasm.a
SRC			= 	ft_strlen.s	ft_strcmp.s ft_strcpy.s ft_strdup.s ft_read.s ft_write.s
MAIN		=	main.c
CC			=	gcc
CCFLAGS		=	-Wall -Wextra -Werror

OBJS		=	$(SRC:.s=.o)

%.o:	%.s
	$(ASM) $(ASMFLAGS) -o $@ $<

all:	$(NAME)

$(NAME): $(OBJS) libasm.h
		ar rc $(NAME) $(OBJS)
		$(CC) $(MAIN) $(NAME) -o libasm

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all