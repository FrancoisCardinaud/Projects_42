/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:45:42 by fcardina          #+#    #+#             */
/*   Updated: 2023/10/13 15:59:55 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

extern int	g_stat;

char	*expand_directory(char *input, int index, int quote_flags[2], char *variable)
{
	char	*directory;
	char	*temp;

	quote_flags[0] = 0;
	quote_flags[1] = 0;
	while (input && input[++index])
	{
		quote_flags[0] = (quote_flags[0] + (!quote_flags[1] && input[index] == '\'')) % 2;
		quote_flags[1] = (quote_flags[1] + (!quote_flags[0] && input[index] == '\"')) % 2;
		if (!quote_flags[0] && !quote_flags[1] && input[index] == '~' && (index == 0 || \
			input[index - 1] != '$'))
		{
			temp = ft_substr(input, 0, index);
			directory = ft_strjoin(temp, variable);
			free(temp);
			temp = ft_substr(input, index + 1, ft_strlen(input));
			free(input);
			input = ft_strjoin(directory, temp);
			free(temp);
			free(directory);
			return (expand_directory(input, index + ft_strlen(variable) - 1, quote_flags, variable));
		}
	}
	free(variable);
	return (input);
}

static char	*retrieve_sub_var(char *input, int index, t_prompt *shell_data)
{
	char	*temp;
	int		position;
	char	*directory;
	char	*variable;

	position = ft_strchars_i(&input[index], "|\"\'$?>< ") + (ft_strchr("$?", input[index]) != 0);
	if (position == -1)
		position = ft_strlen(input) - 1;
	temp = ft_substr(input, 0, index - 1);
	variable = shell_retrieve_env(&input[index], shell_data->envp, \
		ft_strchars_i(&input[index], "\"\'$|>< "));
	if (!variable && input[index] == '$')
		variable = ft_itoa(shell_data->pid);
	else if (!variable && input[index] == '?')
		variable = ft_itoa(g_stat);
	directory = ft_strjoin(temp, variable);
	free(temp);
	temp = ft_strjoin(directory, &input[index + position]);
	free(variable);
	free(directory);
	free(input);
	return (temp);
}

char	*expand_variables(char *input, int index, int quote_flags[2], t_prompt *shell_data)
{
	quote_flags[0] = 0;
	quote_flags[1] = 0;
	while (input && input[++index])
	{
		quote_flags[0] = (quote_flags[0] + (!quote_flags[1] && input[index] == '\'')) % 2;
		quote_flags[1] = (quote_flags[1] + (!quote_flags[0] && input[index] == '\"')) % 2;
		if (!quote_flags[0] && input[index] == '$' && input[index + 1] && \
			((ft_strchars_i(&input[index + 1], "/~%^{}:; ") && !quote_flags[1]) || \
			(ft_strchars_i(&input[index + 1], "/~%^{}:;\"") && quote_flags[1])))
			return (expand_variables(retrieve_sub_var(input, ++index, shell_data), -1, \
				quote_flags, shell_data));
	}
	return (input);
}
