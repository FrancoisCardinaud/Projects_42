/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 03:22:22 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/14 18:17:37 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <X11/keysym.h>
# include <X11/X.h>

/* ---------------------------------------------------------------------------*
							MACROS
 --------------------------------------------------------------------------- */

# ifndef WIN_WIDTH
#  define WIN_WIDTH 640
# endif

# ifndef WIN_HEIGHT
#  define WIN_HEIGHT 480
# endif

# ifndef TEX_SIZE
#  define TEX_SIZE 64
# endif

# ifndef O_DIRECTORY
#  define O_DIRECTORY 00200000
# endif

# define WALKSPEED 0.0125
# define RUNSPEED 0.035
# define ROTSPEED 0.025

# define JUMP_HEIGHT 20
# define JUMP_SPEED 0.2

#define CROSSHAIR_SIZE 5
#define CROSSHAIR_COLOR 0xFFFFFF

// ERROR MESSAGES
# define USAGE "./cub3d <path/to/map.cub>"
# define FILE_NOT_CUB "Not a .cub file"
# define FILE_NOT_XPM "Not an .xpm file"
# define FILE_IS_DIR "Is a directory"
# define FLOOR_CEILING "Invalid floor/ceiling RGB color(s)"
# define COLOR_FLOOR "Invalid floor RGB color"
# define COLOR_CEILING "Invalid ceiling RGB color"
# define INVALID_MAP "Map description is either wrong or incomplete"
# define INV_LETTER "Invalid character in map"
# define NUM_PLAYER "Map has more than one player"
# define TEX_RGB_VAL "Invalid RGB value (min: 0, max: 255)"
# define TEX_MISSING "Missing texture(s)"
# define TEX_INVALID "Invalid texture(s)"
# define COLOR_MISSING "Missing color(s)"
# define MAP_MISSING "Missing map"
# define MAP_TOO_SMALL "Map is not at least 3 lines high"
# define MAP_NO_WALLS "Map is not surrounded by walls"
# define MAP_LAST "Map is not the last element in file"
# define PLAYER_POS "Invalid player position"
# define PLAYER_DIR "Map has no player position (expected N, S, E or W)"
# define MALLOC "Could not allocate memory"
# define MLX_START "Could not start mlx"
# define MLX_WIN "Could not create mlx window"
# define MLX_IMG "Could not create mlx image"

enum e_output
{
	OK = 0,
	NOT_OK = 1,
	ERR = 2,
	BREAK = 3,
	CONTINUE = 4
};

enum e_texture_index
{
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3
};

typedef unsigned long	t_ulong;

/* ---------------------------------------------------------------------------*
							STRUCTURES
 --------------------------------------------------------------------------- */

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		pixel_bits;
	int		size_line;
	int		endian;
}	t_img;

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
}	t_texinfo;

typedef struct s_mapinfo
{
	int			fd;
	int			line_count;
	char		*path;
	char		**file;
	int			height;
	int			width;
	int			index_end_of_map;
}	t_mapinfo;

typedef struct s_ray
{
	double	camera_x;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	wall_dist;
	double	wall_x;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_ray;

typedef struct s_player
{
	char	dir;
	double	pos_x;
	double	pos_y;
	double  pos_z;
	double	dir_x;
	double	dir_y;
	double	plane_vector_x;
	double	plane_vector_y;
	int		has_moved;
	int		move_x;
	int		move_y;
	int		rotate;
	int     running;
}	t_player;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			win_height;
	int			win_width;
	t_mapinfo	mapinfo;
	char		**map;
	t_player	player;
	t_ray		ray;
	int			**texture_pixels;
	int			**textures;
	t_texinfo	texinfo;
}	t_info;

/* ---------------------------------------------------------------------------*
							FUNCTIONS
 --------------------------------------------------------------------------- */

/* init/initialize_game_info.c */
void	initialize_game_info(t_info *game_info);
void	reset_image(t_img *img);
void	initialize_ray(t_ray *ray);

/* init/initialize_graphics.c */
void	initialize_graphics(t_info *game_info);
void	initialize_image(t_info *game_info, t_img *image, int width, int height);
void	initialize_texture_image(t_info *game_info, t_img *img, char *file_path);

/* init/load_textures.c */
void	initialize_textures(t_info *game_info);
void	initialize_texture_info(t_texinfo *texture_info);

/* parsing/verify_file.c */
int		verify_file(char *arg, bool is_cub_file);

/* parsing/read_file_data.c */
void	read_file_data(char *path, t_info *game_info);
bool	contains_no_digits(char *string);
int		count_lines_in_file(char *file_path);
int		*populate_rgb_array(char **rgb_parts, int *rgb_array);

/* parsing/retrieve_file_data.c */
int		retrieve_file_data(t_info *game_info, char **file_data);

/* parsing/assign_color_textures.c */
int		assign_color_textures(t_info *game_info, t_texinfo *texture_info, char *line, int index);

/* parsing/generate_map.c */
int		generate_map(t_info *game_info, char **file_data, int start_index);

/* parsing/validate_textures.c */
int		validate_textures(t_info *game_info, t_texinfo *texture_info);

/* parsing/validate_map.c */
int		validate_map(t_info *game_info, char **map_data);

/* parsing/validate_map_borders.c */
int		validate_map_borders(t_mapinfo *map_info, char **map_data);

/* parsing/parsing_helpers.c */
int		is_whitespace(char c);
size_t	find_max_length(t_mapinfo *map_info, int start_index);

/* engine/render_utils.c */
void display_crosshair(t_img *frame, t_info *game_info);

/* render/render_frame.c */
int		update_frame(t_info *game_info);
void	render_images(t_info *game_info);

/* render/cast_rays.c */
int		perform_raycast(t_player *player, t_info *game_info);

/* render/update_texture.c */
void	initialize_texture_pixels(t_info *game_info);
void	refresh_texture_pixels(t_info *game_info, t_texinfo *texture_info, t_ray *ray, int x);

/* render/image_helpers.c */
void	set_image_pixel(t_img *image, int x, int y, int color);

/* move/handle_input.c */
void	listen_input(t_info *game_info);

/* player_controls/direction.c */
void	config_player_north_south(t_player *player_data);
void	config_player_east_west(t_player *player_data);

/* move/execute_player_move.c */
int		execute_player_move(t_info *game_info);
int		validate_move(t_info *game_info, float next_x, float next_y);

/* move/rotate_player_view.c */
int		rotate_player_direction(t_info *game_info, float rotation_direction);

/* exit/clean_exit.c */
void	clean_exit(t_info *game_info, int exit_code);
int		exit_game(t_info *game_info);

/* exit/release_resources.c */
void	release_memory(void **memory_block);
int		release_resources(t_info *game_info);

/* error.c */
int		display_error_message(char *detail, char *message, int code);
int		display_error_with_value(int detail, char *message, int code);

#endif
