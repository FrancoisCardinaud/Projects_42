/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 22:44:18 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/16 17:41:24 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/* Processes the command-line arguments and initializes the game data */
static int	process_arguments(t_info *game_info, char **argv)
{
	if (validate_file(argv[1], true) == NOT_OK)
		total_exit(game_info, NOT_OK);
	read_file_data(argv[1], game_info);
	if (retrieve_file_data(game_info, game_info->mapinfo.file) == NOT_OK)
		return (release_memory_resources(game_info));
	if (validate_map(game_info, game_info->map) == NOT_OK)
		return (release_memory_resources(game_info));
	if (validate_textures(game_info, &game_info->texinfo) == NOT_OK)
		return (release_memory_resources(game_info));
	config_player_north_south(&game_info->player);
	config_player_east_west(&game_info->player);
	return (0);
}

/* Displays the game controls to the console */
static void	show_controls(void)
{
	printf("\033[0;33m");
	printf("\n");
	printf("\tW/Z: move forward\n");
	printf("\tS: move backward\n");
	printf("\tA/Q: move left\n");
	printf("\tD: move right\n");
	printf("\t<-: turn left\n");
	printf("\t->: turn right\n");
	printf("\tL-SHIFT: sprint\n");
	printf("\033[0m");
}

/* Sets up the game */
static int	setup_game(t_info *game_info, char **argv)
{
	initialize_game_info(game_info);
	if (process_arguments(game_info, argv) != 0)
		return (1);
	initialize_graphics(game_info);
	initialize_textures(game_info);
	show_controls();
	return (0);
}

int	main(int argc, char **argv)
{
	t_info	game_info;

	if (argc != 2)
		return (disp_err_msg("Usage", INV_USAGE, 1));
	if (setup_game(&game_info, argv) != 0)
		return (1);
	execute_raycasting(&game_info);
	listen_input(&game_info);
	mlx_loop_hook(game_info.mlx, update_frame, &game_info);
	mlx_loop(game_info.mlx);
	return (0);
}
