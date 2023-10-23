/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmdtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:47:29 by fcardina          #+#    #+#             */
/*   Updated: 2023/10/23 17:48:41 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	count_trimmed_words(const char *str, char *delimiters)
{
	int	index;
	int	word_count;
	int	quotes[2] = {0, 0};

	index = 0;
	word_count = 0;
	while (str[index] != '\0')
	{
		if (!ft_strchr(delimiters, str[index]))
		{
			word_count++;
			while ((!ft_strchr(delimiters, str[index]) || quotes[0]
					|| quotes[1]) && str[index] != '\0')
			{
				if (!quotes[1] && (str[index] == '\"' || str[index] == '\''))
					quotes[1] = str[index];
				quotes[0] = (quotes[0] + (str[index] == quotes[1])) % 2;
				quotes[1] *= quotes[0] != 0;
				index++;
			}
			if (quotes[0])
				return (-1);
		}
		else
			index++;
	}
	return (word_count);
}

static char	**populate_trimmed_words(char **result, const char *str,
		char *delimiters)
{
	unsigned int	indices[3] = {0, 0, 0};
	int				quotes[2] = {0, 0};

	while (str[indices[0]])
	{
		while (ft_strchr(delimiters, str[indices[0]])
			&& str[indices[0]] != '\0')
			indices[0]++;
		indices[1] = indices[0];
		while ((!ft_strchr(delimiters, str[indices[0]]) || quotes[0]
				|| quotes[1]) && str[indices[0]])
		{
			quotes[0] = (quotes[0] + (!quotes[1] && str[indices[0]] == '\''))
						% 2;
			quotes[1] = (quotes[1] + (!quotes[0] && str[indices[0]] == '\"'))
				% 2;
			indices[0]++;
		}
		if (indices[1] < ft_strlen(str))
			result[indices[2]++] = ft_substr(str, indices[1], indices[0]
					- indices[1]);
		else
			result[indices[2]++] = "\0";
	}
	return (result);
}

char	**ft_cmdtrim(const char *str, char *delimiters)
{
	char	**result;
	int		word_count;

	if (!str)
		return (NULL);
	word_count = count_trimmed_words(str, delimiters);
	if (word_count == -1)
		return (NULL);
	result = malloc((word_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	result = populate_trimmed_words(result, str, delimiters);
	result[word_count] = NULL;
	return (result);
}
