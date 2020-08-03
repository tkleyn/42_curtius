# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 16:38:24 by tkleynts          #+#    #+#              #
#    Updated: 2020/08/03 15:36:18 by tkleynts         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

F = frintf/
M = Mem/
O = Other/
S = Str/
C = Conv/
G = GNL/

HEADERS = libft.h $(F)frintf.h

M_SRC =	$(M)ft_memcpy.c		$(M)ft_memccpy.c	$(M)ft_memchr.c		$(M)ft_memcmp.c			\
		$(M)ft_memset.c		$(M)ft_memmove.c	$(M)ft_calloc.c		$(M)ft_bzero.c			
																			
O_SRC =	$(O)ft_isalnum.c	$(O)ft_isdigit.c	$(O)ft_isascii.c	$(O)ft_isprint.c		\
		$(O)ft_isalpha.c	$(O)ft_tolower.c	$(O)ft_toupper.c	$(O)ft_isspace.c		\
		$(O)is_str_digit.c

																											
S_SRC =	$(S)ft_strcpy.c		$(S)ft_strlen.c		$(S)ft_strndup.c	$(S)ft_strdup.c			\
		$(S)ft_strjoin2.c	$(S)ft_strnjoin2.c	$(S)ft_substr.c		$(S)ft_strjoin.c		\
		$(S)ft_strcat.c		$(S)ft_strlcat.c	$(S)ft_strnstr.c	$(S)ft_strlcpy.c		\
		$(S)ft_strrchr.c	$(S)ft_strmapi.c	$(S)ft_strtrim.c	$(S)ft_split.c			\
		$(S)ft_strncmp.c	$(S)ft_strchr.c		$(S)ft_strncpy.c	$(S)ft_strnjoin.c		\
		$(S)split_space.c	$(S)rm_spaces.c
																		
C_SRC =	$(C)ft_atoi.c		$(C)ft_itoa.c		$(C)ft_utoa.c		$(C)ft_itohex.c			\
		$(C)ft_ptohex.c		$(C)ft_bswap.c														
																			
G_SRC = $(G)ft_gnl.c

F_SRC = $(F)frintf.c		$(F)conv_c.c		$(F)conv_diux.c		$(F)conv_p.c			\
		$(F)conv_s.c		$(F)conv_pc.c		$(F)flags.c			$(F)flags_utils.c		\
		$(F)ffrintf.c

M_OBJS = $(M_SRC:.c=.o)
O_OBJS = $(O_SRC:.c=.o)
S_OBJS = $(S_SRC:.c=.o)
C_OBJS = $(C_SRC:.c=.o)
G_OBJS = $(G_SRC:.c=.o)
F_OBJS = $(F_SRC:.c=.o)

OBJS = $(M_OBJS) $(O_OBJS) $(S_OBJS) $(C_OBJS) $(G_OBJS) $(F_OBJS)

all : $(NAME)

$(NAME) : $(OBJS) $(HEADERS)
			ar -rc $(NAME) $(OBJS)

clean :
			rm -f $(OBJS)

fclean :	clean
			rm -f $(NAME)

re: fclean all
