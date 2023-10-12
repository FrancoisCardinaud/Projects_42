/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmdsubsplit.c                                       :+:      :+:    :+:   */
/*   By: [Your Name] <[Your Email]>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 by [Your Name]              #+#    #+#             */
/*   Updated: 2023/10/12 by [Your Name]              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static int	count_subwords(char *str, char *delimiters, int count)
{
	int		quotes[2];
	int		index;

	index = 0;
	quotes[0] = 0;
	quotes[1] = 0;
	while (str && str[index] != '\0')
	{
		count++;
		if (!ft_strchr(delimiters, str[index]))
		{
			while ((!ft_strchr(delimiters, str[index]) || quotes[0] || quotes[1]) && str[index] != '\0')
			{
				quotes[0] = (quotes[0] + (!quotes[1] && str[index] == '\'')) % 2;
				quotes[1] = (quotes[1] + (!quotes[0] && str[index] == '\"')) % 2;
				index++;
			}
			if (quotes[0] || quotes[1])
				return (-1);
		}
		else
			index++;
	}
	return (count);
}

static char	**populate_subwords(char **result, char *str, char *delimiters, int indices[3])
{
	int		quotes[2];

	quotes[0] = 0;
	quotes[1] = 0;
	while (str && str[indices[0]] != '\0')
	{
		indices[1] = indices[0];
		if (!ft_strchr(delimiters, str[indices[0]]))
		{
			while ((!ft_strchr(delimiters, str[indices[0]]) || quotes[0] || quotes[1]) && str[indices[0]])
			{
				quotes[0] = (quotes[0] + (!quotes[1] && str[indices[0]] == '\'')) % 2;
				quotes[1] = (quotes[1] + (!quotes[0] && str[indices[0]] == '\"')) % 2;
				indices[0]++;
			}
		}
		else
			indices[0]++;
		result[indices[2]++] = ft_substr(str, indices[1], indices[0] - indices[1]);
	}
	return (result);
}

char	**cmd_subsplit(const char *str, char *delimiters)
{
	char	**result;
	int		subword_count;
	int		indices[3] = {0, 0, 0};

	if (!str)
		return (NULL);
	subword_count = count_subwords((char *)str, delimiters, 0);
	if (subword_count == -1)
		return (NULL);
	result = malloc((subword_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	result = populate_subwords(result, (char *)str, delimiters, indices);
	result[subword_count] = NULL;
	return (result);
}
