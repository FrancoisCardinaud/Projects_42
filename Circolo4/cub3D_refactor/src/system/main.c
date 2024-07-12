/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 22:44:18 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/12 17:29:37 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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

/* Processes the command-line arguments and initializes the game data */
static int	process_arguments(t_data *game_data, char **argv)
{
	if (verify_file(argv[1], true) == FAILURE)
		clean_exit(game_data, FAILURE);
	read_file_data(argv[1], game_data);
	if (retrieve_file_data(game_data, game_data->mapinfo.file) == FAILURE)
		return (release_resources(game_data));
	if (validate_map(game_data, game_data->map) == FAILURE)
		return (release_resources(game_data));
	if (validate_textures(game_data, &game_data->texinfo) == FAILURE)
		return (release_resources(game_data));
	config_player_north_south(&game_data->player);
	config_player_east_west(&game_data->player);
	return (0);
}

/* Sets up the game */
static int	setup_game(t_data *game_data, char **argv)
{
	initialize_game_data(game_data);
	if (process_arguments(game_data, argv) != 0)
		return (1);
	initialize_graphics(game_data);
	initialize_textures(game_data);
	show_controls();
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	game_data;

	if (argc != 2)
		return (display_error_message("Usage", ERR_USAGE, 1));
	if (setup_game(&game_data, argv) != 0)
		return (1);
	render_images(&game_data);
	listen_input(&game_data);
	mlx_loop_hook(game_data.mlx, update_frame, &game_data);
	mlx_loop(game_data.mlx);
	return (0);
}
