/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:54:05 by fcardina          #+#    #+#             */
/*   Updated: 2024/01/25 00:33:25 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "FragTrap.hpp"

using std::cout;
using std::endl;

int main(void)
{
	FragTrap Jim("Jim");
	FragTrap Bob("Bob");

	cout << endl;

	Jim.attack("Bob");
	Bob.takeDamage(30);

	cout << endl;

	Jim.attack("Bob");
	Bob.takeDamage(20);

	cout << endl;

	Bob.attack("Jim");
	Jim.takeDamage(99);

	cout << endl;

	Jim.attack("Bob");
	Bob.takeDamage(40);

	cout << endl;

	Bob.beRepaired(10);

	cout << endl;

	Jim.attack("Bob");
	Bob.takeDamage(10);

	cout << endl;

	Bob.highFivesGuys();

	cout << endl;

	Jim.attack("Bob");
	Bob.takeDamage(200);

	cout << endl;

	return EXIT_SUCCESS;
}