# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/08 15:21:34 by apuchill          #+#    #+#              #
#    Updated: 2024/02/26 16:38:47 by fcardina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= miniRT

MLX_FLAGS	= -lbsd -lmlx -L/usr/X11/lib -lXext -lX11 -lm -framework OpenGL -framework AppKit
INCLUDES	= -I includes -I $(LIBFT_DIR)/includes/

LIBFT		= $(LIBFT_DIR)libft.a
LIBFT_DIR	= libft/
LIB_FLAGS	= -L $(LIBFT_DIR) -lft

CC			= clang
CFLAGS		= -Wall -Wextra -Werror
# CFLAGS		= -Wall -Wextra -Werror -g3 -fsanitize=address
RM			= /bin/rm -f
NORM		= ~/.norminette/norminette.rb

DIR_SRCS	= srcs
DIR_OBJS	= objs
SUBDIRS		= main errors scene vectors bitmap

SRCS_DIRS	= $(foreach dir, $(SUBDIRS), $(addprefix $(DIR_SRCS)/, $(dir)))
OBJS_DIRS	= $(foreach dir, $(SUBDIRS), $(addprefix $(DIR_OBJS)/, $(dir)))
SRCS		= $(foreach dir, $(SRCS_DIRS), $(wildcard $(dir)/*.c))
OBJS		= $(subst $(DIR_SRCS), $(DIR_OBJS), $(SRCS:.c=.o))

$(DIR_OBJS)/%.o :	$(DIR_SRCS)/%.c
			@mkdir -p $(DIR_OBJS) $(OBJS_DIRS)
			@$(CC) $(CFLAGS) $(INCLUDES) -Imlx -c -o $@ $<

all:		$(NAME)

$(LIBFT):
			@make --no-print-directory -C $(LIBFT_DIR)

$(NAME):	$(OBJS) $(LIBFT)
			@$(CC) $(CFLAGS) $(MLX_FLAGS) -o $(NAME) $(OBJS) $(LIB_FLAGS)

clean:
			@make clean --no-print-directory -C $(LIBFT_DIR)
			@$(RM) $(OBJS)
			@$(RM) -r $(DIR_OBJS)

fclean:		clean
			@make fclean --no-print-directory -C $(LIBFT_DIR)
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re

.PHONY:		reset
reset:
			@$(RM) $(OBJS) $(NAME)

.PHONY:		rt
rt:			reset all
			./minirt "scenes/base_file.rt"

.PHONY:		norm
norm:
			@$(NORM) */*.h */*/*.h */*/*.c */*/*/*.c

.PHONY:		norm2
norm2:
			@$(NORM) */minirt.h */errors.h */scene.h */vectors.h */bitmap.h && echo ""
			@$(NORM) srcs/main/*.c && echo ""
			@$(NORM) srcs/errors/*.c && echo ""
			@$(NORM) srcs/scene/*.c && echo ""
			@$(NORM) srcs/vectors/*.c && echo ""
			@$(NORM) srcs/bitmap/*.c
