/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:46:24 by fcardina          #+#    #+#             */
/*   Updated: 2023/10/13 15:59:57 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

extern int	g_stat;

static char	*retrieve_home_directory(t_prompt prompt_data)
{
	char	*temporary;
	char	*current_directory;
	char	*home_directory;

	current_directory = getcwd(NULL, 0);
	if (!current_directory)
		current_directory = ft_strdup("∅ ");
	home_directory = shell_retrieve_env("HOME", prompt_data.envp, 4);
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

const char *determine_color(char first_char)
{
    switch (first_char % 5)
    {
        case 0:
            return CYAN;
        case 1:
            return GRAY;
        case 2:
            return GREEN;
        case 3:
            return MAGENTA;
        default:
            return YELLOW;
    }
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
		username = ft_extend_matrix(username, "guest");
	if (!ft_strncmp(username[0], "root", 4))
		color_code = ft_strjoin(NULL, RED);
	else
		color_code = ft_strjoin(NULL, determine_color(username[0][0]));
	temporary = ft_strjoin(color_code, *username);
	free(color_code);
	ft_free_matrix(&username);
	return (temporary);
}

char	*shell_getprompt(t_prompt prompt_data)
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
	if (!g_stat || g_stat == -1)
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
