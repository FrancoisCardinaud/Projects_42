# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: francoiscardinaud <marvin@42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 14:16:12 by francoiscardi     #+#    #+#              #
#    Updated: 2023/02/24 14:21:14 by francoiscardi    ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol
OS		= $(shell uname)

# directories
SRCDIR	= ./src
INCDIR	= ./includes
OBJDIR	= ./obj

# src / obj files
SRC		= event.c fractal.c main.c tools.c events2.c

OBJ		= $(addprefix $(OBJDIR)/,$(SRC:.c=.o))

# compiler
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g


# mlx library
MLX		= ./miniLibX/
MLX_LNK	= -L $(MLX) -l mlx -framework OpenGL -framework AppKit

MLX_INC	= -I $(MLX)
MLX_LIB	= $(addprefix $(MLX),mlx.a)

# ft library
FT		= ./libft/
FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= -I ./libft
FT_LNK	= -L ./libft -l ft -l pthread

all: obj $(FT_LIB) $(MLX_LIB) $(NAME)

obj:
	mkdir -p $(OBJDIR)
	mkdir -p $(OBJDIR)/fractals

$(OBJDIR)/%.o:$(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(MLX_INC) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
	@make -C $(FT)

$(MLX_LIB):
	@make -C $(MLX)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_LNK) $(FT_LNK) -lm -o $(NAME)

clean:
	rm -rf $(OBJDIR)
	make -C $(FT) clean
	make -C $(MLX) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(FT) fclean

re: fclean all
