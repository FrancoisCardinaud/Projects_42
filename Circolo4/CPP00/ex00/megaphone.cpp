/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 02:52:52 by fcardina          #+#    #+#             */
/*   Updated: 2023/11/08 03:03:33 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <locale>
#include <stdio.h>
#include <string>

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "LOUD AND UNBEARABLE FEEDBACK NOISE" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
		{
			for (int j = 0; argv[i][j]; j++)
				std::cout << (char)toupper(argv[i][j]);
			std::cout << " ";
		}
	}
	std::cout << std::endl;
	return (0);
}