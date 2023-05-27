# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/01 20:46:11 by fcardina          #+#    #+#              #
#    Updated: 2023/05/25 16:18:53 by fcardina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= main.c

SRCS	+= error.c init.c utils.c launcher.c

OBJS	= $(SRCS:.c=.o)

NAME	= philo

CLANG	= clang

FLAGS	= -Wall -Wextra -Werror

INCLUDE	= -lpthread

HEADER	= philo.h

$(NAME): $(OBJS)
	$(CLANG) $(INCLUDE) $(FLAGS) -o $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CLANG) $(FLAGS) -c $<  -o $(<:.c=.o)

all:	$(NAME)

clean:
	rm -f $(OBJS) $(B_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

