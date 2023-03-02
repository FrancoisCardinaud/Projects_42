# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: francoiscardinaud <marvin@42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/02 20:27:48 by francoiscardi     #+#    #+#              #
#    Updated: 2023/03/02 20:27:50 by francoiscardi    ###   ########.fr        #
#                                                                              #
# **************************************************************************** # 
 
# PROJECT
NAME	= libftprintf.a
CC		= @clang
CFLAGS	= -Wall -Werror -Wextra
RM		= @rm -f
CLEAR	= @clear
FILE	= $(shell ls -l src/ | grep -F .c | wc -l)
CMP		= 1

#FILE
SRC	= ./ft_printf/ft_printf.c
OBJ	= $(SRC:.c=.o)

# LIBFT
LIBFT_PATH	= ./libft --no-print-directory
LIBFT_NAME	= ./libft/libft.a

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
RNBW	= @printf "$(RED)Pri$(ORANGE)ntf $(YELLOW)libr$(GREEN)ary $(LBLUE)is r$(BLUE)ea$(INDI)dy $(PURPLE)to use$(RESET)\n"

all: $(LIBFT_NAME) $(NAME)

%.o: %.c
	@printf "\r$(LBLUE)[$(RESET)+$(LBLUE)] $(RESET)Adding $(GREEN)$<$(BLUE) [$(RESET)$(CMP)$(BLUE)/$(RESET)$(FILE)$(BLUE)]$(RESET)\n\r"
	$(CC) $(CFLAGS) -c $< -o $@
	@$(eval CMP=$(shell echo $$(($(CMP)+1))))
	
$(LIBFT_NAME):
	@make -C $(LIBFT_PATH)

$(NAME): $(OBJ) 
	@ar rcsT $(NAME) $(OBJ) $(LIBFT_NAME)
	$(RNBW)

clean:
	@make clean -C $(LIBFT_PATH)
	$(RM) $(OBJ)

fclean: clean
	@make fclean -C $(LIBFT_PATH)
	$(RM) $(NAME)

re: fclean all

.SILENT:
	all
.PHONY: 
	all libftmake clean fclean re
