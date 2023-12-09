/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:38:24 by fcardina          #+#    #+#             */
/*   Updated: 2023/12/09 16:33:18 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"

int	main(void)
{
	int number = 0;
	std::string	name;
	Zombie 		*z;
	
	std::cout << "Name of zombie:" << std::endl;
	std::cin >> name;
	std::cout << "Number of zombies:" << std::endl;
	std::cin >> number;
	z = zombieHorde(number, name);

	for (int i = 0; i < number; i++)
		z[i].announce();
	for (int i = 0; i < number; i++)
		z[i].destroy();
	delete[] z;
}