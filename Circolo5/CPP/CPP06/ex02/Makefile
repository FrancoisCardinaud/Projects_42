# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/02 19:26:55 by fcardina          #+#    #+#              #
#    Updated: 2024/01/02 19:27:48 by fcardina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 #-fsanitize=address
INCLUDE = -I./includes
VPATH = srcs
RM = rm -rf

GENERAL = Base functions

NAME = realtype
SRCS = $(addsuffix .cpp, $(GENERAL))\
	   main.cpp

OBJ_DIR = obj
OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR):
	mkdir -p obj

$(OBJ_DIR)/%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

run: all clean
	@echo ""
	./$(NAME)

noleaks: re clean
	echo ""
	valgrind --leak-check=full -s ./$(NAME)

.PHONY: all clean fclean re run

#.SILENT: