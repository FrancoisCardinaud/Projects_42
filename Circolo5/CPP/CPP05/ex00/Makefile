# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/02 19:24:31 by fcardina          #+#    #+#              #
#    Updated: 2024/07/29 15:40:13 by fcardina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -O3 -Wshadow -Wno-shadow -fsanitize=address
INCLUDE = -I./includes
RM = rm -rf

TARGET = ex00
SRC = main.cpp Bureaucrat.cpp

OBJ_DIR = obj
OBJS = $(SRC:%.cpp=$(OBJ_DIR)/%.o)

all: $(TARGET)

$(TARGET): $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(TARGET)

re: fclean all

run: re clean
	echo ""
	./$(TARGET)

leaks: re clean
	echo ""
	valgrind --leak-check=full -s ./$(TARGET)

.PHONY: all clean fclean re run