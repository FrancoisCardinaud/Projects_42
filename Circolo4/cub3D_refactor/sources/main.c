/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 22:44:18 by alexa             #+#    #+#             */
/*   Updated: 2024/04/07 04:35:16 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_controls(void)
{
	printf(CYAN "\n");
	printf("░█▀▀░█░█░█▀▄░▀▀█░█▀▄░░░█▀▀░█▀█░█▀█░▀█▀░█▀▄░█▀█░█░░░█▀▀\n");
	printf("░█░░░█░█░█▀▄░░▀▄░█░█░░░█░░░█░█░█░█░░█░░█▀▄░█░█░█░░░▀▀█\n");
	printf("░▀▀▀░▀▀▀░▀▀░░▀▀░░▀▀░░░░▀▀▀░▀▀▀░▀░▀░░▀░░▀░▀░▀▀▀░▀▀▀░▀▀▀\n");
	printf(RESET "\n");
	printf(CYAN "\tW" RESET ": move forward\t");
	printf(CYAN "\tS" RESET ": move backward\n");
	printf(CYAN "\tA" RESET ": strafe left\t");
	printf(CYAN "\tD" RESET ": strafe right\n");
	printf(CYAN "\t<" RESET ": rotate left\t");
	printf(CYAN "\t>" RESET ": rotate right\n");
	if (BONUS)
		printf(CYAN "\tMouse" RESET ": rotate view\n");
	printf("\n");
}

static int	parse_args(t_data *data, char **av)
{
	if (validate_file(av[1], true) == FAILURE)
		exit_cleanup(data, FAILURE);
	parse_data(av[1], data);
	if (retrieve_file_data(data, data->mapinfo.file) == FAILURE)
		return (free_all_data(data));
	if (validate_map(data, data->map) == FAILURE)
		return (free_all_data(data));
	if (validate_textures(data, &data->texture_data) == FAILURE)
		return (free_all_data(data));
	set_player_direction(data);
	if (DEBUG_TEXT)
		display_debug_data(data);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (display_error_message("Usage", ERR_USAGE, 1));
	initialize_data(&data);
	if (parse_args(&data, av) != 0)
		return (1);
	initialize_mlx(&data);
	initialize_textures(&data);
	print_controls();
	trace_images(&data);
	await_input(&data);
	mlx_loop_hook(data.mlx, trace, &data);
	mlx_loop(data.mlx);
	return (0);
}
