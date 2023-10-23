/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmdsubsplit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:47:33 by fcardina          #+#    #+#             */
/*   Updated: 2023/10/24 00:25:43 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	count_subwords(char *str, char *delimiters, int count)
{
	int	tmp[2];
	int	index;

	index = 0;
	tmp[0] = 0;
	tmp[1] = 0;
	while (str && str[index] != '\0')
	{
		count++;
		if (!ft_strchr(delimiters, str[index]))
		{
			while ((!ft_strchr(delimiters, str[index]) || tmp[0] || tmp[1])
				&& str[index] != '\0')
			{
				tmp[0] = (tmp[0] + (!tmp[1] && str[index] == '\'')) % 2;
				tmp[1] = (tmp[1] + (!tmp[0] && str[index] == '\"')) % 2;
				index++;
			}
			if (tmp[0] || tmp[1])
				return (-1);
		}
		else
			index++;
	}
	return (count);
}

static char	**populate_subwords(char **result, char *str, char *delimiters,
		int i[3])
{
	int	tmp[2];

	tmp[0] = 0;
	tmp[1] = 0;
	while (str && str[i[0]] != '\0')
	{
		i[1] = i[0];
		if (!ft_strchr(delimiters, str[i[0]]))
		{
			while ((!ft_strchr(delimiters, str[i[0]]) || tmp[0] || tmp[1])
				&& str[i[0]])
			{
				tmp[0] = (tmp[0] + (!tmp[1] && str[i[0]] == '\'')) % 2;
				tmp[1] = (tmp[1] + (!tmp[0] && str[i[0]] == '\"')) % 2;
				i[0]++;
			}
		}
		else
			i[0]++;
		result[i[2]++] = ft_substr(str, i[1], i[0] - i[1]);
	}
	return (result);
}

char	**ft_cmdsubsplit(const char *str, char *delimiters)
{
	char	**result;
	int		subword_count;
	int		i[3];

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	if (!str)
		return (NULL);
	subword_count = count_subwords((char *)str, delimiters, 0);
	if (subword_count == -1)
		return (NULL);
	result = malloc((subword_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	result = populate_subwords(result, (char *)str, delimiters, i);
	result[subword_count] = NULL;
	return (result);
}
