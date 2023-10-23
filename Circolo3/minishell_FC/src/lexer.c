/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:45:04 by fcardina          #+#    #+#             */
/*   Updated: 2023/10/24 01:41:44 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static t_mini	*initialize_command(void)
{
	t_mini	*cmd_data;

	cmd_data = malloc(sizeof(t_mini));
	if (!cmd_data)
		return (NULL);
	cmd_data->full_cmd = NULL;
	cmd_data->full_path = NULL;
	cmd_data->infile = STDIN_FILENO;
	cmd_data->outfile = STDOUT_FILENO;
	return (cmd_data);
}

static t_mini	*extract_parameters(t_mini *cmd_data, char **args_set[2],
		int *index)
{
	if (args_set[0][*index])
	{
		if (args_set[0][*index][0] == '>' && args_set[0][*index + 1]
			&& args_set[0][*index + 1][0] == '>')
			cmd_data = get_outfile2(cmd_data, args_set[1], index);
		else if (args_set[0][*index][0] == '>')
			cmd_data = get_outfile1(cmd_data, args_set[1], index);
		else if (args_set[0][*index][0] == '<' && args_set[0][*index + 1]
			&& args_set[0][*index + 1][0] == '<')
			cmd_data = get_infile2(cmd_data, args_set[1], index);
		else if (args_set[0][*index][0] == '<')
			cmd_data = get_infile1(cmd_data, args_set[1], index);
		else if (args_set[0][*index][0] != '|')
			cmd_data->full_cmd = ft_extend_matrix(cmd_data->full_cmd,
					args_set[1][*index]);
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
	char	**t_args;
	char	*temp_arg;
	int		counter;

	counter = -1;
	t_args = ft_dup_matrix(args);
	while (t_args && t_args[++counter])
	{
		temp_arg = ft_strtrim_all(t_args[counter], 0, 0);
		free(t_args[counter]);
		t_args[counter] = temp_arg;
	}
	return (t_args);
}

static t_list	*terminate_fill(t_list *cmd_list, char **args, char **t_args)
{
	ft_lstclear(&cmd_list, release_content);
	ft_free_matrix(&t_args);
	ft_free_matrix(&args);
	return (NULL);
}

t_list	*populate_commands(char **args, int c)
{
	t_list	*cmd_list_set[2];
	char	**t_args[2];

	cmd_list_set[0] = NULL;
	t_args[1] = trim_args(args);
	while (args[++c])
	{
		cmd_list_set[1] = ft_lstlast(cmd_list_set[0]);
		if (c == 0 || (args[c][0] == '|' && args[c + 1] && args[c + 1][0]))
		{
			c += args[c][0] == '|';
			ft_lstadd_back(&cmd_list_set[0], ft_lstnew(initialize_command()));
			cmd_list_set[1] = ft_lstlast(cmd_list_set[0]);
		}
		t_args[0] = args;
		cmd_list_set[1]->content = extract_parameters(cmd_list_set[1]->content,
				t_args, &c);
		if (c < 0)
			return (terminate_fill(cmd_list_set[0], args, t_args[1]));
		if (!args[c])
			break ;
	}
	ft_free_matrix(&t_args[1]);
	ft_free_matrix(&args);
	return (cmd_list_set[0]);
}
