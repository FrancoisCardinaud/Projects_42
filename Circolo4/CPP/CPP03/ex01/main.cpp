/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:54:05 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/29 16:29:46 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "ScavTrap.hpp"




int main(void)
{
	ScavTrap Jim("Jim");
	ScavTrap Bob("Bob");

	std::cout << std::endl;

	Jim.attack("Bob", 5);
	Bob.takeDamage(5);

	std::cout << std::endl;

	Jim.attack("Bob", 1);
	Bob.takeDamage(1);

	std::cout << std::endl;

	Jim.attack("Bob", 1);
	Bob.takeDamage(1);

	std::cout << std::endl;

	Bob.beRepaired(7);

	std::cout << std::endl;

	Jim.attack("Bob", 10);
	Bob.takeDamage(10);

	std::cout << std::endl;

	Jim.attack("Bob", 200);
	Bob.takeDamage(200);

	std::cout << std::endl;
	
	Bob.attack("Jim", 10);

	std::cout << std::endl;

	Jim.guardGate();

	std::cout << std::endl;

	return EXIT_SUCCESS;
}