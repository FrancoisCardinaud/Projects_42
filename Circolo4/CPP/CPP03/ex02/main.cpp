/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:54:05 by fcardina          #+#    #+#             */
/*   Updated: 2024/01/02 18:58:52 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "FragTrap.hpp"

using std::cout;
using std::endl;

int main(void)
{
	FragTrap John("John");
	FragTrap Albert("Albert");

	cout << endl;

	John.attack("Albert");
	Albert.takeDamage(30);

	cout << endl;

	John.attack("Albert");
	Albert.takeDamage(30);

	cout << endl;

	John.attack("Albert");
	Albert.takeDamage(30);

	cout << endl;

	John.attack("Albert");
	Albert.takeDamage(30);

	cout << endl;

	Albert.beRepaired(100);

	cout << endl;

	Albert.highFivesGuys();

	cout << endl;

	Albert.takeDamage(100);

	return EXIT_SUCCESS;
}