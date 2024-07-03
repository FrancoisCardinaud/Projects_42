.PHONY: all re clean fclean bonus

# Program file name
NAME	= cub3D

# Mode
BONUS = 0

# Compiler and compilation flags
CC		= gcc
CFLAGS	= -Werror -Wextra -Wall -g3 #-fsanitize=address

# Minilibx
MLX_PATH	= minilibx-linux/
MLX_NAME	= libmlx.a
MLX			= $(MLX_PATH)$(MLX_NAME)

# Libft
LIBFT_PATH	= libft/
LIBFT_NAME	= libft.a
LIBFT		= $(LIBFT_PATH)$(LIBFT_NAME)

# Sources
SRC_PATH = ./sources/
SRC		= 	main.c \
			error.c \
			engine/raycasting.c \
			engine/render.c \
			engine/manage_textures.c \
			engine/render_utils.c \
			exit/terminate_program.c \
			exit/free_resources.c \
			configuration/config_game_data.c \
			configuration/config_mlx.c \
			configuration/config_textures.c \
			parsing/parse_data.c \
			parsing/retrieve_data.c \
			parsing/build_map.c \
			parsing/assign_coltex.c \
			parsing/parse_utils.c \
			validation/validate_arguments.c \
			validation/validate_map_textures.c \
			validation/validate_map.c \
			validation/validate_map_borders.c \
			player_controls/manage_inputs.c \
			player_controls/direction.c \
			player_controls/position.c \
			player_controls/move.c \
			player_controls/rotate.c
SRCS	= $(addprefix $(SRC_PATH), $(SRC))

# Objects
OBJ_PATH	= ./objects/
OBJ			= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))

# Includes
INC			=	-I ./includes/\
				-I ./libft/\
				-I ./minilibx-linux/

# Main rule
all: $(OBJ_PATH) $(MLX) $(LIBFT) $(NAME)

# Objects directory rule
$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)
	mkdir -p $(OBJ_PATH)/configuration
	mkdir -p $(OBJ_PATH)/parsing
	mkdir -p $(OBJ_PATH)/player_controls
	mkdir -p $(OBJ_PATH)/engine
	mkdir -p $(OBJ_PATH)/validation
	mkdir -p $(OBJ_PATH)/exit

# Objects rule
$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

# Project file rule
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(INC) $(LIBFT) $(MLX) -lXext -lX11 -lm

# Libft rule
$(LIBFT):
	make -sC $(LIBFT_PATH)

# MLX rule
$(MLX):
	make -sC $(MLX_PATH)

# Clean up build files rule
clean:
	rm -rf $(OBJ_PATH)
	make -C $(LIBFT_PATH) clean
	make -C $(MLX_PATH) clean

# Remove program executable
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

# Clean + remove executable
re: fclean all
