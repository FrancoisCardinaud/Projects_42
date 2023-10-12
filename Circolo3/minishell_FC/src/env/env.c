/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: [Your Name] <[Your Email]>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 by [Your Name]              #+#    #+#             */
/*   Updated: 2023/10/12 by [Your Name]              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*shell_retrieve_env(char *key, char **envp, int key_len)
{
	int	i;
	int	env_key_len;

	i = 0;
	if (key_len < 0)
		key_len = ft_strlen(key);
	while (!ft_strchr(key, '=') && envp && envp[i])
	{
		env_key_len = key_len;
		if (env_key_len < ft_strchr_i(envp[i], '='))
			env_key_len = ft_strchr_i(envp[i], '=');
		if (!ft_strncmp(envp[i], key, env_key_len))
			return (ft_substr(envp[i], env_key_len + 1, ft_strlen(envp[i])));
		i++;
	}
	return (NULL);
}

char	**shell_update_env(char *key, char *value, char **envp, int key_len)
{
	int		index[2];
	char	*temp[2];

	if (key_len < 0)
		key_len = ft_strlen(key);
	index[0] = -1;
	temp[0] = ft_strjoin(key, "=");
	temp[1] = ft_strjoin(temp[0], value);
	free(temp[0]);
	while (!ft_strchr(key, '=') && envp && envp[++index[0]])
	{
		index[1] = key_len;
		if (index[1] < ft_strchr_i(envp[index[0]], '='))
			index[1] = ft_strchr_i(envp[index[0]], '=');
		if (!ft_strncmp(envp[index[0]], key, index[1]))
		{
			temp[0] = envp[index[0]];
			envp[index[0]] = temp[1];
			free(temp[0]);
			return (envp);
		}
	}
	envp = ft_extend_matrix(envp, temp[1]);
	free(temp[1]);
	return (envp);
}

static int	key_exists_in_env(char *arg, char **envp, int index_pair[2])
{
	int	key_pos;

	index_pair[1] = 0;
	key_pos = ft_strchr_i(arg, '=');
	if (key_pos == -1)
		return (-1);
	while (envp[index_pair[1]])
	{
		if (!ft_strncmp(envp[index_pair[1]], arg, key_pos + 1))
			return (1);
		index_pair[1]++;
	}
	return (0);
}

int	shell_add_export(t_prompt *shell_data)
{
	int		index_pair[2];
	int		key_pos;
	char	**args;

	args = ((t_mini *)shell_data->cmds->content)->full_cmd;
	if (ft_matrixlen(args) >= 2)
	{
		index_pair[0] = 1;
		while (args[index_pair[0]])
		{
			key_pos = key_exists_in_env(args[index_pair[0]], shell_data->envp, index_pair);
			if (key_pos == 1)
			{
				free(shell_data->envp[index_pair[1]]);
				shell_data->envp[index_pair[1]] = ft_strdup(args[index_pair[0]]);
			}
			else if (!key_pos)
				shell_data->envp = ft_extend_matrix(shell_data->envp, args[index_pair[0]]);
			index_pair[0]++;
		}
	}
	return (0);
}

int	shell_remove_unset(t_prompt *shell_data)
{
	char	**args;
	char	*temp;
	int		index_pair[2];

	index_pair[0] = 0;
	args = ((t_mini *)shell_data->cmds->content)->full_cmd;
	if (ft_matrixlen(args) >= 2)
	{
		while (args[++index_pair[0]])
		{
			if (args[index_pair[0]][ft_strlen(args[index_pair[0]]) - 1] != '=')
			{
				temp = ft_strjoin(args[index_pair[0]], "=");
				free(args[index_pair[0]]);
				args[index_pair[0]] = temp;
			}
			if (key_exists_in_env(args[index_pair[0]], shell_data->envp, index_pair))
				replace_in_matrix(&shell_data->envp, NULL, index_pair[1]);
		}
	}
	return (0);
}
