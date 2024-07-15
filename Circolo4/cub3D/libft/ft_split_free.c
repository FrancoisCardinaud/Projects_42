/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 21:12:32 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/15 21:12:41 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_split_free(char **s)
{
	size_t	i;

	if (!s || !*s)
		return ;
	i = 0;
	while (i < ft_strlen_const(s))
		free(s[i++]);
	free(s);
}
