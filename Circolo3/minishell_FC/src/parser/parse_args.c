/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*   By: [Your Name] <[Your Email]>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 by [Your Name]              #+#    #+#             */
/*   Updated: 2023/10/12 by [Your Name]              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

extern int	g_status;

static char	**divide_and_expand(char **arguments, t_prompt *prompt_data)
{
	char	**sub_divided;
	int		counter;
	int		quote_flags[2];

	counter = -1;
	while (arguments && arguments[++counter])
	{
		arguments[counter] = expand_variable(arguments[counter], -1, quote_flags, prompt_data);
		arguments[counter] = expand_directory(arguments[counter], -1, quote_flags, \
			retrieve_environment("HOME", prompt_data->envp, 4));
		sub_divided = command_subdivide(arguments[counter], "<|>");
		replace_in_arg_matrix(&arguments, sub_divided, counter);
		counter += matrix_length(sub_divided) - 1;
		free_arg_matrix(&sub_divided);
	}
	return (arguments);
}

static void	*process_arguments(char **arguments, t_prompt *prompt_data)
{
	int	exit_flag;
	int	counter;

	exit_flag = 0;
	prompt_data->cmds = populate_command_nodes(divide_and_expand(arguments, prompt_data), -1);
	if (!prompt_data->cmds)
		return (prompt_data);
	counter = list_size(prompt_data->cmds);
	g_status = execute_builtin(prompt_data, prompt_data->cmds, &exit_flag, 0);
	while (counter-- > 0)
		waitpid(-1, &g_status, 0);
	if (!exit_flag && g_status == 13)
		g_status = 0;
	if (g_status > 255)
		g_status = g_status / 255;
	if (arguments && exit_flag)
	{
		clear_command_list(&prompt_data->cmds, free_content_data);
		return (NULL);
	}
	return (prompt_data);
}

void	*validate_arguments(char *input, t_prompt *prompt_data)
{
	char	**arg_set;
	t_command	*cmd_data;

	if (!input)
	{
		printf("exit\n");
		return (NULL);
	}
	if (input[0] != '\0')
		add_to_history(input);
	arg_set = command_trim(input, " ");
	free(input);
	if (!arg_set)
		shell_error(QUOTE, NULL, 1);
	if (!arg_set)
		return ("");
	prompt_data = process_arguments(arg_set, prompt_data);
	if (prompt_data && prompt_data->cmds)
		cmd_data = prompt_data->cmds->content;
	if (prompt_data && prompt_data->cmds && cmd_data && cmd_data->full_cmd && list_size(prompt_data->cmds) == 1)
		prompt_data->envp = set_environment("_", cmd_data->full_cmd[matrix_length(cmd_data->full_cmd) - 1], \
			prompt_data->envp, 1);
	if (prompt_data && prompt_data->cmds)
		clear_command_list(&prompt_data->cmds, free_content_data);
	return (prompt_data);
}
