# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/02 19:29:48 by fcardina          #+#    #+#              #
#    Updated: 2024/07/25 18:33:45 by fcardina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address #-DLOGS
INCLUDE = -I./includes
RM = rm -rf

GENERAL = Span

TARGET = ex01
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
	./$(TARGET)

noleaks: re clean
	@echo ""
	valgrind --leak-check=full -s ./$(TARGET)

.PHONY: all clean fclean re run noleaks

#.SILENT:
