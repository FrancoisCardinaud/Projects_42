/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:45:42 by fcardina          #+#    #+#             */
/*   Updated: 2023/10/23 19:13:07 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

extern int	g_stat;

char	*expand_dir(char *input, int index, int quote[2], char *var)
{
	char	*directory;
	char	*temp;

	quote[0] = 0;
	quote[1] = 0;
	while (input && input[++index])
	{
		quote[0] = (quote[0] + (!quote[1] && input[index] == '\'')) % 2;
		quote[1] = (quote[1] + (!quote[0] && input[index] == '\"')) % 2;
		if (!quote[0] && !quote[1] && input[index] == '~' && (index == 0
				|| input[index - 1] != '$'))
		{
			temp = ft_substr(input, 0, index);
			directory = ft_strjoin(temp, var);
			free(temp);
			temp = ft_substr(input, index + 1, ft_strlen(input));
			free(input);
			input = ft_strjoin(directory, temp);
			free(temp);
			free(directory);
			return (expand_dir(input, index + ft_strlen(var) - 1, quote, var));
		}
	}
	free(var);
	return (input);
}

static char	*retrieve_sub_var(char *input, int index, t_prompt *data)
{
	char	*temp;
	int		position;
	char	*directory;
	char	*variable;

	position = ft_strchars_i(&input[index], "|\"\'$?>< ") + (ft_strchr("$?",
			input[index]) != 0);
	if (position == -1)
		position = ft_strlen(input) - 1;
	temp = ft_substr(input, 0, index - 1);
	variable = shell_retrieve_env(&input[index], data->envp,
			ft_strchars_i(&input[index], "\"\'$|>< "));
	if (!variable && input[index] == '$')
		variable = ft_itoa(data->pid);
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

char	*expand_variables(char *input, int index, int quote_flags[2],
		t_prompt *data)
{
	quote_flags[0] = 0;
	quote_flags[1] = 0;
	while (input && input[++index])
	{
		quote_flags[0] = (quote_flags[0] + (!quote_flags[1]
					&& input[index] == '\'')) % 2;
		quote_flags[1] = (quote_flags[1] + (!quote_flags[0]
					&& input[index] == '\"')) % 2;
		if (!quote_flags[0] && input[index] == '$' && input[index + 1]
			&& ((ft_strchars_i(&input[index + 1], "/~%^{}:; ")
					&& !quote_flags[1]) || (ft_strchars_i(&input[index + 1],
						"/~%^{}:;\"") && quote_flags[1])))
			return (expand_variables(retrieve_sub_var(input, ++index, data), -1,
					quote_flags, data));
	}
	return (input);
}
