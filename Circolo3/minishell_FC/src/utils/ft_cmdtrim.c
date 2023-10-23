/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmdtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:47:29 by fcardina          #+#    #+#             */
/*   Updated: 2023/10/24 01:41:26 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	is_delimiter(char c, char *delimiters)
{
	return (ft_strchr(delimiters, c) != NULL);
}

static int	handle_quotes(const char *str, int *index, char *delimiters)
{
	int	tmp[2];

	tmp[0] = 0;
	tmp[1] = 0;
	while ((!is_delimiter(str[*index], delimiters) || tmp[0] || tmp[1])
		&& str[*index])
	{
		if (!tmp[1] && (str[*index] == '\"' || str[*index] == '\''))
			tmp[1] = str[*index];
		tmp[0] = (tmp[0] + (str[*index] == tmp[1])) % 2;
		tmp[1] *= tmp[0] != 0;
		(*index)++;
	}
	return (tmp[0]);
}

static int	count_trimmed_words(const char *str, char *delimiters)
{
	int	index;
	int	word_count;

	index = 0;
	word_count = 0;
	while (str[index])
	{
		if (!is_delimiter(str[index], delimiters))
		{
			word_count++;
			if (handle_quotes(str, &index, delimiters))
				return (-1);
		}
		else
			index++;
	}
	return (word_count);
}

static char	**populate_trimmed_words(char **result, const char *str,
		char *delim)
{
	unsigned int	indices[3];
	int				tmp[2];

	ft_bzero(indices, sizeof(indices));
	ft_bzero(tmp, sizeof(tmp));
	while (str[indices[0]])
	{
		while (ft_strchr(delim, str[indices[0]])
			&& str[indices[0]] != '\0')
			indices[0]++;
		indices[1] = indices[0];
		while ((!ft_strchr(delim, str[indices[0]]) || tmp[0] || tmp[1])
			&& str[indices[0]])
		{
			tmp[0] = (tmp[0] + (!tmp[1] && str[indices[0]] == '\'')) % 2;
			tmp[1] = (tmp[1] + (!tmp[0] && str[indices[0]] == '\"')) % 2;
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
