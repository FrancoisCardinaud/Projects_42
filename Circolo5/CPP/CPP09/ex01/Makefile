# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/02 19:30:53 by fcardina          #+#    #+#              #
#    Updated: 2024/07/25 18:35:43 by fcardina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address #-DLOGS
INCLUDE = -I./includes
RM = rm -rf

GENERAL = RPN

TARGET = RPN
SRCS = $(addsuffix .cpp, $(GENERAL))\
		main.cpp

OBJ_DIR = obj
OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

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
	./$(TARGET) "8 9 * 9 - 9 - 9 - 4 - 1 +"
	@echo ""
	@echo "TEST 2"
	./$(TARGET) "7 7 * 7 -"
	@echo ""
	@echo "TEST 3"
	./$(TARGET) "1 2 * 2 / 2 * 2 4 - +"
	@echo ""
	@echo "TEST 4"
	./$(TARGET) "1 0 /"
	@echo ""
	@echo "TEST 5"
	./$(TARGET) "3 3 * 9 / 1"
	@echo ""
	@echo "TEST 6"
	./$(TARGET) "(1 + 1)"

noleaks: re clean
	echo ""
	valgrind --leak-check=full -s ./$(TARGET)

.PHONY: all clean fclean re run noleaks

#.SILENT:
