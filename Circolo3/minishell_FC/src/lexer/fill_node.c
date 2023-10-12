/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_node.c                                        :+:      :+:    :+:   */
/*   By: [Your Name] <[Your Email]>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 by [Your Name]              #+#    #+#             */
/*   Updated: 2023/10/12 by [Your Name]              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static t_command	*initialize_command(void)
{
	t_command	*cmd_data;

	cmd_data = malloc(sizeof(t_command));
	if (!cmd_data)
		return (NULL);
	cmd_data->full_cmd = NULL;
	cmd_data->full_path = NULL;
	cmd_data->infile = STDIN_FILENO;
	cmd_data->outfile = STDOUT_FILENO;
	return (cmd_data);
}

static t_command	*extract_parameters(t_command *cmd_data, char **args_set[2], int *index)
{
	if (args_set[0][*index])
	{
		if (args_set[0][*index][0] == '>' && args_set[0][*index + 1] && args_set[0][*index + 1][0] == '>')
			cmd_data = retrieve_outfile2(cmd_data, args_set[1], index);
		else if (args_set[0][*index][0] == '>')
			cmd_data = retrieve_outfile1(cmd_data, args_set[1], index);
		else if (args_set[0][*index][0] == '<' && args_set[0][*index + 1] && \
			args_set[0][*index + 1][0] == '<')
			cmd_data = retrieve_infile2(cmd_data, args_set[1], index);
		else if (args_set[0][*index][0] == '<')
			cmd_data = retrieve_infile1(cmd_data, args_set[1], index);
		else if (args_set[0][*index][0] != '|')
			cmd_data->full_cmd = extend_arg_matrix(cmd_data->full_cmd, args_set[1][*index]);
		else
		{
			shell_error(PIPENDERR, NULL, 2);
			*index = -2;
		}
		return (cmd_data);
	}
	shell_error(PIPENDERR, NULL, 2);
	*index = -2;
	return (cmd_data);
}

static char	**trim_args(char **args)
{
	char	**trimmed_args;
	char	*temp_arg;
	int		counter;

	counter = -1;
	trimmed_args = duplicate_arg_matrix(args);
	while (trimmed_args && trimmed_args[++counter])
	{
		temp_arg = trim_all_spaces(trimmed_args[counter], 0, 0);
		free(trimmed_args[counter]);
		trimmed_args[counter] = temp_arg;
	}
	return (trimmed_args);
}

static t_list	*terminate_fill(t_list *cmd_list, char **args, char **trimmed_args)
{
	clear_command_list(&cmd_list, free_content_data);
	free_arg_matrix(&trimmed_args);
	free_arg_matrix(&args);
	return (NULL);
}

t_list	*populate_commands(char **args, int counter)
{
	t_list	*cmd_list_set[2];
	char	**trimmed_args_set[2];

	cmd_list_set[0] = NULL;
	trimmed_args_set[1] = trim_args(args);
	while (args[++counter])
	{
		cmd_list_set[1] = ft_lstlast(cmd_list_set[0]);
		if (counter == 0 || (args[counter][0] == '|' && args[counter + 1] && args[counter + 1][0]))
		{
			counter += args[counter][0] == '|';
			ft_lstadd_back(&cmd_list_set[0], ft_lstnew(initialize_command()));
			cmd_list_set[1] = ft_lstlast(cmd_list_set[0]);
		}
		trimmed_args_set[0] = args;
		cmd_list_set[1]->content = extract_parameters(cmd_list_set[1]->content, trimmed_args_set, &counter);
		if (counter < 0)
			return (terminate_fill(cmd_list_set[0], args, trimmed_args_set[1]));
		if (!args[counter])
			break ;
	}
	free_arg_matrix(&trimmed_args_set[1]);
	free_arg_matrix(&args);
	return (cmd_list_set[0]);
}
