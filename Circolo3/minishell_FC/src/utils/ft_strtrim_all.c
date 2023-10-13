/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:47:14 by fcardina          #+#    #+#             */
/*   Updated: 2023/10/13 15:59:48 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	calculate_trim_length(const char *str)
{
	int	count = 0;
	int	index = 0;
	int	double_quote = 0;
	int	single_quote = 0;

	while (str && str[index])
	{
		single_quote = (single_quote + (!double_quote && str[index] == '\'')) % 2;
		double_quote = (double_quote + (!single_quote && str[index] == '\"')) % 2;
		if ((str[index] == '\"' && !single_quote) || (str[index] == '\'' && !double_quote))
			count++;
		index++;
	}
	if (single_quote || double_quote)
		return (-1);
	return (count);
}

char	*ft_strtrim_all(const char *str, int single_quote, int double_quote)
{
	int		trim_length;
	int		indices[2] = {0, -1};
	char	*trimmed_str;

	trim_length = calculate_trim_length(str);
	if (!str || trim_length == -1)
		return (NULL);
	trimmed_str = malloc(sizeof(char) * (ft_strlen(str) - trim_length + 1));
	if (!trimmed_str)
		return (NULL);
	while (str[indices[0]])
	{
		single_quote = (single_quote + (!double_quote && str[indices[0]] == '\'')) % 2;
		double_quote = (double_quote + (!single_quote && str[indices[0]] == '\"')) % 2;
		if ((str[indices[0]] != '\"' || single_quote) && (str[indices[0]] != '\'' || double_quote))
			trimmed_str[++indices[1]] = str[indices[0]];
		indices[0]++;
	}
	trimmed_str[++indices[1]] = '\0';
	return (trimmed_str);
}
