/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:47:14 by fcardina          #+#    #+#             */
/*   Updated: 2023/10/24 00:57:51 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	calculate_trim_length(const char *str)
{
	int	count;
	int	index;
	int	quotes;
	int	quote;

	count = 0;
	index = 0;
	quotes = 0;
	quote = 0;
	while (str && str[index])
	{
		quote = (quote + (!quotes && str[index] == '\'')) % 2;
		quotes = (quotes + (!quote && str[index] == '\"')) % 2;
		if ((str[index] == '\"' && !quote) || (str[index] == '\'' && !quotes))
			count++;
		index++;
	}
	if (quote || quotes)
		return (-1);
	return (count);
}

char	*ft_strtrim_all(const char *str, int quote, int quotes)
{
	int		trim_length;
	int		indices[2];
	char	*trimmed_str;

	indices[0] = 0;
	indices[1] = -1;
	trim_length = calculate_trim_length(str);
	if (!str || trim_length == -1)
		return (NULL);
	trimmed_str = malloc(sizeof(char) * (ft_strlen(str) - trim_length + 1));
	if (!trimmed_str)
		return (NULL);
	while (str[indices[0]])
	{
		quote = (quote + (!quotes && str[indices[0]] == '\'')) % 2;
		quotes = (quotes + (!quote && str[indices[0]] == '\"')) % 2;
		if ((str[indices[0]] != '\"' || quote) && (str[indices[0]] != '\''
				|| quotes))
			trimmed_str[++indices[1]] = str[indices[0]];
		indices[0]++;
	}
	trimmed_str[++indices[1]] = '\0';
	return (trimmed_str);
}
