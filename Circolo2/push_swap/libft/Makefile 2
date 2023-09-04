SRCS = $(shell find "." -name "*.c")

OBJS		= $(SRCS:.c=.o)

HEAD		= ./includes/

NAME		= libft.a

AR		= ar rc

RM		= rm -f

LIB		= ranlib

GCC		= gcc

CFLAGS		= -Wall -Wextra -Werror

all:		$(NAME)

.c.o:
			$(GCC) $(CFLAGS) -c -I $(HEAD) $< -o $(<:.c=.o)

${NAME}:	$(OBJS)
			$(AR) $(NAME) $(OBJS)
			$(LIB) $(NAME)

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
