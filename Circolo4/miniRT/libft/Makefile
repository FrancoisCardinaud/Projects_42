# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/13 15:52:01 by fcardina          #+#    #+#              #
#    Updated: 2024/02/21 18:19:50 by fcardina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_arrdel.c ft_atoi.c ft_bzero.c ft_calloc.c ft_countchar.c ft_dup_matrix.c ft_extend_matrix.c ft_free_matrix.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isnbr.c ft_isprint.c ft_isspace.c ft_itoa.c ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c ft_matrixlen.c ft_matrix_replace_in.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_print_hex.c ft_print_ptr.c ft_print_unsigned.c ft_printf_utils.c ft_printf.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putmatrix_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strchars_i.c ft_strchr_i.c ft_strdel.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_striteri.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c

OBJS = $(SRCS:.c=.o)

HEAD = ./includes/

NAME = libft.a

AR = ar rc

RM = rm -f

LIB = ranlib

GCC = gcc

CFLAGS = -Wall -Wextra -Werror

all: force $(NAME)

force:
	@rm -f $(NAME)

.c.o:
	$(GCC) $(CFLAGS) -c -I $(HEAD) $< -o $(<:.c=.o)

${NAME}: $(OBJS)
	$(AR) $(NAME) $(OBJS)
	$(LIB) $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re force
