/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:38:24 by fcardina          #+#    #+#             */
/*   Updated: 2023/12/03 12:40:47 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"

int	main(void)
{
	int number = 0;
	std::string	name;
	Zombie 		*z;
	
	z = zombieHorde(number, name);
	std::cout << "name of zombie" << std::endl;
	std::cin >> name;
	std::cout << "number of zombies" << std::endl;
	std::cin >> number;

	for (int i = 0; i < number; i++)
		z[i].announce();
	for (int i = 0; i < number; i++)
		z[i].distroyz();
	free(z);
}