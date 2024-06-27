/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 03:21:44 by fcardina          #+#    #+#             */
/*   Updated: 2024/06/22 15:38:34 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/* Prints a 2D character array for debugging purposes */
void	print_char_array_debug(char **char_array)
{
	int	index;

	printf("\n");
	index = 0;
	while (char_array[index])
	{
		printf("%s\n", char_array[index]);
		index++;
	}
	printf("\n");
}

/* Displays minimap information for debugging */
void	show_minimap_debug(t_minimap *mini_map)
{
	printf(YELLOW "\n---- MINIMAP\n" RESET);
	printf("Minimap view distance: %d\n", mini_map->view_dist);
	printf("Minimap size: %d * %d\n", mini_map->size, mini_map->size);
	print_char_array_debug(mini_map->map);
}

/* Displays map information for debugging */
void	show_map_info_debug(t_data *game_data)
{
	printf(YELLOW "\n---- MAP\n" RESET);
	printf("Map height: %d\n", game_data->mapinfo.height);
	printf("Map width: %d\n", game_data->mapinfo.width);
	print_char_array_debug(game_data->map);
	printf(YELLOW "\n---- TEXTURES & COLORS\n" RESET);
	printf("Color ceiling: #%lx\n", game_data->texinfo.hex_ceiling);
	printf("Color floor: #%lx\n", game_data->texinfo.hex_floor);
	printf("Texture north: %s\n", game_data->texinfo.north);
	printf("Texture south: %s\n", game_data->texinfo.south);
	printf("Texture east: %s\n", game_data->texinfo.east);
	printf("Texture west: %s\n", game_data->texinfo.west);
}

/* Displays player information for debugging */
void	show_player_debug(t_data *game_data)
{
	printf(YELLOW "\n---- PLAYER\n" RESET);
	printf("Player pos: ");
	printf("x = %f, y = %f\n", game_data->player.pos_x, game_data->player.pos_y);
	printf("Player direction: %c ", game_data->player.dir);
	printf("(x = %f, y = %f)\n", game_data->player.dir_x, game_data->player.dir_y);
}

/* Displays overall game data for debugging */
void	show_debug_info(t_data *game_data)
{
	show_map_info_debug(game_data);
	show_player_debug(game_data);
	printf("\n");
}
