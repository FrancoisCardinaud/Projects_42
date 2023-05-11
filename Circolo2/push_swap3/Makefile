# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/01 20:26:14 by fcardina          #+#    #+#              #
#    Updated: 2023/05/11 17:30:19 by fcardina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_COMMON = 	./common/instructions/instructions_1.c \
				./common/instructions/instructions_2.c \
				./common/instructions/instructions_3.c \
				./common/args.c \
				./common/clean.c \
				./common/stack.c \
				./common/utils/ft_utils_1.c \
				./common/utils/ft_utils_2.c \
				./common/utils/ft_utils_3.c

SRC_SORTER =	./sorter/looper.c \
				./sorter/main.c \
				./sorter/sorter.c \
				./sorter/utils/five_optimize.c \
				./sorter/utils/indexer.c \
				./sorter/utils/rotator.c \
				./sorter/utils/sorter_utils.c

SRC_CHECKER =	./checker/checker.c \
				./checker/main.c


OBJS_COMMON	= ${SRC_COMMON:.c=.o}
OBJS_SORTER		= ${SRC_SORTER:.c=.o}
OBJS_CHECKER	= ${SRC_CHECKER:.c=.o}

INCLUDE = ./src/include

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap
NAME_CHECKER = checker

CC = gcc
RM = rm -f

all: ${NAME}

.c.o:
			${CC} ${CFLAGS} -I$(INCLUDE) -c $< -o ${<:.c=.o}

$(NAME): $(OBJS_COMMON) $(OBJS_SORTER)
			${CC} $(CFLAGS) -I$(INCLUDE) -o $(NAME) $(OBJS_COMMON) $(OBJS_SORTER)

$(NAME_CHECKER): $(OBJS_COMMON) $(OBJS_CHECKER)
			${CC} $(CFLAGS) -I$(INCLUDE) -o $(NAME_CHECKER) $(OBJS_COMMON) $(OBJS_CHECKER)

clean:
			${RM} ${OBJS_COMMON} ${OBJS_SORTER} ${OBJS_CHECKER}

fclean: clean
			${RM} ${NAME} ${NAME}

re: fclean all

bonus: checker

.PHONY:		checker bonus all clean fclean re
