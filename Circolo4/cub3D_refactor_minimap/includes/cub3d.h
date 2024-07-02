/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 03:22:22 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/02 20:12:59 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "colors.h"
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

/* # define WIN_WIDTH 960 */
/* # define WIN_HEIGHT 720 */
# define WIN_WIDTH 640
# define WIN_HEIGHT 480

# define TEX_SIZE 64

# ifndef O_DIRECTORY
#  define O_DIRECTORY 00200000
# endif

# define MOVESPEED 0.0125
# define RUNSPEED 0.035
# define ROTSPEED 0.025

# define JUMP_HEIGHT 20
# define JUMP_SPEED 0.2
# define GRAVITY 0.1

#define CROSSHAIR_SIZE 5
#define CROSSHAIR_COLOR 0xFFFFFF

/* MINIMAP MACROS */
# define MMAP_PIXEL_SIZE 128
# define MMAP_VIEW_DIST 4
# define MMAP_COLOR_PLAYER 0x00FF00
# define MMAP_COLOR_WALL 0x808080
# define MMAP_COLOR_FLOOR 0xE6E6E6
# define MMAP_COLOR_SPACE 0x404040

// ERROR MESSAGES
# define ERR_USAGE "usage: ./cub3d <path/to/map.cub>"

# define ERR_FILE_NOT_CUB "Not a .cub file"
# define ERR_FILE_NOT_XPM "Not an .xpm file"
# define ERR_FILE_IS_DIR "Is a directory"
# define ERR_FLOOR_CEILING "Invalid floor/ceiling RGB color(s)"
# define ERR_COLOR_FLOOR "Invalid floor RGB color"
# define ERR_COLOR_CEILING "Invalid ceiling RGB color"
# define ERR_INVALID_MAP "Map description is either wrong or incomplete"
# define ERR_INV_LETTER "Invalid character in map"
# define ERR_NUM_PLAYER "Map has more than one player"
# define ERR_TEX_RGB_VAL "Invalid RGB value (min: 0, max: 255)"
# define ERR_TEX_MISSING "Missing texture(s)"
# define ERR_TEX_INVALID "Invalid texture(s)"
# define ERR_COLOR_MISSING "Missing color(s)"
# define ERR_MAP_MISSING "Missing map"
# define ERR_MAP_TOO_SMALL "Map is not at least 3 lines high"
# define ERR_MAP_NO_WALLS "Map is not surrounded by walls"
# define ERR_MAP_LAST "Map is not the last element in file"
# define ERR_PLAYER_POS "Invalid player position"
# define ERR_PLAYER_DIR "Map has no player position (expected N, S, E or W)"
# define ERR_MALLOC "Could not allocate memory"
# define ERR_MLX_START "Could not start mlx"
# define ERR_MLX_WIN "Could not create mlx window"
# define ERR_MLX_IMG "Could not create mlx image"

enum e_output
{
	SUCCESS = 0,
	FAILURE = 1,
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

typedef struct s_minimap
{
	char	**map;
	t_img	*img;
	int		size;
	int		offset_x;
	int		offset_y;
	int		view_dist;
	int		tile_size;
}	t_minimap;

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
	double	plane_x;
	double	plane_y;
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
	t_img		minimap;
}	t_data;

/* ---------------------------------------------------------------------------*
							FUNCTIONS
 --------------------------------------------------------------------------- */

/* init/initialize_game_data.c */
void	initialize_game_data(t_data *game_data);
void	reset_image(t_img *img);
void	initialize_ray(t_ray *ray);

/* init/initialize_graphics.c */
void	initialize_graphics(t_data *game_data);
void	initialize_image(t_data *game_data, t_img *image, int width, int height);
void	initialize_texture_image(t_data *game_data, t_img *image, char *path);

/* init/load_textures.c */
void	initialize_textures(t_data *game_data);
void	initialize_texture_info(t_texinfo *texture_info);

/* parsing/verify_file.c */
int		verify_file(char *arg, bool is_cub_file);

/* parsing/read_file_data.c */
void	read_file_data(char *path, t_data *game_data);

/* parsing/retrieve_file_data.c */
int		retrieve_file_data(t_data *game_data, char **file_data);

/* parsing/assign_color_textures.c */
int		assign_color_textures(t_data *game_data, t_texinfo *texture_info, char *line, int index);

/* parsing/generate_map.c */
int		generate_map(t_data *game_data, char **file_data, int start_index);

/* parsing/validate_textures.c */
int		validate_textures(t_data *game_data, t_texinfo *texture_info);

/* parsing/validate_map.c */
int		validate_map(t_data *game_data, char **map_data);

/* parsing/validate_map_borders.c */
int		validate_map_borders(t_mapinfo *map_info, char **map_data);

/* parsing/parsing_helpers.c */
int		is_whitespace(char c);
size_t	find_max_length(t_mapinfo *map_info, int start_index);

/* render/render_frame.c */
int		update_frame(t_data *game_data);
void	render_images(t_data *game_data);

/* render/cast_rays.c */
int		perform_raycast(t_player *player, t_data *game_data);

/* render/update_texture.c */
void	initialize_texture_pixels(t_data *game_data);
void	refresh_texture_pixels(t_data *game_data, t_texinfo *texture_info, t_ray *ray, int x);

/* render/image_helpers.c */
void	set_image_pixel(t_img *image, int x, int y, int color);

/* render/draw_minimap.c */
void	draw_minimap(t_data *game_data);

/* render/draw_minimap_image.c */
void	display_minimap(t_data *game_data, t_minimap *mini_map);

/* move/handle_input.c */
void	listen_input(t_data *game_data);

/* move/set_player_direction.c */
void	set_player_direction(t_data *game_data);

/* move/execute_player_move.c */
void 	update_player_jump(t_data *game_data);
int		execute_player_move(t_data *game_data);
int		validate_move(t_data *game_data, double next_x, double next_y);

/* move/rotate_player_view.c */
int		rotate_player_direction(t_data *game_data, double rotation_direction);

/* exit/clean_exit.c */
void	clean_exit(t_data *game_data, int exit_code);
int		exit_game(t_data *game_data);

/* exit/release_resources.c */
void	release_memory(void **memory_block);
int		release_resources(t_data *game_data);

/* error.c */
int		display_error_message(char *detail, char *message, int code);
int		display_error_with_value(int detail, char *message, int code);

#endif
