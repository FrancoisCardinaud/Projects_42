# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/02 19:26:17 by fcardina          #+#    #+#              #
#    Updated: 2024/10/10 16:46:14 by fcardina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
INCLUDE = -I./includes
RM = rm -rf

TARGET = convert
SRC = ScalarConverter.cpp main.cpp

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

run: all clean
	@echo ""
	@echo "TEST 1"
	./$(TARGET) 0
	@echo ""
	@echo "TEST 2"
	./$(TARGET) nan
	@echo ""
	@echo "TEST 3"
	./$(TARGET) 42.0f

leaks: re clean
	@echo ""
	valgrind --leak-check=full -s ./$(TARGET)

.PHONY: all clean fclean re run noleaks

#.SILENT:
