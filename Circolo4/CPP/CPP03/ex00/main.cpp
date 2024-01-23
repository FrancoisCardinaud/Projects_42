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

	Jim.attack("Bob");
	Bob.takeDamage(5);

	cout << endl;

	Jim.attack("Bob");
	Bob.takeDamage(1);

	cout << endl;

	Jim.attack("Bob");
	Bob.takeDamage(1);

	cout << endl;

	Bob.beRepaired(7);

	cout << endl;

	Jim.attack("Bob");
	Bob.takeDamage(10);

	cout << endl;

	return EXIT_SUCCESS;
}