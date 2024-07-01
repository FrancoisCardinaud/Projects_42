/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 22:44:18 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/01 20:02:29 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/* Displays the game controls to the console */
static void	show_controls(void)
{
	printf(RESET "\n");
	printf(CYAN "\tW" RESET ": move forward\t");
	printf(CYAN "\tS" RESET ": move backward\n");
	printf(CYAN "\tA" RESET ": strafe left\t");
	printf(CYAN "\tD" RESET ": strafe right\n");
	printf(CYAN "\t<" RESET ": rotate left\t");
	printf(CYAN "\t>" RESET ": rotate right\n");
	printf(CYAN "\tL-SHIFT" RESET ": sprint\n");
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
	set_player_direction(game_data);
	if (DEBUG_MSG)
		show_debug_info(game_data);
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
