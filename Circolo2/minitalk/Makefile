# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: francoiscardinaud <marvin@42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 02:34:17 by francoiscardi     #+#    #+#              #
#    Updated: 2023/02/22 02:40:58 by francoiscardi    ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER   = server

CLIENT   = client

LIB	 = -L./libft -lft

LIBFT	 = libft.a

CC	 = gcc

FLAGS    = -Wall -Werror -Wextra

all : $(LIBFT) $(SERVER) $(CLIENT)

$(LIBFT) : 
	@make -C libft

$(SERVER) : server.o minitalk.h
	@$(CC) server.o $(LIB) -o $@
	@printf "\e[38;5;226m./$@ successfully build\e[0m\n"

$(CLIENT) : client.o minitalk.h
	@$(CC) client.o $(LIB) -o $@
	@printf "\e[38;5;46m./$@ successfully build\e[0m\n"

%.o : %.c
	@$(CC) $(FLAGS) $< -c -I includes

clean :
	@make clean -C libft
	@rm -f *.o
	@printf "\e[38;5;200mObject files deleted\e[0m\n"

fclean: clean
	@make fclean -C libft
	@rm -f $(SERVER) $(CLIENT)
	@printf "\e[38;5;200mBinaries deleted\e[0m\n"

re: fclean all
