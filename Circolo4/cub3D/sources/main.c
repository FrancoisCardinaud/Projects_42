/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 22:44:18 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/14 18:09:32 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

static int	parse_args(t_info *data, char **av)
{
	if (check_file(av[1], true) == FAIL)
		clean_exit(data, FAIL);
	parse_data(av[1], data);
	if (get_file_data(data, data->mapinfo.file) == FAIL)
		return (free_data(data));
	if (check_map_validity(data, data->map) == FAIL)
		return (free_data(data));
	if (check_textures_validity(data, &data->texinfo) == FAIL)
		return (free_data(data));
	init_player_direction(data);
	if (DEBUG_MSG)
		debug_display_data(data);
	return (0);
}

int	main(int ac, char **av)
{
	t_info	data;

	if (ac != 2)
		return (err_msg("Usage", ERR_USAGE, 1));
	init_info(&data);
	if (parse_args(&data, av) != 0)
		return (1);
	init_mlx(&data);
	init_textures(&data);
	print_controls();
	render_images(&data);
	listen_for_input(&data);
	mlx_loop_hook(data.mlx, render, &data);
	mlx_loop(data.mlx);
	return (0);
}
