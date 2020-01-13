# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 16:38:24 by tkleynts          #+#    #+#              #
#    Updated: 2020/01/13 16:35:41 by tkleynts         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC =	ft_isalnum.c		ft_memccpy.c		ft_memset.c						\
		ft_putnbr_fd.c		ft_strcpy.c			ft_strlen.c					 	\
		ft_putchar.c		ft_putstr.c			ft_strdup.c						\
		ft_substr.c			ft_atoi.c			ft_isascii.c					\
		ft_putchar_fd.c		ft_putstr_fd.c		ft_strjoin.c		 			\
		ft_tolower.c		ft_bzero.c			ft_isdigit.c		 			\
		ft_putendl_fd.c		ft_strcat.c			ft_strlcat.c					\
		ft_strnstr.c		ft_toupper.c		ft_isprint.c					\
		ft_memmove.c		ft_putnbr.c			ft_strchr.c						\
		ft_strlcpy.c		ft_strrchr.c		ft_strmapi.c					\
		ft_itoa.c			ft_split.c			ft_strtrim.c					\
		ft_memchr.c			ft_isalpha.c		ft_strncmp.c					\
		ft_memcmp.c			ft_strndup.c		ft_memcpy.c						\
		ft_calloc.c																\
		ft_lstadd_back_bonus.c					ft_lstadd_front_bonus.c			\
		ft_lstclear_bonus.c						ft_lstdelone_bonus.c			\
		ft_lstiter_bonus.c						ft_lstlast_bonus.c				\
		ft_lstmap_bonus.c						ft_lstnew_bonus.c				\
		ft_lstsize_bonus.c														\
		ft_strjoin2.c		ft_strnjoin2.c		ft_utoa.c						\
		itohex.c			ptohex.c			ft_strncpy.c

OBJS = $(SRC:.c=.o)
B_OBJS = $(B_SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

bonus : $(OBJS) $(B_OBJS) libft.h
			ar -rc $(NAME) $(OBJS) $(B_OBJS)

$(NAME) : $(OBJS) libft.h
			ar -rc $(NAME) $(OBJS)

clean :
			rm -f $(OBJS) $(B_OBJS)

fclean :	clean
			rm -f $(NAME)

re: fclean all
