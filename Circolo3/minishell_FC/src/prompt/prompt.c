/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*   By: [Your Name] <[Your Email]>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 by [Your Name]              #+#    #+#             */
/*   Updated: 2023/10/12 by [Your Name]              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

extern int	g_status;

static char	*retrieve_home_directory(t_prompt prompt_data)
{
	char	*temporary;
	char	*current_directory;
	char	*home_directory;

	current_directory = getcwd(NULL, 0);
	if (!current_directory)
		current_directory = ft_strdup("∅ ");
	home_directory = retrieve_environment("HOME", prompt_data.envp, 4);
	if (home_directory && home_directory[0] && ft_strnstr(current_directory, home_directory, ft_strlen(current_directory)))
	{
		temporary = current_directory;
		current_directory = ft_strjoin("~", &current_directory[ft_strlen(home_directory)]);
		free(temporary);
	}
	free(home_directory);
	home_directory = ft_strjoin(BLUE, current_directory);
	free(current_directory);
	current_directory = ft_strjoin(home_directory, " ");
	free(home_directory);
	home_directory = ft_strjoin(" ", current_directory);
	free(current_directory);
	current_directory = ft_strjoin(home_directory, DEFAULT);
	free(home_directory);
	return (current_directory);
}

static char	*retrieve_username(t_prompt prompt_data)
{
	char	**username;
	char	*temporary;
	char	*color_code;

	username = NULL;
	color_code = NULL;
	execute_custom_command(&username, "/usr/bin/whoami", "whoami", prompt_data.envp);
	if (!username)
		username = extend_arg_matrix(username, "guest");
	if (!ft_strncmp(username[0], "root", 4))
		color_code = ft_strjoin(NULL, RED);
	else
		color_code = ft_strjoin(NULL, determine_color(username[0][0]));
	temporary = ft_strjoin(color_code, *username);
	free(color_code);
	free_arg_matrix(&username);
	return (temporary);
}

char	*generate_prompt(t_prompt prompt_data)
{
	char	*temporary;
	char	*temporary2;
	char	*auxiliary;

	temporary = retrieve_username(prompt_data);
	temporary2 = ft_strjoin(temporary, "@minishell");
	free(temporary);
	auxiliary = retrieve_home_directory(prompt_data);
	temporary = ft_strjoin(temporary2, auxiliary);
	free(auxiliary);
	free(temporary2);
	if (!g_status || g_status == -1)
		temporary2 = ft_strjoin(temporary, BLUE);
	else
		temporary2 = ft_strjoin(temporary, RED);
	free(temporary);
	temporary = ft_strjoin(temporary2, "$ ");
	free(temporary2);
	temporary2 = ft_strjoin(temporary, DEFAULT);
	free(temporary);
	return (temporary2);
}
