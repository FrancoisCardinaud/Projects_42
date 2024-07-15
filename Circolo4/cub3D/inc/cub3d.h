/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 03:22:22 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/15 22:34:02 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

// MACROS
# ifndef WINDOW_H
#  define WINDOW_H 540
# endif
// 480

# ifndef WINDOW_W
#  define WINDOW_W 910
# endif
// 640

# ifndef WALK_SPEED
#  define WALK_SPEED 0.0125
# endif

# ifndef RUN_SPEED
#  define RUN_SPEED 0.035
# endif

# ifndef ROTSPEED
#  define ROTSPEED 0.025
# endif

# ifndef CROSSHAIR_SIZE
#  define CROSSHAIR_SIZE 5
# endif

# ifndef CROSSHAIR_COLOR
#  define CROSSHAIR_COLOR 0xFFFFFF
# endif

// ERROR MESSAGES
# define COLOR_NOT_FOUND "One or more colors are missing"
# define INV_CEILING_COLOR "Ceiling RGB value is invalid"
# define INV_CHAR "Found an invalid character in the map"
# define INV_CUB_FILE "This is not a .cub file"
# define INV_DIRECTION "Missing player start direction (N, S, E, or W)"
# define INV_FLOOR_CEILING "Floor/Ceiling RGB values are invalid"
# define INV_FLOOR_COLOR "Floor RGB value is invalid"
# define INV_MAP "Map description is incomplete or incorrect"
# define INV_MAP_BORDERS "Map is not properly enclosed by walls"
# define INV_MAP_ORDER "Map data must be the last element in the file"
# define INV_MAP_SIZE "Map too small, must be at least 3 lines high"
# define INV_P_NB "Multiple player positions detected in the map"
# define INV_POSITION "Player position is invalid"
# define INV_TEXTURE "Invalid texture(s) found"
# define INV_TEXTURE_FILE "This is not an .xpm file"
# define INV_TEXTURE_RGB_VALUE "RGB value invalid (between 0 and 255)"
# define INV_USAGE "Usage: ./cub3d <path/to/map.cub>"
# define IS_NOT_FILE "The specified path is a directory"
# define MALLOC_ERROR "Memory allocation failed"
# define MAP_NOT_FOUND "Map data is missing"
# define MISSING_TEXTURE "One or more textures are missing"
# define UNABLE_CREATE_MLX_IMAGE "Failed to create mlx image"
# define UNABLE_CREATE_MLX_WINDOW "Failed to create mlx window"
# define UNABLE_START_MLX "Failed to initialize mlx"

// STRUCTURES
enum				e_result
{
	OK = 0,
	NOT_OK = 1,
	ERROR = 2,
	BREAK = 3,
	CONTINUE = 4
};

typedef struct s_img
{
	void			*img;
	int				*addr;
	int				pixel_bits;
	int				size_line;
	int				endian;
}					t_img;

typedef struct s_texinfo
{
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	int				*floor;
	int				*ceiling;
	unsigned long	hex_floor;
	unsigned long	hex_ceiling;
	int				size;
	int				index;
	double			step;
	double			pos;
	int				x;
	int				y;
}					t_texture_info;

typedef struct s_mapinfo
{
	int				fd;
	int				line_count;
	char			*path;
	char			**file;
	int				height;
	int				width;
	int				index_end_of_map;
}					t_mapinfo;

typedef struct s_ray
{
	double			camera_x;
	double			dir_x;
	double			dir_y;
	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	double			sidedist_x;
	double			sidedist_y;
	double			deltadist_x;
	double			deltadist_y;
	double			wall_dist;
	double			wall_x;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
}					t_ray;

typedef struct s_player
{
	char			dir;
	double			pos_x;
	double			pos_y;
	double			pos_z;
	double			dir_x;
	double			dir_y;
	double			plane_vector_x;
	double			plane_vector_y;
	int				has_moved;
	int				move_x;
	int				move_y;
	int				rotate;
	int				running;
}					t_player;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	int				window_height;
	int				window_width;
	t_mapinfo		mapinfo;
	char			**map;
	t_player		player;
	t_ray			ray;
	int				**tex_pixels;
	int				**textures;
	t_texture_info	texinfo;
}					t_info;

enum				e_texture
{
	NO = 0,
	SO = 1,
	EA = 2,
	WE = 3
};

// FUNCTIONS
/* config/config_game_info.c */
void				initialize_game_info(t_info *game_info);
void				reset_image(t_img *img);
void				initialize_ray(t_ray *ray);

/* config/config_direction.c */
void				config_player_north_south(t_player *player_data);
void				config_player_east_west(t_player *player_data);

/* config/config_mlx.c */
void				initialize_graphics(t_info *game_info);
void				initialize_image(t_info *game_info, t_img *image, int width,
						int height);
void				initialize_texture_image(t_info *game_info, t_img *img,
						char *file_path);

/* config/config_textures.c */
void				initialize_textures(t_info *game_info);
void				initialize_texture_info(t_texture_info *tex_info);

/* parsing/retrieve_game_info.c */
void				read_file_data(char *path, t_info *game_info);
bool				contains_no_digits(char *string);
int					count_lines_in_file(char *file_path);
int					*populate_rgb_array(char **rgb_parts, int *rgb_array);
size_t				find_max_length(t_mapinfo *map_info, int start_index);

/* parsing/parse_game_info.c */
int					retrieve_file_data(t_info *game_info, char **file_data);

/* parsing/color_texture.c */
int					assign_col_tex(t_info *game_info,
						t_texture_info *tex_info, char *line, int index);

/* parsing/build_map.c */
int					generate_map(t_info *game_info, char **file_data,
						int start_index);

/* validation/validate_textures.c */
int					validate_textures(t_info *game_info,
						t_texture_info *tex_info);

/* validation/validate_map.c */
int					validate_map(t_info *game_info, char **map_data);

/* validation/validate_arguments.c */
int					verify_file(char *arg, bool is_cub_file);
int					is_space(char c);

/* validation/validate_map_borders.c */
int					validate_map_borders(t_mapinfo *map_info, char **map_data);

/* engine/engine_utils.c */
void				display_crosshair(t_img *frame, t_info *game_info);
void				set_image_pixel(t_img *image, int x, int y, int color);

/* engine/engine.c */
int					update_frame(t_info *game_info);
void				render_images(t_info *game_info);

/* engine/raycast_algo.c */
int					perform_raycast(t_player *player, t_info *game_info);

/* engine/manage_textures.c */
void				initialize_texture_pixels(t_info *game_info);
void				refresh_texture_pixels(t_info *game_info,
						t_texture_info *tex_info, t_ray *ray, int x);

/* player_controls/manage_inputs.c */
void				listen_input(t_info *game_info);

/* player_controls/move.c */
int					execute_player_move(t_info *game_info);
int					validate_move(t_info *game_info, float next_x,
						float next_y);

/* player_controls/rotate.c */
int					rotate_player_direction(t_info *game_info,
						float rotation_direction);

/* system/free_resources.c */
void				release_memory(void **memory_block);
int					release_resources(t_info *game_info);

/* system/system_functions.c */
int					disp_err_msg(char *detail, char *message,
						int code);
int					display_error_with_value(int detail, char *message,
						int code);
void				total_exit(t_info *game_info, int exit_code);
int					exit_game(t_info *game_info);

#endif
