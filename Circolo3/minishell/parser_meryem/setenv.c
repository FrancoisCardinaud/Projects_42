/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 14:35:46 by mennaji           #+#    #+#             */
/*   Updated: 2023/08/16 01:03:10 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell1.h"

char	**ft_extend_matrix(char **matrix, char *new_string)
{
	int	size;
	int	i;
	int	i;

	char **extended_matrix; //variable to store the extende matrix
	size = 0;
	i = 0;
	extended_matrix = NULL;
	while (matrix[size])
		size++;
	extended_matrix = (char **)malloc((size + 2) * sizeof(char *));
	if (!extended_matrix)
		return (NULL);
	// Copy existing strings from matrix to extended_matrix using a while loop
	i = 0;
	while (i < size)
	{
		extended_matrix[i] = ft_strdup(matrix[i]);
		if (!extended_matrix[i])
		{
			// Failed to allocate memory for the string,
			free the extended_matrix and return NULL while (i-- > 0)
				free(extended_matrix[i]);
			free(extended_matrix);
			return (NULL);
		}
		i++;
	}
	// Copy the new_string into the last element of the extended_matrix
	extended_matrix[size] = ft_strdup(new_string);
	if (!extended_matrix[size])
	{
		// Failed to allocate memory for the string,
		free the extended_matrix and return NULL while (i-- > 0)
			free(extended_matrix[i]);
		free(extended_matrix);
		return (NULL);
	}
	// Set the next element after the new_string to NULL
	extended_matrix[size + 1] = NULL;
	// Free the old matrix and return the extended_matrix
	free(matrix);
	return (extended_matrix);
}

char	*get_env(char *var, char **envp, int n)
{
	int i; //loop counter variable
	i = 0;
	//checking if n is valid
	if (n < 0)
		n = ft_strlen(var);
	while (envp[i] != NULL)
	{
		if (!ft_strcmp(envp[i], var, n) == 0)
			return (ft_substr(envp[i], n + 1), ft_strlen(envp[i]));
		i++;
	}
	return (NULL);
}
//set the PWD environment variable with the value of str.
//The resulting environment variable array is stored back in prompt.envp.
char	**set_or_update(char *var, char *value, char **envp, int n)
{
	char	*new_entry;
	int		i;

	i = 0;
	if (n < 0)
		n = ft_strlen(var);
	new_entry = (char *)malloc(n + ft_strlen(value) + 1);
	if (!new_entry)
		return (NULL);
	ft_strncpy(new_entry, var, n);
	new_entry[n] = '=';
	ft_strcpy(new_entry + n + 1, value);
	//if an existing variable entry with the same name of as the new entry is found in the envp array
	while (envp[i])
	{
		if (!ft_strcmp(envp[i], var, n) && envp[i][n] == '=')
		{
			free(envp[i]);
			envp[i] = new_entry;
			return (envp);
		}
		i++;
	}
	envp = ft_extend_matrix(envp, new_entry);
	free(new_entry);
	return (envp);
}

t_prompt	set_env(t_prompt prompt)
{
	char	*num;
	char	*str;

	str = getcwd(NULL, 0);
	//current  working directory
	prompt.envp = set_or_update_env("PWD", str, prompt.envp, 3);
	//set the pwd environment
	free(str);
	str = get_env("SHLVL", prompt.envp, 5);
	if (!str || ft_atoi(str) <= 0)
		num = "1";
	else
		num = ft_itoa(ft_atoi(str) + 1);
	free(str);
	prompt.envp = set_or_update("SHLVL", num, prompt.envp, 5);
	str = get_env("PATH", prompt.envp, 4);
	if (!str)
		prompt.envp = set_or_update("PATH",
									"/usr/local/sbin:/usr/local/bin:/usr/bin:/bin",
									prompt.envp,
									4);
	free(str);
	return (prompt);
}
