/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 21:25:39 by fcardina          #+#    #+#             */
/*   Updated: 2024/04/07 04:35:16 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* Includes */
# include "colors.h"
# include "libft.h"
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

/* Macros */
# ifndef DEBUG_TEXT
#  define DEBUG_TEXT 0
# endif

# ifndef DEBUG_MINIMAP
#  define DEBUG_MINIMAP 0
# endif

# ifndef BONUS
#  define BONUS 1
# endif

# define WINDOW_W 640
# define WINDOW_H 480
# define TEXTURE_SIZE 64
# define T_SPEED 0.0125
# define R_SPEED 0.015
# define MOUSE_WRAP_DISTANCE 20
# define MINIMAP_VIEW_DISTANCE 128
# define MMAP_VIEW_DIST 4
# define MINIMAP_CHARACTER_COLOR 0x00FF00
# define MINIMAP_WALL_COLOR 0x808080
# define MINIMAP_FLOOR_COLOR 0xE6E6E6
# define MINIMAP_SPACE_COLOR 0x404040

# ifndef DIR_FLAG
#  define DIR_FLAG 00200000
# endif

/* Error Messages */
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

/* Enumerations */
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

/* Structures */
typedef struct s_img
{
    void    *img;
    int     *addr;
    int     pixel_bits;
    int     size_line;
    int     endian;
}   t_img;

typedef struct s_texture_data
{
    char            *north;
    char            *south;
    char            *west;
    char            *east;
    int             *floor;
    int             *ceiling;
    unsigned long   hex_floor;
    unsigned long   hex_ceiling;
    int             size;
    int             index;
    double          step;
    double          pos;
    int             x;
    int             y;
}   t_texture_data;

typedef struct s_minimap
{
    char    **map;
    t_img   *img;
    int     size;
    int     offset_x;
    int     offset_y;
    int     view_dist;
    int     tile_size;
}   t_minimap;

typedef struct s_mapinfo
{
    int     fd;
    int     line_count;
    char    *path;
    char    **file;
    int     height;
    int     width;
    int     index_end_of_map;
}   t_mapinfo;

typedef struct s_ray
{
    double  camera_x;
    double  dir_x;
    double  dir_y;
    int     map_x;
    int     map_y;
    int     step_x;
    int     step_y;
    double  sidedist_x;
    double  sidedist_y;
    double  deltadist_x;
    double  deltadist_y;
    double  wall_dist;
    double  wall_x;
    int     side;
    int     line_height;
    int     draw_start;
    int     draw_end;
}   t_ray;

typedef struct s_player
{
    char    dir;
    double  pos_x;
    double  pos_y;
    double  dir_x;
    double  dir_y;
    double  plane_x;
    double  plane_y;
    int     has_moved;
    int     move_x;
    int     move_y;
    int     rotate;
}   t_player;

typedef struct s_data
{
    void    *mlx;
    void    *win;
    int     win_height;
    int     win_width;
    t_mapinfo   mapinfo;
    char    **map;
    t_player    player;
    t_ray   ray;
    int     **texture_pixels;
    int     **textures;
    t_texture_data   texture_data;
    t_img   minimap;
}   t_data;

/* Function Prototypes */
void    initialize_data(t_data *data);
void    clean_initialize_img(t_img *img);
void    initialize_rays(t_ray *ray);
void    initialize_mlx(t_data *data);
void    initialize_img(t_data *data, t_img *image, int width, int height);
void    initialize_texture_image(t_data *data, t_img *image, char *path);
void    initialize_textures(t_data *data);
void    initialize_texture_data(t_texture_data *textures);
int     validate_file(char *arg, bool cub);
void    parse_data(char *path, t_data *data);
int     retrieve_file_data(t_data *data, char **map);
int     fill_textures_color_data(t_data *data, t_texture_data *textures, char *line, int j);
int     validate_textures(t_data *data, t_texture_data *textures);
int		generate_map(t_data *data, char **map, int i);
int     validate_map(t_data *data, char **map_tab);
int     validate_map_borders(t_mapinfo *map, char **map_tab);
int     check_white_space(char c);
size_t  find_largest_length(t_mapinfo *map, int i);
int     trace(t_data *data);
void    trace_images(t_data *data);
int     perform_raycasting(t_player *player, t_data *data);
void    initialize_texture_pixels(t_data *data);
void    update_texture_pixels(t_data *data, t_texture_data *tex, t_ray *ray, int x);
void    set_image_pixel(t_img *image, int x, int y, int color);
void    trace_minimap(t_data *data);
void    trace_minimap_image(t_data *data, t_minimap *minimap);
void    await_input(t_data *data);
void    set_player_direction(t_data *data);
int     validate_move(t_data *data, double new_x, double new_y);
int     move_character(t_data *data);
int     rotate_character(t_data *data, double rotdir);
void    exit_cleanup(t_data *data, int code);
int     quit_program(t_data *data);
void    free_memory(void **tab);
int     free_all_data(t_data *data);
int     display_error_message(char *detail, char *str, int code);
int     display_error_message_validation(int detail, char *str, int code);
void    display_debug_data(t_data *data);
void    debug_display_minimap(t_minimap *minimap);
void    debug_display_player(t_data *data);
void    debug_print_char_tab(char **tab);

#endif
