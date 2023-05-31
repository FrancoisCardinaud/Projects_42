# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/01 20:46:11 by fcardina          #+#    #+#              #
#    Updated: 2023/05/31 15:55:06 by fcardina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= main.c init.c launcher.c utils.c

OBJS	= $(SRCS:.c=.o)

NAME	= philo

CC	= gcc

FLAGS	= -Wall -Wextra -Werror

INCLUDE	= -lpthread

HEADER	= philo.h

$(NAME): $(OBJS)
	$(CC) $(INCLUDE) $(FLAGS) -o $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $<  -o $(<:.c=.o)

all:	$(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

