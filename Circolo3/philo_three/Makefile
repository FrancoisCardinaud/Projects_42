# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/01 20:46:11 by fcardina          #+#    #+#              #
#    Updated: 2023/05/02 15:38:23 by fcardina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= main.c

SRCS	+= error_manager.c init.c utils.c launcher.c

OBJS	= $(SRCS:.c=.o)

NAME	= philo_three

CLANG	= clang

FLAGS	= -Wall -Wextra -Werror

INCLUDE	= -lpthread

HEADER	= philo.h

$(NAME): $(OBJS)
	$(CLANG) $(INCLUDE) $(FLAGS) -o $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CLANG) $(FLAGS) -c $<  -o $(<:.c=.o)

all:	$(NAME)

.PHONY:	clean fclean re bonus bench bclean

clean:
	rm -f $(OBJS) $(B_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

