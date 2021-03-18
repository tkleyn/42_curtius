# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 16:38:24 by tkleynts          #+#    #+#              #
#    Updated: 2021/03/18 13:11:09 by tkleynts         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

P_PATH = push_swap_src
C_PATH = checker_src
BIN = push_swap checker

all : 
		@make -C $(P_PATH) all
		mv $(P_PATH)/push_swap .
		@make -C $(C_PATH) all
		mv $(C_PATH)/checker .

clean :
		@make -C $(P_PATH) clean
		@make -C $(C_PATH) clean

fclean :
		@make -C $(P_PATH) fclean
		@make -C $(C_PATH) fclean
		rm -rf $(BIN)

re: fclean all