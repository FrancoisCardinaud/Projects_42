/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:37:28 by fcardina          #+#    #+#             */
/*   Updated: 2023/12/09 16:46:02 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	if (N < 1)
	{
		std::cout << "Enter a valid number." << std::endl;
		return (NULL);
	}

    Zombie *horde = new Zombie[N];
	
    if (horde == NULL)
	{
		std::cout << "Horde allocation failed." << std::endl;
		return (NULL);
	}
	for (int i = 0; i < N; i++)
		horde[i].setname(name);
	return (horde);
}
