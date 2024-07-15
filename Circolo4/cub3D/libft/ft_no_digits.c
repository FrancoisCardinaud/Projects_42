/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_no_digits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 23:43:27 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/13 17:57:27 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	contains_no_digits(char *string)
{
	int		char_index;
	bool	found_no_digit;

	char_index = 0;
	found_no_digit = true;
	while (string[char_index])
	{
		if (ft_isdigit(string[char_index]) == 1)
			found_no_digit = false;
		char_index++;
	}
	return (found_no_digit);
}
