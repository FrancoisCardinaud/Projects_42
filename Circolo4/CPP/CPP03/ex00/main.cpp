/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:54:05 by fcardina          #+#    #+#             */
/*   Updated: 2024/01/19 17:43:57 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "ClapTrap.hpp"

using std::cout;
using std::endl;

int main(void)
{
	ClapTrap Jim("Jim");
	ClapTrap Bob("Bob");

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

	Bob.attack("Jim", 9);
	Jim.takeDamage(9);

	cout << endl;

	Jim.attack("Bob", 10);
	Bob.takeDamage(10);

	cout << endl;

	return EXIT_SUCCESS;
}