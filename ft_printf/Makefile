# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcardina <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/28 20:23:21 by fcardina          #+#    #+#              #
#    Updated: 2023/01/28 20:48:34 by fcardina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_printf ft_printf_utils ft_print_ptr ft_print_unsigned ft_print_hex

OBJ_DIR		=	obj/

SRC 		=	$(addsuffix .c, $(SRCS)))

OBJ 		=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRCS)))

HEAD		=	include

NAME		=	libftprintf.a

AR			=	ar rcs

RM			=	rm -f

LIBFT		=	libft

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra -I

OBJF		=	.cache_exists

all:		$(NAME)

$(NAME):	$(OBJ)
			@make -C $(LIBFT)
			@cp libft/libft.a .
			@mv libft.a $(NAME)
			@$(AR) $(NAME) $(OBJ)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
			@$(CC) $(CFLAGS) $(HEAD) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)

clean:
			@$(RM) -rf $(OBJ_DIR)
			@make clean -C $(LIBFT)

fclean:		clean
			@$(RM) -f $(NAME)
			@$(RM) -f $(LIBFT)/libft.a
			
re:			fclean all
			
norm:
			@norminette $(SRC) $(HEAD) $(LIBFT) | grep -v Norme -B1 || true

.PHONY:		all clean fclean re norm
