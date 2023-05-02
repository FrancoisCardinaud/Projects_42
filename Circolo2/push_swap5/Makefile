# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/01 20:26:14 by fcardina          #+#    #+#              #
#    Updated: 2023/05/02 17:00:37 by fcardina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_COMMON = 	./src/main.c \
				./src/order_utils.c \
				./src/order.c \
				./src/stack_multi.c \
				./src/stack_print.c \
				./src/stack_transform.c \
				./src/stack_utils.c \
				./src/stack.c \

SRC_CHECKER =	./tests/checker_linux \
				./tests/checker_Mac \


OBJS_COMMON	= ${SRC_COMMON:.c=.o}
OBJS_SORTER		= ${SRC_SORTER:.c=.o}
OBJS_CHECKER	= ${SRC_CHECKER:.c=.o}
AR = ar rcs
LIBFT = libft/libft.a
LIBFT_DIR = libft
LIBFT_SRC = $(shell [ -d libft ] && ls libft/*.c)

INCLUDE = ./include

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap
NAME_CHECKER = checker

CC = gcc
RM = rm -f

all: ${NAME}

.c.o:
			${CC} ${CFLAGS} -I$(INCLUDE) -c $< -o ${<:.c=.o}

$(NAME): $(LIBFT) $(OBJS_COMMON) $(OBJS_SORTER)
			${CC} $(CFLAGS) -I$(INCLUDE) $(LIBFT) -o $(NAME) $(OBJS_COMMON) $(OBJS_SORTER)

$(LIBFT): $(LIBFT_SRC) | $(LIBFT_DIR)
	@make all -C libft
	@$(AR) $(NAME) $(LIBFT)		

$(NAME_CHECKER): $(OBJS_COMMON) $(OBJS_CHECKER)
			${CC} $(CFLAGS) -I$(INCLUDE) -o $(NAME_CHECKER) $(OBJS_COMMON) $(OBJS_CHECKER)

clean:
			@make clean -C libft
			${RM} ${OBJS_COMMON} ${OBJS_SORTER}

fclean: clean
			@make fclean -C libft
			${RM} ${NAME}

re: fclean all

bonus: checker
