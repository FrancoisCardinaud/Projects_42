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
#include "FragTrap.hpp"




int main(void)
{
	FragTrap Jim("Jim");
	FragTrap Bob("Bob");

	std::cout << std::endl;

	Jim.attack("Bob", 30);
	Bob.takeDamage(30);

	std::cout << std::endl;

	Jim.attack("Bob", 20);
	Bob.takeDamage(20);

	std::cout << std::endl;

	Bob.attack("Jim", 99);
	Jim.takeDamage(99);

	std::cout << std::endl;

	Jim.attack("Bob", 40);
	Bob.takeDamage(40);

	std::cout << std::endl;

	Bob.highFivesGuys();

	std::cout << std::endl;

	Bob.beRepaired(10);
	Jim.beRepaired(9);

	std::cout << std::endl;

	Bob.attack("Jim", 8);
	Jim.takeDamage(8);

	std::cout << std::endl;

	Jim.attack("Bob", 200);
	Bob.takeDamage(200);

	std::cout << std::endl;

	return EXIT_SUCCESS;
}