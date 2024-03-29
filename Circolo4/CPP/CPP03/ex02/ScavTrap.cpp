/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:55:49 by fcardina          #+#    #+#             */
/*   Updated: 2024/01/25 00:27:00 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

using std::cout;
using std::endl;

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	cout << "Default ScavTrap constructor "<< name <<" was called!" << endl;
}

ScavTrap::~ScavTrap(void) 
{
	cout << "ScavTrap destructor was called for " << name << endl;
}

void ScavTrap::attack(const std::string& target, const int points)
{
	if (this->_energy_points == 0)
	{
		cout << "ScavTrap "<< name <<" cannot attack because he has no more energy points!" << endl;
		return;
	}
	else if (this->_hit_points == 0)
	{
		cout << "ScavTrap "<< name <<" cannot attack because he has no more hit points!" << endl;
		return;
	}
	std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << points << " points of damage!" << std::endl;
	this->_energy_points -= 1;
}

void ScavTrap::guardGate(void) 
{
	cout << "ScarvTrap " << this->name << " is now in Gate keeper mode" << endl;
}
