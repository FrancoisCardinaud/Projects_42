# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: francoiscardinaud <marvin@42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/02 21:41:48 by francoiscardi     #+#    #+#              #
#    Updated: 2023/03/02 21:41:50 by francoiscardi    ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PROJECT
NAME	= push_swap
CC		= @clang
CFLAGS	= -Wall -Werror -Wextra
RM		= @rm -f
CLEAR	= @clear
FILE	= $(shell ls -l src/ | grep -F .c | wc -l)
CMP		= 1

#FILE
SRC	= ./src/push_swap.c\
	  ./src/lst_utils.c\
	  ./src/push.c\
	  ./src/radix_sort.c\
	  ./src/reverse.c\
	  ./src/rotate.c\
	  ./src/swap.c\
	  ./src/index.c\
	  ./src/simple_sort.c\
	  ./src/simple_sort_utils.c
OBJ	= $(SRC:.c=.o)

# LIBFT
PRINT_PATH	= ./printf/ft_printf --no-print-directory
PRINT_NAME	= ./printf/ft_printf/libftprintf.a

# COLOR #
GREEN	= \033[38;5;76m
RED		= \033[38;5;160m
YELLOW	= \033[38;5;226m
ORANGE	= \033[38;5;202m
PURPLE	= \033[38;5;213m
LBLUE	= \033[38;5;51m
BLUE	= \033[38;5;117m
INDI	= \033[38;5;99m
RESET	= \033[00m

# PRINT
RNBW	= @printf "\nPlease enter a series of non-repeating numbers as such: ./push_swap [nb1 nb1 nb3 ...]\n"

all: $(PRINT_NAME) $(NAME)

%.o: %.c
	@printf "\rCompiling                      \r"
	$(CC) $(CFLAGS) -c $< -o $@
	@$(eval CMP=$(shell echo $$(($(CMP)+1))))
	
$(PRINT_NAME):
	@make -C $(PRINT_PATH)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) $(PRINT_NAME) -o $(NAME)
	$(RNBW)

clean:
	@make clean -C $(PRINT_PATH)
	$(RM) $(OBJ)

fclean: clean
	@make fclean -C $(PRINT_PATH)
	$(RM) $(NAME)

re: fclean all

.PHONY: 
	all clean fclean re
