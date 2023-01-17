/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstracke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 12:28:46 by dstracke          #+#    #+#             */
/*   Updated: 2019/05/14 18:09:16 by dstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		word_counter(char const *s, char c)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			j++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (j);
}

void	ft_freewd(char **str, int l)
{
	while (l--)
		free(str[l]);
	free(str);
}

char	**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**kek;
	int		word;

	word = 0;
	j = 0;
	i = 0;
	if (!s)
		return (NULL);
	if (!(kek = (char **)malloc(sizeof(char*) * (word_counter(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
			if (!(kek[word++] = ft_strndup(s + j, i - j)))
				ft_freewd(kek, word);
	}
	kek[word] = 0;
	return (kek);
}
