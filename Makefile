# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 16:38:24 by tkleynts          #+#    #+#              #
#    Updated: 2020/02/04 20:07:11 by tkleynts         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

F = frintf/

SRC =	ft_memcpy.c		ft_memccpy.c	ft_memchr.c		ft_memcmp.c			\
		ft_memset.c		ft_memmove.c	ft_calloc.c		ft_bzero.c			\
																			\
		ft_isalnum.c	ft_isdigit.c	ft_isascii.c	ft_isprint.c		\
		ft_isalpha.c														\
																			\
		ft_strcpy.c		ft_strlen.c		ft_strndup.c	ft_strdup.c			\
		ft_strjoin2.c	ft_strnjoin2.c	ft_substr.c		ft_strjoin.c		\
		ft_strcat.c		ft_strlcat.c	ft_strnstr.c	ft_strlcpy.c		\
		ft_strrchr.c	ft_strmapi.c	ft_strtrim.c	ft_split.c			\
		ft_strncmp.c	ft_strchr.c		ft_strncpy.c	ft_strnjoin.c		\
																			\
		ft_atoi.c		ft_itoa.c		ft_utoa.c		itohex.c			\
		ptohex.c															\
																			\
		ft_tolower.c	ft_toupper.c										\
																			\
		ft_putnbr_fd.c	ft_putendl_fd.c	ft_putnbr.c	ft_putchar_fd.c			\
		ft_putchar.c		ft_putstr.c		ft_putstr_fd.c					\
																			\
		ft_lstadd_back.c	ft_lstadd_front.c	ft_lstclear.c		ft_lstdelone.c	\
		ft_lstiter.c		ft_lstlast.c		ft_lstmap.c			ft_lstnew.c		\
		ft_lstsize.c					


F_SRC = 	$(F)frintf.c		$(F)conv_c.c									\
			$(F)conv_diux.c		$(F)conv_p.c									\
			$(F)conv_s.c		$(F)conv_pc.c									\
			$(F)flags.c			$(F)flags_utils.c				


OBJS = $(SRC:.c=.o)
F_OBJS = $(F_SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS) $(F_OBJS) libft.h $(F)frintf.h
			ar -rc $(NAME) $(OBJS) $(F_OBJS)

clean :
			rm -f $(OBJS) $(F_OBJS)

fclean :	clean
			rm -f $(NAME)

re: fclean all
