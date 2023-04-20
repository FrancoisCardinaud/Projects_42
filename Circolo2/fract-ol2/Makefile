# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 12:18:57 by fcardina          #+#    #+#              #
#    Updated: 2023/04/20 16:30:20 by fcardina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC_PATH = srcs
SRC_NAME = burningship.c julia.c keyboard.c main.c mandelbrot.c mouse.c tools.c 

OBJ_PATH = objs
OBJ_NAME = $(SRC_NAME:.c=.o)

CC = clang
CFLAGS = -Wall -Werror -Wextra

CPPFLAGS = -I includes -I libft/includes

LDFLAGS = -L libft
LDLIBS = -O2 -lft -lm -lmlx -framework OpenGL -framework AppKit

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@
	@echo "Compilation:	\033[38;5;46mOK\033[m"
	@printf "\e[38;5;46mHow to use:\e[0m\n"
	@printf "\e[38;5;46mEsc or close button -> close program\e[0m\n"
	@printf "\e[38;5;46mSpace -> reset fractal\e[0m\n"
	@printf "\e[38;5;46mClick or wheel -> zoom\e[0m\n"
	@printf "\e[38;5;46mArrow Up -> move image up\e[0m\n"
	@printf "\e[38;5;46mArrow Down -> move image down\e[0m\n"
	@printf "\e[38;5;46mArrow Left -> move image left\e[0m\n"
	@printf "\e[38;5;46mArrow Right -> move image right\e[0m\n"
	@printf "\e[38;5;46mEnter -> change colors\e[0m\n"
	@printf "\e[38;5;46mC -> reset color\e[0m\n"
	@printf "\e[38;5;46mI -> show number of iterations\e[0m\n"
	@printf "\e[38;5;46mP -> stop mouse (for Julia) \e[0m\n"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -c $< $(CPPFLAGS) -o $@

clean:
	@make -C libft clean
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
