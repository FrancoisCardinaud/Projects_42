/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:54:05 by fcardina          #+#    #+#             */
/*   Updated: 2024/01/25 00:09:11 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "ScavTrap.hpp"

using std::cout;
using std::endl;

int main(void)
{
	ScavTrap Jim("Jim");
	ScavTrap Bob("Bob");

	cout << endl;

	Jim.attack("Bob", 5);
	Bob.takeDamage(5);

	cout << endl;

	Jim.attack("Bob", 1);
	Bob.takeDamage(1);

	cout << endl;

	Jim.attack("Bob", 1);
	Bob.takeDamage(1);

	cout << endl;

	Bob.beRepaired(7);

	cout << endl;

	Jim.attack("Bob", 10);
	Bob.takeDamage(10);

	cout << endl;

	Jim.attack("Bob", 200);
	Bob.takeDamage(200);

	cout << endl;
	
	Bob.attack("Jim", 10);

	cout << endl;

	Jim.guardGate();

	cout << endl;

	return EXIT_SUCCESS;
}