.PHONY: all re clean fclean

# Program file name
NAME	= cub3D

# Compiler and compilation flags
CC		= gcc
CFLAGS	= -Werror -Wextra -Wall -g3

# Minilibx
MLX_PATH	= minilibx-linux/
MLX_NAME	= libmlx.a
MLX			= $(MLX_PATH)$(MLX_NAME)

# Libft
LIBFT_PATH	= libft/
LIBFT_NAME	= libft.a
LIBFT		= $(LIBFT_PATH)$(LIBFT_NAME)

# Sources
SRC_PATH = ./src/
SRC		= 	system/main.c \
			system/free_resources.c \
			system/system_functions.c \
			config/config_game_info.c \
			config/config_mlx.c \
			config/config_textures.c \
			config/config_direction.c \
			engine/raycast_algo.c \
			engine/engine.c \
			engine/manage_textures.c \
			engine/engine_utils.c \
			parsing/parse_game_info.c \
			parsing/retrieve_game_info.c \
			parsing/build_map.c \
			parsing/color_texture.c \
			validation/validate_arguments.c \
			validation/validate_textures.c \
			validation/validate_map.c \
			validation/validate_map_borders.c \
			validation/validate_position.c \
			player_controls/manage_inputs.c \
			player_controls/move.c \
			player_controls/rotation.c
SRCS	= $(addprefix $(SRC_PATH), $(SRC))

# Objects
OBJ_PATH	= ./obj/
OBJ			= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))

# inc
INC			=	-I ./inc/\
				-I ./libft/\
				-I ./minilibx-linux/

# Main rule
all: $(OBJ_PATH) $(MLX) $(LIBFT) $(NAME)

# Objects directory rule
$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)
	mkdir -p $(OBJ_PATH)/system
	mkdir -p $(OBJ_PATH)/config
	mkdir -p $(OBJ_PATH)/engine
	mkdir -p $(OBJ_PATH)/parsing
	mkdir -p $(OBJ_PATH)/validation
	mkdir -p $(OBJ_PATH)/player_controls

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
